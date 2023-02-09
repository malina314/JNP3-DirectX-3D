#ifndef DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H
#define DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H


#include "DXApp.h"

using Vertex = DXApp::Vertex;

#define CUBE \
// Front face \
{{-1.0f, 1.0f,-1.0f},   {1.0f,1.0f,0.5f,1.0f}}, \
{{1.0f, 1.0f,-1.0f},	{1.0f,1.0f,0.5f,1.0f}},\
{{-1.0f,-1.0f,-1.0f},	{0.5f,0.5f,0.0f,1.0f}},\
\
{{1.0f, 1.0f,-1.0f},  	{1.0f,1.0f,0.5f,1.0f}},\
{{1.0f,-1.0f,-1.0f},	{0.5f,0.5f,0.0f,1.0f}},\
{{-1.0f,-1.0f,-1.0f},	{0.5f,0.5f,0.0f,1.0f}},\
\
// Left side\
{{1.0f, 1.0f,-1.0f},  	{1.0f,0.5f,0.0f,1.0f}},\
{{1.0f, 1.0f, 1.0f},	{1.0f,0.5f,0.0f,1.0f}},\
{{1.0f,-1.0f,-1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
{{1.0f, 1.0f, 1.0f},  	{1.0f,0.5f,0.0f,1.0f}},\
{{1.0f,-1.0f, 1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
{{1.0f,-1.0f,-1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
// Right side\
{{-1.0f, 1.0f, 1.0f},   {1.0f,0.5f,0.0f,1.0f}},\
{{-1.0f, 1.0f,-1.0f},	{1.0f,0.5f,0.0f,1.0f}},\
{{-1.0f,-1.0f, 1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
{{-1.0f, 1.0f,-1.0f},  	{1.0f,0.5f,0.0f,1.0f}},\
{{-1.0f,-1.0f,-1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
{{-1.0f,-1.0f, 1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
// Back face\
{{1.0f, 1.0f, 1.0f},   {1.0f,1.0f,0.5f,1.0f}},\
{{-1.0f, 1.0f, 1.0f},	{1.0f,1.0f,0.5f,1.0f}},\
{{1.0f,-1.0f, 1.0f},	{0.5f,0.5f,0.0f,1.0f}},\
\
{{-1.0f, 1.0f, 1.0f},  	{1.0f,1.0f,0.5f,1.0f}},\
{{-1.0f,-1.0f, 1.0f},	{0.5f,0.5f,0.0f,1.0f}},\
{{1.0f,-1.0f, 1.0f},	{0.5f,0.5f,0.0f,1.0f}},\
\
// Top face\
{{-1.0f, 1.0f,-1.0f},   {1.0f,0.5f,0.0f,1.0f}},\
{{1.0f, 1.0f,-1.0f},	{1.0f,0.5f,0.0f,1.0f}},\
{{-1.0f, 1.0f, 1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
{{1.0f, 1.0f,-1.0f},  	{1.0f,0.5f,0.0f,1.0f}},\
{{1.0f, 1.0f, 1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
{{-1.0f, 1.0f, 1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
// Bottom face\
{{-1.0f,-1.0f, 1.0f},   {1.0f,0.5f,0.0f,1.0f}},\
{{1.0f,-1.0f, 1.0f},	{1.0f,0.5f,0.0f,1.0f}},\
{{-1.0f,-1.0f,-1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
\
{{1.0f,-1.0f, 1.0f},  	{1.0f,0.5f,0.0f,1.0f}},\
{{1.0f,-1.0f,-1.0f},	{0.5f,0.0f,0.0f,1.0f}},\
{{-1.0f,-1.0f,-1.0f},	{0.5f,0.0f,0.0f,1.0f}},

#define TETRAHEDRON \
/* Back inside */\
{{0.0f,  0.3f,  0.0f},   {0.0f, 0.0f, -1.0f},  {0.4f, 0.1f, 0.1f, 1.0f}},\
{{0.3f,  -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.4f, 0.1f, 0.1f, 1.0f}},\
{{-0.3f, -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.4f, 0.1f, 0.1f, 1.0f}},\
\
/* Bottom inside */ \
{{0.0f,  -0.3f, -0.5f},  {0.0f, 0.0f, -1.0f},  {0.1f, 0.4f, 0.1f, 1.0f}},\
{{-0.3f, -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.1f, 0.4f, 0.1f, 1.0f}},\
{{0.3f,  -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.1f, 0.4f, 0.1f, 1.0f}},\
\
/* Right inside */ \
{{0.0f,  -0.3f, -0.5f},  {0.0f, 0.0f, -1.0f},  {0.1f, 0.1f, 0.4f, 1.0f}},\
{{0.3f,  -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.1f, 0.1f, 0.4f, 1.0f}},\
{{0.0f,  0.3f,  0.0f},   {0.0f, 0.0f, -1.0f},  {0.1f, 0.1f, 0.4f, 1.0f}},\
\
/* Left inside */ \
{{0.0f,  -0.3f, -0.5f},  {0.0f, 0.0f, -1.0f},  {0.4f, 0.4f, 0.1f, 1.0f}},\
{{0.0f,  0.3f,  0.0f},   {0.0f, 0.0f, -1.0f},  {0.4f, 0.4f, 0.1f, 1.0f}},\
{{-0.3f, -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.4f, 0.4f, 0.1f, 1.0f}},\
\
\
/* Back */ \
{{0.0f,  0.3f,  0.0f},   {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},\
{{-0.3f, -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{0.3f,  -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}},\
\
/* Bottom */ \
{{0.0f,  -0.3f, -0.5f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{0.3f,  -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}},\
{{-0.3f, -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
\
/* Right */ \
{{0.0f,  -0.3f, -0.5f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{0.0f,  0.3f,  0.0f},   {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},\
{{0.3f,  -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}},\
\
/* Left */ \
{{0.0f,  -0.3f, -0.5f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-0.3f, -0.3f, 0.5f},   {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{0.0f,  0.3f,  0.0f},   {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},

#define INSIDE \
/* first room */ \
/* front */ \
/* red */ \
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
{{1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
{{1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
\
{{1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}}, \
/* blue */ \
{{-1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}}, \
               \
{{1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}},\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}},\
{{-1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}}, \
               \
{{8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}}, \
               \
/* right */ \
/* green */ \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
               \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
               \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
/* yellow */               \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},  \
               \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}},  \
               \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},  \
               \
/* back */ \
/* pink */ \
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
\
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}}, \
/* cyan */ \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{-8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}}, \
               \
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}},\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}},\
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}}, \
               \
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}}, \
               \
/* left */ \
/* light-cyan */ \
{{-8.0f,  3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, 8.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
               \
{{-8.0f,  3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
{{-8.0f,  -3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
{{-8.0f,  -3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
               \
{{-8.0f,  3.0f, -8.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, -8.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
/* reddish */               \
{{-8.0f,  3.0f, 8.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  -3.0f, 8.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}},  \
               \
{{-8.0f,  3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.7f, 0.2f, 0.35f, 1.0f}}, \
{{-8.0f,  -3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.7f, 0.2f, 0.35f, 1.0f}}, \
{{-8.0f,  3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.7f, 0.2f, 0.35f, 1.0f}},  \
               \
{{-8.0f,  3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  -3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  3.0f, -8.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}},\
/* floor */ \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
/* ceiling */ \
{{-8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{-8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
/* second room */ \
/* front */ \
/* red */ \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
\
{{-1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
{{1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
{{1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
\
{{1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}}, \
/* blue */ \
{{-1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}}, \
               \
{{1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}},\
{{-1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}},\
{{-1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}}, \
               \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}}, \
               \
/* right */ \
/* green */ \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
               \
{{8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
               \
{{8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
/* yellow */               \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},  \
               \
{{8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}},  \
               \
{{8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},  \
               \
/* back */ \
/* pink */ \
{{-1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{-1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
\
{{1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
{{-1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
{{1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
\
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}}, \
/* cyan */ \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{-1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}}, \
               \
{{-1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}},\
{{1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}},\
{{-1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}}, \
               \
{{1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}}, \
               \
/* left */ \
/* light-cyan */ \
{{-8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
               \
{{-8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
{{-8.0f + 27.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
               \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
/* reddish */               \
{{-8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f}},  \
               \
{{-8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.2f, 0.35f, 1.0f}}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.2f, 0.35f, 1.0f}}, \
{{-8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.2f, 0.35f, 1.0f}},  \
               \
{{-8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f}},\
/* floor */ \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
/* ceiling */ \
{{-8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}},  \
/* corridor */ \
/* floor */ \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{-8.0f + 27.0f, -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f, -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
/* ceiling */ \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f, 1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f, 1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
/* right */ \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f}}, \
               \
{{-8.0f + 27.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f}}, \
/* left */ \
{{8.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f}}, \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f}}, \
               \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f}}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f}}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f}}, \


#define TRIANGLE \
/* Front face */ \
{{0.0f,  0.25f,  0.0f},    {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{0.25f,   -0.25f,  0.0f}, {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 1.0f, 1.0f }},\
{{-0.25f, -0.25f,  0.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.0f, 1.0f }}, \


#define INSIDE2 \
/* first room */ \
/* front */ \
/* red */ \
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
{{1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
{{1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f}},\
\
{{1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}},\
{{8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f}}, \
/* blue */ \
{{-1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}}, \
               \
{{1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}},\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}},\
{{-1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f}}, \
               \
{{8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f}}, \
               \
/* right */ \
/* green */ \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
               \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f}}, \
               \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f}}, \
/* yellow */               \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},  \
               \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f}},  \
               \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f}},  \
               \
/* back */ \
/* pink */ \
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f}},\
\
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}},\
{{8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f}}, \
/* cyan */ \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{-8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}}, \
               \
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}},\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}},\
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f}}, \
               \
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}},\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f}}, \
               \
/* left */ \
/* light-cyan */ \
{{-8.0f,  3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, 8.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
               \
{{-8.0f,  3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
{{-8.0f,  -3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
{{-8.0f,  -3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.3f, 0.7f, 0.6f, 1.0f}}, \
               \
{{-8.0f,  3.0f, -8.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, -8.0f},  {1.0f, 0.0f, 0.0f},  {0.5f, 1.0f, 0.7f, 1.0f}}, \
/* reddish */               \
{{-8.0f,  3.0f, 8.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  -3.0f, 8.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}},  \
               \
{{-8.0f,  3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.7f, 0.2f, 0.35f, 1.0f}}, \
{{-8.0f,  -3.0f, 1.0f},  {1.0f, 0.0f, 0.0f},  {0.7f, 0.2f, 0.35f, 1.0f}}, \
{{-8.0f,  3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {0.7f, 0.2f, 0.35f, 1.0f}},  \
               \
{{-8.0f,  3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  -3.0f, -1.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}}, \
{{-8.0f,  3.0f, -8.0f},  {1.0f, 0.0f, 0.0f},  {1.0f, 0.3f, 0.4f, 1.0f}},\
/* floor */ \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
/* ceiling */ \
{{-8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{-8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
               \
{{-8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f}}, \

class Geometry {
public:
    static int GetVerticesCount() {
        return sizeof(vertices) / sizeof(Vertex);
    }

    static int GetVerticesSize() {
        return sizeof(vertices);
    }

    static constexpr Vertex vertices[] =
            {
//                    TETRAHEDRON
//                    INSIDE
                    TRIANGLE
            };
};


#endif //DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H
