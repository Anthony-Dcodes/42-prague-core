/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:37:43 by advorace          #+#    #+#             */
/*   Updated: 2026/01/16 19:34:36 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include "keys.h"

// Structures
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

// Color manipulation
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int get_b(int trgb);

// Pixel manipulations
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_square_put(t_data *data, int x, int y, int color, int size);

// Hooks
int	close_window_red_cross(t_vars *vars);
int close_window_esc(int keycode, t_vars *vars);

#endif
