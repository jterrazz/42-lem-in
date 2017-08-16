/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:58:01 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 00:58:57 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_ant_tour(t_ant *ants, int i, t_ant **first_ant, int space)
{
	t_path	*path;
	t_ant	*next;
	int		tmp;

	while (ants)
	{
		if (i >= ants->start_i)
		{
			if (i > 0)
				space = (space ? ft_putstr_ret(" ") + 1 : 1);
			path = ants->path;
			tmp = ants->progression;
			while (tmp-- > 0)
				path = path->next;
			if (ants->progression)
				ft_printf("L%d-%s", ants->id, path->room->name);
			ants->progression++;
			next = ants->next;
			if (!path->next)
				*first_ant = delete_ant(*first_ant, ants);
		}
		else
			next = ants->next;
		ants = next;
	}
}

int				send_ants(t_ant *ants, t_flags *flags)
{
	t_ant	*first_ant;
	int		i;

	i = 0;
	print_buffer(flags);
	first_ant = ants;
	while (ants)
	{
		if (i > 0)
			ft_printf("\n");
		print_ant_tour(ants, i, &first_ant, 0);
		i++;
		ants = first_ant;
	}
	return (0);
}
