/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:26:11 by numussan          #+#    #+#             */
/*   Updated: 2022/10/29 23:42:12 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_3(t_stack **a)
{
	int one = (*a)->nbr;
	int two = (*a)->next->nbr;
	int three = (*a)->next->next->nbr;
	
	if (three > one && three > two && one > two)
		sa(a, 1);
	if (two > one && two > three && one > three)
		rra(a, 1);
	if (two > one && two > three  && three > one)
	{
		sa(a, 1);
		ra(a, 1);
	}
	if (one > two && one > three && three > two)
		ra(a, 1);
	if (one > two && one > three && two > three)
	{
		ra(a, 1);
		sa(a, 1);
	}
}