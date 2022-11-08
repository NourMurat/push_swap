/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:04 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 10:27:15 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err_free_split_and_list(t_stack **head, char **str, char *s)
{
	ft_free_after_split(str);
	ft_free_stack(head);
	ft_error(s);
}

void	ft_free_after_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

void	ft_free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_print_stack(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	while (temp != NULL)
	{
		printf("nbr: %d   ra: %d   rra: %d  rb: %d    rrb: %d\n",
			temp->nbr, temp->rotA, temp->revrotA, temp->rotB, temp->revrotB);
		// printf("%d\n", temp->pos);
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
	ft_check_dubl(&a);
	ft_sorting(&a);
	ft_free_stack(&a);
	return (0);
}
