/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:39:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/27 20:34:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char *argv[])
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	if (argc == 4 && ft_strncmp(argv[1], "j", 2) == 0)
	{
		vars.c_real = ft_atof(argv[2]);
		vars.c_imag = ft_atof(argv[3]);
		vars.fract_type = 'j';
	}
	else if (argc == 2 && ft_strncmp(argv[1], "m", 2) == 0)
	{
		vars.fract_type = 'm';
	}
	else
		print_usage_and_exit();
	init_t_vars(&vars, vars.fract_type);
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "Hellow world!");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	vars.img.img = mlx_new_image(vars.mlx, vars.win_width, vars.win_height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	my_mlx_square_put(&vars.img, 5, 5, create_trgb(120, 120, 11, 99), 100);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	//mlx_hook(vars.win, ON_DESTROY, 0, close_window_red_cross, &vars);
	//mlx_hook(vars.win, ON_KEYDOWN, 0, close_window_esc, &vars);
	//mlx_key_hook(vars.win, close_window_esc, &vars);
	//mlx_hook(vars.win, ON_KEYDOWN, 1L << 0, close_window_esc, &vars);
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, key_hook, &vars);
	//mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_possition_hook, &vars);
	mlx_key_hook(vars.win, close_window_esc, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_window_red_cross, &vars);
	mlx_mouse_hook(vars.win, mouse_zoom_hook, &vars);

	//mlx_key_hook(vars.win, move_circle_hook, &vars);
	mlx_loop_hook(vars.mlx, render_fractal, &vars);
	mlx_loop(vars.mlx);

}
