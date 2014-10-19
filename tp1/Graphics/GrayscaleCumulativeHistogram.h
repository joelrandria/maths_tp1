#ifndef GRAPHICS_GRAYSCALECUMULATIVEHISTOGRAM_H
#define GRAPHICS_GRAYSCALECUMULATIVEHISTOGRAM_H

#include "GrayscaleHistogram.h"

#include <vector>
#include <string>

namespace Graphics
{

class GrayscaleCumulativeHistogram
{
private:

    std::vector<double> _intensityCumulativeProbabilities;

public:

    GrayscaleCumulativeHistogram(const GrayscaleHistogram& sourceHisto);

    void save(const std::string &path);

private:

    void reset(int size);
    void update(const GrayscaleHistogram& sourceHisto);

};

} // namespace Graphics

#endif // GRAPHICS_GRAYSCALECUMULATIVEHISTOGRAM_H
