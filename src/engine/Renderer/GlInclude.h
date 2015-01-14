//
//  GlInclude.h
//  Game2
//
//  Created by Stepanov Ilia on 03/03/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#define TARGET_MAC_OS_X

#ifdef MAC_OS_PLATFORM
	#include <OpenGL/gl3.h>
#else
//#ifdef ANDROID_PLATFORM //@todo
	#include <GLES2/gl2.h>
	#include <GLES2/gl2ext.h>
#endif