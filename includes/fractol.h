/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:26:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/05 15:38:48 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"

# define WIN_WIDTH 720
# define WIN_HEIGHT 480

typedef enum e_error
{
	success = 0,
	error
}	t_error;

typedef struct s_win
{
	void		*win;
	const char	*name;
	int			width;
	int			height;
	void		*mlx;
	t_error		error;
}				t_win;

typedef struct s_img
{
	char	*buf;
	t_win	*win;
}			t_img;

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct s_root
{
	t_win	win;
	t_error	error;
}			t_root;

int	main_fractol(int ac, const char *av[]);

#endif
