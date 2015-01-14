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

#include <cstdio>
#include <cstdlib>
#include <csetjmp>
#include <ctime>

#include <libpng/pnglibconf.h>
#include <libpng/pngconf.h>
#include <libpng/png.h>

class TextureLoader
{
public:
	
	TextureLoader() {}
	~TextureLoader() {}
	
	GLuint png_texture_load(const char * file_name, int * width, int * height);
	
	GLuint LoadBMPTexture( const char * filename );
	
};

#endif /* defined(__Game2__TextureLoader__) */
