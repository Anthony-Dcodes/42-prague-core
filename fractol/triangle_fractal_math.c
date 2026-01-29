/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_fractal_math.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:22:53 by advorace          #+#    #+#             */
/*   Updated: 2026/01/29 23:03:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Return 0 pixel on line ac
// Return 1 pixel on the right ac
// Return -1 pixel on the left ac
static int	pixel_in_ac(t_fractal *fract, int x, int y)
{
	int	ac_x;
	int	ac_y;
	int	ap_x;
	int	ap_y;
	int	cross;

	ac_x = fract->triangle_Cx - fract->triangle_Ax;
	ac_y = fract->triangle_Cy - fract->triangle_Ay;
	ap_x = x - fract->triangle_Ax;
	ap_y = y - fract->triangle_Ay;
	cross = (ac_x * ap_y) - (ac_y * ap_x);
	return (cross);
}

// Return 0 pixel on line cb
// Return 1 pixel on the right cb
// Return -1 pixel on the left cb
static int	pixel_in_cb(t_fractal *fract, int x, int y)
{
	int	cb_x;
	int	cb_y;
	int	cp_x;
	int	cp_y;
	int	cross;

	cb_x = fract->triangle_Bx - fract->triangle_Cx;
	cb_y = fract->triangle_By - fract->triangle_Cy;
	cp_x = x - fract->triangle_Cx;
	cp_y = y - fract->triangle_Cy;
	cross = (cb_x * cp_y) - (cb_y * cp_x);
	return (cross);
}

// Return 0 pixel on line ba
// Return 1 pixel on the right ba
// Return -1 pixel on the left ba
static int	pixel_in_ba(t_fractal *fract, int x, int y)
{
	int	ba_x;
	int	ba_y;
	int	bp_x;
	int	bp_y;
	int	cross;

	ba_x = fract->triangle_Ax - fract->triangle_Bx;
	ba_y = fract->triangle_Ay - fract->triangle_By;
	bp_x = x - fract->triangle_Bx;
	bp_y = y - fract->triangle_By;
	cross = (ba_x * bp_y) - (ba_y * bp_x);
	return (cross);
}

static int	pixel_in_smallest_sub_triangle(int Cx, int Cy, int x, int y)
{
	int	tmp_dx;
	int	tmp_dy;
	int	dx;
	int	dy;

	dx = x - Cx;
	dy = y - Cy;
	tmp_dx = dx;
	tmp_dy = dy;
	while (tmp_dx != 0 || tmp_dy != 0)
	{
		if ((tmp_dx % 2 == 1) && (tmp_dy % 2 == 1))
			return (0);
		tmp_dx /= 2;
		tmp_dy /= 2;
	}
	return (1);
}

// Return 0 if pixel outside triangle
// Return 1 if pixel inside triangle
int	pixel_in_sirepinski(t_vars *vars, t_fractal *fract, int x, int y)
{
	int	side_lenght;
	int	height;

	height = vars->win_height;
	side_lenght = 2*height / sqrt(3);
	fract->triangle_Ax = vars->win_width / 2 - side_lenght / 2;
	fract->triangle_Ay = vars->win_height;
	fract->triangle_Bx = fract->triangle_Ax + side_lenght;
	fract->triangle_By = vars->win_height;
	fract->triangle_Cx = vars->win_width / 2;
	fract->triangle_Cy = 0;
	if (pixel_in_ac(fract, x, y) < 0)
		return (0);
	else if (pixel_in_cb(fract, x, y) < 0)
		return (0);
	else if (pixel_in_ba(fract, x, y) < 0)
		return (0);
	if (pixel_in_smallest_sub_triangle(fract->triangle_Bx, fract->triangle_Cy,
	x, y))
		return (1);
	return (0);
}

