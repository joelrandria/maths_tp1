#ifndef IMAGE_H
#define IMAGE_H

namespace Graphics
{

class Image
{
private:

    int _width;
    int _height;

    int _channelByteSize;

public:

    Image(int width, int height, int channelByteSize);
    Image(const Image& other);
    virtual ~Image();

    int width() const { return (_width); }
    int height() const { return (_height); }
    int channelByteSize() const { return (_channelByteSize); }

    virtual Color getColorAt(int x, int y) const = 0;

private:

    void assertValidSize(int width, int height) const;
};

}

#endif // IMAGEBASE_H
