/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:17 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:18 by agardina         ###   ########.fr       */
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
	if (c == 'R' || c == 'S' || c == 'U' || c == 'a' || c == 'l' || c == 'n'
		|| c == 'r' || c == 't' || c == 'u')
		return (1);
	return (0);
}

/**
** \brief Print a message to let the user know he or she has specified
** an invalid ft_ls option
**
** \param c the invalid option that was specified
*/
static void	print_message_illegal_option(char c)
{
	ft_printf("ls: illegal option -- %c\nusage: ./ft_ls [-RSUalnrtu]\n", c);
}

/**
** \brief Parse the options specified by the user of the ft_ls program
**
** \details Supported options: -R, -S, -U, -a, -l, -n, -r, -t, -u
**
** \param ls the ls structure
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
**
** \return the number of command line arguments that were parsed by
** the function if success
** \return -1 if an unsupported option was found
*/
int	ls_parsing_options(t_ls *ls, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (j == 0)
		{
			if (argv[i][j] != '-')
				return (i);
			else if (argv[i][j + 1] == '\0')
				return (i);
		}
		else
		{
			if (!is_valid_option(argv[i][j]))
			{
				print_message_illegal_option(argv[i][j]);
				return (-1);
			}
			else
				add_option(ls, argv[i][j]);
		}
		if (argv[i][j + 1] == '\0')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}
