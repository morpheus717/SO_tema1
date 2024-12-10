// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int n = strlen(source);
	for (int i = 0; i < n; i++)
		destination[i] = source[i];
	destination[n] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int n = strlen(source);
	for (int i = 0; i < len; i++) {
		if (i >= n)
			destination[i] = '\0';
		else
			destination[i] = source[i];
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *p = destination + strlen(destination);
	strcpy(p, source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int n = strlen(source);
	char *aux = destination;
	aux += strlen(destination);
	if (len > n) {
		strncpy(aux, source, n);
		aux[n] = '\0';
	}
	else {
		strncpy(aux, source, len);
		aux[len] = '\0';
	}
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	while(str1[i] || str2[i]) {
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int i = 0;
	while ((str1[i] || str2[i]) && i < len) {
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (int i = 0; i < strlen(str); i++)
		if (c == str[i])
			return str + i;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if (!str)
		return NULL;
	for (int i = strlen(str) - 1; i >= 0; i--)
		if (c == str[i])
			return str + i;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (!needle || !haystack)
		return NULL;
	int lenn = strlen(needle);
	int lenh = strlen(haystack);
	if (!lenn)
		return haystack;
	for (int i = 0; i <= lenh - lenn; i++) {
		if (haystack[i] == needle[0]) {
			int ok = 1;
			for (int j = 1; j < lenn; j++) {
				if (haystack[i + j] != needle[j]) {
					ok = 0;
					break;
				}
			}
			if (ok)
				return haystack + i;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *ptr = strstr(haystack, needle);
	if (!ptr)
		return NULL;
	char *last = strstr(ptr + 1, needle);
	while (last != NULL) {
		ptr = last++;
		last = strstr(last, needle);
	}
	return ptr;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = (char *)destination;
	char *s = (char *)source;
	for (int i = 0; i < num; i++, d++, s++)
		*d = *s;
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = (char *)destination;
	char *s = (char *)source;
	if (destination == source)
		return destination;
	if (destination <= source + num) {
		for (int i = num - 1; i >= 0; i--)
			d[i] = s[i];
		d[num] = '\0';
		return destination;
	}
	for (int i = 0; i < num; i++)
		d[i] = s[i];
	d[num] = '\0';
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *d = (char *)ptr1;
	char *s = (char *)ptr2;
	for (int i = 0; i < num; i++, d++, s++)
		if (*d != *s)
			return *d - *s;
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *d = (char *)source;
	for (int i = 0; i < num; i++, d++)
		*d = (char)value;
	return source;
}
