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


#define INDEX_BUFFER 0
#define POS_VB 1
#define NORMAL_VB 2
#define TEXCOORD_VB 3
#define WVP_MAT_VB 4
#define WORLD_MAT_VB 5
