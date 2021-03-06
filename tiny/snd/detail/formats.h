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

#include <exception>
#include <vector>

#include <cassert>

#include <AL/al.h>
#include <AL/alc.h>

namespace tiny
{

namespace snd
{

namespace detail
{

template<size_t T, typename S>
inline ALenum getOpenALBufferFormat() {return AL_FORMAT_MONO8;}

template<>
inline ALenum getOpenALBufferFormat<1, char>() {return AL_FORMAT_MONO8;}
template<>
inline ALenum getOpenALBufferFormat<2, char>() {return AL_FORMAT_STEREO8;}
template<>
inline ALenum getOpenALBufferFormat<1, short>() {return AL_FORMAT_MONO16;}
template<>
inline ALenum getOpenALBufferFormat<2, short>() {return AL_FORMAT_STEREO16;}

}

}

}

