#include	"ft_printf.h"

void	prtf_flg_dot(t_string *str, t_flags *flgs)
{
	if (str->specific == 's' && flgs->len_dot < str->s_len)
		str->s_len = flgs->len_dot;
	else if (str->specific != 's')
	{
		if (flgs->len_dot >= str->s_len && str->s[0] == '-')
		{
			str->s[0] = '0';
			prtf_tmp_str(str, '0', flgs->len_dot, 0);
			prtf_attach_front(str, "-");
		}
		else if (flgs->len_dot > str->s_len)
			prtf_tmp_str(str, '0', flgs->len_dot, 0);
		else if (flgs->len_dot == 0 && str->s[0] == '0')
			str->s_len = 0;
	}
}

void	prtf_flg_zero(t_string *str)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < str->s_len)
	{
		if (str->s[i] == ' ')
			str->s[i] = '0';
		else if (str->s[i] == '-' || str->s[i] == '+')
		{
			c = str->s[i];
			str->s[i] = '0';
			str->s[0] = c;
			break ;
		}
		else if (str->s[i] == '0' && (str->s[i + 1] == 'x'
				|| str->s[i + 1] == 'X'))
		{
			str->s[0] = '0';
			str->s[1] = str->s[i + 1];
			str->s[i] = '0';
			str->s[i + 1] = '0';
		}
		i++;
	}
}

void	prtf_flg_blank(t_string *str, t_flags *flgs)
{
	if (str->s[0] == '0' && ft_isdigit(str->s[1]) && flgs->zero == 1)
		str->s[0] = ' ';
	else
	{
		prtf_attach_front(str, " ");
		if (flgs->width == 1)
			str->s_len--;
	}
}

void	prtf_tmp_str(t_string *str, char c, size_t len, int left)
{
	char	*tmp;

	tmp = str->s;
	str->s = (char *)malloc(sizeof(char) * (len + 1));
	if (str->s)
	{
		ft_memset(str->s, c, len);
		if (left == 1)
			ft_memcpy(str->s, tmp, sizeof(char) * str->s_len);
		else
			ft_strlcpy(&(str->s[len - str->s_len]), tmp, str->s_len + 1);
		str->s_len = len;
	}
	free(tmp);
}

void	prtf_attach_front(t_string *str, char *attach)
{
	char	*tmp;

	tmp = str->s;
	str->s = ft_strjoin(attach, str->s);
	str->s_len += ft_strlen(attach);
	free(tmp);
}
