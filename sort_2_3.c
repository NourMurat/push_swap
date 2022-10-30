/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:26:11 by numussan          #+#    #+#             */
/*   Updated: 2022/10/30 05:07:41 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorting_2_3(t_stack **a)
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

void	ft_count_stack_a_and_sort(t_stack **a)
{
	(*a)->size = op_stack_size(a);
	if ((*a)->size == 2 && (*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
	if ((*a)->size == 3)
		sorting_2_3(a);
	if ((*a)->size > 3)
	{
		if (!(preparation_for_big_sorting(a)))
		{
			ft_error("<<<<< ERROR! Memmory didn`t allocate! >>>>>\n");
			return ;
		}
	}
}
