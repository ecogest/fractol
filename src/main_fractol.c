/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 12:17:05 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fig_init(t_figure *fig, t_win *win)
{
	fig->name = fig_circle;
	fig->colors = (t_colors){\
		.bg = BG_COLOR, .border = BORDER_COLOR, .area = AREA_COLOR};
	fig->offset.x = win->dim.width / 2;
	fig->offset.y = win->dim.height / 2;
	fig->scale = 1;
	fig->circle = (t_circle){50, 0, 0};
}

bool	is_in_circle(t_coordinates *m, t_circle *circle)
{
	return (powf(m->x - circle->x0, 2) + powf(m->y - circle->y0, 2) \
			<= powf(circle->r, 2));
}

void	fig_px_set(t_figure *fig, t_pixel *px)
{
	t_coordinates	coordo;

	coordo.x = fig->scale * (px->x - fig->offset.x);
	coordo.y = fig->scale * (px->y - fig->offset.y);
	if (is_in_circle(&coordo, &fig->circle))
		px->color = fig->colors.area;
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
