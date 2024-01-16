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
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "../src/include/extern/stb_image.h"
#include "../src/include/extern/stb_image_resize2.h"


int main(int argc, char*argv[]) {

	// Declaration of image and pixel struct to store data 
	Image img;
	Pixels p;

	// For options
	char c;

	int w_flag = 0;
	int h_flag = 0;
	int f_flag = 0;

	int width_val = 0;
	int height_val = 0;
	char* filename_val = NULL;

/*
	Arguments args;

	// Flags
	args.w_flag = 0;
	args.h_flag = 0;
	args.f_flag = 0;

	// Args values
	args.width_val = NULL;
	args.height_val = NULL;
	args.filename_val = NULL;

	int new_width = 0;	
	int new_height = 0;	
*/

	// Verify arguments in execution to see if the user
	// have a preferred size for his ascii
	while ((c = getopt(argc, argv, "f:w:h:")) != -1) {
		switch (c) {
			case 'f':
				f_flag = 1;
				filename_val = optarg;
				break;	
			case 'w':
				w_flag = 1;
				width_val = atoi(optarg); 
				break;
			case 'h':
				h_flag = 1;
				height_val = atoi(optarg); 
				break;
		}
	}

	// Extract some informations from the image to store them in the Image struct
	// and store all image data in a unsigned char  
	img.all_data = stbi_load(
		filename_val,   
		&img.width, 
		&img.height, 
		&img.channels,
		0); // preferred color channels (0 default so the channels of the image)
	
	if (img.all_data == NULL) {
		printf("%s\n",stbi_failure_reason());
		return 1;
	}

	// To store the ascii image
	char* ascii_image = (char*) malloc(32000);
	if (ascii_image == NULL) {
		printf("Not allocated\n");
		return 1;
	}
	
	// This is where the magic begin
	displayASCII(img);	

	free(ascii_image);
	return 0;
}
