/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:13:20 by numussan          #+#    #+#             */
/*   Updated: 2022/10/22 01:01:07 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_list(int nbr)
{
	// (void) nbr;
	ft_printf("%d\n", nbr);
	// a->nbr = nbr;
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

void	ft_parsing(char	*s)
{
	int i;
	char **several_nbrs;

	i = 0;
	if (strchr(s, ' '))
	{
		several_nbrs = ft_split(s, ' ');
		while (several_nbrs[i])
		{
			add_nbr_to_list(several_nbrs[i]);
			i++;
		}
	}
	else
		add_nbr_to_list(s);
}

// void	ft_check_dublication(int argc, char **new_argv)
// {
// 	int	i;
// 	int j;

// 	i = 0;
// 	if (argc > 2)
// 	{
// 		while (new_argv[i] != NULL)
// 		{
// 			j = 1;
// 			while (new_argv[i + j] != NULL)
// 			{
// 				if ((ft_strcmp(new_argv[i], new_argv[i + j])) == 0)
// 					ft_error("ERROR! Numbers are dublicated!\n");
// 				j++;
// 			}
// 			ft_printf("%s\n", new_argv[i]);
// 			i++;
// 		}
// 	}
// }

// char	**ft_separate_string(int argc, char **argv)
// {
// 	int		i;
// 	char	*new_arr;
// 	char	*temp_new_arr;

// 	i = 1;
// 	new_arr = "";
// 	temp_new_arr = NULL;
// 	while (i < argc)
// 	{
// 		temp_new_arr = new_arr;
// 		new_arr = ft_strjoin(new_arr, argv[i]);
// 		if (i > 1)
// 			free(temp_new_arr);
// 		i++;
// 	}
// 	return(ft_split(new_arr, ' '));
// }

int	main(int argc, char **argv)
{
	// t_stack	*a;
	// t_stack	*b;
	// t_stack	cursor;
	int	i;
	// char **new_argv;

	// new_argv = NULL;
	// *a = malloc(sizeof(t_stack *a));
	// if (!*a)
	// 	ft_error("ERROR! Memmory didn`t allocate");
	// new_argv = ft_separate_string(argc, argv);
	if (argc <= 1)
		ft_error("ERROR! Wrong start command!\n");
	// ft_check_dublication(argc, new_argv);
	i = 1;
	while(i < argc)
	{
		ft_parsing(argv[i]);
		i++;
	}
	return (0);
}
