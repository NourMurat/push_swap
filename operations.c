/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:22:48 by numussan          #+#    #+#             */
/*   Updated: 2022/10/29 23:47:43 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_list_a(t_stack **a, int nbr)
{
	t_stack	*new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error("<<<<< ERROR! Memmory didn`t allocate! >>>>>\n");
	new_node->nbr = nbr;
	new_node->next = NULL;
	if (*a)
		ft_find_last(*a)->next = new_node;
	else
		*a = new_node;
}

void	ft_push_to_head(t_stack **head, int nbr)
{
	t_stack	*new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error("<<<<< ERROR! Memmory didn`t allocate! >>>>>\n");
	new_node->nbr = nbr;
	new_node->next = *head;
	*head = new_node;
}

t_stack	*ft_find_last(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*ft_find_prelast(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

void    ft_delete_head(t_stack **head)
{
    t_stack *temp;
    
    temp = *head;
    *head = (*head)->next;
    free(temp);
}
