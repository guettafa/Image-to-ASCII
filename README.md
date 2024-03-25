# Image to ASCII 
![Image-to-ASCII](https://socialify.git.ci/guettafa/Image-to-ASCII/image?language=1&owner=1&name=1&stargazers=1&theme=Light)
a simple program made with the C programming language to transform 
an image to ASCII art.

## Why 
This program was mainly built to practice myself with the C programming language
and understand how image are interpreted.

## Library I used for this project 
[stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h)

## WAIT
I am unable to guarantee that it is functional on either Windows or macOS. Regardless, I am confident that it works on Arch and Debian based distros.

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


