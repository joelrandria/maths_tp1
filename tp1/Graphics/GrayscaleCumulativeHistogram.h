#ifndef GRAPHICS_GRAYSCALECUMULATIVEHISTOGRAM_H
#define GRAPHICS_GRAYSCALECUMULATIVEHISTOGRAM_H

#include "GrayscaleHistogram.h"

#include <vector>

namespace Graphics
{

class GrayscaleCumulativeHistogram
{
private:

    std::vector<unsigned long> _pixelValueCount;

public:

    GrayscaleCumulativeHistogram(const GrayscaleHistogram& sourceHisto);

private:

    void reset(int size);
    void update(const GrayscaleHistogram& sourceHisto);

};

} // namespace Graphics

#endif // GRAPHICS_GRAYSCALECUMULATIVEHISTOGRAM_H
