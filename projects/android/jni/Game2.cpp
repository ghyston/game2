#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../../src/engine/GameEngine.h"
#include "../../../src/engine/Renderer/Renderer.h"

GameEngine * engine;

extern "C"
{
	JNIEXPORT void Java_com_hyston_games_game2_Game2JNI_init(JNIEnv * env, jobject obj, int width, int height);

	JNIEXPORT void Java_com_hyston_games_game2_Game2JNI_draw(JNIEnv * env, jobject obj);

	JNIEXPORT void Java_com_hyston_games_game2_Game2JNI_step(JNIEnv * env, jobject obj);
}


JNIEXPORT void Java_com_hyston_games_game2_Game2JNI_init(JNIEnv * env, jobject obj, int width, int height)
{
	GameEngine::create_instance();
	engine = GameEngine::get_instance();
	engine->init(width, height);
}


JNIEXPORT void Java_com_hyston_games_game2_Game2JNI_draw(JNIEnv * env, jobject obj)
{
	engine->draw_all();
}

JNIEXPORT void Java_com_hyston_games_game2_Game2JNI_step(JNIEnv * env, jobject obj)
{
	engine->move_all();
}

