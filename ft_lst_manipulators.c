/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_manipulators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:20:09 by gly               #+#    #+#             */
/*   Updated: 2018/11/27 15:55:11 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_printlpf_all(t_lpf *lpf, int *ret)
{
	t_lpf	*elem;

	if (lpf)
	{
		elem = lpf;
		while (elem)
		{
			if (elem->type == 0)
			{
				ft_putstr(elem->str);
				*ret += elem->ret + 1;
				write(1, "\0", 1); // a quoi ca sert ?
			}
			else
			{
				ft_putstr(elem->str);
				*ret += elem->ret;
			}
			elem = elem->next;
		}
	}
}

t_lpf	*ft_lpfnew()
{
	t_lpf	*new;
	
	if (!(new = (t_lpf*)malloc(sizeof(t_lpf))))
		return (NULL);
	new->next = NULL;
	new->flag = 0;
	new->width = 0;
	new->acc = 0;
	new->ret = 0;
	new->type = -1;
	new->str = NULL;
	return (new);
}

t_lpf	**ft_lpf_push(t_lpf **lpf, t_lpf *node)
{
	t_lpf	*elem;

	if (*lpf != NULL)
	{
		elem = *lpf;
		while (elem->next)
			elem = elem->next;
		elem->next = node;
	}
	else
		*lpf = node;
	return (lpf);
}

void	ft_rmlpf_all(t_lpf *lst)
{
	t_lpf	*elem;
	t_lpf	*tmp;

	elem = NULL;
	if (lst != NULL)
	{
		elem = lst;
		while (elem != NULL)
		{
			ft_strdel(&(elem->str));
			tmp = elem;
			elem = elem->next;
			free(tmp);
		}
	}
}

void	ft_error(t_lpf *lst)
{
	ft_rmlpf_all(lst);
	ft_putstr("error\n");
	exit(0);
}
