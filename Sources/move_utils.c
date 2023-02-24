#include "../Includes/so_long.h"

void move(t_game *game, int move_x, int move_y)
{
	char next_pos;
	static char last_pos;

	next_pos = game->map_data[game->player_y + move_y][game->player_x + move_x];
	last_pos = game->map_data[game->player_y][game->player_x];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P' || next_pos == 'E')
	{
		move_help(game, move_x, move_y, next_pos, last_pos);
		game->player_x += move_x;
		game->player_y += move_y;
		put_img(game, SPRITE * game->player_x + move_x,
						SPRITE * game->player_y + move_y, game->img_player);
		game->moves_count++;
		ft_printf("Moves : %i\r", game->moves_count);
	}
	move_exit(game, next_pos);
}

void move_help(t_game *game, int move_x, int move_y, char next_pos, char last_pos)
{
	if (last_pos == 'E')
	{
		put_img(game, SPRITE * game->player_x, SPRITE * game->player_y,
						game->img_exit);
	}
	if (last_pos != 'E')
	{
		put_img(game, SPRITE * game->player_x, SPRITE * game->player_y,
						game->img_floor);
	}
	if (next_pos == 'C')
	{
		game->item_player++;
		game->map_data[game->player_y + move_y][game->player_x + move_x] = '0';
	}
}
