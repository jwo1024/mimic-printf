#include    "ft_printf.h"
/*
#include    <stdarg.h>
#include	<stdio.h>

int ft_printf(const char *c, ...);

char    *ft_conv_dec(size_t n, size_t to);
int     ft_prtf_justr(const char **cptr);
int     ft_prtf_form(const char **cptr, va_list *ap);
int     ft_form(char c, va_list *ap, char **nbr);
int     ft_form_c(va_list *ap, char **str, char c);
int     ft_form_s(va_list *ap, char **str);
int     ft_form_di(va_list *ap, char **str);
int     ft_form_p(va_list *ap, char **str);
int     ft_form_u(va_list *ap, char **str);
int     ft_form_xX(va_list *ap, char **str, char c);
*/
/*
int main(void)
{
    int i = -392;
	int	k = 99;
	char c = 'a';
	char *a = "9!";
	int	rtn;

    rtn = ft_printf("123\n%x\n%u\n%i\n", i, i, i);
	printf("rtn = %d\n", rtn);
    return (0);
}
*/
// 자료형 - 서식문자 합 맞는지 확인 필요 ? 어떻게? 

int ft_printf(const char *c, ...)
{
	va_list ap;
	int len;
	int rtn;

	va_start(ap, c);
	len = 1;
    rtn = 0;
	while(*c != '\0') // c는 함수 파라미터로 포인터 주소를 넣어 돌려준다.(&c)
	{
		if (*c == '%')
		{
			len = ft_prtf_form(&c, &ap);
		}
		else // 일반 문자열일때
			len = ft_prtf_justr(&c);
		if (len == -1) // 실패시 -1
		{
			rtn = len;
			break;
		}
		rtn += len;
	}
	va_end(ap);
	return(rtn);
}


int ft_prtf_justr(const char **cptr) //일반 문자열 일때
{
	int     len;

	len = 0;
	while((*cptr)[len] != '\0' && (*cptr)[len] != '%')
	{
		ft_putchar_fd((*cptr)[len], 1);
		len++;
	}
	*cptr += len;
	return (len);
}


int ft_prtf_form(const char **cptr, va_list *ap) //%일때
{
	int i;
	int rtn;
	char	a;
	char *str; //더블포인터로 설정 해야하나?? 어떻게 하지
	
	i = 0;
	rtn = 0;

	(*cptr)++;
	while(1) //서식문자 찾기
	{
		a = (*cptr)[i];
		i++;
		rtn = ft_form(a, ap, &str);
		if(rtn == 1)
			break;
		else if(a == '\0' || rtn == -1)
		{
			rtn = -1; //서식문자를 찾지 못하면 잘못된입력 // 플래그 몇개 이상이면, 
			break;
		}
	}

/*
	if(i > 1 && rtn != -1) //i 가 1보다 크다면 플래그가 존재한다는 뜻
	{
		//while // 서식문자 flag에 맞게 편집
		// 플래그에 맞게 nbr 을 편집하여 새로운 nbr을 만들음
	}
*/

// print str
	if(str != NULL || rtn != -1)
	{
		rtn = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	*cptr += i;
	return (rtn); // 연결부분 수정필요 길이를 반환하던지 그래야함
}


int ft_form(char c, va_list *ap, char **nbr)
{
	int rtn;

	rtn = 0;
	if (c == '%'|| c == 'c')
		rtn = ft_form_c(ap, nbr, c);
	else if (c == 's')
		rtn = ft_form_s(ap, nbr);
	else if (c == 'd' || c == 'i')
		rtn = ft_form_di(ap, nbr);
	else if (c == 'p')
		rtn = ft_form_p(ap, nbr);
	else if (c == 'u')
		rtn = ft_form_u(ap, nbr);
	else if (c == 'x' || c == 'X')
		rtn = ft_form_xX(ap, nbr, c);
	return (rtn);
}


int ft_form_c(va_list *ap, char **str, char c) //'\0' 출력하도록
{
	*str = (char *)malloc(sizeof(char) * 2);
	if(*str)
	{
		if (c == '%')
			(*str)[0] = '%';
		else if (c == 'c')
			(*str)[0] = va_arg(*ap, int);// char 은 int 로 접근 // 사유 찾기
        (*str)[1] = '\0';
	    return (1);
	}
	return (0);
}


int ft_form_s(va_list *ap, char **str)
{
	char *s;
	
	s = va_arg(*ap, char *);
	if (s)
	{
		*str = ft_substr(s, 0, ft_strlen(s) + 1);
		if (*str)
			return (1);
	}
	
	return (-1);
}


int ft_form_di(va_list *ap, char **str)
{
	int		n;
	char	*tmp;

	n = va_arg(*ap, int);
	if (n < 0)
	{
		if(n == -2147483648)
			*str = ft_substr("-2147483648", 0, 12);
		else
		{
			n *= -1;
			tmp = ft_conv_dec(n, 10);
			*str = ft_strjoin("-", tmp);
			free(tmp);
		}
	}
	else
		*str = ft_conv_dec(n, 10);
	if (*str == NULL)
		return(0);
	return (1);
}


int ft_form_p(va_list *ap, char **str) //16진수 다루는 p, x, X 합칠수? 안될듯
{
	size_t n; //주소는 양수만
	void *p;
	char *tmp;	

	p = va_arg(*ap, void *);
	n = (size_t)p;
	tmp = ft_conv_dec(n, 16); //n을 16진수로 변환
	// 앞에 0x 달아주기,,
	*str = ft_strjoin("0x", tmp);
	free(tmp); //어디서 free 해야하지
	if (str == NULL)
		return (0);
	return (1);
}


int ft_form_u(va_list *ap, char **str)
{
	unsigned int n;

	n = va_arg(*ap, unsigned int);
	*str = ft_conv_dec(n, 10); // unsigned int -> size_t ??
	if (*str == NULL)
		return(0);
	return (1);
}


int ft_form_xX(va_list *ap, char **str, char c) //자리수 8개 맞추기 X일경우 확인
{
	size_t	n; //x, X는 부호 없는 16진법 정수
	char	*tmp;
	size_t	rtn;

	rtn = 0;
	n = (size_t)va_arg(*ap, size_t); //size_t로 읽는게 맞나
	tmp = ft_conv_dec(n, 16);
	if (tmp)
	{
		if (ft_strlen(tmp) > 8)
		{
			*str = ft_substr(tmp, ft_strlen(tmp) - 8, ft_strlen(tmp) + 1);
			free(tmp);
		}
		else
			*str = tmp;
		if (c == 'X')
		{
			n = 0;
			while((*str)[n])
			{
				(*str)[n] = ft_toupper((*str)[n]);
				n++;
			}
		}
		if (*str)
			rtn = 1;
	}
	return(rtn);
}

//			*str = ft_strjoin("", tmp);  //0x
// ok;

char    *ft_conv_dec(size_t n, size_t to) // oct 수정! -> dec // ft_dectoa();
{
    size_t a; //tmp 이름 바꾸기
	size_t l;
	char idx[20];
	char *nbr;
	
	ft_strlcpy(idx, "0123456789abcdef", 20); //20 조절 
	l = 0;
	a = n;
	while (a)
	{
		a = a / to;
		l++;
	}
	if (n == 0)
		l++;
	nbr = (char *)malloc(sizeof(char) * (l + 1));
	if (nbr)
	{
		a = 0;
		while(a < l)
		{
			nbr[l - a - 1] = idx[n % to];
			n = n / to;
			a++;
		}
	}
	nbr[a] = '\0';
	return (nbr);
}