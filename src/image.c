#include "./include/image.h"
#include <stdio.h>

/*	FUNCTIONS DEFINITIONS		*/

void displayASCII(Image img) {

	// Create a index to track which pixel are we looking at 
	int index;

	// Loop trought every pixel of width and height 
	while (img.pixel.y_pos != img.height) {		
		while (img.pixel.x_pos != img.width) {
			index = (img.pixel.y_pos * img.width + img.pixel.x_pos) * img.channels;

			/* Store the rgba color of the pixel
			   Because rgba values are stored like that in each index:

			     R - G - B  - A  -   R - G  ...
			   {255, 42, 13, 0.2}, {243, 24
			*/ 			
			img.pixel.r_val = img.all_data[index]; 
			img.pixel.g_val = img.all_data[index+=1];
			img.pixel.b_val = img.all_data[index+=2];
			img.pixel.a_val = img.all_data[index+=3];
			img.pixel.intensity_val = calculateIntensity(
				img.pixel.r_val, img.pixel.g_val, img.pixel.b_val, img.pixel.a_val);

			char c = intensityToChar(img.pixel.intensity_val);
			printf("%c",c);

			img.pixel.x_pos++;
		}

		img.pixel.x_pos = 0;
		img.pixel.y_pos++;

		printf("\n");
	}
}

