/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:21:36 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 14:48:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_map(int i)
{
	if (i == -4)
		ft_putendl_fd("Error : To many arguments", 1);
	if (i == -3)
		ft_putendl_fd("Error : To few arguments", 1);
	if (i == -2)
		ft_putendl_fd("Error : No file found", 1);
	if (i == -1)
		ft_putendl_fd("Error : Map is not using .ber extension", 1);
	if (i == 0)
		ft_putendl_fd("Error : Wrong size", 1);
	if (i == 1)
		ft_putendl_fd("Error : Missing wall on the edge of the map", 1);
	if (i == 2)
		ft_putendl_fd("Error : Wrong parameter in map", 1);
	if (i == 3)
		ft_putendl_fd("Error : To few collectible ", 1);
	if (i == 4)
		ft_putendl_fd("Error : 1 starting position", 1);
	if (i == 5)
		ft_putendl_fd("Error : 1 exit", 1);
	if (i == 6)
		ft_putendl_fd("Error : Map is not solvable", 1);
	exit(1);
}

int	ft_exit(t_game *game)
{
	int	i;

	i = 0;
	if (is_win(*game))
	{
		game->count++;
		ft_printf("and %d\n", game->count);
		ft_printf ("\n\n+ - - - - - - - - +\n");
		ft_printf ("|       WIN       |\n");
		ft_printf ("+ - - - - - - - - +\n");
		ft_printf("\n\nmove count : %d\n\n", game->count);
	}
	free_map(game->map);
	exit(0);
	return (0);
}

int	is_win(t_game g)
{
	return (g.collectible == 0 && g.map[g.player.pos.x][g.player.pos.y] == 'E');
}
