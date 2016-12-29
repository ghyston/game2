//
//  TextureLoader.h
//  Game2
//
//  Created by Stepanov Ilia on 11/01/15.
//  Copyright (c) 2015 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__TextureLoader__
#define __Game2__TextureLoader__

#include "GlInclude.h"
#include "../Common/GlobalMacros.h"

#include <cstdio>
#include <cstdlib>
#include <csetjmp>
#include <ctime>

#include <pnglibconf.h>
#include <pngconf.h>
#include <png.h>

class TextureHelper
{
public:
	
	static GLuint png_texture_load(const char * file_name, int * width, int * height);
	
	static GLuint LoadBMPTexture(const char * filename );
	
	static GLuint createTexture(uint width, uint height, unsigned char * data);
	
	static void updateTexture(GLuint texture, uint width, uint height, unsigned char * data);
	
};

#endif /* defined(__Game2__TextureLoader__) */
