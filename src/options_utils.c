#include "prototypes.h"

void	deactivate_option(t_ls *ls, unsigned int option)
{
	ls->flags &= (~option);
}

int	is_option_activated(t_ls *ls, unsigned int option)
{
	return (ls->flags & option);
}
