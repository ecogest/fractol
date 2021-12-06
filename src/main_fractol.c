/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 18:51:15 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fig_init(t_figure *fig, t_win *win)
{
	fig->colors = (t_colors){\
		.max = COLOR_MAX, .one = COLOR_ONE, .two = COLOR_TWO, \
			.three = COLOR_THREE, .bg = COLOR_BG};
	fig->offset.x = win->dim.width / 2;
	fig->offset.y = win->dim.height / 2;
	fig->scale = fminf(win->dim.width / 4.0, win->dim.height / 2.0);
	fig->scale_start = fig->scale;
	fig->max_iter = MAX_ITER_START;
}

void	fig_px_set(t_figure *fig, t_pixel *px)
{
	t_coordinates	coordo;
	int				iterations;

	coordo.x = (px->x - fig->offset.x) / fig->scale;
	coordo.y = (px->y - fig->offset.y) / fig->scale;
	if (fig->name == fig_mandelbrot)
		iterations = iter_mandelbrot(&coordo, fig->max_iter);
	else
		iterations = iter_julia(&coordo, &fig->z0, fig->max_iter);
	if (iterations == fig->max_iter)
		px->color = fig->colors.max;
	else if (iterations > fig->max_iter - ITER_THRESHOLD_1)
		px->color = fig->colors.one;
	else if (iterations > fig->max_iter - ITER_THRESHOLD_2)
		px->color = fig->colors.two;
	else if (iterations > fig->max_iter - ITER_THRESHOLD_3)
		px->color = fig->colors.three;
	else
		px->color = fig->colors.bg;
}

void	win_put_figure(t_win *win, t_figure *fig)
{
	t_img *const	img = &win->img;
	t_pixel			px;

	px = (t_pixel){};
	while (px.y < img->dim->height)
	{
		while (px.x < img->dim->width)
		{
			fig_px_set(fig, &px);
			img_px_put(img, &px);
			px.x++;
		}
		px.x = 0;
		px.y++;
	}
	mlx_put_image_to_window(win->mlx, win->ptr, img->ptr, 0, 0);
}

int	main_fractol(int ac, const char *av[])
{
	t_root	root;

	root = (t_root){};
	parse_args(&root, ac, av);
	if (!root.error)
	{
		win_init(&root.win);
		fig_init(&root.fig, &root.win);
		win_put_figure(&root.win, &root.fig);
		f_hook_and_loop(&root);
		if (root.win.error)
			root.error = error_win;
		win_destroy(&root.win);
	}
	if (root.error)
		return (1);
	else
		return (0);
}
