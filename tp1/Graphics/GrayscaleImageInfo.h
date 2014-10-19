#ifndef GRAPHICS_GRAYSCALEIMAGEINFO_H
#define GRAPHICS_GRAYSCALEIMAGEINFO_H

namespace Graphics
{

class GrayscaleImageInfo
{
private:
    
    int _width;
    int _height;

    int _channelByteSize;
    
public:
    
    GrayscaleImageInfo();

    int height() const { return _height; }
    void setHeight(int height);

    int width() const { return _width; }
    void setWidth(int width);
    
    int channelByteSize() const { return (_channelByteSize); }
    void setChannelByteSize(int channelByteSize);
    
private:
    
    void assertValidChannelByteSize(int channelByteSize) const;
    
};


} // namespace Graphics

#endif // GRAPHICS_GRAYSCALEIMAGEINFO_H
