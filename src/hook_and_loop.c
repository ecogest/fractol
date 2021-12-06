/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:56:28 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 09:56:35 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_win *win)
{
	if (key == XK_Escape)
		mlx_loop_end(win->mlx);
	return (0);
}

void	win_hook_and_loop(t_win *win)
{
	mlx_key_hook(win->win, key_hook, win);
	mlx_loop(win->mlx);
}
