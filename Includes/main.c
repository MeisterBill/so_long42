
#include "so_long.h"

int	check_extension(char **argv)
{
	int	checker;

	checker = 0;
	if (argv[1][ft_strlen(argv[1]) - 4] != '.')
		checker = 1;
	if (argv[1][ft_strlen(argv[1]) - 3] != 'b')
		checker = 1;
	if (argv[1][ft_strlen(argv[1]) - 2] != 'e')
		checker = 1;
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r')
		checker = 1;
	return (checker);
}

void	close_window(t_game *game)
{
	(void)game;
	exit(0);
}

int	check_argv(t_game *game, int ac, char **argv)
{
	if (ac != 2)
	{
		write(1, "Error\nUse <./so_long maps/mapx.ber>", 36);
		close_window(game);
	}
	if (check_extension(argv) == 1)
	{
		write(1, "Error\nMap has to be a <.ber> file", 34);
		close_window(game);
	}
	return (0);
}

int	main(int ac, char **argv)
{
	t_game	game;

	game.map_data = NULL;
	check_argv(&game, ac, argv);
	if (get_map_width(&game, argv) == 1)
	{
		write(1, "Error\nREPLACE", 34);
		close_window(&game);
	}

}
