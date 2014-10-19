#ifndef GRAPHICS_CROPPINGMATCHINGFUNCTION_H
#define GRAPHICS_CROPPINGMATCHINGFUNCTION_H

#include "MatchingFunction.h"

namespace Graphics
{

class GrayscaleImage;
class GrayscaleHistogram;

class CroppingMatchingFunction : public MatchingFunction
{
public:

    CroppingMatchingFunction(const GrayscaleImage* image);

private:

    void getIntensityRange(const GrayscaleHistogram& histo, int &rangeStart, int &rangeEnd);
    void buildMatchingTable(int rangeStart, int rangeEnd);
};

} // namespace Graphics

#endif // GRAPHICS_CROPPINGMATCHINGFUNCTION_H
