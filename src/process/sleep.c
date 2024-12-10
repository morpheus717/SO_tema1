#include <time.h>

int sleep(unsigned int seconds)
{
	struct timespec given;
	given.tv_sec = seconds;
	given.tv_nsec = 0;
	int ok = nanosleep(&given, &given);
	return ok;
}
