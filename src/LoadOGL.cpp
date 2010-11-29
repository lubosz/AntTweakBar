//  ---------------------------------------------------------------------------
//
//  @file       LoadOGL.cpp
//  @author     Philippe Decaudin - http://www.antisphere.com
//  @license    This file is part of the AntTweakBar library.
//              For conditions of distribution and use, see License.txt
//
//  note:       TAB=4
//
//  ---------------------------------------------------------------------------


#include "TwPrecomp.h"
#include "LoadOGL.h"


//  ---------------------------------------------------------------------------

#define ANT_NB_OGL_FUNC_MAX 512

struct COGLFuncRec
{
    const char *    m_Name;
    GL::PFNOpenGL * m_FuncPtr;
    COGLFuncRec() : m_Name(NULL), m_FuncPtr(NULL) {}
};
COGLFuncRec g_OGLFuncRec[ANT_NB_OGL_FUNC_MAX];
int g_NbOGLFunc = 0;
#if defined(ANT_WINDOWS)
HMODULE g_OGLModule = NULL;
#endif

//  ---------------------------------------------------------------------------


namespace GL { PFNGLGetProcAddress _glGetProcAddress = NULL; }

//  ---------------------------------------------------------------------------

#if defined(ANT_UNIX)
    
    int LoadOpenGL()
    {
        _glGetProcAddress = reinterpret_cast<GL::PFNGLGetProcAddress>(glXGetProcAddressARB);

        return 1; // "OpenGL library is statically linked"
    }
    
    int UnloadOpenGL()
    {
        return 1; // "OpenGL library is statically linked"
    }
    
#elif defined(ANT_OSX)

    #include <dlfcn.h>

    static void *gl_dyld = NULL;
    void *NSGLGetProcAddressNew(const GLubyte *name) 
    {
        void *proc=NULL;
        if (gl_dyld == NULL) 
        {
            gl_dyld = dlopen("OpenGL",RTLD_LAZY);
        }
        if (gl_dyld) 
        {
            NSString *sym = [[NSString alloc] initWithFormat: @"_%s",name];
            proc = dlsym(gl_dyld,[sym UTF8String]);
            [sym release];
        }
        return proc;
    }

    int LoadOpenGL() 
    {
        _glGetProcAddress = reinterpret_cast<GL::PFNGLGetProcAddress>(NSGLGetProcAddressNew);
        return 1;
    }

    int UnloadOpenGL() 
    {
       if (gl_dyld) 
       {
           dlclose(gl_dyld);
           gl_dyld = NULL;
       }
       return 1;
   }    
   
#endif // defined(ANT_UNIX)

//  ---------------------------------------------------------------------------
