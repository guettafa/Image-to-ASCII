
# PATHS
#
SOURCE_VIDEO=./badapple.mp4
SOURCE_FILE=./src/i2a.c ./src/image.c

OUTPUT_FRAMES=frames/
OUTPUT_FILE=./build/image2ascii

# FLAGS 

MATH_LIB=-lm

# THE "PUT ALL TOGETHER SPACE"

build:
	rm -rf $(OUTPUT_FILE)
	gcc $(MATH_LIB) $(SOURCE_FILE) -o $(OUTPUT_FILE);

transform:
	ffmpeg -i $(SOURCE_VIDEO) $(OUTPUT_FRAMES)frame%d.jpg

cleanup:
	rm -rf $(OUTPUT_FRAMES)frame

