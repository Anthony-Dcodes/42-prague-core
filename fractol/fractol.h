/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:37:43 by advorace          #+#    #+#             */
/*   Updated: 2026/01/24 14:40:59 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include "keys.h"
# include "colors.h"
# include "math.h"

// Structures
// Represents image itself
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// Window context
typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	int		win_width;
	int		win_height;
	int		color_shift;
	int		frame;
	double	circle_x;
	double	circle_y;
	double	circle_size;
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
int	close_window_red_cross(void *param);
int close_window_esc(int keycode, void *vars);
int	key_hook(int key_code);
int	mouse_possition_hook(int x, int y, void *param);

// Rendering functions
int	render_rainbow(void *param);
int	render_circle(void *param);

// Math functions
double	euclidian_distance(double x1, double x2, double y1, double y2);

#endif
