package com.hyston.games.game2;

import android.os.Bundle;
import android.app.Activity;

public class Game2Activity extends Activity
{
	Game2GLView game_view;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		game_view = new Game2GLView(getApplication());
		
		setContentView(game_view);		
	}
	
	@Override
	protected void onPause()
	{
		super.onPause();
		game_view.onPause();
	}
	
	@Override
	protected void onResume()
	{
		super.onResume();
		game_view.onResume();
	}

}
