#include "GrayscaleSquaredRootHistogram.h"

#include <cmath>

namespace Graphics {

GrayscaleSquaredRootHistogram::GrayscaleSquaredRootHistogram()
    :GrayscaleHistogram()
{
    double intensityValueCount = _intensityProbabilities.size();
    double maxIntensityValue = intensityValueCount - 1;
    double factor = 3.0f / (2.0f * maxIntensityValue * sqrt(maxIntensityValue));

    for (int i = 0; i < intensityValueCount; ++i)
        _intensityProbabilities[i] = sqrt(i) * factor;
}

} // namespace Graphics
