#ifndef __TIME_H__
#define __TIME_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <internal/syscall.h>
#include <internal/types.h>

struct timespec {
	long tv_sec, tv_nsec;
};

int nanosleep (const struct timespec *t1, struct timespec *t2);

int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif