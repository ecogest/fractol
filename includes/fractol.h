/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:26:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 10:22:32 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** ================================ Includes ================================ **
*/

# include "mlx.h"
# include "libft.h"

// Including defines for keyboard keys
# define XK_MISCELLANY 1
# include "X11/keysymdef.h"

# define WIN_WIDTH 720
# define WIN_HEIGHT 480

# define BG_COLOR 0xf0f0f0
# define BORDER_COLOR 0xff0000
# define AREA_COLOR 0x000000

/*
** ================================= Enums ================================== **
*/

typedef enum e_error
{
	success = 0,
	error
}	t_error;

typedef enum e_figname
{
	fig_circle,
	fig_julia,
	fig_mandelbrot
}	t_figname;

/*
** =============================== Structures =============================== **
*/

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct s_circle
{
	float	r;
	float	x0;
	float	y0;
}		t_circle;

typedef struct s_dim
{
	int	width;
	int	height;
}		t_dim;

typedef struct s_img
{
	char	*buf;
	t_dim	*dim;
	int		bpp;
	int		size_line;
	int		endian;
	void	*ptr;
}			t_img;

typedef struct s_win
{
	const char	*name;
	t_dim		dim;
	t_img		img;
	void		*ptr;
	void		*mlx;
	t_error		error;
}				t_win;

typedef struct s_root
{
	t_win	win;
	t_error	error;
}			t_root;

/*
** =============================== Functions ================================ **
*/

// Main frame
int		main_fractol(int ac, const char *av[]);
void	win_init(t_win *win);
void	win_destroy(t_win *win);

// Hook and loop
int		key_hook(int key, t_win *win);
void	win_hook_and_loop(t_win *win);

#endif
