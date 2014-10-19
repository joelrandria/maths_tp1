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

    valueCount =_pixelValueCount.size();
    ofs.open(path.c_str(),std::ofstream::out);

    for (int i = 0; i < valueCount; ++i)
        ofs << i << "\t" << _pixelValueCount[i] << std::endl;

    ofs.close();
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
        currentSum += sourceHistoValues[i];
        _pixelValueCount[i] = currentSum;
    }
}

} // namespace Graphics
