/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:53:06 by gbeco             #+#    #+#             */
/*   Updated: 2021/05/29 11:13:53 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->size = 0;
}

int		insert_elem_list(t_stack *stack, int n)
{
	t_elem	*elem;
	t_elem	*tmp;

	elem = malloc(sizeof(t_elem));
	elem->n = n;
	if (stack->size == 0)
	{
		elem->next = elem;
		elem->prev = elem;
		stack->first = elem;
		stack->size++;
		return (0);
	}
	stack->first->prev = elem;
	tmp = stack->first;

	while (tmp->next != stack->first)
		tmp = tmp->next;
	elem->prev = tmp;
	tmp->next = elem;
	elem->next = stack->first;
	stack->size++;
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_elem	*elem;
	int		i;

	i = -1;
	elem = stack->first;
	printf("-----------\n");
	while (++i < stack->size)
	{
		printf("%d\n", elem->n);
		elem = elem->next;
	}
	printf("-----------\n");
}

int		verif_doubl(t_stack *stack)
{
	int		tab[stack->size];
	int		i;
	int		j;
	t_elem	*elem;

	elem = stack->first;
	tab[0] = 0;
	i = -1;
	while(++i < stack->size)
	{
		j = -1;
		while(++j < i)
		{
			if (tab[j] == elem->n)
				return (-1);
		}
		tab[j] = elem->n;
		elem = elem->next;
	}
	return (0);
}