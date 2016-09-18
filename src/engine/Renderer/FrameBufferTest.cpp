//
//  FrameBufferTest.cpp
//  Game2
//
//  Created by Stepanov Ilia on 15/09/16.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#include "FrameBufferTest.hpp"
#include "GameEngine.h"

void FrameBufferTest::init()
{
	GlobalData::DeviceScreen screen = GameEngine::get_instance()->get_data()->screen;
	int w = screen.width;
	int h = screen.height;
	
	// create framebuffer
	glGenFramebuffers(1, &_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
	
	// create render texture
	glGenTextures(1, &_renderedTexture);
	glBindTexture(GL_TEXTURE_2D, _renderedTexture);
	
	// Give an empty image to OpenGL ( the last "0" )
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, 0);
	
	// Poor filtering. Needed !
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	// Depth buffer
	glGenRenderbuffers(1, &_depthbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, _depthbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, w, h);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthbuffer);
	
	// Set "renderedTexture" as our colour attachement #0
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, _renderedTexture, 0);
	
	// Set the list of draw buffers.
	GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers
	
	// init texturedRect
	texturedRect.set_height(screen.ratio);
	texturedRect.set_width(1.0);
	texturedRect.coords.x = 0.5;
	texturedRect.coords.y = screen.ratio / 2;
	
	texturedRect.texture1 = _renderedTexture;
	GLuint shader = GameEngine::get_renderer()->getBlurShader();
	texturedRect.set_shader(shader);
	texturedRect.setup_vertexes();
	texturedRect.SetColor(0.0f, 0.0f, 1.0f);
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBufferTest::preRender()
{
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
}

void FrameBufferTest::postRender()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	GameEngine::get_instance()->get_renderer()->clear_frame_for_postrender();
	
	texturedRect.Draw();
}
