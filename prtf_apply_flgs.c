/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:38:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/02/23 15:33:07 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	prtf_apply_flgs(t_string *str, t_flags *flgs)
{
	if (str->s[0] == '0' && str->s_len == 1) //0일경우 처리
		flgs->sharp = 0;
	if (flgs->dot == 1)
		prtf_flg_dot(str, flgs);
	if (flgs->width == 1 && str->s_len < flgs->len_width)
		prtf_tmp_str(str, ' ', flgs->len_width, flgs->minus);
	if (flgs->zero == 1 && flgs->dot == 0)
		prtf_flg_zero(str);
	if (flgs->sharp == 1)
	{
		if (str->specific == 'x')
			prtf_attach_front(str, "0x");
		else if (str->specific == 'X')
			prtf_attach_front(str, "0X");
	}
	if (flgs->blank == 1 && ft_strchr(str->s, '-') == NULL && str->specific != 's')
		prtf_attach_front(str, " ");
	if (flgs->plus == 1 && ft_strchr(str->s, '-') == NULL)
		prtf_attach_front(str, "+");


	if (str->s == NULL)
		return (0);
	return (1);
}

void	prtf_flg_dot(t_string *str, t_flags *flgs)
{
	if ((str->specific == 's') && flgs->len_dot < str->s_len) // s, 일경우
			str->s_len = flgs->len_dot; // 길이에 맞게 앞 기준으로 뒷문자 자르기 꼼수인가;
	else if (str->specific != 's' && str->specific != 'c' && str->specific != 'p')
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

	i = 0;
	while (i < str->s_len)
	{
		if (str->s[i] == ' ')
			str->s[i] =  '0';
		else if (str->s[i] == '-')
		{
			str->s[i] = '0';
			str->s[0] = '-';
			break;
		}
		i++;
	}
}

void	prtf_tmp_str(t_string *str, char c, size_t len, int left) //return();, 
{
	char *tmp;

	tmp = str->s;
	str->s = (char *)malloc(sizeof(char) * (len + 1));
	ft_memset(str->s, c, len);
	if (left == 1)
		ft_memcpy(str->s, tmp, sizeof(char) * str->s_len);
	else
		ft_strlcpy(&(str->s[len - str->s_len]), tmp, str->s_len + 1);
	str->s_len = len;
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