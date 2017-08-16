/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 23:52:26 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:02:17 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_path(t_path *path)
{
	t_path *temp;

	while (path)
	{
		temp = path->next;
		free(path);
		path = temp;
	}
	return (0);
}

t_path	*get_last_path(t_path *path)
{
	t_path *path_c;

	path_c = path;
	if (!path_c)
		return (NULL);
	while (path_c->next)
		path_c = path_c->next;
	return (path_c);
}

int		remove_last_path(t_path *path)
{
	t_path *new_last;

	if (!path)
		return (0);
	new_last = path;
	if (new_last->next)
	{
		while (new_last->next && new_last->next->next)
			new_last = new_last->next;
		free(new_last->next);
		new_last->next = NULL;
	}
	else
		free(new_last);
	return (0);
}

int		add_path(t_path **path, t_room *room)
{
	t_path *new_path;
	t_path *last_path;

	if (!path || !(new_path = (t_path *)malloc(sizeof(t_path))))
		return (0);
	new_path->room = room;
	new_path->next = NULL;
	if (!(*path))
		*path = new_path;
	else
	{
		last_path = get_last_path(*path);
		last_path->next = new_path;
	}
	return (1);
}
