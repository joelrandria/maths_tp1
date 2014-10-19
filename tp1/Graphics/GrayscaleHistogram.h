#ifndef GRAYSCALEHISTOGRAM_H
#define GRAYSCALEHISTOGRAM_H

#include <vector>
#include <string>

namespace Graphics
{

class GrayscaleImage;

class GrayscaleHistogram
{
private:

    std::vector<unsigned long> _pixelValueCount;

public:

    GrayscaleHistogram(const GrayscaleImage& grayImg);
    GrayscaleHistogram(const std::string& filePath);

    const std::vector<unsigned long>& pixelValues() const { return _pixelValueCount; }

    void load(const std::string &path);
    void save(const std::string &path);

private:

    void reset(int size);
    void update(const GrayscaleImage& grayImg);
};

}

#endif // GRAYSCALEHISTOGRAM_H
