/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:03:37 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 09:04:04 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sorting_5(t_stack **a, t_stack **b)
{
	int	best_pos;

	best_pos = 0;
	fill_pos(a);
	push_min_to_b(a, b, find_min_in_stack(a, &best_pos), best_pos);
	sorting_4(a, b);
	pa(a, b);
}

void	push_min_to_b(t_stack **a, t_stack **b, int min, int best_pos)
{
	int		size;
	int		best_rev;
	t_stack	*tmp;

	tmp = *a;
	size = op_stack_size(a);
	best_rev = size - best_pos;
	while (tmp)
	{
		if (tmp->nbr == min && best_pos <= (size / 2))
		{
			while (best_pos--)
				ra(a, 1);
			pb(a, b);
			break ;
		}
		else if ((tmp->nbr == min && best_pos > (size / 2)))
		{
			while (best_rev--)
				rra(a, 1);
			pb(a, b);
			break ;
		}
		tmp = tmp->next;
	}
}

int	find_min_in_stack(t_stack **a, int *best_pos)
{
	int		min;
	t_stack	*tmp;

	tmp = *a;
	min = tmp->nbr;
	*best_pos = tmp->pos;
	while (tmp->next)
	{
		if (tmp->next->nbr < min)
		{
			min = tmp->next->nbr;
			*best_pos = tmp->next->pos;
			// printf("%d\n", *best_pos);
		}
		tmp = tmp->next;
	}
	return (min);
}

void	fill_pos(t_stack **a)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->pos = count++;
		// printf("%d\n", tmp->pos);
		tmp = tmp->next;
	}
}

void	sorting_4(t_stack **a, t_stack **b)
{
	int	best_pos;

	best_pos = 0;
	fill_pos(a);
	push_min_to_b(a, b, find_min_in_stack(a, &best_pos), best_pos);
	sorting_3(a);
	pa(a, b);
}
