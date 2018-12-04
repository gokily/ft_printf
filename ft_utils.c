/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:51:51 by gly               #+#    #+#             */
/*   Updated: 2018/12/04 15:37:35 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strspace(size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strzero(size_t len)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = '0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strinsert(char *s1, char *s2, int index)
{
	char	*output;
	int		i;
	int		j;

	output = NULL;
	if (!(output = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = -1;
	while (++i < index)
		output[i] = s1[i];
	j = -1;
	while (s2[++j])
		output[i + j] = s2[j];
	while (s1[i])
	{
		output[i + j] = s1[i];
		i++;
	}
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (output);
}
