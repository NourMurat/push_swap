/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:04 by numussan          #+#    #+#             */
/*   Updated: 2022/10/29 23:46:30 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}

int	ft_size_stack(t_stack **head)
{
	int	count;
	
	count = 0;
	while (*head)
	{
		*head = (*head)->next;
		count++;
	}
	return (count);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;
	
	size = ft_size_stack(a);
	b = NULL; //remove it after
	if (size == 3)
		sort_3(a);
}

void	ft_error(char *s)
{
	ft_printf("%s", s);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	ft_parsing_and_fill_list_a(argc, argv, &a);
	// ft_sort(&a, &b);
	while (a)
	{
		ft_printf("%d\n", (a)->nbr);
		(a) = (a)->next;
	}
	// ft_print_stack(a);
	// ft_printf("\n");
	// ra(&a, 1);
	// ft_print_stack(a);
	// rra(&a, 1);
	// ft_printf("\n");
	// ft_print_stack(a);
	return (0);
}
