/*******************************************************************
Copyright (C) 2018 Oscar MARIE--TAILLEFER   <o5mariet@enib.fr>
Copyright (C) 2018 Nils JEGOU-GERGAUD       <n5jegoug@enib.fr>
Copyright (C) 2018 Nicols FRANCIS           <n4franci@enib.fr>
Copyright (C) 2018 Corentin LAMBERT         <c4lamber@enib.fr>

This file is part of Minifier.

Minifier is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minifier is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minifier.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************/

#ifndef IMAGECOMPRESS_IMAGECOMPRESSOR_HPP
#define IMAGECOMPRESS_IMAGECOMPRESSOR_HPP 1

#include <string>

namespace imageCompress{
	
class ImageCompressor{

public :
	
	ImageCompressor(std::string n, int h, int w, std::string ext, int q, int d, std::string f);
	ImageCompressor(ImageCompressor &&) = default;
    ImageCompressor(const ImageCompressor &) = default;
    ImageCompressor &operator=(ImageCompressor &&) = default;
    ImageCompressor &operator=(const ImageCompressor &) = default;
    ~ImageCompressor();

    // Load the picture
    void loadPicture();

    void YCrCb();
    void Echant422();
    void Decoup8x8();
    void Quantify();
    void ZigZag();
    void DCT();
    void Huffman();
    void resize();
    void createImageSource();
    void createImageCible();
    void toCible();
    void HuffmanInverse();
    void unquantify();
    void DCTInverse();

    // Converte function
    void convertPNG();

    // Accesseur

    inline int getHeight();
    inline int getWidth();
    inline int getQuality();
    inline int getDim();
    inline std::string getName();
    inline std::string getExtension();
    inline std::string getFile();

    // Mutateur

    inline void setHeight( int h);
    inline void setWidth( int w);
    inline void setQuality( int q);
    inline void setDim( int d);
    inline void setName( std::string n);
    inline void setExtension( std::string e);
    inline void setFile( std::string f );
    
private:
	
	std::string name_,extension_,file_;
	int height_,width_,quality_,dimension_
	
};

} // End imageCompress

#endif