/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:19:52 by gbeco             #+#    #+#             */
/*   Updated: 2021/05/29 13:56:30 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		three_tri(t_stack *a)
{
	if (a->first->n < a->first->next->n)
	{
		if (a->first->prev->n < a->first->n)
			write(1, "rra\n", 4);
		else if (a->first->next->n > a->first->prev->n)
			write(1, "sa\nra\n", 6);
	}
	else if (a->first->n < a->first->prev->n)
		write(1, "sa\n", 3);
	else if (a->first->next->n < a->first->prev->n)
		write(1, "ra\n", 3);
	else if (a->first->next->n > a->first->prev->n)
		write(1, "sa\nrra\n", 7);
	return (0);
}

int		five_tri(t_stack *a)
{
	write(1, "pb\npb\n", 6);
	three_tri(a);
	// ++++++++++++++++
	return (0);
}

void	put_min_high(t_stack *a)

{
	int		pos;
	int		min;
	int		i;
	t_elem	*elem;
	
	i = -1;
	min = a->first->n;
	elem = a->first;
	while (++i < a->size)
	{
		if (elem->n < min)
		{
			min = elem->n;
			pos = i + 1;
		}
		elem = elem->next;
	}
	if (pos <= a->size / 2)
	{
		while (--pos > 0)
		{
			write(1, "ra\n", 3);	
			rotate(a);
		}
	}
	else
	{
		while (pos++ <= a->size)
		{
			write(1,"rra\n", 4);
			reverse_rotate(a);
		}
	}

}

int		insertion_tri(t_stack *a)
{
	t_stack b;
	
	init_stack(&b);
	while(a->size > 1)
	{
		put_min_high(a);
		write(1, "pb\n", 3);
		push(a, &b);
	}
	
	while(b.size > 0)
	{
		write(1, "pa\n", 3);
		push(&b, a);
	}
	return (0);
}