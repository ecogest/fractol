/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 14:15:07 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fig_init(t_figure *fig, t_win *win)
{
	fig->offset.x = win->dim.width / 2;
	fig->offset.y = win->dim.height / 2;
	fig->scale = fminf(win->dim.width / 5.0, win->dim.height / 3.0);
	fig->scale_start = fig->scale;
	fig->max_iter = MAX_ITER_START;
	fig->julia_c = (t_coordinates){.x = JULIA_DEF_X, .y = JULIA_DEF_Y};
}

int	get_color(t_palettes *palettes, size_t i_color)
{
	return (palettes->array[palettes->choice].colors[i_color]);
}

/*
** In order to correctly translate px->x and px->y into real coordo:
** once y_0 is correctly set, remember that
** 	 px->y increases when going down
** 	 coordo->y increases when going up
*/

void	fig_px_set(t_figure *fig, t_pixel *px)
{
	t_coordinates	candidate;
	int				iterations;

	candidate.x = (px->x - fig->offset.x) / fig->scale;
	candidate.y = - (px->y - fig->offset.y) / fig->scale;
	if (fig->name == fig_mandelbrot)
		iterations = iter_mandelbrot(&candidate, fig->max_iter);
	else
		iterations = iter_julia(&fig->julia_c, &candidate, fig->max_iter);
	if (iterations == fig->max_iter)
		px->color = get_color(&fig->palettes, 0);
	else if (iterations > fig->max_iter - ITER_THRESHOLD_1)
		px->color = get_color(&fig->palettes, 1);
	else if (iterations > fig->max_iter - ITER_THRESHOLD_2)
		px->color = get_color(&fig->palettes, 2);
	else if (iterations > fig->max_iter - ITER_THRESHOLD_3)
		px->color = get_color(&fig->palettes, 3);
	else
		px->color = get_color(&fig->palettes, 4);
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
		palettes_init(&root.fig.palettes);
		if (!root.fig.palettes.error)
		{
			win_init(&root.win);
			if (!root.win.error)
			{
				fig_init(&root.fig, &root.win);
				win_put_figure(&root.win, &root.fig);
				f_hook_and_loop(&root);
			}
			win_destroy(&root.win);
		}
		palettes_free(&root.fig.palettes);
	}
	if (root.error || root.win.error || root.fig.palettes.error)
		return (1);
	else
		return (0);
}
