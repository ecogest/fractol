/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:18:32 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 10:35:07 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	win_img_init(t_win *win)
{
	t_img	*img;

	img = &win->img;
	img->dim = &win->dim;
	img->ptr = mlx_new_image(win->mlx, win->dim.width, win->dim.height);
	img->buf = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, \
			&img->endian);
}

void	win_init(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx)
	{
		win->dim.width = WIN_WIDTH;
		win->dim.height = WIN_HEIGHT;
		win->ptr = mlx_new_window(win->mlx, win->dim.width, win->dim.height, \
				(char *)win->name);
		win_img_init(win);
	}
	if (!win->mlx || !win->ptr || !win->img.ptr)
		win->error = error;
}

void	win_destroy(t_win *win)
{
	if (win->mlx)
	{
		if (win->ptr)
			mlx_destroy_window(win->mlx, win->ptr);
		if (win->img.ptr)
			mlx_destroy_image(win->mlx, win->img.ptr);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
}
