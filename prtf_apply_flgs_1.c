/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_apply_flgs_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:37:33 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/28 02:28:50 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	prtf_apply_flgs(t_string *str, t_flags *flgs)
{
	if (flgs->dot == 1 && str->s)
		prtf_flg_dot(str, flgs);
	if (flgs->sharp == 1 && str->specific == 'x' && str->s)
		prtf_attach_front(str, "0x");
	else if (flgs->sharp == 1 && str->specific == 'X' && str->s)
		prtf_attach_front(str, "0X");
	if (flgs->plus == 1 && ft_strchr(str->s, '-') == NULL && str->s)
		prtf_attach_front(str, "+");
	if (flgs->width == 1 && str->s_len < flgs->len_width && str->s)
		prtf_tmp_str(str, ' ', flgs->len_width, flgs->minus);
	if (flgs->zero == 1 && str->s)
		prtf_flg_zero(str);
	if (flgs->blank == 1 && str->s[0] != ' '
		&& ft_strchr(str->s, '-') == NULL && str->s)
		prtf_flg_blank(str, flgs);
	if (str->s == NULL)
		return (0);
	return (1);
}

void	prtf_valid_flgs(t_string *str, t_flags *flgs)
{
	if (str->specific == 's' || str->specific == 'c' || str->specific == 'p')
	{
		flgs->plus = 0;
		flgs->blank = 0;
		flgs->sharp = 0;
		flgs->zero = 0;
		if (str->specific != 's')
			flgs->dot = 0;
	}
	else if (str->specific == 'x' || str->specific == 'X'
		|| str->specific == 'u' || str->specific == '%')
	{
		flgs->plus = 0;
		flgs->blank = 0;
		if (str->specific == '%')
			flgs->dot = 0;
	}
	if ((str->specific == 'u' || str->specific == 'd' || str->specific == 'i')
		|| (flgs->sharp == 1 && str->s[0] == '0' && str->s_len == 1))
		flgs->sharp = 0;
	if (flgs->zero == 1 && (flgs->minus == 1 || flgs->dot == 1))
		flgs->zero = 0;
	if (flgs->blank == 1 && flgs->plus == 1)
		flgs->blank = 0;
}
