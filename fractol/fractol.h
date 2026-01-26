/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:37:43 by advorace          #+#    #+#             */
/*   Updated: 2026/01/26 21:18:18 by advorace         ###   ########.fr       */
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
# include "fractal_space.h"

# define MAX_FRACTAL_ITER 100
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

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
	double	c_real;
	double	c_imag;
	char	fract_type;
}	t_vars;

// Fractal data
typedef struct s_fractal {
	int		iter;
	double	a;
	double	b;
	double	last_z_magnitude;
	double	smooth_iter_count;
	int		final_color;
} t_fractal;

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
int	key_hook(int key_code, void *vars);
int	mouse_possition_hook(int x, int y, void *param);
int	move_circle_hook(int key_code, void *param);

// Rendering functions
int	render_rainbow(void *param);
int	render_circle(void *param);
int	render_fractal(void *param);
int	fractal_julia_set(double x, double y, t_fractal *fract, double c_real, double c_imag);

// Math functions
double	euclidian_distance(double x1, double x2, double y1, double y2);
double	x_coordinate_to_complex_plane(int x, float x_min, float x_max, int width);
double	y_coordinate_to_complex_plane(int y, float y_min, float y_max, int height);
int		fractal_equation(double x, double y, t_fractal *fract);
void	last_z_magnitude(t_fractal *fract);
void	smooth_iter_count(t_fractal *fract);
void	compute_polynomial_pallete(t_fractal *fract);

// Error functions
void	print_usage_and_exit();

#endif
