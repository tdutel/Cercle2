/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:56:05 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 13:58:03 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *g)
{
	if (g->map[g->player.pos.x - 1][g->player.pos.y] != '1')
	{
		if (g->map[g->player.pos.x - 1][g->player.pos.y] == 'C')
		{
			g->collectible--;
			display_player_up(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
		else if ((g->map[g->player.pos.x - 1][g->player.pos.y] == 'E')
		&& (g->collectible == 0))
		{	
			display_player_up(g, g->player.pos.x, g->player.pos.y);
			ft_exit(g);
		}
		else
		{
			display_player_up(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
	}
	else
		move_direction(g, g->player.pos.x, g->player.pos.y, 'w');
}

void	move_down(t_game *g)
{
	if (g->map[g->player.pos.x + 1][g->player.pos.y] != '1')
	{
		if (g->map[g->player.pos.x + 1][g->player.pos.y] == 'C')
		{
			g->collectible--;
			display_player_down(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
		else if (g->map[g->player.pos.x + 1][g->player.pos.y] == 'E'
			&& g->collectible == 0)
		{
			display_player_down(g, g->player.pos.x, g->player.pos.y);
			ft_exit(g);
		}
		else
		{
			display_player_down(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
	}
	else
		move_direction(g, g->player.pos.x, g->player.pos.y, 's');
}

void	move_left(t_game *g)
{
	if (g->map[g->player.pos.x][g->player.pos.y - 1] != '1')
	{
		if (g->map[g->player.pos.x][g->player.pos.y - 1] == 'C')
		{
			g->collectible--;
			display_player_left(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
		else if (g->map[g->player.pos.x][g->player.pos.y - 1] == 'E'
			&& g->collectible == 0)
		{
			display_player_left(g, g->player.pos.x, g->player.pos.y);
			ft_exit(g);
		}
		else
		{
			display_player_left(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
	}
	else
		move_direction(g, g->player.pos.x, g->player.pos.y, 'a');
}

void	move_right(t_game *g)
{
	if (g->map[g->player.pos.x][g->player.pos.y + 1] != '1')
	{
		if (g->map[g->player.pos.x][g->player.pos.y + 1] == 'C')
		{
			g->collectible--;
			display_player_right(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
		else if (g->map[g->player.pos.x][g->player.pos.y + 1] == 'E'
			&& g->collectible == 0)
		{
			display_player_right(g, g->player.pos.x, g->player.pos.y);
			ft_exit(g);
		}
		else
		{
			display_player_right(g, g->player.pos.x, g->player.pos.y);
			g->count++;
			ft_printf("%d, ", g->count);
		}
	}
	else
		move_direction(g, g->player.pos.x, g->player.pos.y, 'd');
}

void	move_direction(t_game *g, int i, int j, char c)
{
	if (c == 'w')
	{
		display_direction(g, i, j, PLAYER_BACK);
	}
	if (c == 'a')
	{
		display_direction(g, i, j, PLAYER_LEFT);
	}
	if (c == 's')
	{
		display_direction(g, i, j, PLAYER_FRONT);
	}
	if (c == 'd')
	{
		display_direction(g, i, j, PLAYER_RIGHT);
	}
}
