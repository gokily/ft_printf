/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:05:26 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 13:05:28 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_size_tlen_base(size_t n, size_t base)
{
	size_t	i;
	size_t	power;

	i = 1;
	power = base;
	while ((n / power) != 0)
	{
		i++;
		power *= base;
	}
	return (i);
}
