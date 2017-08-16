/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 17:00:55 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 00:57:41 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*add_ant(t_ant **ants, t_paths *paths, int start_i, int id)
{
	t_ant *ant;
	t_ant *temp;

	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	ant->id = id;
	ant->path = paths->path;
	ant->start_i = start_i;
	ant->progression = 0;
	ant->next = NULL;
	if (!(*ants))
		return (ant);
	temp = *ants;
	while (temp->next)
		temp = temp->next;
	temp->next = ant;
	return (*ants);
}

t_ant			*delete_ant(t_ant *start, t_ant *ant)
{
	t_ant *temp;

	temp = start;
	if (!ant || !start)
		return (NULL);
	if (ant->id == start->id)
	{
		temp = start->next;
		return (free_ret(ant) + temp);
	}
	else if (ant->next == NULL)
	{
		while (temp->next && temp->next->next)
			temp = temp->next;
		free(temp->next);
		temp->next = NULL;
	}
	else
	{
		while (temp->next && temp->next->id != ant->id)
			temp = temp->next;
		temp->next = ant->next;
		free(ant);
	}
	return (start);
}

static int		get_max_ants_to_send(t_paths *paths)
{
	int i;

	i = 0;
	while (paths)
	{
		if (paths->ants_to_send > i)
			i = paths->ants_to_send;
		paths = paths->next;
	}
	return (i);
}

int				create_ants(t_paths *paths, t_flags *flags, int id)
{
	t_ant	*ants;
	t_paths	*paths_c;
	int		i;
	int		j;

	i = get_max_ants_to_send(paths);
	j = 0;
	while (i && (i-- || 1))
	{
		paths_c = paths;
		while (paths_c)
		{
			if (paths_c->ants_to_send > 0)
			{
				if (!(ants = add_ant(&ants, paths_c, j, id)))
					return (0);
				paths_c->ants_to_send--;
				id++;
			}
			paths_c = paths_c->next;
		}
		j++;
	}
	return (1 + send_ants(ants, flags));
}
