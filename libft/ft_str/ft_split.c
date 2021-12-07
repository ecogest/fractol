/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:46:06 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:03:23 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_piece(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_n_pieces(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	if (*s)
	{
		while (*s && *s != c)
			s++;
		return (ft_n_pieces(s, c) + 1);
	}
	return (0);
}

static char	**ft_cleartab(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		ft_bzero(t[i], ft_strlen(t[i]));
		free(t[i]);
		t[i++] = NULL;
	}
	free(t);
	t = NULL;
	return (NULL);
}

/*
** Split string at each char delimiter. Return NULL terminated array of strings.
*/

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	t = (char **)malloc(sizeof(*t) * (ft_n_pieces(s, c) + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = ft_len_piece(s, c);
			t[i] = ft_strsub(s, 0, len);
			if (!t[i++])
				return (ft_cleartab(t));
			s += len;
		}
	}
	t[i] = NULL;
	return (t);
}
