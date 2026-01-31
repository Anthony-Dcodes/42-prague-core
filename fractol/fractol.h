/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:37:43 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 12:56:09 by advorace         ###   ########.fr       */
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

# define MAX_FRACTAL_ITER 200
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

// Structures
// Represents image itself
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// Window context
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	int			win_width;
	int			win_height;
	int			color_shift;
	int			frame;
	//double		circle_x;
	//double		circle_y;
	//double		circle_size;
	double		c_real;
	double		c_imag;
	char		fract_type;
	long double	x_min;
	long double	x_max;
	long double	y_min;
	long double	y_max;
	int			max_fractal_iter;
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
	int		triangle_Ax;
	int		triangle_Ay;
	int		triangle_Bx;
	int		triangle_By;
	int		triangle_Cx;
	int		triangle_Cy;
}	t_fractal;

// Color manipulation
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// Pixel manipulations
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Escape hooks
int		close_window_red_cross(void *param);
int		close_window_esc(int keycode, void	*param);

// Mouse hooks
void	zoom_in(int x, int y, t_vars *vars);
void	zoom_out(int x, int y, t_vars *vars);
int		mouse_zoom_hook(int button, int x, int y, void *param);

// Hooks
//int		mouse_possition_hook(int x, int y, void *param);
//int		move_circle_hook(int key_code, void *param);

// Rendering functions
//int		render_rainbow(void *param);
//int		render_circle(void *param);
int		render_fractal(void *param);
void	fractal_mandelbrot_set(double x, double y, t_fractal *fract);
void	fractal_julia_set(double x, double y, t_fractal *fract,
			t_vars *vars);
void	render_mandlerbrot(t_vars *vars, t_fractal *fract,
			int x1, int y1);
void	render_julia(t_vars *vars, t_fractal *fract,
			int x1, int y1);
void	fractal_burning_ship(double x, double y, t_fractal *fract);
void	render_burning_ship(t_vars *vars, t_fractal *fract, int x1, int y1);

// Math functions
double	euclidian_distance(double x1, double x2,
			double y1, double y2);
double	x_coordinate_to_complex_plane(int x, long double x_min,
			long double x_max, int width);
double	y_coordinate_to_complex_plane(int y, long double y_min,
			long double y_max, int height);
int		fractal_equation(double x, double y, t_fractal *fract);
void	last_z_magnitude(t_fractal *fract);
void	smooth_iter_count(t_fractal *fract);
void	compute_polynomial_pallete(t_fractal *fract, t_vars *vars);

// Error functions
void	print_usage(void);

// Initialisation
void	init_t_vars(t_vars *vars, char fractal_type);

// Clean-up
void	clean_up(t_vars *vars, int exit_status);

// Parsing
void	parse_arguments(t_vars *vars, int argc, char *argv[]);

#endif
