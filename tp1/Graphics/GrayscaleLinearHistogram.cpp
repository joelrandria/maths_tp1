#include "GrayscaleLinearHistogram.h"

#include <cmath>

namespace Graphics {

GrayscaleLinearHistogram::GrayscaleLinearHistogram()
    :GrayscaleHistogram()
{
    double intensityValueCount = _intensityProbabilities.size();
    double factor = 2.0f / pow(intensityValueCount - 1, 2);

    for (int i = 0; i < intensityValueCount; ++i)
        _intensityProbabilities[i] = i * factor;
}

} // namespace Graphics
