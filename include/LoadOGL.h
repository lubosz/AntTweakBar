//  ---------------------------------------------------------------------------
//
//  @file       LoadOGL.h
//  @brief      OpenGL declarations for dynamic loading
//  @author     Philippe Decaudin - http://www.antisphere.com
//  @license    This file is part of the AntTweakBar library.
//              For conditions of distribution and use, see License.txt
//
//  notes:      Private header
//              TAB=4
//
//  ---------------------------------------------------------------------------


#pragma once


#define ANT_GL_DECL(_Ret, _Fct, _Params) \
    extern "C" { typedef _Ret (APIENTRY* PFN##_Fct)_Params; } \
    namespace GL { extern PFN##_Fct _##_Fct; } \
    using GL::_##_Fct;


int LoadOpenGL();
int UnloadOpenGL();

namespace GL
{
    extern "C" { typedef void (APIENTRY* PFNOpenGL)(); }
    PFNOpenGL Record(const char *_FuncName, PFNOpenGL *_FuncPtr);

    extern "C" { typedef PFNOpenGL (APIENTRY *PFNGLGetProcAddress)(const char *); }
    extern PFNGLGetProcAddress _glGetProcAddress;
}
using GL::_glGetProcAddress;
