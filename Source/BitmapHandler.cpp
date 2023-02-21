#include "BitmapHandler.h"

BitmapHandler::BitmapHandler(GLenum texture, string filename) {
	this->texture = texture;
	this->filename = filename;
}

void BitmapHandler::loadBitmap() {
	int width = 0;
	int height = 0;
	int bitsPerImage = 0;
	stbi_set_flip_vertically_on_load(1);
	unsigned char* image = stbi_load(filename.c_str(), &width, &height, &bitsPerImage, 0);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);

	glTexParameterf(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(texture, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(texture, GL_TEXTURE_WRAP_T, GL_CLAMP);
}