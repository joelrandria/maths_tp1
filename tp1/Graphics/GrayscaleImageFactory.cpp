#include "GrayscaleImageFactory.h"
#include "GrayscaleImage.h"
#include "GrayscaleImageInfo.h"

#include <tr1/regex>

namespace Graphics
{

GrayscaleImage* GrayscaleImageFactory::loadFromFile(const std::string& filename)
{
    std::ifstream ifs;
    GrayscaleImage* pImage = 0;
    
    ifs.open(filename.c_str(), std::ifstream::in);
    pImage = loadImage(ifs);
    ifs.close();
    
    return (pImage);
}

void GrayscaleImageFactory::skipCommentLines(std::ifstream &ifs)
{
    std::string line;
    
    while (ifs.peek() == '#')
        std::getline(ifs, line);
}

GrayscaleImage* GrayscaleImageFactory::loadImage(std::ifstream& ifs)
{
    std::string magic;
    
    std::getline(ifs, magic);
    if ((magic == "P2") || (magic == "P5"))
        return (loadGrayscaleImage(ifs, magic));
    
    return (0);
}
void GrayscaleImageFactory::loadImageInfo(std::ifstream &ifs, GrayscaleImageInfo* pImageInfo)
{
    int width = 0;
    int height = 0;
    
    skipCommentLines(ifs);
    
    ifs >> width;
    ifs >> height;
    
    pImageInfo->setWidth(width);
    pImageInfo->setHeight(height);
}

GrayscaleImage* GrayscaleImageFactory::loadGrayscaleImage(std::ifstream &ifs, const std::string &magic)
{
    GrayscaleImage* pPgm = 0;
    GrayscaleImageInfo* pPgmInfo = 0;
        
    pPgmInfo = new GrayscaleImageInfo();
    loadGrayscaleImageInfo(ifs, pPgmInfo);
    
    if (pPgmInfo->channelByteSize() > 1)
        throw new std::invalid_argument("Seules les images 8 bits sont supportées");
    
    pPgm = new GrayscaleImage(pPgmInfo->width(), pPgmInfo->height(), pPgmInfo->channelByteSize());
    
    if (magic == "P2")
        loadAsciiGrayscaleImage(ifs, pPgm);
    else
        loadBinaryGrayscaleImage(ifs, pPgm);
    
    delete (pPgmInfo);
    
    return (pPgm);
}
void GrayscaleImageFactory::loadGrayscaleImageInfo(std::ifstream &ifs, GrayscaleImageInfo *pPgmInfo)
{
    int maxPixelValue = 0;
    
    loadImageInfo(ifs, pPgmInfo);
    
    ifs >> maxPixelValue;
    
    pPgmInfo->setChannelByteSize((maxPixelValue <= 255) ? 1 : 2);
}

void GrayscaleImageFactory::loadAsciiGrayscaleImage(std::ifstream &ifs, GrayscaleImage* pPgm)
{
    int value = 0;
    int imageColCount = pPgm->width();
    int imageRowCount = pPgm->height();
    
    for (int y = 0; y < imageRowCount; ++y)
    {
        for (int x = 0; x < imageColCount; ++x)
        {
            ifs >> value;
            pPgm->setIntensityAt(x, y, (unsigned short)value);
        }
    }
}

void GrayscaleImageFactory::loadBinaryGrayscaleImage(std::ifstream &ifs, GrayscaleImage* pPgm)
{
    char byte = 0;
    int imageColCount = pPgm->width();
    int imageRowCount = pPgm->height();
    
    for (int y = 0; y < imageRowCount; ++y)
    {
        for (int x = 0; x < imageColCount; ++x)
        {
            byte = 0;
            ifs.read(&byte, 1);
            pPgm->setIntensityAt(x, y, (unsigned char)byte);
        }
    }
}

}
