/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:08:08 by artvan-d          #+#    #+#             */
/*   Updated: 2023/02/23 15:27:07 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

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

void	move_exit(t_game *game, char next_pos)
{
	if (next_pos == 'E')
	{
		if (check_if_all_collected(game) == 1)
		{
			game->moves_count++;
			ft_printf("Well done, is %i moves the best you can do?\n",
				game->moves_count);
			close_window(game);
		}
	}
}

void	move(t_game *game, int move_x, int move_y)
{
	char		next_pos;
	static char	last_pos;

	next_pos = game->map_data[game->player_y + move_y][game->player_x + move_x];
	last_pos = game->map_data[game->player_y][game->player_x];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P' \
	|| next_pos == 'E')
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
			game->map_data[game->player_y + move_y][game->player_x + move_x] \
			= '0';
		}
		game->player_x += move_x;
		game->player_y += move_y;
		put_img(game, SPRITE * game->player_x + move_x,
			SPRITE * game->player_y + move_y, game->img_player);
		game->moves_count++;
		ft_printf("Moves : %i\r", game->moves_count);
	}
	move_exit(game, next_pos);
}

void	key_process(int key, t_game *game)
{
	if (key == UP)
		move(game, 0, -1);
	if (key == DOWN)
		move(game, 0, +1);
	if (key == LEFT)
		move(game, -1, 0);
	if (key == RIGHT)
		move(game, +1, 0);
	if (key == ESC)
		close_window(game);
}

int	key_hook(int key, t_game *game)
{
	key_process(key, game);
	return (0);
}
