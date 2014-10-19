#ifndef MATCHINGFUNCTION_H
#define MATCHINGFUNCTION_H

#include <vector>
#include <string>

namespace Graphics
{

class GrayscaleImage;

class MatchingFunction
{
private:

    std::vector<unsigned long> _valueMatchs;

public:

    MatchingFunction(const std::string &path);

    GrayscaleImage* apply(GrayscaleImage* image);
};

}

#endif // MATCHINGFUNCTION_H
