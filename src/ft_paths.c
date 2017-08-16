/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 17:11:42 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:15:00 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	append_in_paths_next(t_paths *new, t_path *path_cpy,
	t_paths **paths, t_paths *ps)
{
	new->path = path_cpy;
	new->next = NULL;
	new->weight = 0;
	new->temp_weight = 0;
	new->ants_to_send = 0;
	if (!(*paths))
	{
		*paths = new;
		return (1);
	}
	while (ps->next)
		ps = ps->next;
	ps->next = new;
	return (1);
}

int			append_in_paths(t_paths **paths, t_path *path)
{
	t_path		*path_cpy;
	t_paths		*new;
	t_path		*p;
	t_paths		*ps;

	p = path;
	ps = *paths;
	path_cpy = NULL;
	while (p)
	{
		if (!add_path(&path_cpy, p->room))
			return (free_path(path_cpy));
		p = p->next;
	}
	if (!(new = (t_paths *)malloc(sizeof(t_paths))))
		return (free_path(path_cpy));
	append_in_paths_next(new, path_cpy, paths, ps);
	return (1);
}

int			save_paths(t_paths **dest, t_paths *src)
{
	while (src)
	{
		if (!append_in_paths(dest, src->path))
			return (0);
		src = src->next;
	}
	return (1);
}

int			free_paths(t_paths **paths)
{
	t_path		*path;
	t_path		*path_temp;
	t_paths		*sav;
	t_paths		*sav2;

	sav = *paths;
	while (*paths)
	{
		path = (*paths)->path;
		while (path)
		{
			path_temp = path->next;
			free(path);
			path = path_temp;
		}
		(*paths)->path = NULL;
		sav2 = (*paths)->next;
		free(*paths);
		*paths = sav2;
	}
	sav = NULL;
	return (0);
}

void		remove_last_paths(t_paths **paths)
{
	t_paths *paths_c;

	paths_c = *paths;
	if (!(*paths))
		return ;
	else if (!(*paths)->next)
	{
		free_path((*paths)->path);
		free(*paths);
		*paths = NULL;
		return ;
	}
	while (paths_c->next->next)
		paths_c = paths_c->next;
	free_path(paths_c->next->path);
	free(paths_c->next);
	paths_c->next = NULL;
}
