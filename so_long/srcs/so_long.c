/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:49:36 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/28 10:29:48 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/assets_path.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc < 2)
		ft_error_map (-3);
	if (argc > 2)
		ft_error_map (-4);
	ft_read(argv[1], &g);
	ft_parsing(&g, argv[1]);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.map_size.y * 32,
			g.map_size.x * 32, "so_long");
	display_game(&g);
	mlx_hook(g.win, ON_DESTROY, 0, ft_exit, &g);
	mlx_hook(g.win, ON_KEYDOWN, 2, key_event, &g);
	mlx_loop(g.mlx);
	return (0);
}

int	key_event(int key, t_game *param)
{
	if (key == esc || key == q)
		ft_exit(param);
	else if (key == w || key == up)
		move_up(param);
	else if (key == s || key == down)
		move_down(param);
	else if (key == a || key == left)
		move_left(param);
	else if (key == d || key == right)
		move_right(param);
	if (param->collectible == 0)
		display_exit(param, param->exit.x, param->exit.y);
	return (0);
}

void	ft_read(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*gnl;

	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	(*game).map_size.x = 0;
	while (gnl)
	{
		(*game).map_size.x++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	(*game).map = malloc(sizeof (char *) * ((*game).map_size.x + 1));
	if (!(*game).map)
		exit(0);
	i = 0;
	fd = open(file, O_RDONLY);
	(*game).map[0] = get_next_line(fd);
	(*game).map_size.y = ft_strlen_no_nl((*game).map[0]);
	while (++i < (*game).map_size.x)
		(*game).map[i] = get_next_line(fd);
	(*game).map[i] = NULL;
}
