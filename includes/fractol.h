/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:26:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 09:57:15 by mjacq            ###   ########.fr       */
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

/*
** ================================= Enums ================================== **
*/

typedef enum e_error
{
	success = 0,
	error
}	t_error;

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
