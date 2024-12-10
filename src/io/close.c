// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int fc = syscall(3, fd);
	if (fc < 0) {
		fc *= -1;
		errno = fc;
		return -1;
	}
	return fc;
}

