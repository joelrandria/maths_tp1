#include "CroppingMatchingFunction.h"
#include "GrayscaleHistogram.h"

namespace Graphics {

CroppingMatchingFunction::CroppingMatchingFunction(const GrayscaleImage *image)
    :MatchingFunction()
{
    int range_start;
    int range_end;
    GrayscaleHistogram histo(*image);

    getIntensityRange(histo, range_start, range_end);
    buildMatchingTable(range_start, range_end);
}

void CroppingMatchingFunction::getIntensityRange(const GrayscaleHistogram& histo, int &rangeStart, int &rangeEnd)
{
    int i;
    int intensity_value_count;
    std::vector<double> intensity_probabilities;

    intensity_probabilities = histo.intensityProbabilities();
    intensity_value_count = intensity_probabilities.size();

    rangeStart = 0;
    rangeEnd = 255;

    for (i = 0; i < intensity_value_count; ++i)
    {
        if (intensity_probabilities[i] != 0)
        {
            rangeStart = i;
            break;
        }
    }
    for (i = intensity_value_count - 1; i >= 0; --i)
    {
        if (intensity_probabilities[i] != 0)
        {
            rangeEnd = i;
            break;
        }
    }
}
void CroppingMatchingFunction::buildMatchingTable(int rangeStart, int rangeEnd)
{
    int intensityTargetValue;

    for (int i = rangeStart; i <= rangeEnd; ++i)
    {
        intensityTargetValue = (255 * (i - rangeStart)) / (rangeEnd - rangeStart);
        _intensityMatchings[i] = intensityTargetValue;
    }
}

} // namespace Graphics
