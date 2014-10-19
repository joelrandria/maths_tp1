#ifndef GRAPHICS_IMAGEINFO_H
#define GRAPHICS_IMAGEINFO_H

namespace Graphics
{

class ImageInfo
{
private:
    
    int _width;
    int _height;
    
public:
    
    ImageInfo()
    {
        setWidth(0);
        setHeight(0);
    }
    
    int height() const { return _height; }
    void setHeight(int height);
    
    int width() const { return _width; }
    void setWidth(int width);
};

} // namespace Graphics

#endif // GRAPHICS_IMAGEINFO_H
