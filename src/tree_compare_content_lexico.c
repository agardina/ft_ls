#include "prototypes.h"

int compare_operands_lexico(void *s1, void *s2)
{
	return (ft_strequ((char *)s1, (char *)s2));
}

int compare_operands_lexico_reverse(void *s1, void *s2)
{
	return (-ft_strequ((char *)s1, (char *)s2));
}
