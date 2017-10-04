/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:10:38 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/02 21:58:03 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstadd_nb(t_list *lst, int nb,
		void const *content, size_t content_size);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen(char const *str);
void				ft_swap(int *a, int *b);
void				*ft_memset(void *ptr, int value, size_t num);
void				ft_bzero(void *ptr, size_t num);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memchr(const void *ptr, int value, size_t num);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char				*ft_strdup(char *str);
char				*ft_strcpy(char *cpy, char *src);
char				*ft_strncpy(char *cpy, char *src, size_t num);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, size_t num);
size_t				ft_strlcat(char *dest, char *src, size_t num);
char				*ft_strchr(char *str, int value);
char				*ft_strrchr(char *str, int value);
char				*ft_strstr(char *str1, char *str2);
char				*ft_strnstr(char *str1, char *str2, size_t num);
int					ft_strncmp(char *s1, char *s2, size_t num);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_split(char *str, char *charset);
int					ft_getnbr(char *str);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin3(char *s1, char *s2, char *s3);
void				*ft_check_malloc(void *assertion);

#endif
