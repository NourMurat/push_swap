/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_revrotates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:49:05 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 08:49:41 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **head_a, int flag)
{
	t_stack	*last;
	t_stack	*prelast;

	last = op_find_last(*head_a);
	prelast = op_find_prelast(*head_a);
	last->next = *head_a;
	prelast->next = NULL;
	*head_a = last;
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **head_b, int flag)
{
	t_stack	*last;
	t_stack	*prelast;

	last = op_find_last(*head_b);
	prelast = op_find_prelast(*head_b);
	last->next = *head_b;
	prelast->next = NULL;
	*head_b = last;
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	ft_printf("rrr\n");
}
