/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:25:19 by gbeco             #+#    #+#             */
/*   Updated: 2021/05/29 11:16:06 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->first->n;
	stack->first->n = stack->first->next->n;
	stack->first->next->n = tmp;
}

void	push(t_stack *a, t_stack *b)
{
	t_elem	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->first;
	a->first->prev->next = a->first->next;
	a->first->next->prev = a->first->prev;
	a->first = a->first->next;
	a->size--;

	if (b->size == 0)
		insert_elem_list(b, tmp->n);
	else
	{
		b->first->prev->next = tmp;
		b->first->next->prev = tmp;
		tmp->next = b->first;
		tmp->prev = b->first->prev;
		b->first = tmp;
		b->size++;
	}
}

void	rotate(t_stack *stack)
{
	stack->first = stack->first->next;
}

void	reverse_rotate(t_stack *stack)
{
	stack->first = stack->first->prev;
}