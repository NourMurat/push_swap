/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:04 by numussan          #+#    #+#             */
/*   Updated: 2022/09/23 21:40:58 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_list(int nbr)
{
	// t_stack	*new_nbr;
	
	// *new_nbr = (t_stack *)malloc(sizeof(t_stack));
	// a->nbr = nbr;
	// new_nbr->next = a;
	// a = new_nbr;
	ft_printf("%d\n", nbr);
}

void	ft_error(char *s)
{
	ft_printf("%s", s);
	exit (1);
}

void	check_is_it_nbr(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			ft_error("Non numeric character\n");
		i++;
	}
}

void	add_nbr_to_list(char *s)
{
	long long	nbr;

	nbr = 0;
	check_is_it_nbr(s);
	nbr = ft_atoi(s);
	if (nbr < -2147483648 || nbr > 2147483647)
		ft_error("Number is not in the range of int type\n");
	push_to_list((int)nbr);
}

void	ft_check_dublication(int argc, char **new_argv)
{
	int	i;
	int j;

	i = 0;
	if (argc > 2)
	{
		while (new_argv[i] != NULL)
		{
			j = 1;
			while (new_argv[i + j] != NULL)
			{
				if ((ft_strcmp(new_argv[i], new_argv[i + j])) == 0)
					ft_error("ERROR! Numbers are dublicated!\n");
				j++;
			}
			i++;
		}
	}
}

char	**ft_separate_string(int argc, char **argv)
{
	int		i;
	char	*new_arr;
	char	*temp_new_arr;

	i = 1;
	new_arr = "";
	temp_new_arr = NULL;
	while (i < argc)
	{
		temp_new_arr = new_arr;
		new_arr = ft_strjoin(new_arr, argv[i]);
		if (i > 1)
			free(temp_new_arr);
		i++;
	}
	return(ft_split(new_arr, ' '));
}

int	main(int argc, char **argv)
{
	// t_stack	*a;
	int	i;
	char **new_argv;
	int	ready_nbrs;

	ready_nbrs = 0;
	new_argv = NULL;
	if (argc <= 1)
		ft_error("ERROR! Wrong start command!\n");
	// *a = (t_stack *)malloc(sizeof(t_stack));
	// if (!*a)
	// 	ft_error("ERROR! Memmory didn`t allocate");
	new_argv = ft_separate_string(argc, argv);
	ft_check_dublication(argc, new_argv);
	i = 0;
	while(i <= argc)
	{
		add_nbr_to_list(new_argv[i]);
		i++;
	}
	return (0);
}
