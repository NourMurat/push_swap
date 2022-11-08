/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 04:01:12 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 08:51:29 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	temp;

	temp = 0;
	if (*a && (*a)->next)
	{
		temp = (*a)->nbr;
		(*a)->nbr = (*a)->next->nbr;
		(*a)->next->nbr = temp;
		if (flag)
			ft_printf("sa\n");
	}
	else
		ft_printf("<<<<< There is only 1 or no elements in stack A! >>>>>");
}

void	sb(t_stack **b, int flag)
{
	int	temp;

	temp = 0;
	if (*b && (*b)->next)
	{
		temp = (*b)->nbr;
		(*b)->nbr = (*b)->next->nbr;
		(*b)->next->nbr = temp;
		if (flag)
			ft_printf("sb\n");
	}
	else
		ft_printf("<<<<< There is only 1 or no elements in stack B! >>>>>");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b)
	{
		op_push_to_head(a, (*b)->nbr);
		op_delete_head(b);
		ft_printf("pa\n");
	}
	else
		ft_printf("<<<<< The stack B is empty! >>>>>");
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a)
	{
		op_push_to_head(b, (*a)->nbr);
		op_delete_head(a);
		ft_printf("pb\n");
	}
	else
		ft_printf("<<<<< The stack A is empty! >>>>>");
}
