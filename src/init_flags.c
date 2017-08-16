/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:46:25 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:27:58 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	analyse_and_add_arg(char *line, t_flags *flags, int *checked_rooms,
	int *need_room)
{
	int found_room;

	if (*checked_rooms == 1)
	{
		if (init_global_links(line, flags))
			return (1);
	}
	else
	{
		found_room = init_global_room(line, flags);
		if (found_room)
			return (1);
		else if (!found_room && (flags->nb_rooms == 0 || *need_room == 1))
			return (0);
		else if (init_global_links(line, flags))
		{
			*checked_rooms = 1;
			return (1);
		}
	}
	return (0);
}

static int	check_for_command(char *line, t_flags *flags,
	int *need_room)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (flags->index_starting_room > -1)
			return (0);
		if (*need_room == 1)
			return (0);
		*need_room = 1;
		flags->index_starting_room = flags->nb_rooms;
		return (1);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (flags->index_ending_room > -1)
			return (0);
		if (*need_room == 1)
			return (0);
		*need_room = 1;
		flags->index_ending_room = flags->nb_rooms;
		return (1);
	}
	else if (*line == '#')
		return (1);
	return (-1);
}

static int	init_flags_next(t_flags *flags, char *line, int checked_rooms,
	int need_room)
{
	int ret;

	while (get_next_line(0, &line) > 0)
	{
		ret = check_for_command(line, flags, &need_room);
		if (ret == 1)
			;
		else if (ret == 0 || *line == 'L')
			return (free_ret(line));
		else
		{
			ret = analyse_and_add_arg(line, flags, &checked_rooms, &need_room);
			need_room = 0;
			if (!ret && checked_rooms && flags->nb_links > 0)
				return (1 + free_ret(line));
			else if (!ret)
				return (free_ret(line));
		}
		if ((ret = add_line_to_buffer(line, flags) + free_ret(line)) < 0)
			return (0);
	}
	return (1);
}

static int	get_nb_ant(t_flags *flags, char *line)
{
	char *l;

	l = line;
	if (!str_is_nb(l))
		return (0);
	flags->nb_ants = ft_atoi(&l);
	add_line_to_buffer(line, flags);
	free(line);
	return (1);
}

int			init_flags(t_flags *flags)
{
	char *line;

	flags->nb_rooms = 0;
	flags->nb_links = 0;
	flags->index_starting_room = -1;
	flags->index_ending_room = -1;
	flags->nb_of_rounds = -1;
	flags->buffer = NULL;
	if (get_next_line(0, &line) <= 0)
		return (0);
	while (*line == '#')
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			return (0);
		add_line_to_buffer(line, flags);
		free(line);
		if (get_next_line(0, &line) <= 0)
			return (0);
	}
	if (!get_nb_ant(flags, line))
		return (0);
	if (!init_flags_next(flags, line, 0, 0))
		return (0);
	return (1);
}
