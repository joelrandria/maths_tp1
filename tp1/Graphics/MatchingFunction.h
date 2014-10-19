#ifndef MATCHINGFUNCTION_H
#define MATCHINGFUNCTION_H

#include <vector>
#include <string>

#define INTENSITY_VALUE_COUNT   256

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

    GrayscaleImage* apply(GrayscaleImage* image);
};

}

#endif // MATCHINGFUNCTION_H
