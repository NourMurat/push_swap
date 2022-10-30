/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:04 by numussan          #+#    #+#             */
/*   Updated: 2022/10/30 04:59:56 by numussan         ###   ########.fr       */
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

void	ft_error(char *s)
{
	ft_printf("%s", s);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	ft_parsing_and_fill_list_a(argc, argv, &a);
	ft_count_stack_a_and_sort(&a);
	// ft_print_stack(a);

	// ft_printf("\n");
	// ra(&a, 1);
	// ft_print_stack(a);
	// rra(&a, 1);
	// ft_printf("\n");
	// ft_print_stack(a);
	return (0);
}
