/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_edge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:17:31 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 14:51:51 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_corner(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	if (i == 0 && j == 0)
		ptr = mlx_xpm_file_to_image(g->mlx, CORNER_TL, &w, &h);
	else if (i == 0 && j == g->map_size.y - 1)
		ptr = mlx_xpm_file_to_image(g->mlx, CORNER_TR, &w, &h);
	else if (i == g->map_size.x - 1 && j == 0)
		ptr = mlx_xpm_file_to_image(g->mlx, CORNER_BL, &w, &h);
	else if (i == g->map_size.x - 1 && j == g->map_size.y - 1)
		ptr = mlx_xpm_file_to_image(g->mlx, CORNER_BR, &w, &h);
	else
		return ;
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * h, i * w);
}

void	display_wall_updown(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, WALL_TB, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * h, i * w);
}

void	display_wall_side(t_game *g, int i, int j)
{
	int		h;
	int		w;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->mlx, WALL_LR, &w, &h);
	mlx_put_image_to_window(g->mlx, g->win, ptr, j * h, i * w);
}
