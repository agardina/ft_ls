/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:46:36 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:46:38 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Check if the given char is a valid ft_ls option
**
** \param c the char to check
**
** \retval 1 if the given char is a valid ft_ls option
** \retval 0 otherwise
*/
static int	is_valid_option(char c)
{
	if (c == '@' || c == 'F' || c == 'H' || c == 'R' || c == 'S' || c == 'U'
		|| c == 'a' || c == 'd' || c == 'e' || c == 'l' || c == 'n' || c == 'r'
		|| c == 't' || c == 'u' || c == '1')
		return (1);
	return (0);
}

/**
** \brief Print a message to let the user know he or she has specified
** an invalid ft_ls option
**
** \param c the invalid option that was specified
*/
static void	display_message_illegal_option(char c)
{
	ft_dprintf(2,
		"ft_ls: illegal option -- %c\nusage: ./ft_ls [-@FHRSUadelnrtu1]"
		"[file ...]\n", c);
}

/**
** \brief Move forward to the next option to parse
**
** \param argv array of command line arguments
** \param arg_nb current position in the array of command line arguments
** \param i current position in the argument in use
*/
static void	parsing_options_move_forward(char **argv, int *arg_nb, int *i)
{
	if (argv[*arg_nb][*i + 1] == '\0')
	{
		(*arg_nb)++;
		*i = 0;
	}
	else
		(*i)++;
}

int	ls_parsing_options(t_ls *ls, int argc, char **argv)
{
	int	arg_nb;
	int	pos;

	arg_nb = 1;
	pos = 0;
	while (arg_nb < argc)
	{
		if (pos == 0)
		{
			if (argv[arg_nb][pos] != '-' || argv[arg_nb][pos + 1] == '\0')
				return (arg_nb);
		}
		else
		{
			if (!is_valid_option(argv[arg_nb][pos]))
			{
				display_message_illegal_option(argv[arg_nb][pos]);
				return (-1);
			}
			else
				add_option_from_letter(ls, argv[arg_nb][pos]);
		}
		parsing_options_move_forward(argv, &arg_nb, &pos);
	}
	return (arg_nb);
}
