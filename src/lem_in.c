/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:39:37 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/15 02:08:18 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_flags flags;

	argv = (char **)argv;
	flags.flag_understand = 0;
	if (argc == 2 && !ft_strcmp("-wtf", argv[1]))
		flags.flag_understand = 1;
	else if (argc == 2)
		return (ft_error());
	if (argc > 2)
		return (ft_error());
	if (!init_flags(&flags))
		return (free_flags(&flags) + ft_error());
	if (!check_flags(&flags))
		return (free_flags(&flags) + ft_error());
	if (!resolve(&flags))
		return (free_flags(&flags) + ft_error());
	free_flags(&flags);
	return (0);
}
