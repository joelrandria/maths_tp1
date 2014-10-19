#include "GrayscaleImage.h"

#include <stdexcept>
#include <string>
#include <cmath>

namespace Graphics
{

GrayscaleImage::GrayscaleImage(int width, int height, int channelByteSize)
    :_pixels(0)
{
    initializeAttributes(width, height, channelByteSize);

    resetPixelMap();
}
GrayscaleImage::GrayscaleImage(const GrayscaleImage &other)
    :_pixels(0)
{
    initializeAttributes(other._width, other._height, other._channelByteSize);

    resetPixelMap(other._pixels);
}
GrayscaleImage::~GrayscaleImage()
{
    deletePixelMap();
}

void GrayscaleImage::initializeAttributes(int width, int height, int channelByteSize)
{
    assertValidSize(width, height);
    assertValidChannelSize(channelByteSize);

    _width = width;
    _height = height;
    _channelByteSize = channelByteSize;
}

void GrayscaleImage::deletePixelMap()
{
    if (_pixels != 0)
    {
        for (int x = 0; x < width(); ++x)
            delete (_pixels[x]);
        delete (_pixels);

        _pixels = 0;
    }
}
void GrayscaleImage::resetPixelMap(unsigned short** newPixels)
{
    int colCount = width();
    int rowCount = height();

    deletePixelMap();

    _pixels = new unsigned short*[colCount]();
    for (int x = 0; x < colCount; ++x)
    {
        _pixels[x] = new unsigned short[rowCount];
        for (int y = 0; y < rowCount; ++y)
            _pixels[x][y] = newPixels ? newPixels[x][y] : 0;
    }
}

unsigned short GrayscaleImage::getIntensityAt(int x, int y) const
{
    assertValidLocation(x, y);
    return (_pixels[x][y]);
}
void GrayscaleImage::setIntensityAt(int x, int y, unsigned short value)
{
    assertValidLocation(x, y);
    assertValidChannelValue(value);
    _pixels[x][y] = value;
}

void GrayscaleImage::assertValidSize(int width, int height) const
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
void GrayscaleImage::assertValidLocation(int x, int y) const
{
    if ((x < 0) || (x >= width()) || (y < 0) || (y >= height()))
    {
        std::string errorMessage = "Position d'image invalide: (";
        errorMessage += x;
        errorMessage += ", ";
        errorMessage += y;
        errorMessage += ")";
        
        throw std::out_of_range(errorMessage);
    }
}
void GrayscaleImage::assertValidChannelSize(int channelByteSize) const
{
    if ((channelByteSize < 0) || (channelByteSize > 2))
    {
        std::string errorMessage = "Profondeur de niveaux de gris invalide: ";
        errorMessage += channelByteSize;

        throw std::out_of_range(errorMessage);
    }
}
void GrayscaleImage::assertValidChannelValue(unsigned short value) const
{
    if (value > (pow(2, 8 * _channelByteSize) - 1))
    {
        std::string errorMessage = "Valeur de niveau de gris invalide: ";
        errorMessage += value;
        errorMessage += " : profondeur courante = ";
        errorMessage += _channelByteSize;

        throw std::out_of_range(errorMessage);
    }
}

} // namespace Graphics
