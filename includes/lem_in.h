/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:39:33 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 01:32:21 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_room
{
	int					id;
	int					x;
	int					y;
	char				*name;
	struct s_room		*next;
	struct s_connexions	*connexions;
}				t_room;

typedef struct	s_connexions
{
	struct s_room		*room;
	struct s_connexions	*next;
}				t_connexions;

typedef struct	s_path
{
	struct s_room	*room;
	struct s_path	*next;
}				t_path;

typedef struct	s_paths
{
	int				weight;
	int				temp_weight;
	int				ants_to_send;
	struct s_path	*path;
	struct s_paths	*next;
}				t_paths;

typedef struct	s_link
{
	int				id_room1;
	int				id_room2;
	struct s_link	*next;
}				t_link;

typedef struct	s_ant
{
	int				id;
	int				start_i;
	int				progression;
	struct s_path	*path;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_buffer
{
	char				*str;
	struct s_buffer		*next;
}				t_buffer;

typedef struct	s_flags
{
	int				flag_understand;
	int				nb_ants;
	int				nb_rooms;
	int				nb_links;
	int				nb_of_rounds;
	int				index_starting_room;
	int				index_ending_room;
	struct s_buffer	*buffer;
	struct s_room	*rooms;
	struct s_link	*links;
	int				malloc_failed;
}				t_flags;

int				add_line_to_buffer(char *line, t_flags *flags);
int				get_weight_for_paths(t_flags *flags, t_paths *paths);
int				path_is_looping(t_path *path, int id);
void			print_buffer(t_flags *flags);
int				free_connexions(t_connexions *connexions);
int				free_rooms(t_room *room);
int				free_links(t_link *link);
int				free_flags(t_flags *f);
int				init_global_links(char *line, t_flags *flags);
int				init_global_room(char *line, t_flags *flags);
int				check_flags(t_flags *flags);
int				init_flags(t_flags *flags);
void			set_weight(t_paths *paths);
void			show_rooms(t_flags *flags);
int				resolve(t_flags *flags);
void			show_flags(t_flags *flags);
int				free_ret(void *p);
void			show_paths(t_paths *paths);
int				ft_error(void);
int				send_ants(t_ant *ants, t_flags *flags);
int				create_ants(t_paths *paths, t_flags *flags, int id);
t_ant			*delete_ant(t_ant *start, t_ant *ant);
t_ant			*add_ant(t_ant **ants, t_paths *paths, int start_i, int id);
int				init_links(t_flags *flags);
t_room			*get_room_for_id(t_flags *flags, int id);
t_paths			*get_all_paths(t_flags *flags, t_room *room_start);
int				free_paths(t_paths **paths);
int				free_path(t_path *path);
int				path_is_crossing(t_paths *main_paths, t_path *new_path);
void			remove_last_paths(t_paths **paths);
int				add_path(t_path **path, t_room *room);
int				remove_last_path(t_path *path);
int				save_paths(t_paths **dest, t_paths *src);
int				append_in_paths(t_paths **paths, t_path *path);
int				str_is_nb(char *str);

#endif
