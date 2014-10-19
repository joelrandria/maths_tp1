#include "NegatingMatchingFunction.h"

namespace Graphics {

NegatingMatchingFunction::NegatingMatchingFunction()
    :MatchingFunction()
{
    int intensityMatchingCount = _intensityMatchings.size();

    for (int i = 0; i < intensityMatchingCount; ++i)
        _intensityMatchings[i] = (intensityMatchingCount - 1) - i;
}

} // namespace Graphics
