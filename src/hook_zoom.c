/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:42:53 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 17:43:14 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Make sure that the mouse still points to the same place in the fractal
** when zooming.
** Solution to :
**	coordo.x = (px->x - fig->offset.x) / fig->scale;
**	and coordo.x_after = coordo.x_before (where px->x is the x of the mouse)
**
**	(idem with y)
*/

static void	f_zoom_fix_offset(t_figure *fig, int x, int y, float old_scale)
{
	fig->offset.x = - ((x - fig->offset.x) / old_scale * fig->scale - x);
	fig->offset.y = - ((y - fig->offset.y) / old_scale * fig->scale - y);
}

int	hook_zoom(int button, int x, int y, t_root *root)
{
	t_win *const	win = &root->win;
	t_figure *const	fig = &root->fig;
	const float		old_scale = root->fig.scale;

	if (button == ZOOM_IN)
	{
		fig->scale *= (float)ZOOM_SPEED;
		ft_putstr("Zoom in!\n");
	}
	else if (button == ZOOM_OUT)
	{
		fig->scale /= (float)ZOOM_SPEED;
		ft_putstr("Zoom out!\n");
	}
	f_zoom_fix_offset(fig, x, y, old_scale);
	win_put_figure(win, fig);
	return (0);
}
