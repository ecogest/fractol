/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:45:42 by mjacq             #+#    #+#             */
/*   Updated: 2021/11/29 11:01:59 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>

# define FT_MASK_1BIT	0x1
# define FT_MASK_2BIT	0x3
# define FT_MASK_3BIT	0x7
# define FT_MASK_4BIT	0xF
# define FT_MASK_5BIT	0x1F
# define FT_MASK_6BIT	0x3F
# define FT_MASK_7BIT	0x7F
# define FT_MASK_8BIT	0xFF
# define FT_MASK_11BIT	0x7FF
# define FT_MASK_16BIT	0xFFFF
# define FT_MASK_21BIT	0x1FFFFF
# define FT_MASK_24BIT	0xFFFFFF
# define FT_MASK_32BIT	0xFFFFFFFF

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

/*
** t_op is the optimal size handled by the proc
** on a 64bit proc it is int64_t, (long in linux)
** used in ft_memset
*/

typedef int64_t			t_op;

/*
** ================================= ft_is ================================== **
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isnumber(const char *str);
int					ft_isint(const char *str);

/*
** ================================= ft_to ================================== **
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long long n, int base);
int					ft_wctomb(char *s, wchar_t wc);

/*
** ================================= ft_str ================================= **
*/

size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
int					ft_stris(const char *s, int (*ft_is)(int c));
char				*ft_strnjoin(const char *s1, const char *s2, size_t n);
char				*ft_strappend(char**str, const char *suffix);
char				*ft_strnappend(char **str, const char *part2, size_t n);

/*
** ================================= ft_mem ================================= **
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, \
		size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void *ap);

/*
** ================================= ft_put ================================= **
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putchar_err(char c);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_err(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_err(const char *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_err(int n);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwchar(wchar_t chr);

/*
** ================================= ft_lst ================================= **
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new_lst_elem);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new_lst_elem);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

/*
** ================================ ft_math ================================= **
*/

int					ft_int_abs(int x);
int					ft_int_max(int x, int y);
int					ft_int_min(int x, int y);

#endif
