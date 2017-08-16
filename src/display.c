/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 06:01:23 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:26:17 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_flags(t_flags *flags)
{
	t_room *rooms;
	t_link *links;

	rooms = flags->rooms;
	links = flags->links;
	ft_printf(" ---------------- FLAGS --------------- \n");
	ft_printf("| Number of ants : %19d |\n", flags->nb_ants);
	ft_printf("| Start at : %25d |\n", flags->index_starting_room);
	ft_printf("| End at : %27d |\n", flags->index_ending_room);
	ft_printf("|- ROOMS ------------X--------Y--------|\n");
	while (rooms)
	{
		ft_printf("| #%-2d : %-7s      %-8d %-8d |\n", rooms->id,
			rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}
	ft_printf("|---------------- LINKS ---------------|\n");
	while (links)
	{
		ft_printf("| %17d - %-16d |\n", links->id_room1, links->id_room2);
		links = links->next;
	}
	ft_printf("| ------------------------------------ |\n\n");
}

void	show_rooms(t_flags *flags)
{
	t_connexions	*connexions;
	t_room			*rooms;

	rooms = flags->rooms;
	while (rooms)
	{
		ft_printf("|-----------   Room #%-3d --------------|\n", rooms->id);
		connexions = rooms->connexions;
		while (connexions)
		{
			ft_printf("| Linked to #%3d                       |\n",
				connexions->room->id);
			connexions = connexions->next;
		}
		rooms = rooms->next;
	}
	ft_printf("| ------------------------------------ |\n\n");
}

void	print_buffer(t_flags *flags)
{
	t_buffer *buffer;

	buffer = flags->buffer;
	while (buffer)
	{
		ft_printf("%s\n", buffer->str);
		buffer = buffer->next;
	}
}

int		add_line_to_buffer(char *line, t_flags *flags)
{
	t_buffer *new;
	t_buffer *tmp;

	if (!(new = (t_buffer *)malloc(sizeof(t_buffer))))
		return (-1);
	new->str = ft_strdup(line);
	new->next = NULL;
	tmp = flags->buffer;
	if (!flags->buffer)
		flags->buffer = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

void	show_paths(t_paths *paths)
{
	t_path	*path;
	int		first;

	ft_printf("| -------------- Paths --------------- |\n");
	while (paths)
	{
		first = 0;
		path = paths->path;
		ft_printf("| ");
		while (path)
		{
			if (first)
				ft_printf("--> ", path->room->name);
			else
				first = 1;
			ft_printf("%s ", path->room->name);
			path = path->next;
		}
		ft_printf("\n");
		paths = paths->next;
	}
	ft_printf("| ------------------------------------ |\n\n");
}
