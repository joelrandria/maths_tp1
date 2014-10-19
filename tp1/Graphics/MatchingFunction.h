#ifndef MATCHINGFUNCTION_H
#define MATCHINGFUNCTION_H

#include "GrayscaleHistogram.h"

#include <vector>
#include <string>

namespace Graphics
{

class GrayscaleImage;

class MatchingFunction
{
protected:

    std::vector<unsigned long> _intensityMatchings;

public:

    MatchingFunction();
    MatchingFunction(const std::string &path);
    MatchingFunction(const GrayscaleHistogram& sourceHisto, const GrayscaleHistogram& targetHisto);

    GrayscaleImage* apply(GrayscaleImage* image);

private:

    void reset(int size);
};

}

#endif // MATCHINGFUNCTION_H
