/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths_weight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 23:42:15 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:14:55 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_weight(t_paths *paths)
{
	int		i;
	t_path	*path;

	while (paths)
	{
		i = 0;
		path = paths->path;
		while (path)
		{
			path = path->next;
			i++;
		}
		paths->weight = i;
		paths = paths->next;
	}
}

static void	fill_paths_with_ants(t_paths *paths)
{
	int		best_weight;
	t_paths	*best_path;

	if (!paths)
		return ;
	best_path = paths;
	best_weight = paths->temp_weight;
	paths = paths->next;
	while (paths)
	{
		if (paths->temp_weight < best_weight)
		{
			best_weight = paths->temp_weight;
			best_path = paths;
		}
		paths = paths->next;
	}
	best_path->ants_to_send++;
	best_path->temp_weight++;
}

static int	get_nb_rounds(t_paths *paths)
{
	int ret;

	ret = 0;
	if (!paths)
		return (-1);
	while (paths)
	{
		if (ret < paths->ants_to_send)
			ret = paths->ants_to_send;
		paths = paths->next;
	}
	return (ret);
}

int			get_weight_for_paths(t_flags *flags, t_paths *paths)
{
	int			nb_ants;
	t_paths		*paths_c;

	nb_ants = flags->nb_ants;
	paths_c = paths;
	while (paths_c)
	{
		paths_c->ants_to_send = 0;
		paths_c->temp_weight = paths_c->weight;
		paths_c = paths_c->next;
	}
	while (nb_ants > 0)
	{
		fill_paths_with_ants(paths);
		nb_ants--;
	}
	return (get_nb_rounds(paths));
}
