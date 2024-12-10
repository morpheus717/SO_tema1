// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size <= 0)
		return NULL;
	void *all = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (all == (void *)(-1))
		return NULL;
	int new = mem_list_add(all, size);
	if (new == -1) {
		munmap(all, size);
		return NULL;
	}
	return all;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	if (size <= 0 || nmemb <= 0)
		return NULL;
	void *ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return NULL;
	memset(ptr, 0, size * nmemb);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
		return;
	struct mem_list *res = mem_list_find(ptr);
	if (res == NULL)
		return;
	size_t len = res->len;
	munmap(ptr, len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *old = mem_list_find(ptr);
	int old_size = old->len;
	void *new = mremap(old, old_size, size, MREMAP_MAYMOVE);
	if (new == NULL)
		return NULL;
	mem_list_del(ptr);
	mem_list_add(new, size);
	return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return realloc(ptr, nmemb * size);
}
