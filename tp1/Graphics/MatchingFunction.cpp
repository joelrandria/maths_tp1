#include "MatchingFunction.h"
#include "GrayscaleImage.h"

#include <fstream>

namespace Graphics
{

MatchingFunction::MatchingFunction()
{
    _intensityMatchings.resize(INTENSITY_VALUE_COUNT);

    for (int i = 0; i < INTENSITY_VALUE_COUNT; ++i)
        _intensityMatchings[i] = 0;
}
MatchingFunction::MatchingFunction(const std::string &path)
{
    int targetValue;
    int originalValue;
    std::ifstream ifs;

    _intensityMatchings.resize(INTENSITY_VALUE_COUNT);

    ifs.open(path.c_str(), std::ifstream::in);

    while (!ifs.eof())
    {
        ifs >> originalValue;
        ifs >> targetValue;

        _intensityMatchings[originalValue] = targetValue;
    }

    ifs.close();
}

GrayscaleImage* MatchingFunction::apply(GrayscaleImage* image)
{
    int width = image->width();
    int height = image->height();
    GrayscaleImage* resultImage = new GrayscaleImage(*image);

    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
            resultImage->setIntensityAt(x, y, _intensityMatchings[resultImage->getIntensityAt(x, y)]);

    return (resultImage);
}

}
