/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:29:46 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:25:46 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <wchar.h>

/*
** wchar_t seems to be utf-32Big endian
*/

/*
** Print wchar_t (wide characters : unicode U+... UTF-32).
** Transform to UTF-8 char* then print with write.
*/

void	ft_putwchar_fd(wchar_t wc, int fd)
{
	char	s[4];
	int		nb_bytes;

	nb_bytes = ft_wctomb(s, wc);
	if (nb_bytes == -1)
		return ;
	write(fd, s, nb_bytes);
}

/*
** Below, a function to write a utf-8 int.
** Yet reading utf-8 from int isn't meant to be, sinces utf-8 are char[]
** Careful : unicode emoji U+... is not utf-8 but UTF-32 representation
*/

/*
** static unsigned char	ft_get_octet(size_t integer, int n)
** {
** 	return (integer >> ((n - 1) * CHAR_BIT));
** }
*/

/*
** void	ft_putchar_utf8_fd(unsigned int c, int fd)
** {
** 	size_t	len;
** 	unsigned char	tmp;
**
** 	len = 1;
** 	while (((ft_get_octet(c, len) >> 6) == 0b10) && len < sizeof(c))
** 		len++;
** 	while (len)
** 	{
** 		tmp = ft_get_octet(c, len--);
** 		write(fd, &tmp, 1);
** 	}
** }
*/
