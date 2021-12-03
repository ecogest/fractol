/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:19:00 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/03 13:24:25 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx;

	ft_putstr("Libft is linked.\n");
	mlx = mlx_init();
	mlx_new_window(mlx, 720, 480, "fractol");
	mlx_loop(mlx);
	return (0);
}
