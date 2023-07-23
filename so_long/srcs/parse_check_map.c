/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:04:41 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/26 17:20:10 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_collect_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->map_size.x)
	{
		while (j < g->map_size.y)
		{
			if (g->map[i][j] == 'C')
			{	
				g->collectible++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (g->collectible == 0)
		ft_error_map(3);
}

void	ft_check_starpos_map(t_game *g)
{
	int	i;
	int	j;
	int	cp;

	i = 0;
	j = 0;
	cp = 0;
	while (i < g->map_size.x)
	{
		while (j < g->map_size.y)
		{
			if (g->map[i][j] == 'P')
				cp++;
			j++;
		}
		j = 0;
		i++;
	}
	if (cp != 1)
		ft_error_map(4);
}

void	ft_check_exit_map(t_game *g)
{
	int	i;
	int	j;
	int	ce;

	i = 0;
	j = 0;
	ce = 0;
	while (i < g->map_size.x)
	{
		while (j < g->map_size.y)
		{
			if (g->map[i][j] == 'E')
				ce++;
			j++;
		}
		j = 0;
		i++;
	}
	if (ce != 1)
		ft_error_map(5);
}
