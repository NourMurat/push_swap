/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:26:25 by numussan          #+#    #+#             */
/*   Updated: 2022/10/30 05:10:10 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    presort_3(t_stack **a)
{
	int	one;
	int	two;
	int	three;
	
	one = (*a)->nbr;
	two = (*a)->next->nbr;
	three = (*a)->next->next->nbr;
	if (one > two && one > three && two > three)
		sa(a, 1);
	else if (two > one && two > three  && three > one)
		sa(a, 1);
	else if (three > one && three > two && one > two)
		sa(a, 1);
}



int	*insertion_sort_arr(t_stack **a, int *arr)
{
	int	i;
	int	key;
	int	j;
	
	i = 1;
	while (i < (*a)->size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
		i++;
	}
	return (arr);
}

int	*fill_arr(t_stack **a, int *arr)
{
	int	i;
	t_stack	*tmp;
	
	i = 0;
	tmp = *a;
	while (i < (*a)->size)
	{
		arr[i++] = tmp->nbr;
		tmp = tmp->next;
	}
	return (arr);
}

int	preparation_for_big_sorting(t_stack **a)
{
	int	*arr;
	// int	min;
    // int	max;
	// int med;
	int i = 0;

	if (!(arr = malloc(sizeof(int) * (*a)->size)))
		return (0);
	arr = insertion_sort_arr(a, fill_arr(a, arr));
	while (i < (*a)->size)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	// find_min_max_med(arr, &min, &max, &med);
	
	
	return (1);
}