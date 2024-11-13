# Image to ASCII 
a simple program made with the C programming language to transform 
an image to ASCII art.

![example](https://github.com/guettafa/Image-to-ASCII/assets/81649039/bced37d2-3481-4f31-aec3-60103cb34b13)


## Why 
This program was mainly built to practice myself with the C programming language
and understand how image are interpreted.

## Library I used for this project 
[stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h)

## Requirements
- Make

```sh
# Debian
sudo apt install make

# Arch
sudo pacman -S make
```

## Usage
```sh
# To create a executable
make -B build

# You can execute the program located in the ./build/ directory like that 
./image2ascii -f theImagePath
```

## TODO
- Add colors
- Add size options


