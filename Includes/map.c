
#include "so_long.h"

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
