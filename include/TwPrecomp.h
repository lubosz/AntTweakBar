//  ---------------------------------------------------------------------------
//
//  @file       TwPrecomp.h
//  @brief      Precompiled header
//  @author     Philippe Decaudin - http://www.antisphere.com
//  @license    This file is part of the AntTweakBar library.
//              For conditions of distribution and use, see License.txt
//
//  notes:      Private header
//              TAB=4
//
//  ---------------------------------------------------------------------------


#pragma once

#define GL_GLEXT_PROTOTYPES 1


#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>

#   define ANT_UNIX
#   include <X11/cursorfont.h>
#   define GLX_GLXEXT_LEGACY
#   include <GL/glx.h>
#   include <X11/Xatom.h>
#   include <unistd.h>

#	include <GL/gl.h>

#define  ANT_OGL_HEADER_INCLUDED
