/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 06:03:21 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 02:07:39 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		analyse_weight(t_flags *flags, t_paths **final_paths,
	t_paths **actual_paths)
{
	int			weight;

	weight = get_weight_for_paths(flags, *actual_paths);
	if (weight != -1 && flags->nb_of_rounds == -1)
	{
		flags->nb_of_rounds = weight;
		if (!save_paths(final_paths, *actual_paths))
			flags->malloc_failed = 1;
	}
	else if (weight != -1 && weight < flags->nb_of_rounds)
	{
		free_paths(final_paths);
		flags->nb_of_rounds = weight;
		if (!save_paths(final_paths, *actual_paths))
			flags->malloc_failed = 1;
	}
}

static void		find_best_paths(t_flags *flags, t_paths *paths,
	t_paths **final_paths, t_paths **actual_paths)
{
	t_paths		*paths_c;

	if (flags->malloc_failed)
		return ;
	set_weight(*actual_paths);
	analyse_weight(flags, final_paths, actual_paths);
	paths_c = paths;
	while (paths_c)
	{
		if (!path_is_crossing(*actual_paths, paths_c->path))
		{
			if (!append_in_paths(actual_paths, paths_c->path))
				flags->malloc_failed = 1;
			find_best_paths(flags, paths, final_paths, actual_paths);
		}
		paths_c = paths_c->next;
	}
	remove_last_paths(actual_paths);
}

static void		show_help(t_flags *flags, t_paths *all_paths)
{
	if (flags->flag_understand)
	{
		show_flags(flags);
		show_rooms(flags);
		show_paths(all_paths);
	}
}

int				resolve(t_flags *flags)
{
	t_room	*room_start;
	t_paths	*all_paths;
	t_paths	*temp_paths;
	t_paths	*final_paths;

	temp_paths = NULL;
	final_paths = NULL;
	flags->malloc_failed = 0;
	room_start = get_room_for_id(flags, flags->index_starting_room);
	if (!room_start || !init_links(flags))
		return (0);
	all_paths = get_all_paths(flags, room_start);
	if (flags->malloc_failed || !all_paths)
		return (free_paths(&all_paths));
	find_best_paths(flags, all_paths, &final_paths, &temp_paths);
	if (flags->malloc_failed)
		return (0);
	set_weight(final_paths);
	get_weight_for_paths(flags, final_paths);
	show_help(flags, all_paths);
	free_paths(&all_paths);
	free_paths(&temp_paths);
	if (!flags->malloc_failed && !create_ants(final_paths, flags, 1))
		return (free_paths(&final_paths));
	return (free_paths(&final_paths) + 1);
}
