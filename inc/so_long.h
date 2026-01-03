/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:16:42 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 20:12:09 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100 

typedef struct s_game
{
	void		*mlx;
	void		*win;

	char		**map;
	int			map_width;
	int			map_height;
	int			count_c;
	int			count_e;
	int			count_p;

	int			player_x;
	int			player_y;
	int			moves;

	void		*wall;
	void		*floor;
	void		*player_down;
	void		*player_up;
	void		*player_left;
	void		*player_right;
	void		*player_curr;
	void		*exit_on;
	void		*exit_off;
	void		*exit_curr;
	void		*collect;
	int			w;
	int			h;

}	t_game;

int		init_mlx(t_game *game);
int		check_extension(char *path);
int		get_map(t_game *game, char *path);
int		check_map(t_game *game);
int		init_sprites(t_game *game);
int		close_game(t_game *game);
int		cross_clicked(t_game *game);

void	render_map(t_game *game);
void	free_map(t_game *game);
void	setup_hooks(t_game *game);
void	free_map(t_game *game);
void	move_player(t_game *game, int x, int y, void *sprite);
void	free_images(t_game *game);

#endif