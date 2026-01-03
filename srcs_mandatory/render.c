/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:56:25 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 18:21:47 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	char_type;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			char_type = game->map[y][x];
			if (char_type == '0')
				put_image(game, game->floor, x, y);
			else if (char_type == '1')
				put_image(game, game->wall, x, y);
			else if (char_type == 'P')
				put_image(game, game->player_curr, x, y);
			else if (char_type == 'E')
				put_image(game, game->exit_curr, x, y);
			else if (char_type == 'C')
				put_image(game, game->collect, x, y);
			x++;
		}
		y++;
	}	
}
