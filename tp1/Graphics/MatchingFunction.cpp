#include "MatchingFunction.h"
#include "GrayscaleImage.h"
#include "GrayscaleCumulativeHistogram.h"
#include "Graphics.h"

#include <fstream>

namespace Graphics
{

MatchingFunction::MatchingFunction()
{
    reset(COLOR_CHANNEL_DEPTH);
}
MatchingFunction::MatchingFunction(const std::string &path)
{
    int targetValue;
    int originalValue;
    std::ifstream ifs;

    reset(COLOR_CHANNEL_DEPTH);

    ifs.open(path.c_str(), std::ifstream::in);

    while (!ifs.eof())
    {
        ifs >> originalValue;
        ifs >> targetValue;

        _intensityMatchings[originalValue] = targetValue;
    }

    ifs.close();
}
MatchingFunction::MatchingFunction(const GrayscaleHistogram &sourceHisto, const GrayscaleHistogram &targetHisto)
{
    reset(COLOR_CHANNEL_DEPTH);

    int sourceHistoSize = sourceHisto.intensityProbabilities().size();
    int targetHistoSize = targetHisto.intensityProbabilities().size();

    const std::vector<double> sourceCHisto = GrayscaleCumulativeHistogram(sourceHisto).intensityCumulativeProbabilities();
    const std::vector<double> targetCHisto = GrayscaleCumulativeHistogram(targetHisto).intensityCumulativeProbabilities();

    int x = 0;
    int y = 0;
    while ((y < targetHistoSize) && (x < sourceHistoSize))
    {
        while ((x < sourceHistoSize) && (sourceCHisto[x] < targetCHisto[y]))
        {
            _intensityMatchings[x] = y;
            ++x;
        }
        ++y;
    }
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

void MatchingFunction::reset(int size)
{
    _intensityMatchings.resize(size);

    for (int i = 0; i < size; ++i)
        _intensityMatchings[i] = 0;
}

}
