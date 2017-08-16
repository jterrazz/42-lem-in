/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 01:01:56 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:13:48 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_is_looping(t_path *path, int id)
{
	t_path *path_c;

	path_c = path;
	if (!path_c)
		return (0);
	while (path_c->next)
	{
		if (path_c->room->id == id)
			return (1);
		path_c = path_c->next;
	}
	return (0);
}

int		check_path_is_crossing(t_path *path, t_path *new_path)
{
	if (path->room->id == new_path->room->id && path->next && new_path->next
		&& path->next->room->id == new_path->next->room->id
		&& new_path->next->next == NULL && path->next->next == NULL)
		return (1);
	return (0);
}

int		path_is_crossing(t_paths *main_paths, t_path *new_path)
{
	t_path *path;
	t_path *new_path_c;

	if (!main_paths)
		return (0);
	while (main_paths)
	{
		path = main_paths->path;
		if (check_path_is_crossing(path, new_path))
			return (1);
		path = path->next;
		while (path->next)
		{
			new_path_c = new_path;
			while (new_path_c)
			{
				if (path->room->id == new_path_c->room->id)
					return (1);
				new_path_c = new_path_c->next;
			}
			path = path->next;
		}
		main_paths = main_paths->next;
	}
	return (0);
}
