#pragma once

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include "loadTGA.h"
GLbyte *gltLoadTGA(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat);
