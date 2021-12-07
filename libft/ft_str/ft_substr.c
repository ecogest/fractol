/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:12:40 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/10 17:27:11 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a substring.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;
	size_t	effective_len;

	if (!s)
		return (NULL);
	while (*s && start--)
		s++;
	effective_len = 0;
	while (s[effective_len] && effective_len < len)
		effective_len++;
	substr = malloc(sizeof(*substr) * (effective_len + 1));
	if (!(substr))
		return (NULL);
	i = 0;
	while (*s && len--)
		substr[i++] = *s++;
	substr[i] = '\0';
	return (substr);
}
