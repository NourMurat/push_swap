/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:58:08 by numussan          #+#    #+#             */
/*   Updated: 2022/09/21 23:10:07 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int		i;
	int		positive;
	long long		number;

	i = 0;
	positive = 1;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			positive = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = (number * 10) + str[i] - 48;
		i++;
	}
	return (number * positive);
}
