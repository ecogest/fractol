/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 11:30:37 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//TODO: error checking
void	parse_args(t_root *root, int ac, const char *av[])
{
	if (ac == 2)
		root->win.name = av[1];
	else
		root->win.name = "Fractol";
}

void	win_change_background(t_win *win, int bg_color)
{
	t_img *const	img = &win->img;
	t_pixel			px;

	px = (t_pixel){.color = bg_color};
	while (px.y < img->dim->height)
	{
		while (px.x < img->dim->width)
		{
			img_px_put(img, &px);
			px.x++;
		}
		px.x = 0;
		px.y++;
	}
	mlx_put_image_to_window(win->mlx, win->ptr, img->ptr, 0, 0);
}

void	fig_init(t_figure *fig)
{
	fig->name = fig_circle;
	fig->colors = (t_colors){\
		.bg = BG_COLOR, .border = BORDER_COLOR, .area = AREA_COLOR};
}

	/* img_draw(circle); */
	/* img_render(); */
int	main_fractol(int ac, const char *av[])
{
	t_root	root;

	root = (t_root){};
	parse_args(&root, ac, av);
	win_init(&root.win);
	fig_init(&root.fig);
	win_change_background(&root.win, root.fig.colors.bg);
	win_hook_and_loop(&root.win);
	win_destroy(&root.win);
	return (0);
}
