/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 17:08:11 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:49:35 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		add_connexion(t_room *actual, t_room *room)
{
	t_connexions *connexion;

	if (!(connexion = (t_connexions *)malloc(sizeof(t_connexions))))
		return (0);
	connexion->room = room;
	if (!actual->connexions)
		connexion->next = NULL;
	else
		connexion->next = actual->connexions;
	actual->connexions = connexion;
	return (1);
}

int				init_links(t_flags *flags)
{
	t_link *links;
	t_room *room_a;
	t_room *room_b;

	links = flags->links;
	while (links)
	{
		room_a = get_room_for_id(flags, links->id_room1);
		room_b = get_room_for_id(flags, links->id_room2);
		if (!add_connexion(room_a, room_b))
			return (0);
		if (!add_connexion(room_b, room_a))
			return (0);
		links = links->next;
	}
	return (1);
}
