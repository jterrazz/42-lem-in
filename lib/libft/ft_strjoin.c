/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:07:51 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:07:53 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_multiple(char *s1, char *s2, int x, int y)
{
	if (x)
		free(s1);
	if (y)
		free(s2);
}

char			*ft_strjoin_free(char *s1, char *s2, int x, int y)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_s == NULL)
		return (NULL);
	while (s1[i])
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[j++] = s2[i++];
	free_multiple(s1, s2, x, y);
	return (new_s);
}

char			*ft_strjoin_inside_free(char *s1, char *s2, unsigned int x)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_s == NULL)
		return (NULL);
	while (s2[i] && i < x)
		new_s[j++] = s2[i++];
	i = 0;
	while (s1[i])
		new_s[j++] = s1[i++];
	i = x;
	while (s2[i])
		new_s[j++] = s2[i++];
	free_multiple(s1, s2, 1, 1);
	return (new_s);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_s == NULL)
		return (NULL);
	while (s1[i])
	{
		new_s[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new_s[j] = s2[i];
		i++;
		j++;
	}
	return (new_s);
}
