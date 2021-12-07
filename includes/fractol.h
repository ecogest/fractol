/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:26:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 09:59:25 by mjacq            ###   ########.fr       */
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

// Used for more complex mlx_hook calls (need x_event, x_mask)
# include "X11/X.h"
// Clearer names than "Button1", "Button2", ..., "Button5"
# define LEFT_CLICK 1
# define MIDDLE_CLICK 2
# define RIGHT_CLICK 3
# define ZOOM_IN 4
# define ZOOM_OUT 5

/*
** ================================ Defines ================================= **
*/

// window dimentions
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

// Zoom speed
# define ZOOM_SPEED 1.1

// Find beautiful palettes here: https://coolors.co/palettes/trending
# define COLOR_MAX 0x264653
# define COLOR_ONE 0x2a9d8f
# define COLOR_TWO 0xe9c46a
# define COLOR_THREE 0xf4a261
# define COLOR_BG 0xe76f51

// Number of iterations on startup and floor cap of this number
# define MAX_ITER_START 16
# define MIN_ITER 14

// Three thresholds to select a display color according to the number of iter
// required before ruling a pixel out of the fractal set
# define ITER_THRESHOLD_1 4
# define ITER_THRESHOLD_2 8
# define ITER_THRESHOLD_3 12

// Julia default parameters
# define JULIA_DEF_X 0.3
# define JULIA_DEF_Y 0.5

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
** scale_start: used to adjust max_iter when zooming
*/

typedef struct s_figure
{
	t_figname		name;
	t_coordinates	c_julia;
	t_colors		colors;
	t_offset		offset;
	float			scale;
	float			scale_start;
	int				max_iter;
}					t_figure;

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
void	f_usage(void);

// Hook and loop
void	f_hook_and_loop(t_root *root);
int		hook_zoom(int button, int x, int y, t_root *root);

// Drawing functions
void	img_px_put(t_img *img, t_pixel *px);
void	win_put_bg(t_win *win, int bg_color);//TODO: Remove
void	win_put_figure(t_win *win, t_figure *fig);

// Algos
int		iter_julia(t_coordinates *c, t_coordinates *zn, int max_iter);
int		iter_mandelbrot(t_coordinates *c, int max_iter);

#endif
