
#include <time.h>

int nanosleep (const struct timespec *t1, struct timespec *t2)
{
	int res = syscall(35, t1, t2);
	// if (res == -1) {
	// 	if (t1->tv_sec < 0 || t1->tv_nsec < 0 || t1->tv_nsec > 999999999) {
	// 		errno = EINVAL;
	// 		return -1;
	// 	}
	// 	errno = EINTR;
	// 	return -1;
	// }
	if (res < 0) {
		errno = res * (-1);
		return -1;
	}
	return 0;
}