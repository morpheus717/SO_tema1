// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	if (length <= 0)
		return -1;
	int t = syscall(__NR_truncate, path, length);
	if (t < 0) {
		errno = t * (-1);
		return -1;
	}
	return t;
}
