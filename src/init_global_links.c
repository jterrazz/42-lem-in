/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 00:03:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:37:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_id_room(t_flags *flags, char *str)
{
	t_room	*room;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	room = flags->rooms;
	while (room)
	{
		if (!ft_strcmp(room->name, str))
			return (free_ret(str) + room->id);
		room = room->next;
	}
	return (free_ret(str) - 1);
}

int		init_global_links(char *line, t_flags *flags)
{
	t_link	*link;
	int		index_dash;

	index_dash = 0;
	while (line[index_dash] && line[index_dash] != '-')
		index_dash++;
	if (!line[index_dash] || !(link = (t_link *)malloc(sizeof(t_link))))
		return (0);
	link->id_room1 = get_id_room(flags, ft_strsub(line, 0, index_dash));
	line += index_dash;
	if (*line != '-' || link->id_room1 < 0)
		return (free_ret(link));
	line++;
	link->id_room2 = get_id_room(flags, ft_strsub(line, 0, ft_strlen(line)));
	if (link->id_room2 < 0 || link->id_room2 == link->id_room1)
		return (free_ret(link));
	link->next = NULL;
	if ((flags->nb_links++ || 1) && !(flags->links))
		flags->links = link;
	else
	{
		link->next = flags->links;
		flags->links = link;
	}
	return (1);
}
