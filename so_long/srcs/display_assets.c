/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:36:02 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 14:51:41 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_block(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, DECOR_BIG_ROCK, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
}

void	display_floor(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
}

void	display_collect(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, COLLECTIBLE, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
}

void	display_starpos(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, PLAYER_FRONT, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	g->player.pos.x = i;
	g->player.pos.y = j;
}

void	display_exit(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	if (g->collectible == 0)
		ptr = mlx_xpm_file_to_image(g->mlx, EXIT, &w, &h);
	else
		ptr = mlx_xpm_file_to_image(g->mlx, BASIC_FLOOR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * w, i * h);
	g->exit.x = i;
	g->exit.y = j;
}
