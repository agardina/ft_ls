/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:23 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:24 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

// TODO : add the support of the ft_ls structure in order to parse the options

/*
** \brief Compute the difference in seconds between two given times
**
** \param t1 first time structure
** \param t2 second time structure
**
** \return the difference in seconds between the given times
*/
static long	ft_difftime(time_t t1, time_t t2)
{
	if (t1 >= t2)
		return (t1 - t2);
	return (t2 - t1);
}

/*
** \brief Return the date string corresponding to the type of time
** used by ft_ls (modification, access or creation time)
**
** \param info WIP
**
** \return a date string
*/
static char	*get_time_str(struct stat *info)
{
	return (ctime(&info->st_mtimespec.tv_sec));
}

/*
** \brief Print the time column of a line in the ft_ls output
**
** \param info WIP
*/
void	print_date(struct stat *info)
{
	char	*full;
	char	date[7];
	char	hour_or_year[6];
	long	diff;

	full = get_time_str(info);
	diff = ft_difftime(time(NULL), info->st_mtimespec.tv_sec);
	ft_strncpy(date, full + 4, 6);
	date[6] = '\0';
	if (SIX_MONTHS < diff)
	{
		ft_strncpy(hour_or_year, full + 20, 4);
		hour_or_year[4] = '\0';
	}
	else
		ft_strncpy(hour_or_year, full + 11, 5);
	hour_or_year[5] = '\0';
	ft_printf("%s %s", date, hour_or_year);
}
