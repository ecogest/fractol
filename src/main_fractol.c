/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 14:32:06 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fig_init(t_figure *fig, t_win *win)
{
	fig->name = fig_mandelbrot;
	fig->colors = (t_colors){\
		.bg = BG_COLOR, .border = BORDER_COLOR, .area = AREA_COLOR};
	fig->offset.x = win->dim.width / 2;
	fig->offset.y = win->dim.height / 2;
	fig->scale = fminf(win->dim.width / 4.0, win->dim.height / 2.0);
	fig->max_iter = MAX_ITER_START;
}

void	fig_px_set(t_figure *fig, t_pixel *px)
{
	t_coordinates	coordo;
	int				iterations;

	coordo.x = (px->x - fig->offset.x) / fig->scale;
	coordo.y = (px->y - fig->offset.y) / fig->scale;
	iterations = iter_mandelbrot(&coordo, fig->max_iter);
	if (iterations == fig->max_iter)
		px->color = fig->colors.area;
	else if (iterations == fig->max_iter - 1)
		px->color = fig->colors.border;
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
	win_init(&root.win);
	fig_init(&root.fig, &root.win);
	win_put_figure(&root.win, &root.fig);
	win_hook_and_loop(&root.win);
	win_destroy(&root.win);
	return (0);
}
