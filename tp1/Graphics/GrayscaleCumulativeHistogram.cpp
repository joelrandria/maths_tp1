#include "GrayscaleCumulativeHistogram.h"

#include <fstream>

namespace Graphics
{

GrayscaleCumulativeHistogram::GrayscaleCumulativeHistogram(const GrayscaleHistogram& sourceHisto)
{
    update(sourceHisto);
}

void GrayscaleCumulativeHistogram::save(const std::string &path)
{
    int valueCount;
    std::ofstream ofs;

    valueCount =_intensityCumulativeProbabilities.size();
    ofs.open(path.c_str(),std::ofstream::out);

    for (int i = 0; i < valueCount; ++i)
        ofs << i << "\t" << _intensityCumulativeProbabilities[i] << std::endl;

    ofs.close();
}

void GrayscaleCumulativeHistogram::reset(int size)
{
    _intensityCumulativeProbabilities.resize(size);

    for (int i = 0; i < size; ++i)
        _intensityCumulativeProbabilities[i] = 0;
}
void GrayscaleCumulativeHistogram::update(const GrayscaleHistogram &sourceHisto)
{
    int sourceHistoSize;
    double currentSum;
    std::vector<double> sourceHistoValues = sourceHisto.intensityProbabilities();

    currentSum = 0;
    sourceHistoSize = sourceHistoValues.size();

    reset(sourceHistoSize);

    for (int i = 0; i < sourceHistoSize; ++i)
    {
        currentSum += sourceHistoValues[i];
        _intensityCumulativeProbabilities[i] = currentSum;
    }
}

} // namespace Graphics
