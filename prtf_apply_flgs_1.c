/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_apply_flgs_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:44 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/03 14:41:46 by jiwolee          ###   ########.fr       */
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

int	prtf_valid_flgs(t_string *str, t_flags *flgs)
{
	if (str->specific == 's' || str->specific == 'p' || str->specific == 'c')
	{
		flgs->plus = 0;
		flgs->blank = 0;
		flgs->sharp = 0;
	}
	if (str->specific == '%')
	{
		flgs->plus = 0;
		flgs->blank = 0;
		flgs->sharp = 0;
		flgs->dot = 0;
	}
	if (flgs->sharp == 1 && str->s[0] == '0' && str->s_len == 1)
		flgs->sharp = 0;
	if (flgs->zero == 1 && (flgs->minus == 1 || flgs->dot == 1))
		flgs->zero = 0;
	if (flgs->blank == 1 && flgs->plus == 1)
		flgs->blank = 0;
	return (0);
}
