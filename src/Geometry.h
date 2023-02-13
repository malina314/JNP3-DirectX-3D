#ifndef DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H
#define DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H


#include "DXApp.h"

using Vertex = DXApp::Vertex;

#define NF {0.0f, 0.0f, -1.0f}
#define NB {0.0f, 0.0f, 1.0f}
#define NL {1.0f, 0.0f, 0.0f}
#define NR {-1.0f, 0.0f, 0.0f}
#define NU {0.0f, -1.0f, 0.0f}
#define ND {0.0f, 1.0f, 0.0f}

#define INSIDE \
/* first room */ \
/* front */ \
/* red */ \
{{-8.0f,  -3.0f, 8.0f},  NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  3.0f, 8.0f},   NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  -3.0f, 8.0f},  NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
/* curved normals doesn't work as I expected */               \
/*{{-8.0f,  -3.0f, 8.0f},  {-1.0f, -1.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  3.0f, 8.0f},   {1.0f, 1.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  -3.0f, 8.0f},  {1.0f, -1.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},*/\
\
{{-1.0f,  -3.0f, 8.0f},  NF,  {0.7f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  3.0f, 8.0f},    NF,  {0.7f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  -3.0f, 8.0f},   NF,  {0.7f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{1.0f,  -3.0f, 8.0f},   NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f,  3.0f, 8.0f},    NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f,  -3.0f, 8.0f},   NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
/* blue */ \
{{-1.0f,  3.0f, 8.0f},   NF,  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f,  -3.0f, 8.0f},  NF,  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f,  3.0f, 8.0f},   NF,  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{1.0f,  3.0f, 8.0f},    NF,  {0.0f, 0.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  -3.0f, 8.0f},  NF,  {0.0f, 0.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  3.0f, 8.0f},   NF,  {0.0f, 0.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f,  3.0f, 8.0f},    NF,  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  -3.0f, 8.0f},   NF,  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  3.0f, 8.0f},    NF,  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
/* right */ \
/* green */ \
{{8.0f,  -3.0f, 8.0f},   NR,  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, 1.0f},    NR,  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, 1.0f},   NR,  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f,  1.0f, 1.0f},    NR,  {0.0f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, -1.0f},   NR,  {0.0f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  1.0f, -1.0f},   NR,  {0.0f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f,  -3.0f, -1.0f},  NR,  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, -8.0f},   NR,  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, -8.0f},  NR,  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
/* yellow */               \
{{8.0f,  -3.0f, 8.0f},   NR,  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, 8.0f},    NR,  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, 1.0f},    NR,  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{8.0f,  1.0f, 1.0f},    NR,  {0.7f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, 1.0f},    NR,  {0.7f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, -1.0f},   NR,  {0.7f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{8.0f,  -3.0f, -1.0f},  NR,  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, -1.0f},   NR,  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, -8.0f},   NR,  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},  \
               \
/* back */ \
/* pink */ \
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.7f, 0.0f, 7.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
/* cyan */ \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{1.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f,  3.0f, -8.0f},  {0.0f, 0.0f, 1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
/* left */ \
/* light-cyan */ \
{{-8.0f,  3.0f, 1.0f},    NL,  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, 8.0f},   NL,  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, 1.0f},   NL,  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f,  3.0f, -1.0f},   NL,  {0.3f, 0.7f, 0.6f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, 1.0f},   NL,  {0.3f, 0.7f, 0.6f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, -1.0f},  NL,  {0.3f, 0.7f, 0.6f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f,  3.0f, -8.0f},   NL,  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, -1.0f},  NL,  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, -8.0f},  NL,  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* reddish */               \
{{-8.0f,  3.0f, 8.0f},    NL,  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, 8.0f},   NL,  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  3.0f, 1.0f},    NL,  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{-8.0f,  3.0f, 1.0f},    NL,  {0.7f, 0.2f, 0.35f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, 1.0f},   NL,  {0.7f, 0.2f, 0.35f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  3.0f, -1.0f},   NL,  {0.7f, 0.2f, 0.35f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{-8.0f,  3.0f, -1.0f},   NL,  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, -1.0f},  NL,  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  3.0f, -8.0f},   NL,  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }},\
/* floor */ \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  -3.0f, -8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, 8.0f},  {0.0f, 1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* ceiling */ \
{{-8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, -8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  3.0f, 8.0f},  {0.0f, -1.0f, 0.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* second room */ \
/* front */ \
/* red */ \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{-1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
/* blue */ \
{{-1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
/* right */ \
/* green */ \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
/* yellow */               \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.0f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},  \
               \
/* back */ \
/* pink */ \
{{-1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 7.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 7.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.0f, 7.0f, 1.0f},  { 0.5f, 0.0f }},\
\
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
/* cyan */ \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{1.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{1.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.0f, 1.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
/* left */ \
/* light-cyan */ \
{{-8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.3f, 0.7f, 0.6f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.3f, 0.7f, 0.6f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.3f, 0.7f, 0.6f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.5f, 1.0f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* reddish */               \
{{-8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{-8.0f + 27.0f,  3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.2f, 0.35f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.2f, 0.35f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.2f, 0.35f, 1.0f},  { 0.5f, 0.0f }},  \
               \
{{-8.0f + 27.0f,  3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.3f, 0.4f, 1.0f},  { 0.5f, 0.0f }},\
/* floor */ \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* ceiling */ \
{{-8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, -8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f + 27.0f,  3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }},  \
/* corridor */ \
/* floor */ \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f + 27.0f, -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f, -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* ceiling */ \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f, 1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f, 1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* right */ \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{-8.0f + 27.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  1.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, -1.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.7f, 0.7f, 1.0f},  { 0.5f, 0.0f }}, \
/* left */ \
{{8.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
               \
{{8.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  1.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{-8.0f + 27.0f,  -3.0f, 1.0f},  {0.0f, 0.0f, -1.0f},  {0.7f, 0.7f, 1.0f, 1.0f},  { 0.5f, 0.0f }}, \


#define TRIANGLE \
/* Front face */ \
{{0.0f,  0.25f,  0.0f},    {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }}, \
{{0.25f,   -0.25f,  0.0f}, {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 1.0f, 1.0f }},\
{{-0.25f, -0.25f,  0.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.0f, 1.0f }}, \
/* first room */ \
/* front */ \
/* red */ \
{{-8.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.5f, 0.0f }},\
{{-1.0f,  3.0f, 8.0f},   {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 1.0f, 1.0f }},\
{{-1.0f,  -3.0f, 8.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 0.0f, 1.0f }},\
                 \
{{0.0f - 0.5f,  1.0f, 0.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 1.0f, 1.0f},  { 0.5f, 0.0f }},\
{{0.2f - 0.5f,  1.0f,  0.0f},   {0.0f, 0.0f, -1.0f},  {1.0f, 0.0f, 0.0f, 1.0f},  { 1.0f, 1.0f }},\
{{0.0f - 0.5f,  -1.0f, 0.0f},  {0.0f, 0.0f, -1.0f},  {1.0f, 1.0f, 0.0f, 1.0f},  { 0.0f, 1.0f }},\




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

#include <vector>

class Geometry {
    std::vector<Vertex> vertices;

    void add_rect_xy(float x, float y, float z, float w, float h,
                     DirectX::XMFLOAT3 normal,
                     float tex_x, float tex_y, float tex_w, float tex_h) {
        vertices.push_back({{x, y, z}, normal, {}, {tex_x, tex_y}});
        vertices.push_back({{x + w, y + h, z}, normal, {}, {tex_x + tex_w, tex_y - tex_h}});
        vertices.push_back({{x + w, y, z}, normal, {}, {tex_x + tex_w, tex_y}});

        vertices.push_back({{x, y + h, z}, normal, {}, {tex_x, tex_y - tex_h}});
        vertices.push_back({{x + w, y + h, z}, normal, {}, {tex_x + tex_w, tex_y - tex_h}});
        vertices.push_back({{x, y, z}, normal, {}, {tex_x, tex_y}});
    }

public:
    Geometry() {
        int steps_vertical = 25;
        int steps_horizontal = 50;
        float w = 0.2f;
        float h = 0.2f;
        float tex_w = 1.0f / (float) steps_horizontal;
        float tex_h = 1.0f / (float) steps_vertical;

        for (int i = 0; i < steps_vertical; ++i) {
            for (int j = 0; j < steps_horizontal; ++j) {
                add_rect_xy(-8.0f + (float) j * w, -3.0f + (float) i * h, 8.0f, w, h,
                            {0.0f, 0.0f, -1.0f},
                            tex_w * (float) j, 1.0f - tex_h * (float) i, tex_w, tex_h);
            }
        }

//        vertices.push_back({{-8.0f,  -3.0f, 7.0f},  NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { -0.5f, 1.5f }}); // ld
//        vertices.push_back({{-1.0f,  3.0f, 7.0f},   NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 1.5f, -0.5f }}); // pg
//        vertices.push_back({{-1.0f,  -3.0f, 7.0f},  NF,  {1.0f, 0.0f, 0.0f, 1.0f},  { 1.5f, 1.5f }}); // pd
    }

    Vertex *GetVertices() {
        return vertices.data();
    }

    int GetVerticesCount() {
        return vertices.size();
    }

    int GetVerticesSize() {
        return GetVerticesCount() * sizeof(Vertex);
    }
};

#undef NF
#undef NB
#undef NL
#undef NR
#undef NU
#undef ND
#undef INSIDE


#endif //DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H
