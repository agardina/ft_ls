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
** \param time_used the time to convert to a string
**
** \return a date string
*/
static char	*get_time_str(struct timespec *time_used)
{
	return (ctime(&time_used->tv_sec));
}

void	display_date(t_ls *ls, struct stat *info)
{
	char			*full;
	char			date[7];
	char			hour_or_year[6];
	long			diff;
	struct timespec	*time_used;

	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
		time_used = &(info->st_birthtimespec);
	else if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
		time_used = &(info->st_atimespec);
	else
		time_used = &(info->st_mtimespec);
	full = get_time_str(time_used);
	diff = ft_difftime(time(NULL), time_used->tv_sec);
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
	ft_printf("%s %5s ", date, hour_or_year);
}
