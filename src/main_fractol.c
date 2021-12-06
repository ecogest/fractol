/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 11:33:44 by mjacq            ###   ########.fr       */
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
	win_put_bg(&root.win, root.fig.colors.bg);
	win_hook_and_loop(&root.win);
	win_destroy(&root.win);
	return (0);
}
