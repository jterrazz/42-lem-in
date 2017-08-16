/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 23:46:45 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/16 03:03:52 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		init_room_next(t_flags *flags, char *line, t_room *room)
{
	if (*line != ' ')
		return (0);
	line++;
	room->x = ft_atoi(&line);
	if (*line != ' ')
		return (0);
	room->y = ft_atoi(&line);
	if (*line != '\0')
		return (0);
	room->id = flags->nb_rooms;
	if (!(flags->rooms))
		flags->rooms = room;
	else
	{
		room->next = flags->rooms;
		flags->rooms = room;
	}
	flags->nb_rooms++;
	return (1);
}

static int		check_is_only_name(t_flags *flags, t_room *new)
{
	t_room	*temp;
	int		i;

	i = 0;
	while (new->name[i])
	{
		if (new->name[i] == '-')
			return (0);
		i++;
	}
	temp = flags->rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->name, new->name))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				init_global_room(char *line, t_flags *flags)
{
	int		i;
	t_room	*room;

	i = 0;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (!i)
		return (0);
	room->name = ft_strsub(line, 0, i);
	if (!check_is_only_name(flags, room))
		return (free_ret(room->name) + free_ret(room));
	room->next = NULL;
	room->connexions = NULL;
	line = line + i;
	if (!init_room_next(flags, line, room))
		return (free_ret(room->name) + free_ret(room));
	return (1);
}
