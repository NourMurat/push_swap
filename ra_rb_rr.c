/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:19:22 by numussan          #+#    #+#             */
/*   Updated: 2022/10/29 02:55:28 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack **head_a, int flag)
{
	t_stack	*last;

	last = ft_find_last(*head_a);
	last->next = *head_a;
	*head_a = (*head_a)->next;
	last->next->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **head_b, int flag)
{
	t_stack	*last;

	last = ft_find_last(*head_b);
	last->next = *head_b;
	*head_b = (*head_b)->next;
	last->next->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	ft_printf("rr\n");
}

void    rra(t_stack **head_a, int flag)
{
	t_stack	*last;
	t_stack	*prelast;

	last = ft_find_last(*head_a);
	prelast = ft_find_prelast(*head_a);
	last->next = *head_a;
	prelast->next = NULL;
	*head_a = last;
	if (flag  == 1)
		ft_printf("rra\n");
}

void    rrb(t_stack **head_b, int flag)
{
	t_stack	*last;
	t_stack	*prelast;

	last = ft_find_last(*head_b);
	prelast = ft_find_prelast(*head_b);
	last->next = *head_b;
	prelast->next = NULL;
	*head_b = last;
	if (flag  == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	ft_printf("rrr\n");
}