#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include <string.h>
#include "types.h" // Contains user defined types

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

/* 
 * Structure to store information required for
 * decoding stego.bmp file and store in a  file
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;
    char image_data[MAX_IMAGE_BUF_SIZE];
    char extn_stego_file[MAX_FILE_SUFFIX];

    /* Secret File Info */
	int valid_secret_file_name;
    char secret_file_name[50];
    FILE *fptr_secret;
    char secret_file_extn[MAX_FILE_SUFFIX];
    char secret_data[MAX_SECRET_BUF_SIZE];
    int size_secret_file;
	int secret_file_extn_size;
	

} DecodeInfo;

/* Decoding function prototype */

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* Decode Magic String */
Status decode_magic_string(DecodeInfo *decInfo);

/* Decode function, which does the real Decoding */
Status decode_magic_str_from_image(int size, FILE *fptr_stego, DecodeInfo *decInfo);

/* Decode a byte From LSB of image data array */
Status decode_byte_from_lsb(char *data, char *image_data);

/* Decode the Secet file Extension Size From LSB */
Status decode_extn_size(DecodeInfo *decInfo);

/* Decode a Size (integer) from LSB of image data array */
Status decode_size_from_lsb(int *data, char *image_data);

/*Decode Secret file Extension from LSB */
Status decode_secret_file_extn(DecodeInfo *decInfo, FILE *fptr_stego);

/*Concatinating Secret file Name with Decoded Extension*/
Status str_cat(DecodeInfo *decInfo);

/*Opening the secret file in Write Mode*/
Status open_secret_file(DecodeInfo *decInfo);

/*Decode the secret file Size*/
Status decode_secret_fsize(DecodeInfo *decInfo);

/*Decode the secret file Data*/
Status decode_secret_file_data(DecodeInfo *decInfo);





#endif
