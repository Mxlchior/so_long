/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:26:19 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 19:58:55 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_sprites(t_game *game)
{
	if (!game->player_up || !game->floor || !game->wall || !game->exit_on
		|| !game->exit_off || !game->collect || !game->player_down
		|| !game->player_left || !game->player_right)
	{
		ft_printf("Error\nXpm file not found or corrupted\n");
		return (0);
	}
	return (1);
}

/*turns XPM files into image objects that can be printed to the screen
 by the graphical server*/

int	init_sprites(t_game *game)
{
	game->player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/rick_up.xpm", &game->w, &game->h);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->w, &game->h);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->w, &game->h);
	game->exit_on = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_on.xpm", &game->w, &game->h);
	game->exit_off = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_off.xpm", &game->w, &game->h);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->w, &game->h);
	game->player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/rick_down.xpm", &game->w, &game->h);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/rick_left.xpm", &game->w, &game->h);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/rick_right.xpm", &game->w, &game->h);
	game->player_curr = game->player_down;
	game->exit_curr = game->exit_off;
	if (!check_sprites(game))
		return (0);
	return (1);
}
