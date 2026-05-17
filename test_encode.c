#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"


int main(int argc, char* argv[])
{
    if ( (argv[1] != NULL) && (check_operation_type(argv) == e_encode) )	//checking for is the argument 1 passed is not null and for Encoding or not
	{
		
		
		EncodeInfo encInfo;						//creating EncodeInfo structure variable
		
		if ( read_and_validate_encode_args(argv, &encInfo) == e_success )	//checking for are the files passed as input are readable or not
		{
			printf("INFO: Reading and Validating input files is Successful\n");
			
			if ( do_encoding(&encInfo)  == e_success )			//Starting the process to do Encoding
			{
				printf("INFO: ## Encoding Done Successfully ##\n");
			}
			
			else
			{
				printf("INFO: Encoding not completed\n");
			}
			
		}

		else
		{
			printf("INFO: Reading and Validating input files is not Successful\n");
		}
	}
	
	else if ( (argv[1] != NULL) && (check_operation_type(argv) == e_decode) )	//checking for is the argument 1 passed is not null and for Dencoding or not
	{
		printf("INFO: ## Decoding Procedure Started ##\n");

		DecodeInfo decInfo; 							//creating DecodeInfo structure variable

		if ( read_and_validate_decode_args(argv, &decInfo) == e_success )	//checking for are the files passed as input are readable or not
		{
			printf("INFO: Reading and Validating input files is Successful\n");
			
			if ( do_decoding(&decInfo)  == e_success )			//Starting the Decoding process
			{
				printf("INFO: ## Decoding Done Successfully ##\n");
			}
			
			else
			{
				printf("INFO: Decoding not completed\n");
			}
			
		}

		else
		{
			printf("INFO: Reading and Validating input files is not Successful\n");
		}
	}

	else
	{
		printf("INFO: Invalid Input\n");
	}
}

OperationType check_operation_type(char *argv[])	// Checking argument 1 operation type for Encoding Selected or Decoding Selected
{
	if( strcmp (argv[1] , "-e" ) == 0 )
	{
		return e_encode;
	}

	else if( strcmp (argv[1] , "-d" ) == 0 )
	{
		return e_decode;
	}

	else
	{
		return e_unsupported;
	}
}

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
	

	if ( (argv[2] != NULL) && ( strstr( argv[2] , ".bmp") != NULL ) )	//checking whether input file is passed or not and extension of (argv[2]) is .bmp
	{
		encInfo -> src_image_fname = argv[2] ;
	}

	else
	{
		return e_failure;
	}

	
	//if ( strcmp( strchr(argv[3], '.') , ".txt") != NULL )
	if ( (argv[3] != NULL) && ( strstr( argv[3] , ".txt") != NULL) )	//checking whether secret file is passed or not and extension of (argv[3]) is .txt
	{
		encInfo -> secret_fname = argv[3] ;
	}

	else
	{
		return e_failure;
	}

	

	if ( argv[4] == NULL)							//checking whether output file name is passed or not
	{
		printf("INFO: Output File not mentioned. Creating stego.bmp as default\n");
		encInfo -> stego_image_fname = "stego.bmp";
	}

	else
	{
		encInfo -> stego_image_fname = argv[4] ;
	}
	return e_success;
}



