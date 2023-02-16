
#include "so_long.h"

int	get_map_height(t_game *game, char **argv)
{
	int		fd;
	int		map_height;
	char	*tmp;

	map_height = 0;
	fd = open(argv[1], O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		map_height++;
	}
	free(tmp);
	close(fd);
	game->map_height = map_height;
	return (0);
}

int	get_map_width(t_game *game, char **argv)
{
	int		fd;
	int		map_width;
	char	*tmp;

	map_width = 0;
	fd = open(argv[1], O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	while (tmp[map_width])
		map_width++;
	free(tmp);
	close(fd);
	game->map_width = map_width - 1;
	return (0);
}

int	load_map(t_game *game, char *argv1)
{
	int	map_height;
	int	fd;
	int	i;

	map_height = game->map_height;
	fd = open(argv1, O_RDONLY);
	i = 0;
	game->map_data = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (game->map_data == NULL)
		return (1);
	while (i < game->map_height)
	{
		game->map_data[i] = get_next_line(fd);
		i++;
	}
	game->map_data = NULL;
	close(fd);
	return (0);
}

void	get_item_number(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map_data[i])
	{
		while (game->map_data[i][j])
		{
			if (game->map_data[i][j] == 'C')
				game->item_count++;
			j++;
		}
		i++;
		j = 0;
	}
}
