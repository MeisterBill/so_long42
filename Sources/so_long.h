#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 32
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT	2
# define ESC		53

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef	struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map_data;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		item_count;
	int		item_player;
	int		moves_count;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_item;
	void	*img_exit;
	int		img_x;
	int		img_y;
	int		count;
	char	*file;
}				t_game;

#endif
