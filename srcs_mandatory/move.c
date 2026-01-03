/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:04:13 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 18:50:51 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	perform_move(t_game *game, int new_x, int new_y, void *sprite)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->player_curr = sprite;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

void	move_player(t_game *game, int x, int y, void *sprite)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->count_c--;
		game->map[new_y][new_x] = '0';
		if (game->count_c == 0)
			game->exit_curr = game->exit_on;
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->count_c == 0)
		{
			ft_printf("GG! You won in %d moves", game->moves + 1);
			close_game(game);
		}
		return ;
	}
	perform_move(game, new_x, new_y, sprite);
}
