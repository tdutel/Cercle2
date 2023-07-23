/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:17:06 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 15:21:31 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_parsing(t_game *game, char *file)
{
	ft_check_file_map(file);
	ft_check_size_map(game);
	ft_check_char_map(game);
	ft_check_wall_map(game);
	ft_check_collect_map(game);
	ft_check_starpos_map(game);
	ft_check_exit_map(game);
	check_map_solvability(*game);
}

void	ft_check_file_map(char *file)
{
	size_t	len;
	int		fd;

	len = ft_strlen(file) - 1;
	if (file[len - 3] != '.' || file[len - 2] != 'b'
		|| file[len - 1] != 'e' || file[len] != 'r')
		ft_error_map(-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_map(-2);
}

void	ft_check_size_map(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map_size.x)
	{
		if (ft_strlen_no_nl(g->map[i++]) != g->map_size.y)
			ft_error_map(0);
	}
}

void	ft_check_char_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->map_size.x)
	{
		while (j < g->map_size.y)
		{
			if (g->map[i][j] != '0' && g->map[i][j] != '1'
				&& g->map[i][j] != 'P' && g->map[i][j] != 'C'
					&& g->map[i][j] != 'E')
				ft_error_map(2);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_wall_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->map_size.x)
	{
		while (j < g->map_size.y)
		{
			if (i == 0 || i == g->map_size.x - 1)
			{
				if (g->map[i][j] != '1')
					ft_error_map(1);
			}
			else
			{
				if (g->map[i][0] != '1' || g->map[i][g->map_size.y - 1] != '1')
					ft_error_map(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
