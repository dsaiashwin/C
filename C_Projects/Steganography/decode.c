/*
Name : Sai Ashwin D
Date : 09 - 06 - 2025
Description : Implement Decoding for Steganography
*/

#include "decode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Input: argv[] (Arguments Passed),Structure Variable pointer 
 * Output: e_success or e_failure, on file errors
 */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
	//checking whether input file extension (argv[2]) is .bmp
	
	if ( (argv[2] != NULL) && ( strstr( argv[2] , ".bmp") != NULL ) )
	{
		decInfo -> stego_image_fname = argv[2] ;
	}

	else
	{
		return e_failure;
	}

	//checking whether output file name is passed or not and 

	if ( argv[3] == NULL)
	{
		decInfo -> valid_secret_file_name = 1;
	}

	else
	{
		strcpy(decInfo -> secret_file_name,argv[3]) ;
	}

	return e_success;
	
}


/* 
 * Get File pointer for Stego/Target file
 * Inputs: Stego Image file name and pointer of Structure Variable
 * Output: FILE pointer for Stego file
 * Return Value: e_success or e_failure, on file errors
 */

Status open_stego_file(DecodeInfo *decInfo)
{
	printf("INFO: Opening required files\n");
    // Stego Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
    // Do Error handling
    if (decInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

    	return e_failure;
    }
    // No failure return e_success
    return e_success;
}

/* 
 * Decoding / Extracting bit from LSB there of characters
 * Inputs: Source Image Data of respective number of bytes 
 * Output: Decoded bytes of Stego Image
 * Return Value: e_success or e_failure
 */

Status decode_byte_from_lsb(char *data, char *image_data)
{	
	*data = 0;
	for ( int i = 0 ; i < 8 ; i++)
	{	
		*data= *data | ( ( image_data[i] & 0x01) << 7-i ) ;	
	}
	return e_success;
}

/* 
 * Decoding Magic String From LSB of bytes of Stego Image
 * Inputs: Size of Magic String, file Pointer of Setgo / Target Image,Pointer of Structure Variable
 * Output: Decoded Magic String 
 * Return Value: e_success or e_failure
 */
		
Status decode_magic_str_from_image(int size,FILE *fptr_stego, DecodeInfo *decInfo)
{
	printf("INFO: Decoded Magic String is: ");
	unsigned char data[2];
	for ( int i = 0 ; i < size ; i++)
	{
		fread(decInfo -> image_data, 8, sizeof(char), fptr_stego);	
		decode_byte_from_lsb(&data[i], decInfo -> image_data);

		printf("%s",&data[i]);
	}
	printf("\n");

	if (!(strcmp(MAGIC_STRING,&data[0])))
	{
		printf("INFO: Decoded Magic String matches with Original Magic String\n");
	}
	
	else
	{
		printf("INFO::: Decoded Magic String dosen't match with Original Magic String\n");
	}
	
}
/* 
 * Decoding Magic String From LSB of bytes of Stego Image
 * Inputs: file Pointer of Stego / Target Image,Pointer of Structure Variable
 * Output: Decoded Magic String 
 * Return Value: e_success or e_failure
 */
Status decode_magic_string(DecodeInfo *decInfo)
{
	printf("INFO: Decoding Magic String Signature\n");
	decode_magic_str_from_image( 2, decInfo -> fptr_stego_image, decInfo);
	return e_success;
}

/* 
 * Decoding one 1 bit from LSB of one Number there by 32 bits as integer from 4 bytes at LSB of secret data
 * Inputs: Stego/Target Image Data of respective number of bytes
 * Output: Decoded bytes of Stego/ Target Image
 * Return Value: e_success or e_failure
 */

Status decode_size_from_lsb(int* data, char *image_data)
{	
	for ( int i = 0 ; i < 32 ; i++)
	{
		*data= *data | ( ( image_data[i] & 1) << 31-i ) ;
	}	
}

/* 
 * Decoding Secret file Extension Size
 * Inputs: Size of Data to be Decoded,File Pointer of Target Image,Pointer of Structure Variable
 * Output: Storing the Decoded Extension size in Structure Variable
 * Return Value: e_success or e_failure
 */

Status decode_extn_size(DecodeInfo *decInfo)
{	
	char extn_siz[32];
	printf("INFO: Decoding Output File Extension Size\n");
	fread(extn_siz, 32 , sizeof(char), decInfo -> fptr_stego_image);
	decode_size_from_lsb(&(decInfo -> secret_file_extn_size), extn_siz);
	printf("INFO: The size of extn is : %d\n",decInfo -> secret_file_extn_size);
	return e_success;
}

/* 
 * Concatinating Decoded secret file Extension with Secret file name
 * Inputs: Secret File Name,Secret file Extension ,Pointer of Structure Variable
 * Output: Concatinated Secret File Name
 * Return Value: e_success or e_failure
 */

Status str_cat(DecodeInfo *decInfo)
{	
	if(decInfo -> valid_secret_file_name == 1)
	{
		strcpy(decInfo -> secret_file_name , "Secret_decoded");
		printf("INFO: Output Secret File not mentioned. Creating \" %s \" as default\n",decInfo -> secret_file_name);
	}

	printf("INFO: Concatinating Output File name and Decoded Extension\n");
	strcat(decInfo -> secret_file_name,decInfo ->secret_file_extn);
	printf("INFO: The Output file name is :%s\n",decInfo -> secret_file_name);
	return e_success;
}

/* 
 * Decoding Secret file Extension 
 * Inputs: Size of Data to be Decoded,File Pointer of Target Image,Pointer of Structure Variable
 * Output: Storing the Decoded Extension in Structure Variable
 * Return Value: e_success or e_failure
 */
Status decode_secret_file_extn(DecodeInfo *decInfo, FILE *fptr_stego)
{
	char extn[4];
	printf("INFO: Decoding Output File Extension\n");
	for ( int i = 0 ; i < (decInfo -> secret_file_extn_size) ; i++)
	{
		fread(decInfo -> image_data, 8 , sizeof(char), fptr_stego);	
		decode_byte_from_lsb(&extn[i], decInfo -> image_data);
	}
	extn[4]= '\0';
	printf("INFO: Decoded extension is :\"%s\"\n",extn);
	strcpy(decInfo -> secret_file_extn,extn);

	if (strcmp(extn,".txt")== 0)
	{
		
		printf("INFO: Decoded Size of Extension matches with decoded extension string\n");
	
	}
			
	return e_success;
}

/* 
 * Opening File to store the secret message in Write Mode
 * Inputs: Stego Image file name,Secret file name and pointer of Structure Variable
 * Output: FILE pointer for Secret file
 * Return Value: e_success or e_failure, on file errors
 */

Status open_secret_file(DecodeInfo *decInfo)
{
    // Stego Image file
    decInfo->fptr_secret = fopen(decInfo->secret_file_name, "w");
    // Do Error handling
    if (decInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->secret_file_name);
    	return e_failure;
    }
    // No failure return e_success
	printf("INFO: Opened %s\n",decInfo->secret_file_name);
    return e_success;
}

/* 
 * Decoding Secret file Size
 * Inputs: Size of Data to be Decoded,File Pointer of Target/Stego Image,Pointer of Structure Variable
 * Output: Storing the Decoded Secret FIle Size size in Structure Variable
 * Return Value: e_success or e_failure
 */

Status decode_secret_fsize(DecodeInfo *decInfo)
{
	char secret_fsize[32];
	printf("INFO: Decoding %s File Size\n",decInfo->secret_file_name);
	fread(secret_fsize, 32 , sizeof(char), decInfo -> fptr_stego_image);	
	decode_size_from_lsb(&(decInfo -> size_secret_file), secret_fsize);
	printf("INFO: Secret file size :%d\n",decInfo -> size_secret_file);
	return e_success;
}

/* 
 * Decoding Secret file Size
 * Inputs: Size of Secret file to be Decoded,File Pointer of Target/Stego Image,Pointer of Structure Variable
 * Output: Writing the Decoded Secret data in Secret file
 * Return Value: e_success or e_failure
 */

Status decode_secret_file_data(DecodeInfo *decInfo)
{
	printf("INFO: Decoding %s File Data\n",decInfo -> secret_file_name);
	char msg[decInfo -> size_secret_file];
	decInfo->fptr_stego_image;
	//printf("INFO: Decoding %s File Data\n",decInfo->secret_file_name);
	for ( int i = 0 ; i < (decInfo -> size_secret_file) ; i++)
	{
		fread(decInfo -> image_data, 8 , sizeof(char), decInfo->fptr_stego_image);	
		decode_byte_from_lsb(&msg[i], decInfo -> image_data);
	}
	
	fwrite(msg, decInfo -> size_secret_file, sizeof(char), decInfo->fptr_secret);
	msg[decInfo -> size_secret_file]= '\0';
	printf("INFO: Encoded Data is present in %s file\n",decInfo -> secret_file_name);
	
	return e_success;
	
}

Status do_decoding(DecodeInfo *decInfo)						//starting the Process of Decoding
{
	if( open_stego_file(decInfo) == e_success )				//opening Stego/Encoded Image File
	{
		printf("INFO: Opened %s \n",decInfo -> stego_image_fname);

		fseek(decInfo->fptr_stego_image, 54, SEEK_SET);			//Skipping or Shifting the pointer 54 bytes as it is Header
		
		if ( decode_magic_string(decInfo) == e_success)			//Decoding the Magic String
		{
			printf("INFO: Done\n");
			
			if (decode_extn_size(decInfo) == e_success)		//Decoding the Encoded Secret file Extension Size
			{
				printf("INFO: Done\n");
				
				if (decode_secret_file_extn(decInfo,decInfo -> fptr_stego_image) == e_success)		//Decoding the Encoded Secret file Extension 
				{
					printf("INFO: Done\n");
					
					if (str_cat(decInfo) == e_success)						//Concatinating the secret file Name with Secret file Extension
					{
						printf("INFO: Done\n");

						if ( open_secret_file(decInfo) == e_success )				//Opening the Secret file in Write mode to write Secret encoded Data
						{
							printf("INFO: Done. Opened all required files\n");
						
							if (decode_secret_fsize(decInfo) == e_success)			//Decoding the Encoded Secret file Size
							{
								printf("INFO: Done\n");

								if (decode_secret_file_data(decInfo) == e_success )	//Finally Decoding the Encoded Secret DATA or MESSAGE
								{
									printf("INFO: Done\n");	
									
								}
								else
								{
									printf("INFO: Decoding Secret file Data is not successful\n");
									return e_failure;
								}
							}

							else
							{
								printf("INFO: Decoding Secret file Size is not successful\n");
								return e_failure;
							}
						}
						else
						{
							printf("INFO: opening Stego file is not successful\n");
							return e_failure;																				
						}
					}
					else
					{
						printf("INFO: Concatination of Secret file name with Extension is not successful\n");
						return e_failure;
					}
					
				}
				else 
				{
					printf("INFO: Secret file extension not decoded successfully\n");
					return e_failure;
				}	
			}
			
			else 
			{
				printf("INFO: Secret file extension Size not decoded successfully\n");
				return e_failure;
			}			
			
		}
		else
		{
			printf("INFO: Magic String not Decoded successfully\n");
			return e_failure;
		}
	}
	else
	{
		printf("INFO: opening Stego file is not successful");
		return e_failure;
	}
return e_success;

}

