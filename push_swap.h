/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:05:06 by gbeco             #+#    #+#             */
/*   Updated: 2021/05/29 10:31:36 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

#include <stdio.h> //printf

typedef struct s_elem
{
	int				n;
	struct s_elem	*next;
	struct s_elem	*prev;	
}	t_elem;

typedef struct s_stack
{
	t_elem	*first;
	int		size;
}	t_stack;

void	init_stack(t_stack *stack);
int		insert_elem_list(t_stack *stack, int n);
void	print_stack(t_stack *stack);
int		verif_doubl(t_stack *stack);

void	swap(t_stack *stack);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	parthing(int ac, char **av, t_stack *a);

int		three_tri(t_stack *a);
int		five_tri(t_stack *a);
int		insertion_tri(t_stack *a);
void	put_min_high(t_stack *a);

#endif