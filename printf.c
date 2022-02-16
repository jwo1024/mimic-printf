//#include	"ft_printf.h"
#include	<stdarg.h>
#include	<stdlib.h>

typedef struct hello 
{
	int	c_flg;
	int	s_flg;
} hi;

int		ft_form(const char **cptr, char *str, va_list ap);

static int		ft_justr(const char **cptr, char *str);
static int      ft_isspc(char c, char str, va_list ap); // cal 에서 static 처리

int	ft_printf(const char *c, ...)
{
	char		*str;
	va_list		ap;
	int			flag; //필요한가?
	int			rtn;

	flag = 1; //작동중 실패 할 경우 0으로 변환
	va_start(ap, c);
	
	while (*c)
	{
		if (*c == '\0' && flag == 0)
			break;
		else if (*c == '%')
		{
			flag = ft_form(&c, str, ap); //?? ap 전달 가능 한가? ㅇㅇ ap = 포인터
		}
		else
			flag = ft_justr(&c, str);
	}
	va_end(ap);
	ft_putstr_fd(str, 1);
	rtn = ft_strlen(str);
	free(str);
	return(rtn);
}

static int	ft_justr(const char **cptr, char *str)
{
	size_t	len;
	char	*tmp;
	char	*tmp2;

	len = 0;
	while (**cptr != '%' && **cptr != '\0')
		len++;
	tmp = ft_substr(*cptr, 0, len);
	tmp2 = str;
	//realloc str?;
	str = ft_strjoin(str, tmp); // str, str 겹침 문제
	free(tmp);
	free(tmp2);
	*cptr += len;
	return (1);
}

int		ft_form(const char **cptr, char *str, va_list ap)
{
	char	*nbr;
	int		idx;

	idx = 0;
	*cptr++;
	if (**cptr == '%'|| ft_isspc_c()) // isspcc_c,, c, s 일경우 str 에 문자열 그대로 더하기
		return ;// %출력 str 에 더하기
	else
	{
		while (*cptr[idx] != '%' || *cptr[idx] != '\0')
		{
			if (ft_isspc_n(*cptr[idx], nbr, ap))
				break;
			
			idx++;
		}
	}
	// str 에 nbr 더하기 join
	

	*cptr += idx;
	return (1); //?
}

static int      ft_isspc_n(char c, char *nbr, va_list ap) // 문자랑 숫자랑 분리하기 isspcc c,s/ isspcn 나머지
{
	if (c == 'p')
		ft_prnf_p();
	else if (c == 'd')
		ft_prnf_d();
	else if (c == 'l')
		ft_prnf_l();
	else if (c == 'u')
		ft_prnf_u();
	else if (c == 'x')
		ft_prnf_x();
	else if (c == 'X')
		ft_prnf_X();
	else
		return (0);
	// if else 문에서 ap 내용물을 문자열로 nbr에 할당
	// ?? 뭐하려 했지 
	return (1);
}

void	ft_prnf_c(char *nbr, va_list ap)
{
	char c;

	c = va_arg(ap, char);
	nbr = ft_calloc(2);
	nbr[0] = c;
}

void	ft_prnf_s()
{
	
}

//	while (/*c 처음부터 끝까지 */ 1)
//	{
		/* if (just_str(char *str, c의 위치))
			while (*c != '%' || *c != '\0')
				c++; */
		/* str_with_percent(char *str, c의 위치) */

//	}
	//find str and print str
		//검사 및 프린트할 str(malloc) 할당 후 
		//프린트할 str이 있을 경우 print and free str
		//없을 경우 그냥 지나감;
	//find % percent point to specifier서식문자
		//그 후는 무조건 % or \0