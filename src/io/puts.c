#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int puts (char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	int ok = syscall(__NR_write, 1, str, len);
	if (ok < 0) {
		errno = ok * (-1);
		return -1;
	}
	char newline = '\n';
	syscall(__NR_write, 1, &newline, 1);
	return 1;
}