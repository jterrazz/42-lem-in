/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 23:52:17 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:00:38 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_connexions(t_connexions *connexions)
{
	t_connexions *next;

	while (connexions)
	{
		next = connexions->next;
		free(connexions);
		connexions = next;
	}
	return (0);
}

int		free_rooms(t_room *room)
{
	t_room *next;

	while (room)
	{
		free(room->name);
		next = room->next;
		free_connexions(room->connexions);
		free(room);
		room = next;
	}
	return (0);
}

int		free_links(t_link *link)
{
	t_link *next;

	while (link)
	{
		next = link->next;
		free(link);
		link = next;
	}
	return (0);
}

int		free_buffer(t_buffer *buffer)
{
	t_buffer *next;

	while (buffer)
	{
		next = buffer->next;
		free(buffer->str);
		free(buffer);
		buffer = next;
	}
	return (0);
}

int		free_flags(t_flags *f)
{
	if (f->nb_rooms > 0)
		free_rooms(f->rooms);
	if (f->nb_links > 0)
		free_links(f->links);
	free_buffer(f->buffer);
	return (0);
}
