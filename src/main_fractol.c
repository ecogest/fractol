/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/05 15:48:08 by mjacq            ###   ########.fr       */
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

void	win_init(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx)
	{
		win->width = WIN_WIDTH;
		win->height = WIN_HEIGHT;
		win->win = mlx_new_window(win->mlx, win->width, win->height, \
				(char *)win->name);
	}
	if (!win->mlx || !win->win)
		win->error = error;
}

void	win_destroy(t_win *win)
{
	if (win->mlx && win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
}

	/* img_draw(circle); */
	/* img_render(); */
int	main_fractol(int ac, const char *av[])
{
	t_root	root;

	root = (t_root){};
	parse_args(&root, ac, av);
	win_init(&root.win);
	mlx_loop(root.win.mlx);
	win_destroy(&root.win);
	return (0);
}
