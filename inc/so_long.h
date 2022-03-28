/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:24 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 22:53:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include <stdlib.h>

# define TILE_SIZE 32
# define WINDOWBAR 64
# define COUNTBAR 32
# define PIXELLIMIT 3
# define EXIT_PATH "./img/light.xpm"
# define LOOT_PATH "./img/poo32x32.xpm"
# define PLAYER_PATH "./img/fly_right32x32.xpm"
# define PLAYER_L_PATH "./img/fly_left32x32.xpm"
//Linux
# define SPACE_PATH "./img/black.xpm"
//Mac
//# define SPACE_PATH "./img/space.xpm"
# define WALL_PATH "./img/wall.xpm"
# define BLACK_PATH "./img/black.xpm"
# define ENEMY_PATH "./img/angry_frog32x32.xpm"

typedef enum e_errorcode
{
	ARGUMENTS,
	NOFILE,
	SHAPE,
	WALLS,
	SPAWN,
	NOEXIT,
	NOLOOT,
	WRONGFILE,
	MALLOC,
	OPEN,
	CLOSE,
	IMAGE,
	ERRORS,
	SETUP,
}	t_errorcode;

typedef enum e_timer
{
	ON = -1,
	OFF = -2,
}	t_timer;

typedef enum e_x11events
{
	KeyPress = 2,
	DestroyNotify = 17,
}	t_x11events;

typedef enum e_x11masks
{
	KeyPressMask = 1L << 0,
	StructureNotifyMask = 1L << 17,
}	t_x11masks;

//Linux
/* typedef enum e_key
{
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	UP_KEY = 65362,
	LEFT_KEY = 65361,
	DOWN_KEY = 65364,
	RIGHT_KEY = 65363,
	ESC_KEY = 65307,
}	t_key; */

//Mac
typedef enum e_key
{
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	UP_KEY = 126,
	LEFT_KEY = 123,
	DOWN_KEY = 125,
	RIGHT_KEY = 124,
	ESC_KEY = 53,
}	t_key;

typedef enum e_direction
{
	UP = 1,
	LEFT = 2,
	DOWN = 3,
	RIGHT = 4,
}	t_direction;

typedef enum e_map
{
	WALL = '1',
	LOOT = 'C',
	SPACE = '0',
	START = 'P',
	EXIT = 'E',
}	t_map;

typedef enum e_imgnr
{
	PLAYER_IMAGE,
	SPACE_IMAGE,
	WALL_IMAGE,
	LOOT_IMAGE,
	EXIT_IMAGE,
	PLAYER_L_IMAGE,
	BLACK_IMAGE,
	ENEMY_IMAGE,
	IMAGES,
}	t_imgnr;

typedef enum e_color
{
	RED = 0x00FF0000,
	ORANGE = 0x00FF8000,
	YELLOW = 0x00FFFF00,
	GREEN = 0x0000FF00,
	CYAN = 0x0000FFFF,
	BLUE = 0x000000FF,
	MAGENTA = 0x00FF00FF,
	BLACK = 0x00000000,
	GREY = 0x00808080,
	WHITE = 0x00FFFFFF,
}	t_color;

typedef struct s_img
{
	void	*img;
	int		iwidth;
	int		iheight;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		side;
}				t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	bool	status;
}				t_enemy;

typedef struct s_frame
{
	int		height;
	int		width;
}				t_frame;

typedef struct s_data
{
	bool			errorflags[ERRORS];
	struct s_frame	screen;
	char			**map;
	struct s_frame	grid;
	void			*mlx;
	void			*win;
	struct s_frame	window;
	t_img			*imgs[IMAGES];
	int				img_size;
	struct s_player	player;
	struct s_enemy	enemy;
	int				dx;
	int				dy;
	int				move_count;
	char			*move_count_str;
	int				loot_count;
	unsigned int	rand;
	int				timer;
	int				counter;
}	t_data;

#endif