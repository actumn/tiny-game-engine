/*
Copyright 2012, Bas Fagginger Auer.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <iostream>
#include <exception>
#include <list>

#include <cassert>

#include <tiny/math/vec.h>
#include <tiny/draw/screensquare.h>

namespace tiny
{

namespace draw
{

namespace effects
{

class ShowImage : public tiny::draw::ScreenFillingSquare
{
    public:
        ShowImage();
        ~ShowImage();
        
        template <typename TextureType>
        void setImageTexture(const TextureType &texture)
        {
            uniformMap.setTexture(texture, "imageTexture");
        }
        
        void setAspectRatio(const float &);
        void setAlpha(const float &);
        std::string getFragmentShaderCode() const;
};

}

}

}

