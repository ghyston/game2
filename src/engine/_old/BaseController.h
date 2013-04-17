#ifndef __BASE_CONTROLLER_H__
#define __BASE_CONTROLLER_H__


class BaseController
{
public:
	struct Event
	{
		struct Types
		{
			enum
			{
				press,
				release
			};
		};

		struct Devices
		{
			enum
			{
				keyboard,
				mouse,
				touch
			};
		};

		struct Keys
		{
			enum
			{
				arrow_left,
				arrow_right,
				arrow_up,
				arrow_down
			};
		};

		int device;
		int type;
		int key;
	};

	void proceed(Event event);

};

#endif //__BASE_CONTROLLER_H__
