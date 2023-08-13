/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:39:28 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/13 15:34:20 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define FLAGS		"cspdiuxX%"
# define INT_MAX	2147483647

# define BUFFER_SIZE 42

typedef enum s_tk_type
{
    TK_EOF,
    TK_WORD,
    TK_NO,
    TK_SO,
    TK_EA,
    TK_WE,
}   t_tk_type;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_list
{
	void			*content;
	t_tk_type		tk_type;
	struct s_list	*next;
}	t_list;

/*	GNL		*/
char	*ft_get_next_line(int fd);

/*	PRINTF	*/
int		ft_printf(const char *format, ...);
int		ft_hex(unsigned long nb, char *base);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
int		md_puthex(unsigned long nb, char format);
int		md_putchar(char str);
int		md_putstr(char *str);
int		md_putnbr(int nb);
int		md_unsigned_putnbr(unsigned int nb);

/*	LIBFT	*/
int		ft_atoi(const char *nptr);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nbyte, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	**ft_split(char const *str, char delimiter);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*	My		*/
int		ft_isspace(int c);
void	ft_free(void **ptr);
t_list	*ft_lstdup(t_list *lst);
size_t	ft_strlen_split(char **s);
void	ft_free_split(char **str);
char	**ft_array_dup(char **array);
char	**ft_convert_array(t_list *token);
char	*ft_strjoin_free(char *s1, const char *s2);
char	*ft_strreplace(char *str, char *oldw, char *neww);
#endif