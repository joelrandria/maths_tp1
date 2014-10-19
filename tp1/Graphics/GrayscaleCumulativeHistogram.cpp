#include "GrayscaleCumulativeHistogram.h"

namespace Graphics
{

GrayscaleCumulativeHistogram::GrayscaleCumulativeHistogram(const GrayscaleHistogram& sourceHisto)
{
    update(sourceHisto);
}

void GrayscaleCumulativeHistogram::reset(int size)
{
    _pixelValueCount.resize(size);

    for (int i = 0; i < size; ++i)
        _pixelValueCount[i] = 0;
}
void GrayscaleCumulativeHistogram::update(const GrayscaleHistogram &sourceHisto)
{
    int sourceHistoSize;
    unsigned long currentSum;
    std::vector<unsigned long> sourceHistoValues = sourceHisto.pixelValues();

    currentSum = 0;
    sourceHistoSize = sourceHistoValues.size();

    reset(sourceHistoSize);

    for (int i = 0; i < sourceHistoSize; ++i)
    {
//        currentSum += sourceHistoValues[i];
//        _pixelValueCount[i] = currentSum;w0
    }
}

} // namespace Graphics
