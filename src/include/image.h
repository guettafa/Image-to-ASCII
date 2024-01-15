#pragma once
#ifndef IMAGE_H 

// 255 * 4 
#define MAX_COLOR_VAL 2000

/*
 *	IMAGE STRUCT TO STORE PIXEL DATA
 * */
typedef struct {

	int r_val; // Red 
	int g_val; // Green
	int b_val; // Blue
	float a_val; // Alpha (image opacity)
	//
	float intensity_val; // 
	//
	int x_pos;
	int y_pos;

} Pixel;

typedef struct {

	// RGBA so channels = 4 bytes (because 4 color channels)
	// RGB so channels = 3 bytes (because 3 color channels)
	int channels;

	int width;
	int height;
	int total_size;
} Image;

/*	FUNCTIONS DECLARATIONs	*/

extern char intensityToChar(float intensity);
extern float calculateIntensity(int r, int g, int b, float a);

#endif // !IMAGE_H
