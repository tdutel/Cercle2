/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:18:21 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/17 11:29:21 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(int argc, char **argv)
{
	int				i;
	long long int	arg;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigit_space(argv[i]) == 1)
			return (1);
		arg = ft_atoi_long(argv[i]);
		if (arg < INT_MIN || arg > INT_MAX)
			return (ft_putendl_fd("Error", STDERR_FILENO), 1);
		i++;
	}
	if (ft_is_already_in(argv) == 1)
		return (1);
	return (0);
}

int	ft_is_already_in(char **argv)
{
	int		i;
	int		j;
	int		argi;
	int		argj;

	i = 1;
	while (argv[i])
	{
		argi = ft_atoi_long(argv[i]);
		j = i + 1;
		i++;
		while (argv[j])
		{
			argj = ft_atoi_long(argv[j++]);
			if (argi == argj)
				return (ft_putendl_fd("Error", STDERR_FILENO), 1);
		}
	}
	return (0);
}

int	ft_isdigit_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
				|| ((str[i] == '+' || str[i] == '-')
					&& (str[i + 1] >= '0' && str[i + 1] <= '9')
					&& (!(str[i - 1] >= '0' && str[i - 1] <= '9')))))
			return (ft_putendl_fd("Error", STDERR_FILENO), 1);
		i++;
	}
	return (0);
}

int	is_in(t_stack *a, int nb)
{
	while (a != NULL)
	{
		if ((a)->content == nb)
			return (1);
		a = (a)->next;
	}
	return (0);
}

int	ft_int_list(char *list, t_stack **a)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (list[i])
	{
		while (list[0] == ' ')
			list = list + 1;
		if (list[0] == '\0')
			break ;
		while (list[index] != ' ' && list[index] != '\0')
			index++;
		if (is_in(*a, ft_atoi_long(list)) == 1)
			return (free_stack(*a), 0);
		if (ft_atoi_long(list) < INT_MIN || ft_atoi_long(list) > INT_MAX)
			return (free_stack(*a), 0);
		ft_int_add_back(a, ft_intstack_new(ft_atoi_long(list)));
		list = list + index;
		index = 0;
	}
	if ((*a) == NULL || (*a)->next == NULL)
		free_stack_exit(*a);
	return (1);
}
