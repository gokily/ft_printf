/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:07:48 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 13:07:50 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_longlonglen_base(long long n, int base)
{
	size_t		i;
	long long	power;

	i = 1;
	power = n < 0 ? -base : base;
	while ((n / power) != 0)
	{
		i++;
		power *= base;
	}
	return (i);
}
