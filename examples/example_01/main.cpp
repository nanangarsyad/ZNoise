#include <iostream>
#include "../common/CImg.h"
#include "../../include/Perlin2D.hpp"

using namespace std;
using namespace cimg_library;

// You need to add libgdi32.a in your IDE linker options

int main()
{
    CImg<unsigned char> image(512,512,1,3,0);

    // Perlin code here
    Perlin2D perlin2d;

    for(unsigned int x = 0 ; x < image.width() ; x++)
        for(unsigned int y = 0 ; y < image.height() ; y++)
        {
            perlin2d.Set(x,y);
            float value =  perlin2d.Get();

            unsigned int greyscale = static_cast<int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("perlin2d.bmp");
    return 0;
}