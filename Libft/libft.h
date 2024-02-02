/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:44:48 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/19 14:58:20 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t nb);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strchr(const char *str, int o);
char		*ft_strdup(const char *str1);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char		*ft_strrchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t num);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t num);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
const void	*ft_memchr(const void *ptr, int o, size_t num);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strtrim(char const *s1, char const *set);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		*ft_free_all_tab(char **dest);
int			ft_putchar(unsigned char c);
int			ft_putstr(char *c);
int			ft_putnbr(int nbr);
int			ft_putnbr_hexa(size_t nbr, char *base);
int			ft_put_u_nbr(unsigned int nbr);
int			ft_hexa_pointer(void *pt, char *base);
int			ft_printf(const char *format, ...);
char		*get_next_line(int fd);
char		*ft_strjoin_f(char *s1, char *s2);
int			ft_strchr_bis(char *src);
char		*ft_strlcpy_f(char *src, int len);
int			ft_toupper_hexa(int c);
int			ft_ishexa(char c);
int			ft_atoi_hexa(char *src);

#endif
