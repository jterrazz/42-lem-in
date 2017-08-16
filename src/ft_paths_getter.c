/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 23:39:02 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:14:57 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		find_paths(t_flags *flags, t_room *room, t_paths **paths,
	t_path *path)
{
	t_connexions *connexions;

	if (flags->malloc_failed)
		return ;
	if (!room || path_is_looping(path, room->id))
	{
		remove_last_path(path);
		return ;
	}
	else if (room->id == flags->index_ending_room)
	{
		append_in_paths(paths, path);
		remove_last_path(path);
		return ;
	}
	connexions = room->connexions;
	while (connexions)
	{
		add_path(&path, connexions->room);
		find_paths(flags, connexions->room, paths, path);
		connexions = connexions->next;
	}
	remove_last_path(path);
}

t_paths			*get_all_paths(t_flags *flags, t_room *room_start)
{
	t_paths		*all_paths;
	t_path		*path;

	all_paths = NULL;
	path = NULL;
	flags->malloc_failed = 0;
	if (!add_path(&path, room_start))
		return (NULL);
	find_paths(flags, room_start, &all_paths, path);
	if (flags->malloc_failed)
		return (NULL);
	return (all_paths);
}
