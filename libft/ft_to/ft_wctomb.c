/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:46:52 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 19:39:27 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

/*
** wchar_t seems to be utf-32Big endian
*/

static int	ft_wctomb_count_bytes(wchar_t wc)
{
	if (!(wc & ~FT_MASK_7BIT))
		return (1);
	else if (!(wc & ~FT_MASK_11BIT))
		return (2);
	else if (!(wc & ~FT_MASK_16BIT))
		return (3);
	else if (!(wc & ~FT_MASK_21BIT))
		return (4);
	else
		return (-1);
}

/*
** Wide char to multibyte. s memory must be already allocated.
** Does not automatically adds a '\0' at the end of the string.
**
** Ex char s[4]; ft_wctomb(s, L'🌺');
*/

int	ft_wctomb(char *s, wchar_t wc)
{
	int	nbytes;
	int	ret;

	if (!s)
		return (0);
	nbytes = ft_wctomb_count_bytes(wc);
	if (nbytes == -1)
		return (-1);
	ret = nbytes;
	ft_bzero(s, nbytes);
	if (nbytes > 1)
		s[0] |= (1 << 7);
	while (nbytes > 1)
	{
		s[--nbytes] = (0b10 << 6) | (wc & FT_MASK_6BIT);
		s[0] |= (1 << (7 - nbytes));
		wc >>= 6;
	}
	s[0] |= wc;
	return (ret);
}

/*
** An other way (simpler, less optimized to compile ft_wctomb)
*/

/*
** static wchar_t	ft_nbitswchar(int nbits)
** {
** 	return ((1 << ((wchar_t)nbits)) - 1);
** }
*/

/*
** int		ft_wctomb(char *s, wchar_t wc)
** {
** 	int	nbytes;
** 	int	ret;
**
** 	if (!s)
** 		return (0);
** 	if (wc <= ft_nbitswchar(7))
** 	{
** 		*s = wc;
** 		return (1);
** 	}
** 	else if (wc <= ft_nbitswchar(5 + 6))
** 	{
** 		s[1] = (0b10 << 6) | (wc & ft_nbitswchar(6));
** 		wc >>= 6;
** 		s[0] = (0b110 << 5) | (wc & ft_nbitswchar(5));
** 		return (2);
** 	}
** 	else if (wc <= ft_nbitswchar(4 + 6 + 6))
** 	{
** 		s[2] = (0b10 << 6) | (wc & ft_nbitswchar(6));
** 		wc >>=6;
** 		s[1] = (0b10 << 6) | (wc & ft_nbitswchar(6));
** 		wc >>=6;
** 		s[0] = (0b1110 << 4) | (wc & ft_nbitswchar(4));
** 		return (3);
** 	}
** 	else if (wc <= ft_nbitswchar(3 + 6 + 6 + 6))
** 	{
** 		s[3] = (0b10 << 6) | (wc & ft_nbitswchar(6));
** 		wc >>=6;
** 		s[2] = (0b10 << 6) | (wc & ft_nbitswchar(6));
** 		wc >>=6;
** 		s[1] = (0b10 << 6) | (wc & ft_nbitswchar(6));
** 		wc >>=6;
** 		s[0] = (0b11110 << 3) | (wc & ft_nbitswchar(3));
** 		return (4);
** 	}
** 	else
** 		return (-1);
** }
*/
