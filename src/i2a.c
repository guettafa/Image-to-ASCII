
/*
 *	STANDARD LIBRARY 
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *	CUSTOM HEADERS
 * */
#include "../src/include/image.h"

/*
 *	PUBLIC DOMAIN LIBRARY	
 * */
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "../src/include/extern/stb_image.h"
#include "../src/include/extern/stb_image_resize2.h"

int main(void) {

	const char filename[] = "../examples/linux.png";

	// Declaration of image and pixel struct to store data 
	Image img;
	Pixel p;

	// Extract some informations from the image to store them in the Image struct
	// and store all image data in a unsigned char  
	unsigned char *img_data = stbi_load(

		filename, // input file  
		&img.width, // where to store the image width
		&img.height, // where to store the image height
		&img.channels, // where to store the color channels
		0); // preferred color channels (0 default so the channels of the image)
	
	if (img_data == NULL) {
		printf("%s\n",stbi_failure_reason());
		return 1;
	}

	// Create a index to track which pixel are we looking at 
	int index;
	img.total_size = img.width * img.height;
	
	// To store the ascii image
	char* ascii_image = (char*) malloc(img.total_size++);
	if (ascii_image == NULL) {
		goto failure;
	}

	// Loop trought every pixel of width and height 
	while (p.y_pos != img.height) {		
		while (p.x_pos != img.width) {
			index = (p.y_pos * img.width + p.x_pos) * img.channels;

			/* Store the rgba color of the pixel
			   Because rgba values are stored like that in each index:

			     R - G - B  - A  -   R - G  ...
			   {255, 42, 13, 0.2}, {243, 24
			*/ 			
			p.r_val = img_data[index]; 
			p.g_val = img_data[index+=1];
			p.b_val = img_data[index+=2];
			p.a_val = img_data[index+=3];
			p.intensity_val = calculateIntensity(
				p.r_val, p.g_val, p.b_val, p.a_val);

			char c = intensityToChar(p.intensity_val);
			printf("%c",c);

			p.x_pos++;
		}
		p.x_pos = 0;
		p.y_pos++;

		printf("\n");
	}
	failure:
		printf("Not allocated\n");
		return 1;

	return 0;
}
