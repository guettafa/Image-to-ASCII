
# PATHS

SOURCE_FILE=./src/i2a.c ./src/image.c
OUTPUT_FILE=./build/image2ascii

# FLAGS 

MATH_LIB=-lm
TIME_REPORT=-ftime-report

# THE "PUT ALL TOGETHER SPACE"

build:
	gcc $(TIME_REPORT) $(SOURCE_FILE) -o $(OUTPUT_FILE) $(MATH_LIB);

