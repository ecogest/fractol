/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:07:19 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 10:00:35 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	f_put_error_unsupported(const char *name)
{
	ft_putstr_fd("\e[31mError: Unsupported fractal `", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd("'\e[0m", 2);
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

/*
** Could be used with av to get initial params for Julia
*/

void	parse_get_fig_param(t_root *root, int ac)
{
	const t_figname	name = root->fig.name;

	if (name == fig_mandelbrot && ac != 2)
		root->error = error_args;
	else if (name == fig_julia)
	{
		if (ac == 2)
			root->fig.c_julia = (t_coordinates) \
			{.x = JULIA_DEF_X, .y = JULIA_DEF_Y};
		else
			root->error = 1;
	}
}

void	parse_get_name(t_root *root, const char *name)
{
	root->fig.name = f_get_fractal_name(name);
	root->win.name = name;
	if (root->fig.name == fig_unsupported)
	{
		f_put_error_unsupported(name);
		root->error = error_args;
	}
}

void	parse_args(t_root *root, int ac, const char *av[])
{
	if (root->error)
		return ;
	if (ac >= 2)
	{
		parse_get_name(root, av[1]);
		if (!root->error)
			parse_get_fig_param(root, ac);
	}
	else
		root->error = error_args;
	if (root->error)
		f_usage();
}
