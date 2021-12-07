/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:18:23 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 15:28:58 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	f_switch_between_figures(t_root *root)
{
	if (root->fig.name == fig_mandelbrot)
	{
		root->fig.name = fig_julia;
		ft_putstr("Switch to Julia !\n");
	}
	else if (root->fig.name == fig_julia)
	{
		root->fig.name = fig_mandelbrot;
		ft_putstr("Switch to Mandelbrot !\n");
	}
	mlx_mouse_get_pos(root->win.mlx, root->win.ptr, \
			&root->win.mouse.last_x, &root->win.mouse.last_y);
	win_put_figure(&root->win, &root->fig);
	return (0);
}

static bool	f_is_arrow_key(int key)
{
	return (key == XK_Up || key == XK_Down \
			|| key == XK_Right || key == XK_Left);
}

static void	f_move_view(int key, t_figure *fig, t_win *win)
{
	t_offset *const	offset = &fig->offset;

	offset->x += ((key == XK_Right) - (key == XK_Left)) * win->dim.width / 100;
	offset->y -= ((key == XK_Up) - (key == XK_Down)) * win->dim.width / 100;
	win_put_figure(win, fig);
}

/*
** Mappings:
** - Esc: quit
** - Tab: switch figure
** - Enter: lock julia's parameters
** - c: change the colors
*/

int	hook_keyboard(int key, t_root *root)
{
	if (key == XK_Escape)
		mlx_loop_end(root->win.mlx);
	else if (key == XK_Return && root->fig.name == fig_julia)
	{
		root->fig.julia_lock = !root->fig.julia_lock;
		if (root->fig.julia_lock)
			ft_putendl("Julia's param locked.");
		else
		{
			mlx_mouse_get_pos(root->win.mlx, root->win.ptr, \
					&root->win.mouse.last_x, &root->win.mouse.last_y);
			ft_putendl("Julia's param unlocked.");
		}
	}
	else if (key == XK_Tab)
		f_switch_between_figures(root);
	else if (f_is_arrow_key(key))
		f_move_view(key, &root->fig, &root->win);
	else if (key == XK_c)
	{
		root->fig.palettes.choice = (root->fig.palettes.choice + 1) \
									% PALETTES_COUNT;
		win_put_figure(&root->win, &root->fig);
	}
	return (0);
}
