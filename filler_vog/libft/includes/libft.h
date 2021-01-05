/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:14:53 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/12 20:27:15 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>

# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Functions that manipulate memory
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);

/*
** Check or change char
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isblank(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** Str and atoi
*/

int				ft_atoi(const char *str);
__int128_t		ft_pow(__int128 base, long long pow);
int				ft_abs(int nb);
size_t			ft_count_words(char const *s, char c);
char			*ft_itoa(int n);
int				ft_intlen(int n);
int				ft_ulllen(unsigned long long n, int len);
char			*ft_ulltoa_base(unsigned long value, int base);
int				ft_lllen(long long n, int len);
char			*ft_lltoa(long long value);
int				ft_bigintlen(__int128_t n, int base);
void			ft_swap(int *a, int *b);
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strdup_free(char *src, int fre);
char			*ft_strndup_free(char *src, int n, int fre);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char const *s1, char const *s2, int fre);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_strrev(char *str, int len);
char			*ft_strround_up(char *s, int len, int zero);

/*
** 2-D Arrays
*/

int				ft_strarr_size(char **arr);
char			**ft_strarr_malloc(int rows, int cols);
void			ft_strarr_free(char **arr);
int				**ft_tabarr_malloc(int max_rows, int max_cols);
void			ft_tabarr_free(int **tab, int max_rows);

/*
** Ways to print
*/

void			ft_tabarr_print(int **arr, int max_rows, int max_cols);
void			ft_tabarr_print_fd(int **arr, int max_rows, \
						int max_cols, int fd);
void			ft_strarr_print_fd(char **arr, int fd);
void			ft_strarr_print(char **arr);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
int				ft_putstr_ret_fd(char const *str, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

/*
** Functions that manipulate lists:
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
