#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include    "./libft/libft.h"
# include    <stdarg.h>

int		ft_printf(const char *c, ...);
char	*ft_conv_dec(size_t n, size_t to);
int		ft_prtf_justr(const char **cptr);
int		ft_prtf_form(const char **cptr, va_list *ap);
int		ft_wrtfre_str(char	c, char *str);
int		ft_form(char c, va_list *ap, char **nbr);
int		ft_form_c(va_list *ap, char **str, char c);
int		ft_form_s(va_list *ap, char **str);
int		ft_form_di(va_list *ap, char **str);
int		ft_form_p(va_list *ap, char **str);
int		ft_form_u(va_list *ap, char **str);
int		ft_form_xX(va_list *ap, char **str, char c);
void	ft_form_X(char **str);

#endif