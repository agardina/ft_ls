#include "prototypes.h"

int compare_operands_size(void *s1, void *s2)
{
	if (*(uint64_t *)s1 > *(uint64_t *)s2)
		return (1);
	else if (*(uint64_t *)s1 == *(uint64_t *)s2)
		return (0);
	return (-1);
}

int compare_operands_size_reverse(void *s1, void *s2)
{
	if (*(uint64_t *)s1 > *(uint64_t *)s2)
		return (-1);
	else if (*(uint64_t *)s1 == *(uint64_t *)s2)
		return (0);
	return (1);
}
