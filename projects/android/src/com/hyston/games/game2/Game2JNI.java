package com.hyston.games.game2;

public class Game2JNI
{
	static 
	{		
		System.loadLibrary("Game2jni");		
	}
	
	/**
     * @param width the current view width
     * @param height the current view height
     */
     public static native void init(int width, int height);     
     
     public static native void draw();
     
     public static native void step();

}
