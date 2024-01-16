#pragma once

#include <string.h>
#include <math.h>

#ifndef IMAGE_H 

// Mysterious value that can define the image quality 
#define MAX_COLOR_VAL 2500 
/*
typedef struct {

	int w_flag;
	int h_flag;
	int f_flag;

	char* width_val;
	char* height_val;
	char* filename_val;
} Arguments;
*/

/*
 *	PIXEL STRUCT TO STORE RGBA COLORS AND POSITIONS OF EACH PIXEL 
 * */
typedef struct {

	unsigned int r_val; // Red 
	unsigned int g_val; // Green
	unsigned int b_val; // Blue
	float a_val;	    // Alpha 
	
	float intensity_val; 
	
	int x_pos;
	int y_pos;
} Pixels;

/*
 *	IMAGE STRUCT TO STORE PIXEL AND IMAGE DATA 
 * */

typedef struct {

	Pixels pixel;

	// For color channels, 
	// RGBA = 4 bytes / RGB = 3 bytes
	int channels;

	int width;
	int height;

	// To handle data received by stb_load function
	unsigned char *all_data;
} Image;

/*	
 *	INLINE FUNCTIONS
 */

static inline char intensityToChar(float intensity) {

	/*	Target a char in the CHARACTERS array depend 
	 *	on the intensity of each pixels
	 * */
	char CHARACTERS[] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	return CHARACTERS[(int) round(intensity * strlen(CHARACTERS))];
}

static inline float calculateIntensity(
	int r, int g, int b, float a) 
{
	return ((r + g + b + a) / MAX_COLOR_VAL); 
}

/*
 *	FUNCTIONS DECLARATIONS, DEFINITIONS ARE IN THE image.c file
*/

extern void displayASCII(Image img);
extern unsigned char* resizeImage(Image img);

#endif // !IMAGE_H
