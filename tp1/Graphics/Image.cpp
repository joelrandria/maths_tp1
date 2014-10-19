#include "Image.h"

#include <stdexcept>

namespace Graphics
{

Image::Image(int width, int height, int channelByteSize)
{
    assertValidSize(width, height);

    _width = width;
    _height = height;
    _channelByteSize = channelByteSize;
}
Image::Image(const Image &other)
{
    _width = other._width;
    _height = other._height;
    _channelByteSize = other._channelByteSize;
}
Image::~Image()
{
}

void Image::assertValidSize(int width, int height) const
{
    if ((width < 0) || (height < 0))
    {
        std::string errorMessage = "Dimensions d'image invalide: ";
        errorMessage += width;
        errorMessage += "x";
        errorMessage += height;

        throw new std::out_of_range(errorMessage);
    }
}

}
