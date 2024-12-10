// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	if (fd <= 0) {
		errno = EBADF;
		return -1;
	}
	if (length <= 0) {
		errno = EINVAL;
		return -1;
	}
	int ft = syscall(77, fd, length);
	if (ft < 0) {
		errno = ft * (-1);
		return -1;
	}
	return 0;
}
