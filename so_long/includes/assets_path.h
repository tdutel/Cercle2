/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_path.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:00:27 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/27 14:54:55 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_PATH_H
# define ASSETS_PATH_H

# define ASSET_SIZE 32

/* ---- Normal floors ---- */
# define BASIC_FLOOR		"./assets/floor/base.xpm"

/* ---- Holes ---- */
# define EXIT		"./assets/floor/hole/exit.xpm"

/* ==== Wall assets paths ==== */
# define WALL_LR				"./assets/wall/left.xpm"
# define WALL_TB			"./assets/wall/top_bottom.xpm"
# define CORNER_TL			"./assets/wall/left_top_corner.xpm"
# define CORNER_TR			"./assets/wall/right_top_corner.xpm"
# define CORNER_BL			"./assets/wall/left_bottom_corner.xpm"
# define CORNER_BR			"./assets/wall/right_bottom_corner.xpm"

/* ==== Decor assets paths ==== */
# define DECOR_BIG_ROCK		"./assets/decor/big_rock.xpm"
# define DECOR_CRYSTAL		"./assets/decor/crystal.xpm"

/* ==== Collectible ==== */
# define COLLECTIBLE DECOR_CRYSTAL

/* ==== Player ==== */
# define PLAYER_FRONT		"./assets/character/front.xpm"
# define PLAYER_LEFT		"./assets/character/left.xpm"
# define PLAYER_RIGHT		"./assets/character/right.xpm"
# define PLAYER_BACK		"./assets/character/back.xpm"

#endif