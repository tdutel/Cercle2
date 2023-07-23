/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:49:58 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 14:22:51 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../includes/assets_path.h"

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_player
{
	t_coords	pos;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_coords	map_size;
	t_player	player;
	int			collectible;
	t_coords	exit;
	int			count;

}	t_game;

enum {
	w = 13,
	a = 0,
	s = 1,
	d = 2,
	left = 123,
	right = 124,
	down = 125,
	up = 126,
	esc = 53,
	q = 12,
};

# define ON_DESTROY 17
# define ON_KEYDOWN 2

//	-	-	-	so_long.c	-	-	-	//
int		key_event(int key, t_game *param);
void	ft_read(char *file, t_game *game);

//	-	-	-	parsing_map.c	-	-	-	//
void	ft_parsing(t_game *game, char *file);
void	ft_check_file_map(char *file);
void	ft_check_size_map(t_game *g);
void	ft_check_char_map(t_game *g);
void	ft_check_wall_map(t_game *g);

//	-	-	-	parse_check_map.c	-	-	-	//
void	ft_check_collect_map(t_game *g);
void	ft_check_starpos_map(t_game *g);
void	ft_check_exit_map(t_game *g);

//	-	-	-	check_valid_map.c	-	-	-	//
void	fill_map(char **map, int x, int y);
void	check_map_solvability(t_game game);

//	-	-	-	utils.c	-	-	-	//
int		ft_strlen_no_nl(const char *str);
void	free_map(char **map);

//	-	-	-	error_exit.c	-	-	-	//
void	ft_error_map(int i);
int		ft_exit(t_game *game);
int		is_win(t_game g);

//	-	-	-	display_manager.c	-	-	-	//
void	display_game(t_game *game);
void	display_in(t_game *g, int i, int j);
int		is_corner(t_game *g, int i, int j);

//	-	-	-	display_edge.c	-	-	-	//
void	display_corner(t_game *g, int i, int j);
void	display_wall_updown(t_game *g, int i, int j);
void	display_wall_side(t_game *g, int i, int j);

//	-	-	-	display_assets.c	-	-	-	//
void	display_block(t_game *g, int i, int j);
void	display_floor(t_game *g, int i, int j);
void	display_collect(t_game *g, int i, int j);
void	display_starpos(t_game *g, int i, int j);
void	display_exit(t_game *g, int i, int j);

//	-	-	-	move_file.c	-	-	-	//
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	move_direction(t_game *g, int i, int j, char c);

//	-	-	-	display_player.c	-	-	-	//
void	display_player_up(t_game *g, int i, int j);
void	display_player_down(t_game *g, int i, int j);
void	display_player_left(t_game *g, int i, int j);
void	display_player_right(t_game *g, int i, int j);
void	display_direction(t_game *g, int i, int j, char *str);
#endif
