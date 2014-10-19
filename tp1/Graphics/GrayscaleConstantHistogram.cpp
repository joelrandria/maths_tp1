#include "GrayscaleConstantHistogram.h"

namespace Graphics {

GrayscaleConstantHistogram::GrayscaleConstantHistogram()
    :GrayscaleHistogram()
{
    double intensityValueCount = _intensityProbabilities.size();
    double uniformIntensityProbability = 1.0f / intensityValueCount;

    for (int i = 0; i < intensityValueCount; ++i)
        _intensityProbabilities[i] = uniformIntensityProbability;
}

} // namespace Graphics
