/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 17:10:26 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:15:14 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_room_for_id(t_flags *flags, int id)
{
	t_room *room;

	room = flags->rooms;
	while (room)
	{
		if (room->id == id)
			return (room);
		room = room->next;
	}
	return (NULL);
}
