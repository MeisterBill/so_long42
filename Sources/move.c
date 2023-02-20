
#include "so_long.h"

void get_player_position(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map_data[i])
	{
		while (game->map_data[i][j])
		{
			if (game->map_data[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
