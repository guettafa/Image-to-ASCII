#pragma once

#include <stdint.h>
#include <string.h>
#include <math.h>

#ifndef IMAGE_H 

// Mysterious value that can define the image quality 
#define MAX_COLOR_VAL 2500 

/*
 *	PIXEL STRUCT TO STORE RGBA COLORS AND POSITIONS OF EACH PIXEL 
 * */

typedef struct {

	uint8_t r_val; // Red 
	uint8_t g_val; // Green
	uint8_t b_val; // Blue
	float a_val;	    // Alpha 
	
	float intensity_val; 
	
	unsigned int x_pos;
	unsigned int y_pos;
} Pixels;

/*
 *	IMAGE STRUCT TO STORE PIXEL AND IMAGE DATA 
 * */

typedef struct {

	Pixels pixel;

	// For color channels, 
	// RGBA = 4 bytes / RGB = 3 bytes
	uint8_t channels;

	unsigned int width;
	unsigned int height;

	// To handle data received by stb_load function
	unsigned char* all_data;
} Image;

/*	
 *	INLINE FUNCTIONS
 */

static inline int intensityToChar(float intensity) {
	char CHARACTERS[72] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	return CHARACTERS[(int) round(intensity * strlen(CHARACTERS))];
}

static inline float calculateIntensity(
	uint8_t r, uint8_t g, uint8_t b, float a) 
{
	return ((r + g + b + a) / MAX_COLOR_VAL); 
}

/*
 *	FUNCTIONS DECLARATIONS,DEFINITIONS ARE IN THE image.c file
 */

extern char* alloc_ASCII(int width, int height); 
extern void create_ASCII(Image img, char* ascii);
extern void display_ASCII(char* ascii);

#endif // !IMAGE_H
