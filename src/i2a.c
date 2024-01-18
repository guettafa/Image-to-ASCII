/*
 *	STANDARD LIBRARY 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *	CUSTOM HEADERS
 * */
#include "include/image.h"

/*
 *	PUBLIC DOMAIN LIBRARY	
 * */
#define STB_IMAGE_IMPLEMENTATION

#include "../src/include/stb/stb_image.h"

int main(int argc, char*argv[]) {

	// Declaration of image and pixel struct to store data 
	Image img;
	Pixels p;

	// Alloc enough space to store the ASCII art
	char* ascii_image = NULL;

	// For filename 
	int c;
	int filename_flag = 0;
	char* filename_val = NULL;

	// Verify argument to get the file path of the image	
	while ((c = getopt(argc, argv, "f:")) != -1) {
		switch (c) {
			case 'f':
				filename_flag = 1;
				filename_val = optarg;
				break;	
		}
	}

	// Extract some informations from the image to store them in the Image struct
	// and store all image data in a unsigned char  
	img.all_data = stbi_load(
		filename_val,   
		(int*) &img.width, 
		(int*) &img.height, 
		(int*) &img.channels,
		0); // preferred color channels (0 default so the channels of the image)
	 
	
	if (img.all_data == NULL) {
		printf("%s\n",stbi_failure_reason());
		goto error;
	}

	
	// Alloc enough space to store the ASCII art
	ascii_image = alloc_ASCII(img.width, img.height);

	if (ascii_image == NULL) {
		printf("Not allocated\n");
		goto error;
	}

	// Functions calls
	create_ASCII(img, ascii_image);
	display_ASCII(ascii_image);

	free(ascii_image);

	error:
		return 1;

	free(ascii_image);

	return 0;
}
