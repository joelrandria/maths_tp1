#ifndef GRAYSCALEIMAGEFACTORY_H
#define GRAYSCALEIMAGEFACTORY_H

#include <fstream>
#include <string>

namespace Graphics
{

class GrayscaleImage;
class GrayscaleImageInfo;

/**
 * @brief Prend en charge le chargement d'images en niveaux de gris.
 */
class GrayscaleImageFactory
{
public:
    
    static GrayscaleImage* loadFromFile(const std::string &filename);
    
private:
    
    static void skipCommentLines(std::ifstream &ifs);
    
    static GrayscaleImage* loadImage(std::ifstream &ifs);
    static void loadImageInfo(std::ifstream &ifs, GrayscaleImageInfo* pImageInfo);
    
    static GrayscaleImage* loadGrayscaleImage(std::ifstream &ifs, const std::string &magic);
    static void loadGrayscaleImageInfo(std::ifstream &ifs, GrayscaleImageInfo *pPgmInfo);
    static void loadAsciiGrayscaleImage(std::ifstream &ifs, GrayscaleImage *pPgm);
    static void loadBinaryGrayscaleImage(std::ifstream &ifs, GrayscaleImage *pPgm);
};

}

#endif // GRAYSCALEIMAGEFACTORY_H
