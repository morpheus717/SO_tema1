// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	if (fd <= 0 && (flags & MAP_ANONYMOUS) == 0) {
		errno = EBADF;
		return MAP_FAILED;
	}
	if (flags & MAP_ANONYMOUS && fd != -1) {
		errno = EBADF;
		return MAP_FAILED;
	}
	if (length <= 0) {
		errno = EINVAL;
		return MAP_FAILED;
	}
	if (!((flags & MAP_PRIVATE) || (flags & MAP_SHARED))) {
		errno = EINVAL;
		return MAP_FAILED;
	}
	long long value = syscall(9, addr, length, prot, flags, fd, offset);
	if (value < 0) {
		errno = -value;
		return MAP_FAILED;
	}
	return (void *)value;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	// if (!(flags & MREMAP_MAYMOVE)) {
	// 	errno = EINVAL;
	// 	return MAP_FAILED;
	// }
	// if (new_size <= 0) {
	// 	errno = EINVAL;
	// 	return MAP_FAILED;
	// }
	void *new = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if ((long long)new < 0) {
		errno = -(int)new;
		return MAP_FAILED;
	}
	return new;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	if (length <= 0) {
		errno = EINVAL;
		return -1;
	}
	int fr = syscall(__NR_munmap, addr, length);
	if (fr < 0) {
		return -1;
		errno = EINVAL;
	}
	return 0;
}
