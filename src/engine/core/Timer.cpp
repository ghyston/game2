#include "Timer.h"

clock_t Timer::last_tick = clock();
float Timer::delta_tick = 0.0f;
int Timer::milliseconds_per_frame = 40; //25 FPS

timeval Timer::last;
timeval Timer::delta;

void Timer::tick()
{
#ifdef MAC_OS_PLATFORM
    Timer::tick_mac();
#else
	clock_t new_tick = clock();
	Timer::delta_tick = (new_tick - Timer::last_tick) / (float)CLOCKS_PER_SEC;	
	Timer::last_tick = new_tick;
#endif
}

float Timer::get_delta()
{
#ifdef MAC_OS_PLATFORM
    return Timer::get_delta_mac();
#else
	return Timer::delta_tick;
#endif
}

float Timer::getTime()
{
	return clock() / (float)CLOCKS_PER_SEC;
}

void Timer::tick_mac()
{
    timeval new_tick;
    gettimeofday(&new_tick, NULL);
    timersub(&new_tick, &Timer::last, &Timer::delta);
	//new_tick.tv_sec * 1000 * new_tick.tv_usec
    Timer::last = new_tick;
}

float Timer::get_delta_mac()
{
    return (float)
        (Timer::delta.tv_sec + Timer::delta.tv_usec / 1000000.0f);
}

void Timer::start()
{
    gettimeofday(&Timer::last, NULL);
}