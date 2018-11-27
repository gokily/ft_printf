/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:28:20 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 16:51:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convertbase(int n, char *base)
{
	int		i;
	char	*nb;
	int		power;

	i = ft_inlen_base(n, strlen(base));
	i = n < 0 ? i + 1 : i;
	if (!(nb = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb[i] = '\0';
	i = n < 0 ? 1 : 0;
	if (n < 0)
		nb[0] = '-';
	power = n < 0 ? -base : base;
	while (n / power > 9)
		power *= base;
	while (power > 0)
	{
		nb[i] = n / power;
		power /= base;


