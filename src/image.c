#include "include/image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	FUNCTIONS DEFINITIONS		*/

/*
 *	Store the ASCII art in the char* in param
 *	and refer to the Image struct for dimensions
 * */
void create_ASCII(Image img, char* ascii) {

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

			*++ascii = intensityToChar(img.pixel.intensity_val);
			img.pixel.x_pos++;
		}

		*ascii = '\n';
		img.pixel.x_pos = 0;
		img.pixel.y_pos++;
	}
}

/*	
 *	Alloc enough memory to store 
 *	each characters for the ascii art in it	
 */
char* alloc_ASCII(int width, int height) {
	char* ascii_image = NULL;
	int total = width*height;
	int i=0;
	if ((ascii_image = (char*) calloc(total, sizeof(char))) == NULL) {
		return NULL;
	}
	return ascii_image;
} 

/*
 * Display each character in the char_ptr to draw the ASCII art 
 * */
void display_ASCII(char* ascii) {
	while (*++ascii != '\0') {
		printf("%c",*ascii);
	}
}

