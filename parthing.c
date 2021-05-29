/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:35:02 by gbeco             #+#    #+#             */
/*   Updated: 2021/05/29 13:50:24 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parthing(int ac, char **av, t_stack *a)
{
	int i;
	int	j;
	int	nbr;
	int	signe;

	init_stack(a);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		signe = 1;
		while (av[i][j])
		{
			nbr = 0;
			while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			if (av[i][j]== '-')
			{
				signe = -1;
				j++;
			}
			while (av[i][j] >= '0' && av[i][j] <= '9')
			{
				nbr = nbr * 10 + (av[i][j] - 48);
				j++;
			}
			insert_elem_list(a, nbr * signe);
		}
	}
	
}