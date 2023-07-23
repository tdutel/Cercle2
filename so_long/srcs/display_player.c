/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:11:44 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 12:04:32 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_player_up(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	g->player.pos.x = i - 1;
	g->player.pos.y = j;
	ptr = mlx_xpm_file_to_image(g->mlx, PLAYER_BACK, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, (i - 1) * h);
	ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	if (g->map[i][j] != 'E')
		g->map[i][j] = '0';
}

void	display_player_down(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	g->player.pos.x = i + 1;
	g->player.pos.y = j;
	ptr = mlx_xpm_file_to_image(g->mlx, PLAYER_FRONT, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, (i + 1) * h);
	ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	if (g->map[i][j] != 'E')
		g->map[i][j] = '0';
}

void	display_player_left(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	g->player.pos.x = i;
	g->player.pos.y = j - 1;
	ptr = mlx_xpm_file_to_image(g->mlx, PLAYER_LEFT, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, (j - 1) * w, i * h);
	ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	if (g->map[i][j] != 'E')
		g->map[i][j] = '0';
}

void	display_player_right(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	g->player.pos.x = i;
	g->player.pos.y = j + 1;
	ptr = mlx_xpm_file_to_image(g->mlx, PLAYER_RIGHT, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, (j + 1) * w, i * h);
	ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	if (g->map[i][j] != 'E')
		g->map[i][j] = '0';
}

void	display_direction(t_game *g, int i, int j, char *str)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	ptr = mlx_xpm_file_to_image(g->mlx, str, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
}
