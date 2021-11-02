/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_date.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:37:48 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:37:50 by agardina         ###   ########.fr       */
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

/**
** \brief "Translate" the month to French
**
** \param content the content of the tree node associated to the file
** \param date the char array containing the day and month
*/
static void	get_month(t_ls_tree_node *content, char *date)
{
	ft_strtolower(date);
	if (!ft_strncmp(date, "feb", 3))
		ft_memcpy((char *)content->date + 3, "fév", 4);
	else if (!ft_strncmp(date, "apr", 3))
		ft_memcpy((char *)content->date + 3, "avr", 3);
	else if (!ft_strncmp(date, "may", 3))
		ft_memcpy((char *)content->date + 3, "mai", 3);
	else if (!ft_strncmp(date, "jun", 3))
		ft_memcpy((char *)content->date + 3, "jui", 3);
	else if (!ft_strncmp(date, "aug", 3))
		ft_memcpy((char *)content->date + 3, "aoû", 4);
	else if (!ft_strncmp(date, "dec", 3))
		ft_memcpy((char *)content->date + 3, "déc", 4);
	else
		ft_memcpy((char *)content->date + 3, date, 3);
}

/**
** \brief Set the date string that will be printed
**
** \param content the content of the tree node associated to the file
** \param date the char array containing the day and month
** \param hour_or_year the char array containing the hour or the year
*/
static void	set_date_string(t_ls_tree_node *content, char date[7],
								char hour_or_year[6])
{
	int	hour_or_year_start;

	ft_memcpy((char *)content->date, (char *)date + 4, 2);
	content->date[2] = ' ';
	get_month(content, (char *)date);
	if (!content->date[6])
	{
		content->date[6] = ' ';
		hour_or_year_start = 7;
	}
	else
	{
		content->date[7] = ' ';
		hour_or_year_start = 8;
	}
	ft_memcpy((char *)content->date + hour_or_year_start,
		(char *)hour_or_year, 5);
}

void	get_date(t_ls *ls, t_ls_tree_node *content)
{
	char			*full;
	char			date[7];
	char			hour_or_year[6];
	long			diff;
	struct timespec	*time_used;

	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
		time_used = &(content->info.st_birthtimespec);
	else if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
		time_used = &(content->info.st_atimespec);
	else
		time_used = &(content->info.st_mtimespec);
	full = get_time_str(time_used);
	diff = ft_difftime(time(NULL), time_used->tv_sec);
	ft_strncpy(date, full + 4, 6);
	date[6] = '\0';
	if (SIX_MONTHS < diff)
	{
		hour_or_year[0] = ' ';
		ft_strncpy(hour_or_year + 1, full + 20, 4);
	}
	else
		ft_strncpy(hour_or_year, full + 11, 5);
	hour_or_year[5] = '\0';
	set_date_string(content, date, hour_or_year);
}
