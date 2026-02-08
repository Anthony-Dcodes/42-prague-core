/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:37:43 by advorace          #+#    #+#             */
/*   Updated: 2026/02/08 12:54:56 by advorace         ###   ########.fr       */
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
# define SCREEN_WIDTH 920
# define SCREEN_HEIGHT 640

// Structures
// Represents image itself
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

// Window context variable
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_image		img;
	int			win_width;
	int			win_height;
	int			frame;
	double		c_real;
	double		c_imag;
	char		fract_type;
	long double	x_min;
	long double	x_max;
	long double	y_min;
	long double	y_max;
}	t_vars;

// Fractal data
typedef struct s_fractal
{
	int		iter;
	double	a;
	double	b;
	double	last_z_magnitude;
	double	smooth_iter_count;
	int		final_color;
}	t_fractal;

// Pixel manipulations
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	put_fractal_pixel(t_vars *vars, t_fractal *fract, int x1, int y1);
void	apply_polynomial_palette(t_fractal *fract, t_vars *vars);

// Escape hooks
int		handle_window_close(void *param);
int		key_press_hook(int keycode, void	*param);

// Mouse hooks
void	zoom_at_cursor(int x, int y, t_vars *vars, double zoom);
int		mouse_zoom_hook(int button, int x, int y, void *param);

// Rendering function
int		render_fractal(void *param);

// Fractal iteration functions
void	compute_mandelbrot(double x, double y, t_fractal *fract);
void	compute_julia(double x, double y, t_fractal *fract,
			t_vars *vars);
void	compute_burningship(double x, double y, t_fractal *fract);
void	compute_last_z_magnitude(t_fractal *fract);
void	smooth_iter_count(t_fractal *fract);

// Coordinate mapping
double	map_x_to_complex_plane(int x, long double x_min,
			long double x_max, int width);
double	map_y_to_complex_plane(int y, long double y_min,
			long double y_max, int height);

// Error functions
void	print_usage(void);

// Initialisation
void	init_vars(t_vars *vars, char fractal_type);

// Clean-up
void	clean_up(t_vars *vars, int exit_status);

// Parsing
void	parse_arguments(t_vars *vars, int argc, char *argv[]);

#endif
