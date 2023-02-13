
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
