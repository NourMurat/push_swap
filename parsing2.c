/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:52:08 by numussan          #+#    #+#             */
/*   Updated: 2022/10/29 21:20:40 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_it_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			ft_error("<<<<< ERROR! Non numeric character! >>>>>\n");
		i++;
	}
}

void	ft_add_mubmers_to_stack_a(t_stack **a, char *s)
{
	long long	nbr;

	ft_is_it_number(s);
	nbr = ft_atoi(s);
	if (nbr < -2147483648 || nbr > 2147483647)
		ft_error("<<<<< ERROR! Number is not in the range of int type! >>>>>\n");
	ft_fill_list_a(a, (int)nbr);
}
