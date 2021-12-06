/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:07:19 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 15:44:07 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	f_put_error_unsupported(const char *name)
{
	ft_putstr_fd("\e[31mError: Unsupported fractal `", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd("'\e[0m", 2);
}

static void	f_usage(void)
{
	ft_putendl_fd("\e[33mUsage: ./fractol <fractal_name>", 2);
	ft_putendl_fd("Supported fractals: mandelbrot, julia\e[0m", 2);
}

static t_figname	f_get_fractal_name(const char *name)
{
	if (ft_strequ(name, "mandelbrot"))
		return (fig_mandelbrot);
	else if (ft_strequ(name, "julia"))
		return (fig_julia);
	else
		return (fig_unsupported);
}

static bool	f_is_fig_supported(t_figname name)
{
	return (name != fig_unsupported);
}

void	parse_args(t_root *root, int ac, const char *av[])
{
	if (ac == 2)
	{
		root->fig.name = f_get_fractal_name(av[1]);
		if (f_is_fig_supported(root->fig.name))
		{
			root->win.name = av[1];
			return ;
		}
		else
			f_put_error_unsupported(av[1]);
	}
	f_usage();
	root->error = error_args;
}
