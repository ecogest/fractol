/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/03 13:50:13 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_fractol(int ac, const char *av[])
{
	void	*mlx;

	(void)ac;
	(void)av;
	ft_putstr("Libft is linked.\n");
	mlx = mlx_init();
	mlx_new_window(mlx, 720, 480, "fractol");
	mlx_loop(mlx);
	return (0);
}
