/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:22:48 by numussan          #+#    #+#             */
/*   Updated: 2022/11/03 00:49:49 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_check_sorted_or_presorted(t_stack **a)
{
	t_stack *tmp;
	int	count;

	tmp = *a;
	count = 0;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			count++;
		tmp = tmp->next;
	}
	if (count > 1 || (tmp->nbr > (*a)->nbr && count > 0))
		return (1); //not presort
	if (count == 1)
		return (2); //presort
	return (0); //sort
}

void    op_delete_head(t_stack **head)
{
    t_stack *temp;
    
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void	op_push_to_head(t_stack **head, int nbr)
{
	t_stack	*new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error("<<<<< ERROR! Memmory didn`t allocate! >>>>>\n");
	new_node->nbr = nbr;
	new_node->pos = 0;
	new_node->next = *head;
	new_node->rotA = 0;
	new_node->revrotA = 0;
	new_node->rotB = 0;
	new_node->revrotB = 0;
	new_node->best = 0;
	*head = new_node;
}

int	op_stack_size(t_stack **head)
{
	t_stack	*tmp;
	int	count;
	
	tmp = *head;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_stack	*op_find_prelast(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*op_find_last(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	op_fill_list_a(t_stack **a, int nbr)
{
	t_stack	*new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error("<<<<< ERROR! Memmory didn`t allocate! >>>>>\n");
	new_node->nbr = nbr;
	new_node->pos = 0;
	new_node->revrotA = 0;
	new_node->rotB = 0;
	new_node->revrotB = 0;
	new_node->best = 0;
	new_node->next = NULL;
	if (!*a)
		*a = new_node;
	else
		op_find_last(*a)->next = new_node;
}
