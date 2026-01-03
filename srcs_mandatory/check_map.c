/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:00:50 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 18:48:06 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_rectangular(t_game *game)
{
	int	i;

	if (!game->map || !game->map[0])
		return (0);
	game->map_width = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			return (ft_printf("Error\nMap must be rectangular\n"), 0);
		i++;
	}
	return (1);
}

static int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			return (ft_printf("Error\nMap must be enclosed by walls\n"), 0);
		i++;
	}
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			return (ft_printf("Error\nMap must be enclosed by walls\n"), 0);
		i++;
	}
	return (1);
}

static int	check_char(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->count_p++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == 'E')
		game->count_e++;
	else if (c == 'C')
		game->count_c++;
	else if (c != '1' && c != '0')
		return (ft_printf("Error\nInvalid char found: %c\n", c), 0);
	return (1);
}

static int	check_content(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (!check_char(game, game->map[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (game->count_p != 1 || game->count_e != 1 || game->count_c < 1)
		return (ft_printf("Error\nInvalid count (P=1, E=1, C>=1)\n"), 0);
	return (1);
}

int	check_map(t_game *game)
{
	if (!is_rectangular(game))
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_content(game))
		return (0);
	return (1);
}
