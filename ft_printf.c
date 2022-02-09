//#include	"ft_printf.h"
#include	<stdarg.h>
#include	<stdlib.h>

typedef struct hello 
{
	int	c_flg;
	int	s_flg;
} hi;

static int		ft_specific(const char **cptr, char *str, va_list ap);
static int		ft_justr(const char **cptr, char *str);

int	ft_printf(const char *c, ...)
{
	char		*str;
	va_list		ap;
	int			flag; //필요한가?
	int			rtn;

	flag = 1;
	va_start(ap, c);
	
	while (*c)
	{
		if (*c == '\0' && flag == 0)
			break;
		else if (*c == '%')
		{
			flag = ft_percent(&c, str, ap); //?? ap 전달 가능 한가? ㅇㅇ
		}
		else
			flag = ft_just_str(&c, str);
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

	len = 0;
	while (**cptr != '%' && **cptr != '\0')
		len++;
	tmp = ft_substr(*cptr, 0, len);
	str = ft_strjoin(str, tmp);
	free(tmp);
	*cptr += len;
	return (1);
}

static int		ft_specific(const char **cptr, char *str, va_list ap)
{
	//
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