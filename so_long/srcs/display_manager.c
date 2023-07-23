/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:19:42 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/26 18:02:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_game(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g->map_size.x)
	{
		while (j < g->map_size.y)
		{
			if (is_corner(g, i, j) == 1)
				display_corner(g, i, j);
			else if (i == 0 || i == g->map_size.x - 1)
				display_wall_updown(g, i, j);
			else if (j == 0 || j == g->map_size.y - 1)
				display_wall_side(g, i, j);
			else
				display_in(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	display_in(t_game *g, int i, int j)
{
	if (g->map[i][j] == '1')
		display_block(g, i, j);
	else if (g->map[i][j] == '0')
		display_floor(g, i, j);
	else if (g->map[i][j] == 'C')
		display_collect(g, i, j);
	else if (g->map[i][j] == 'P')
		display_starpos(g, i, j);
	else if (g->map[i][j] == 'E')
		display_exit(g, i, j);
}

int	is_corner(t_game *g, int i, int j)
{
	if ((i == 0 && j == 0) || (i == 0 && j == g->map_size.y - 1)
		|| (i == g->map_size.x - 1 && j == 0)
		|| (i == g->map_size.x - 1 && j == g->map_size.y - 1))
		return (1);
	return (0);
}
