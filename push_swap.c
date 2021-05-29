/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:04:45 by gbeco             #+#    #+#             */
/*   Updated: 2021/05/29 13:50:29 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	a;
	int		i;
	int		j;
	

	if (ac == 1)
		return (0);
	parthing(ac, av, &a);	
	if (verif_doubl(&a) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (a.size == 3)
		return (three_tri(&a));
	if (a.size == 5)
		return (five_tri(&a));
	if (a.size > 5)
		insertion_tri(&a);
	return (0);
}