/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:26:11 by numussan          #+#    #+#             */
/*   Updated: 2022/11/07 03:55:45 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    presort_3(t_stack **a)
{
	int	one;
	int	two;
	int	three;
	
	one = (*a)->nbr;
	two = (*a)->next->nbr;
	three = (*a)->next->next->nbr;
	if (one > two && one > three && two > three)
		sa(a, 1);
	else if (two > one && two > three  && three > one)
		sa(a, 1);
	else if (three > one && three > two && one > two)
		sa(a, 1);
	// printf("The 3 numbers in stack A are pre-sorted!\n"); // remove it before submit
}

void    sorting_3(t_stack **a)
{
	int	one;
	int	two;
	int	three;
	
	one = (*a)->nbr;
	two = (*a)->next->nbr;
	three = (*a)->next->next->nbr;
	if (one > two && one > three && two > three)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (one > two && one > three && three > two)
		ra(a, 1);
	else if (two > one && two > three && one > three)
		rra(a, 1);
	else if (two > one && two > three  && three > one)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (three > one && three > two && one > two)
		sa(a, 1);
}

void	ft_sorting(t_stack **a)
{
	int	size;
	
	size = op_stack_size(a);
	if (size == 2 && (*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
	if (size == 3)
		sorting_3(a);
	if (size > 3)
		preparation_for_big_sorting(a);
}
