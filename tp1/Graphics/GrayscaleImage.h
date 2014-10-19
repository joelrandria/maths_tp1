#ifndef GRAPHICS_GRAYSCALEIMAGE_H
#define GRAPHICS_GRAYSCALEIMAGE_H

namespace Graphics
{

class GrayscaleImage
{
private:

    int _width;
    int _height;

    int _channelByteSize;

    unsigned short** _pixels;

public:

    GrayscaleImage(int width, int height, int channelByteSize);
    GrayscaleImage(const GrayscaleImage& other);
    virtual ~GrayscaleImage();

    int width() const { return (_width); }
    int height() const { return (_height); }
    int channelByteSize() const { return (_channelByteSize); }

    unsigned short getIntensityAt(int x, int y) const;
    void setIntensityAt(int x, int y, unsigned short value);

private:

    void initializeAttributes(int width, int height, int channelByteSize);

    void deletePixelMap();
    void resetPixelMap(unsigned short** newPixels = 0);

    void assertValidSize(int width, int height) const;
    void assertValidLocation(int x, int y) const;
    void assertValidChannelSize(int channelByteSize) const;
    void assertValidChannelValue(unsigned short value) const;
};

} // namespace Graphics

#endif // GRAPHICS_GRAYSCALEIMAGE_H
