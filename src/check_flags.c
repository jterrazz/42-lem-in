/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:45:18 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 00:47:46 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_flags(t_flags *flags)
{
	if (flags->nb_ants < 1)
		return (0);
	else if (flags->nb_rooms < 2)
		return (0);
	else if (flags->nb_links < 1)
		return (0);
	else if (flags->index_starting_room < 0)
		return (0);
	else if (flags->index_ending_room < 0)
		return (0);
	return (1);
}
