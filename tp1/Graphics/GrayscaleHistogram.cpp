#include "GrayscaleHistogram.h"
#include "GrayscaleImage.h"

#include <cmath>
#include <fstream>

namespace Graphics
{

GrayscaleHistogram::GrayscaleHistogram(const GrayscaleImage& grayImg)
{
    update(grayImg);
}
GrayscaleHistogram::GrayscaleHistogram(const std::string &filePath)
{
    reset((int)pow(2, 8));
    load(filePath);
}

void GrayscaleHistogram::load(const std::string &path)
{
    int count;
    int intensity;
    std::ifstream ifs;

    ifs.open(path.c_str(), std::ifstream::in);

    while (!ifs.eof())
    {
        ifs >> intensity;
        ifs >> count;

        _intensityProbabilities[intensity] = count;
    }

    ifs.close();
}
void GrayscaleHistogram::save(const std::string &path)
{
    int valueCount;
    std::ofstream ofs;

    valueCount =_intensityProbabilities.size();
    ofs.open(path.c_str(),std::ofstream::out);

    for (int i = 0; i < valueCount; ++i)
        ofs << i << "\t" << _intensityProbabilities[i] << std::endl;

    ofs.close();
}

void GrayscaleHistogram::reset(int size)
{
    _intensityProbabilities.resize(size);

    for (int i = 0; i < size; ++i)
        _intensityProbabilities[i] = 0;
}
void GrayscaleHistogram::update(const GrayscaleImage &grayImg)
{
    int width = grayImg.width();
    int height = grayImg.height();
    double pixelCount = width * height;
    int intensityCount = pow(2, grayImg.channelByteSize() * 8);

    reset(intensityCount);

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            ++_intensityProbabilities[grayImg.getIntensityAt(x, y)];

    for (int i = 0; i < intensityCount; ++i)
        _intensityProbabilities[i] = _intensityProbabilities[i] / pixelCount;
}

}
