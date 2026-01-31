/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:38:34 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 12:41:04 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_arguments(t_vars *vars, int argc, char *argv[])
{
	if (argc == 4 && ft_strncmp(argv[1], "j", 2) == 0)
	{
		vars->c_real = ft_atof(argv[2]);
		vars->c_imag = ft_atof(argv[3]);
		vars->fract_type = 'j';
	}
	else if (argc == 2 && ft_strncmp(argv[1], "m", 2) == 0)
	{
		vars->fract_type = 'm';
	}
	else
	{
		print_usage();
		clean_up(vars, EXIT_SUCCESS);
	}
}
