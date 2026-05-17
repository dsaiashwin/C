/*
Name : Sai Ashwin D
Date : 09 - 06 - 2025
Description : Implement Encoding for Steganography
*/
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    
    fseek(fptr_image, 18, SEEK_SET);	// Seek to 18th byte

    
    fread(&width, sizeof(int), 1, fptr_image);	// Read the width (an int)
    //printf("width = %u\n", width);

    
    fread(&height, sizeof(int), 1, fptr_image);	// Read the height (an int)
    //printf("height = %u\n", height);

    
    return width * height * 3;	// Return image capacity
}

/* 
 * Get File pointers for input and output files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
	printf("INFO: Opening required files\n");
    
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");	// opening Source Image file in Read mode
    
    if (encInfo->fptr_src_image == NULL)				// Do Error handling
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }
	printf("INFO: Opened %s\n",encInfo->src_image_fname);
    
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");		// opening Secret file in Read Mode
    
    if (encInfo->fptr_secret == NULL)					// Do Error handling
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }
	printf("INFO: Opened %s\n",encInfo->secret_fname);
    
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");	//Opening Stego Image file in Write mode
    
    if (encInfo->fptr_stego_image == NULL)				// Do Error handling
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }
	printf("INFO: Opened %s\n",encInfo->stego_image_fname);
	
    
    return e_success;							// No failure return e_success
}
/* 
 * Get File Size for i/p and o/p files
 * Input: file pointer of Secret file
 * Output: Size of Secret file /pointer pointing to last character in secret file
 * Return Value: pointer position
 */
uint get_file_size(FILE *secret)
{
	fseek (secret , 0 , SEEK_END);
	return ftell(secret);							//gives the size of secret file
}

/* 
 * Checking the capacity of Source file that it can store Secret file data and some other Important data or not 
 * Inputs: Pointer of Structure Variable,Source Image file pointer , Secret file pointer
 * Output: Source Image capacity that it can accomodate Secret file data and some other Important data or not 
 * Return Value: e_success or e_failure
 */

Status check_capacity(EncodeInfo *encInfo)
{
	
	encInfo -> image_capacity = get_image_size_for_bmp(encInfo -> fptr_src_image) ; //source Image .bmp file size

	printf("INFO: checking for %s size\n",encInfo->secret_fname);	
	
	encInfo -> size_secret_file = get_file_size(encInfo -> fptr_secret) ; 		//Secret.txt file size

	if (encInfo -> size_secret_file !=0)
		printf("INFO: Done. Not Empty\n");

	/* Image capacity should be greater than Header + Magic String + size of Extension .bmp + size of Extension .txt + size of secret file + size for encoding data */
	
	printf("INFO: Checking for %s capacity to handle %s\n", encInfo->src_image_fname,encInfo->secret_fname);
	
	if ( encInfo -> image_capacity > ( 54 + 16 + 32 + 32 + 32 + (encInfo -> size_secret_file * 8) ) )
	{
		return e_success;
	}

	else
	{
		return e_failure;
	}
}

/* 
 * Copying source image Header to target / stego image Header
 * Inputs: Source Image file pointer , Secret file pointer
 * Output: Header of Source Image copyed to Stego Image
 * Return Value: writing the Encoded bytes to Target / Stego image
 */

Status copy_bmp_header(FILE *src, FILE *output)
{
	char str[54];
	
	rewind(src); // offset will be set back to 0
	printf("INFO: Copying Image Header\n");

	fread( str , 54 , sizeof(char), src);			//reading 54 bytes from source
	
	fwrite( str , 54 , sizeof(char), output);		//writing the 54 bytes to output file or stego file

}

/* 
 * Encoding one 1 bit to LSB of one character there by 1 byte to LSB's 8 bytes of secret data
 * Inputs: Source Image Data of respective number of bytes , bits of characters to be encoded
 * Output: Encoded bytes of Source Image
 * Return Value: e_success or e_failure
 */

Status encode_byte_to_lsb(char data, char *image_data)
{
	//data - 8 bits, image data - 8 bytes

	unsigned char mask = 1 << 7;
	
	for ( int i = 0 ; i < 8 ; i++)
	{
		image_data[i] = ( (image_data[i] & 0xFE) | ( ( data & mask ) >> (7 - i) ) );
		mask = mask >> 1;
	}
	return e_success;
}

/* 
 * Encoding Data to LSB of one character of Source Image 
 * Inputs: Source Image Data of respective number of bytes ,size of data, file pointers of Source and stego / target image file,Pointer of Structure Variable
 * Output: Encoded bytes of Source Image written in Target Image
 * Return Value: e_success or e_failure
 */

Status encode_data_to_image(const char *data, int size, FILE *fptr_src, FILE *fptr_stego,EncodeInfo* encInfo)
{
	for ( int i = 0 ; i < size ; i++)
	{
		fread(encInfo -> image_data, 8, sizeof(char), fptr_src);	//reading image_data from source image
		encode_byte_to_lsb(data[i], encInfo -> image_data);		//getting the data encoded with image data by passing to function
		fwrite(encInfo -> image_data ,8, sizeof(char), fptr_stego);	//writing back the modified or encoded data to target or stego image
	}
	return e_success;
}

/* 
 * Encoding Magic String to LSB of bytes of Source Image
 * Inputs: Magic String, size of Magic String, file pointer of Source Image, file Pointer of Setgo / Target Image,Pointer of Structure Variable
 * Output: Magic String Encoded bytes of Source Image written in Target Image
 * Return Value: e_success or e_failure
 */

Status encode_magic_string(const char *magic_str, EncodeInfo *encInfo)
{
	printf("INFO: Encoding Magic String Signature\n");
	encode_data_to_image(magic_str, strlen(magic_str), encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);

	return e_success;
}

/* 
 * Encoding one 1 bit to LSB of one Number there by 32 bits as integer with 1 bit at LSB of secret data
 * Inputs: Source Image Data of respective number of bytes , bits of number to be encoded and Size of data
 * Output: Encoded bytes of Source Image
 * Return Value: e_success or e_failure
 */

Status encode_size_to_lsb(char* image_buffer, int size)
{
	unsigned int mask = 1 << 31;
	
	for ( int i = 0 ; i < 32 ; i++)
	{
		image_buffer[i] = ( (image_buffer[i] & 0xFE) | ( ( size & mask ) >> (31 - i) ) );
		mask = mask >> 1;
	}
	return e_success;
}

/* 
 * Encoding Secret file Extension Size
 * Inputs: Size of Data to be Encoded,File Pointer of Source Image,File Pointer of Target Image,,Pointer of Structure Variable
 * Output: writing the Encoded bytes to Target / Stego image
 * Return Value: e_success or e_failure
 */

Status encode_secret_file_extn_size(int size,FILE* src_image, FILE* stego_image,EncodeInfo *encInfo)
{
	char str[32];
	printf("INFO: Encoding %s File Extension Size\n",encInfo->secret_fname);
	fread(str,32,sizeof(char),src_image);		//reading image_data from source image
	encode_size_to_lsb(str,size);			//getting the data encoded with secret.txt file extension size (.txt -> 32 bits)  by passing to function
	fwrite(str,32,sizeof(char),stego_image);	//writing back the modified or encoded data to target or stego image
	return e_success;
}

/* 
 * Encoding Secret file Extension 
 * Inputs: FileExtension to be Encoded,Structure Variable Pointer
 * Output: writing the Encoded bytes to Target / Stego image
 * Return Value: e_success or e_failure
 */

Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
	printf("INFO: Encoding %s File Extension\n",encInfo->secret_fname);
	file_extn = ".txt";
	encode_data_to_image(file_extn, strlen(file_extn), encInfo -> fptr_src_image, encInfo -> fptr_stego_image, encInfo);

	return e_success;
}

/* 
 * Encoding Secret file Size 
 * Inputs: File Size to be Encoded,File Pointer of Source Image,File Pointer of Stego Image, Structure Variable Pointer
 * Output: writing the Encoded bytes to Target / Stego image
 * Return Value: e_success or e_failure
 */

Status encode_secret_file_size(long int file_size, EncodeInfo *encInfo)
{
	char str[32];
	printf("INFO: Encoding %s File Size\n",encInfo->secret_fname);
	fread(str,32,sizeof(char),encInfo -> fptr_src_image);		//reading image_data from source image
	encode_size_to_lsb(str,file_size);				//getting the data encoded with secret.txt file size (integer 25=4 bytes=32 bits so we need-> 32 bytes) by passing to function
	fwrite(str,32,sizeof(char),encInfo -> fptr_stego_image);	//writing back the modified or encoded data to target or stego image

	return e_success;
}

/* 
 * Encoding Secret file Data 
 * Inputs: File Pointer of Source Image,File Pointer of Stego Image,Pointer to  Structure Variable 
 * Output: writing the Encoded bytes to Target / Stego image
 * Return Value: e_success or e_failure
 */

Status encode_secret_file_data(EncodeInfo *encInfo)
{
	fseek(encInfo -> fptr_secret, 0, SEEK_SET);
	printf("INFO: Encoding %s File Data\n",encInfo->secret_fname);
	char ch;
	for (int i = 0 ; i < (encInfo -> size_secret_file) ; i++ )
	{
		fread(encInfo -> image_data, 8, sizeof(char),encInfo -> fptr_src_image);

		fread(&ch, 1, sizeof(char), encInfo -> fptr_secret);

		encode_byte_to_lsb(ch , encInfo -> image_data);

		fwrite(encInfo -> image_data, 8, sizeof(char), encInfo -> fptr_stego_image);	
	}

	return e_success;
}

/* 
 * Copying Remaining Data as it is to Target / Stego Image
 * Inputs: File Pointer of Source Image,File Pointer of Stego Image
 * Output: writing the bytes to Target / Stego image
 * Return Value: e_success or e_failure
 */

Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_stego,EncodeInfo *encInfo)
{
	char ch;
	printf("INFO: Copying Left Over Data\n");
	while ( fread(&ch, 1, sizeof(char), fptr_src) )
	{
		fwrite(&ch, 1,sizeof(char), fptr_stego );
	}
	printf("INFO: The Encoded Image file name is %s\n",encInfo->stego_image_fname);
	return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
	if( open_files(encInfo) == e_success )								//Trying to open the source file and Secret file
	{
		printf("INFO: Done\n");
		printf("INFO: ## Encoding Procedure Started ##\n");

		if ( check_capacity(encInfo) == e_success)						//checking the capacity for Encoding in Target File
		{
			printf("INFO: Done. Found ok\n");

			if ( copy_bmp_header(encInfo -> fptr_src_image, encInfo -> fptr_stego_image) )	//copying the Header part as it is from Source to Target
			{
				printf("INFO: Done\n");

				if ( encode_magic_string(MAGIC_STRING, encInfo) == e_success)		//Encoding the Magic String and Writing in Target Image
				{	
					printf("INFO: Done\n");
													//Encoding the Secret file Extension Size and Writing in Target Image
					if (encode_secret_file_extn_size(strlen(".txt"),encInfo -> fptr_src_image, encInfo -> fptr_stego_image,encInfo) == e_success)	
					{
						printf("INFO: Done\n");
													//Encoding the Secret file Extension and Writing in Target Image
						if(encode_secret_file_extn(encInfo -> extn_secret_file, encInfo) == e_success)
						{
							printf("INFO: Done\n");
													//Encoding the Secret file Size and Writing in Target Image
							if (encode_secret_file_size(encInfo -> size_secret_file, encInfo) == e_success)
							{
								printf("INFO: Done\n");

								if (encode_secret_file_data(encInfo) == e_success)
								{
									printf("INFO: Done\n");
													//Copying Ramaining Data as it is to Target / Stego Image
									if( copy_remaining_img_data(encInfo -> fptr_src_image, encInfo -> fptr_stego_image,encInfo) == e_success)
									{
										printf("INFO: Done\n");
										
									}
									else
									{
										printf("INFO:::Remaining data not copied Successfully\n");
										return e_failure;
									}


								}
								else
								{
									printf("INFO:::Secret file data not encoded succesfully\n");
									return e_failure;
								}

							}
							else
							{
								printf("INFO:::Secret file size not encoded successfully\n");
								return e_failure;
							}
						}
						else
						{
							printf("INFO:::Encoding secret file extension not Successful\n");
							return e_failure;
						}

					}
					else
					{
						printf("INFO:::Secret file extension Size not encoded successfully");
						return e_failure;
					}
				}

				else
				{
					printf("INFO:::Magic String not Encoded successfully\n");
					return e_failure;
				}
			}

			else
			{
				printf("INFO:::HEADER not copied Successfully\n");
				return e_failure;
			}
		}
	
		else
		{
			printf("INFO:::Image doesn't have Enough Capacity\n");
			return e_failure;
		}
	}	

	else
	{
		printf("INFO:::opening files is not successful");
		return e_failure;
	}
	return e_success;
}


