/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:26:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 15:39:04 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** ================================ Includes ================================ **
*/

# include "mlx.h"
# include "libft.h"
# include "float.h"
# include "math.h"

// Including defines for keyboard keys
# define XK_MISCELLANY 1
# include "X11/keysymdef.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

// Find beautiful palettes here: https://coolors.co/palettes/trending
# define COLOR_MAX 0x264653
# define COLOR_ONE 0x2a9d8f
# define COLOR_TWO 0xe9c46a
# define COLOR_THREE 0xf4a261
# define COLOR_BG 0xe76f51

# define MAX_ITER_START 16

/*
** ================================= Enums ================================== **
*/

typedef enum e_error
{
	success = 0,
	error,
	error_win,
	error_args
}	t_error;

typedef enum e_figname
{
	fig_unsupported,
	fig_julia,
	fig_mandelbrot
}	t_figname;

/*
** =============================== Structures =============================== **
*/

typedef struct s_colors
{
	int	max;
	int	one;
	int	two;
	int	three;
	int	bg;
}		t_colors;

typedef struct s_offset
{
	int	x;
	int	y;
}		t_offset;

typedef struct s_coordinates
{
	float	x;
	float	y;
}		t_coordinates;

/*
** Drawing parameters:
** offset: x,y px corresponding to (0,0) floating coordinates
** scale: x px correspondig to 1 in floating coordinates
*/

typedef struct s_figure
{
	t_figname	name;
	t_colors	colors;
	t_offset	offset;
	float		scale;
	int			max_iter;
}				t_figure;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}		t_pixel;

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
	t_win		win;
	t_figure	fig;
	t_error		error;
}			t_root;

/*
** =============================== Functions ================================ **
*/

// Main frame
int		main_fractol(int ac, const char *av[]);
void	parse_args(t_root *root, int ac, const char *av[]);
void	win_init(t_win *win);
void	win_destroy(t_win *win);

// Hook and loop
int		key_hook(int key, t_win *win);
void	win_hook_and_loop(t_win *win);

// Drawing functions
void	img_px_put(t_img *img, t_pixel *px);
void	win_put_bg(t_win *win, int bg_color);//TODO: Remove

// Algos
int		iter_julia(t_coordinates *c, t_coordinates *zn, int max_iter);
int		iter_mandelbrot(t_coordinates *c, int max_iter);

#endif
