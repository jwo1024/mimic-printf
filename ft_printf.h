#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	"./libft/libft.h"
# include	<stdarg.h>

typedef struct s_string
{
	char	specific;
	char	*s;
	size_t	s_len;
}	t_string;

typedef struct s_flags
{
	int		plus;
	int		minus;
	int		blank;
	int		sharp;
	int		zero;
	int		width;
	int		dot;
	size_t	len_width;
	size_t	len_dot;
}	t_flags;

int		ft_printf(const char *c, ...);
char	*prtf_conv_base(size_t n, size_t base, char *idx);
int		prtf_justr(const char **cptr);
int		prtf_form(const char **cptr, va_list *ap);
int		prtf_wrtfre_str(char c, t_string *str);
int		prtf_form_srch(char c, va_list *ap, t_string *str);
int		prtf_form_c(va_list *ap, t_string *str, char c);
int		prtf_form_s(va_list *ap, t_string *str);
int		prtf_form_di(va_list *ap, t_string *str);
int		prtf_form_p(va_list *ap, t_string *str);
int		prtf_form_u(va_list *ap, t_string *str);
int		prtf_form_x(va_list *ap, t_string *str, char c);
void	prtf_x_rmzero(t_string *str);
int		prtf_flags(const char **cptr, t_string *str, t_flags *flgs);
void	prtf_dot_width(t_flags *flgs, char c, const char **cptr);
int		prtf_apply_flgs(t_string *str, t_flags *flgs);
void	prtf_tmp_str(t_string *str, char c, size_t len, int left);
void	prtf_attach_front(t_string *str, char *attach);
void	prtf_flg_dot(t_string *str, t_flags *flgs);
void	prtf_flg_zero(t_string *str);
void	prtf_flg_blank(t_string *str, t_flags *flgs);
int		prtf_valid_flgs(t_string *str, t_flags *flgs);

#endif