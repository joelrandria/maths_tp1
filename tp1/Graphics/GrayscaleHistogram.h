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

    std::vector<double> _intensityProbabilities;

public:

    GrayscaleHistogram(const GrayscaleImage& grayImg);
    GrayscaleHistogram(const std::string& filePath);

    const std::vector<double>& intensityProbabilities() const { return _intensityProbabilities; }

    void load(const std::string &path);
    void save(const std::string &path);

private:

    void reset(int size);
    void update(const GrayscaleImage& grayImg);
};

}

#endif // GRAYSCALEHISTOGRAM_H
