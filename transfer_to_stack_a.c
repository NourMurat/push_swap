/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:11:38 by numussan          #+#    #+#             */
/*   Updated: 2022/11/06 00:54:40 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_decision(t_stack **a, t_stack **b, t_stack *best)
{
	if (best->rotA != -1)
	{
		while (best->rotA-- > 0)
			ra(a, 1);
	}
	else
	{
		while (best->revrotA-- > 0)
			rra(a, 1);
	}
	if (best->rotB != -1)
	{
		while (best->rotB-- > 0)
			rb(b, 1);
	}
	else
	{
		while (best->revrotB-- > 0)
			rrb(b, 1);
	}
	pa(a, b);
}

t_stack		*get_best_node(t_stack *b)
{
	t_stack *tmp;
	t_stack *best;

	tmp = b;
	best = b;
	while (tmp != NULL)
	{
		if (tmp->best < best->best)
			best = tmp;
		tmp = tmp->next;
	}
	return (best);
}

void	choose_best_solution(t_stack **b)
{
	t_stack *tmp;
	int	min_B;
	int	min_A;
	
	tmp = *b;
	while (tmp)
	{
		if (tmp->rotB <= tmp->revrotB)
		{
			min_B = tmp->rotB;
			tmp->revrotB = -1;
		}
		else
		{
			min_B = tmp->revrotB;
			tmp->rotB = -1;
		}
		if (tmp->rotA <= tmp->revrotA)
		{
			min_A = tmp->rotA;
			tmp->revrotA = -1;
		}
		else
		{
			min_A = tmp->revrotA;
			tmp->rotA = -1;
		}
		tmp->best = min_B + min_A;
		tmp = tmp->next;
	}
}

void	count_moves_a(t_stack **a, t_stack **b)
{
	int		i;
	int		prevA;
	t_stack	*tmpA;
	t_stack *tmpB;
	int		size;

	tmpB = *b;
	size = op_stack_size(a);
	while (tmpB)
	{
		tmpA = *a;
		i = 0;
		prevA = op_find_last(*a)->nbr;
		while (tmpA)
		{
			if (prevA < tmpB->nbr && tmpA->nbr > tmpB->nbr)
			{
				tmpB->rotA = i;
				tmpB->revrotA = size - i;
			}
			i++;
			prevA = tmpA->nbr;
			tmpA = tmpA->next;
		}
		tmpB = tmpB->next;
	}
}

void	count_moves_b(t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = *b;
	size = op_stack_size(b);
	while (tmp)
	{
		tmp->rotB = i;
		tmp->revrotB = size - i;
		i++;
		tmp = tmp->next;
	}
}

// void	reset_i(t_stack **a, t_stack **b)
// {
// 	t_stack	*temp1;
// 	t_stack	*temp2;
// 	int		i;

// 	temp1 = *a;
// 	temp2 = *b;
// 	i = 0;
// 	while (temp1 != NULL)
// 	{
// 		temp1->i = i++;
// 		temp1 = temp1->next;
// 	}
// 	i = 0;
// 	while (temp2 != NULL)
// 	{
// 		temp2->i = i++;
// 		temp2 = temp2->next;
// 	}
// }

void    transfer_to_stack_a(t_stack **a, t_stack **b)
{
	// reset_i(a, b);
	// count_moves(a, b);
	count_moves_b(b);
	// printf("============STACK B=========\n");
	// ft_print_stack(b);
	count_moves_a(a, b);
	// printf("============STACK A=========\n");
	// ft_print_stack(a);
	choose_best_solution(b);
	// printf("BEST SOLUTION\n");
	// printf("============STACK A=========\n");
	// ft_print_stack(a);
	// printf("============STACK B=========\n");
	// ft_print_stack(b);
	// printf("\n");
	process_decision(a, b, get_best_node(*b));
	// printf("\n\n============STACK A=========\n");
	// ft_print_stack(a);
	// printf("\n\n============STACK B=========\n");
	// ft_print_stack(b);
	// printf("\n\n\n");
}








