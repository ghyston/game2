#include "Timer.h"

clock_t Timer::last_tick = clock();
float Timer::delta_tick = 0.0f;

void Timer::tick()
{
	clock_t new_tick = clock();	
	Timer::delta_tick = (new_tick - Timer::last_tick) / (float)CLOCKS_PER_SEC;	
	Timer::last_tick = new_tick;
}

float Timer::get_delta()
{
	return Timer::delta_tick;
}

float Timer::getTime()
{
	return clock() / (float)CLOCKS_PER_SEC;
}

