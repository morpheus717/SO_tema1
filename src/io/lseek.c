// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	off_t v = syscall(8, fd, offset, whence);
	if (v < 0) {
		errno = v * (-1);
		return -1;
	}
	return v;
}
