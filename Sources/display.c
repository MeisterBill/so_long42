
#include "so_long.h"

void put_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
}

void load_img(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx,
																					"./includes/sprites/owl.xpm", &game->img_x, &game->img_y);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
																				"./includes/sprites/wall.xpm", &game->img_x, &game->img_y);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
																					"./includes/sprites/grass.xpm", &game->img_x, &game->img_y);
	game->img_item = mlx_xpm_file_to_image(game->mlx,
																				"./includes/sprites/wood_stick.xpm", &game->img_x, &game->img_y);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
																				"./includes/sprites/exit_empty.xpm", &game->img_x, &game->img_y);
}
