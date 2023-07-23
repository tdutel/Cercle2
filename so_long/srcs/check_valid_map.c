/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:06:42 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 15:14:59 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	fill_map(map, x + 1, y);
	fill_map(map, x, y + 1);
	fill_map(map, x - 1, y);
	fill_map(map, x, y - 1);
}

void	check_map_solvability(t_game game)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (game.map_size.x + 1));
	while (game.map[i])
	{
		map[i] = ft_strdup(game.map[i]);
		i++;
	}
	map[i] = NULL;
	fill_map(map, 1, 1);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'P')
			|| ft_strchr(map[i], 'E'))
			ft_error_map(6);
		i++;
	}
	free_map(map);
}
