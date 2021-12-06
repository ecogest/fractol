/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_put_bg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:33:14 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 11:33:44 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	win_put_bg(t_win *win, int bg_color)
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
