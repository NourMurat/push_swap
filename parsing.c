/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:53:53 by numussan          #+#    #+#             */
/*   Updated: 2022/11/07 05:49:11 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_is_it_number(t_stack **a, char **str, char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		if (!s[1])
			ft_err_free_split_and_list(a, str, "<<<<< ERROR! Only one sign - or +! >>>>>\n");
	i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			ft_err_free_split_and_list(a, str, "<<<<< ERROR! Non numeric character! >>>>>\n");
		i++;
	}
	if (i > 11)
		ft_err_free_split_and_list(a, str, "<<<<< ERROR! Overflow of number! >>>>>\n");
}

void	ft_add_numbers_to_stack_a(t_stack **a, char **str, char *s)
{
	long long	nbr;

	ft_is_it_number(a, str, s);
	nbr = ft_atoi(s);
	if (!(nbr >= -2147483648 && nbr <= 2147483647))
		ft_err_free_split_and_list(a, str, "<<<<< ERROR! Number is not in the range of int type! >>>>>\n");
	op_fill_list_a(a, (int)nbr);
}

void	ft_check_dublication(char **s)
{
	int	i;
	int j;

	i = 0;
	while (s[i] != NULL)
	{
		j = 1;
		while (s[i + j] != NULL)
		{
			if ((ft_strcmp(s[i], s[i + j])) == 0)
			{
				ft_free_after_split(s);
				ft_error("<<<<< ERROR! The numbers are dublicated! >>>>>\n");
			}
			j++;
		}
		i++;
	}
}

char	**ft_separate_string(int argc, char **s)
{
	int		i;
	char	*new_arr;
	char	*temp;
	char	**separate_string;

	i = 1;
	new_arr = "";
	temp = NULL;
	while (i < argc)
	{
		temp = new_arr;
		new_arr = ft_strjoin(new_arr, s[i]);
		if (i > 1)
			free(temp);
		i++;
	}
	separate_string = ft_split(new_arr, ' ');
	free(new_arr);
	return (separate_string);
}

void	ft_check_spaces(char **s)
{
	int	i;
	int	j;
	int	sp;

	i = 0;
	while (s[i])
	{
		j = 0;
		sp = 0;
		while (s[i][j])
		{
			// if (s[i][j] == '\0')
			// 	ft_error("<<<<< ERROR! Empty argument! >>>>>\n");
			if (s[i][j] == ' ' || (s[i][j] >= 9 && s[i][j] <= 13))
				sp++;
			j++;
		}
		if (sp == j)
			ft_error("<<<<< ERROR! Only spaces! >>>>>\n");
		i++;
	}
}

void	ft_parsing_and_fill_list_a(int argc, char **s, t_stack **a)
{
	int		i;
	char	**separate_nbrs;

	i = 0;
	if (argc <= 1)
		ft_error("");
	ft_check_spaces(s);
	separate_nbrs = ft_separate_string(argc, s);
	if (argc > 2)
		ft_check_dublication(separate_nbrs);
	while(separate_nbrs[i] != NULL)
	{
		ft_add_numbers_to_stack_a(a, separate_nbrs, separate_nbrs[i]);
		i++;
	}
	ft_free_after_split(separate_nbrs);
}
