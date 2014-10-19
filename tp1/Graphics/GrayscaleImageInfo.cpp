#include "GrayscaleImageInfo.h"

#include <stdexcept>

namespace Graphics
{

GrayscaleImageInfo::GrayscaleImageInfo()
{
    setWidth(0);
    setHeight(0);
    setChannelByteSize(1);
}

void GrayscaleImageInfo::setHeight(int height)
{
    if (height < 0)
        throw std::out_of_range("Hauteur invalide: " + height);
    _height = height;
}

void GrayscaleImageInfo::setWidth(int width)
{
    if (width < 0)
        throw std::out_of_range("Largeur invalide: " + width);
    _width = width;
}

void GrayscaleImageInfo::setChannelByteSize(int pixelByteSize)
{
    assertValidChannelByteSize(pixelByteSize);
    _channelByteSize = pixelByteSize;
}
void GrayscaleImageInfo::assertValidChannelByteSize(int pixelByteSize) const
{
    if (pixelByteSize < 1)
        throw std::out_of_range("Valeur de taille de pixel invalide: " + pixelByteSize);
}

}
