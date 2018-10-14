#include "../lodepng/lodepng.h"

#include <iostream>

int main(void) {
	std::vector<unsigned char> pixels;
	unsigned width, height;

	unsigned error = lodepng::decode(pixels, width, height, "../res/pexels-photo.png");
	//if there's an error, display it
	if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	else std::cout << "image size: " << pixels.size() / 1024 << "K" << std::endl << "image dimmensions: width = " << width << ", height = " << height << std::endl
		<< "first pixel RGBA: " << std::endl
		<< "R: " << (int)pixels[0] << std::endl
		<< "G: " << (int)pixels[1] << std::endl
		<< "B: " << (int)pixels[2] << std::endl
		<< "A: " << (int)pixels[3] << std::endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...

	return 0;
}