#include "./include/image.h"
#include <string.h>
#include <math.h>

/*	Target a char in the CHARACTERS array depend 
 *	on the intensity of each pixels
 * */
char intensityToChar(float intensity) {
	char CHARACTERS[] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	return CHARACTERS[(int) round(intensity * strlen(CHARACTERS))];
}

float calculateIntensity(int r, int g, int b, float a) {
	return ((r + g + b + a) / MAX_COLOR_VAL); 
}



