/* 
 * File:   Timer.h
 * Author: Hyston
 *
 * Created on 23 Июнь 2013 г., 5:20
 */

#ifndef __TIMER_H__
#define	__TIMER_H__

#include <time.h>

class Timer
{
private:

	//Last time, when tick() was called.	
	static clock_t last_tick;
	
	static float delta_tick;


	//We shouldn't create instance of this.
	Timer()	{} 

	Timer(Timer& t) {}	
	
public:	
	
	/**
	*	Return difference between current and previous 
	*	tick() call.
	*/
	static void tick();
	
	static float get_delta();

	/**
	* Return time since programm start
	* @return float seconds.
	*/
	static float getTime();
	
};

#endif	/* __TIMER_H__ */

