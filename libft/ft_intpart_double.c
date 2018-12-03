/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intpart_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:08:22 by gly               #+#    #+#             */
/*   Updated: 2018/12/03 09:39:36 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long ft_intpart_double(long double nb)
{
	long long	i;
	long double	power;

	i = 0;
	power = 1;
	while (nb / power >=  10 || nb / power <= -10)
		power *= 10;
	while (power >= 1)
	{
		i  = i * 10 + nb / power;
		while (nb >= power)
			nb -= power;
		power /= 10;
	}
	return (i);
}
