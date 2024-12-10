// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	if (fd <= 0) {
		errno = EBADF;
		return -1;
	}
	int fs = syscall(__NR_fstat, fd, st);
	if (fs < 0) {
		errno = fs * (-1);
		return -1;
	}
	return fs;
}
