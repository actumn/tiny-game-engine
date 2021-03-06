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
#include <tiny/draw/effects/lambert.h>

using namespace tiny;
using namespace tiny::draw::effects;

Lambert::Lambert()
{
    setLight(normalize(vec3(1.0f, 1.0f, 1.0f)));
}

Lambert::~Lambert()
{

}

std::string Lambert::getFragmentShaderCode() const
{
    return std::string(
"#version 150\n"
"\n"
"precision highp float;\n"
"\n"
"uniform sampler2D diffuseTexture;\n"
"uniform sampler2D worldNormalTexture;\n"
"\n"
"uniform vec2 inverseScreenSize;\n"
"uniform vec3 lightDirection;\n"
"\n"
"out vec4 colour;\n"
"\n"
"void main(void)\n"
"{\n"
"   vec2 tex = gl_FragCoord.xy*inverseScreenSize;\n"
"   vec4 diffuse = texture(diffuseTexture, tex);\n"
"   vec4 worldNormal = texture(worldNormalTexture, tex);\n"
"   \n"
"   colour = vec4(max(0.0f, dot(worldNormal.xyz, lightDirection))*diffuse.xyz, 1.0f);\n"
"}\n");
}

void Lambert::setLight(const vec3 &a_light)
{
    light = normalize(a_light);
    uniformMap.setVec3Uniform(light, "lightDirection");
}

