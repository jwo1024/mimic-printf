
int ft_printf(const char *c, ...)
{
	int len;
	int rtn;
	char **cptr;

	cptr = &c;
	va_start(ap, c);

	while(*c != '\0') // c++ 은 함수 파라미터로 포인터 주소를 넣어 돌려준다.(&c)
	{
		if (*c == '%')
			len = ft_prtf_form(cptr, ap, );
		else // 일반 문자열일때
			len = ft_prtf_justr(cptr);
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

int ft_prtf_justr(const char **cptr, va_list ap, ) //일반 문자열 일때
{
	int len;

	len = 0;
	while(*cptr[len] != '\0' && *cptr[len] != '%')
	{
		ft_putchar_fd(*cptr[len], 1);
		len++;
	}
	*cptr += len;
	return (len);
}

int ft_prtf_form(const char **cptr, va_list ap) //%일때
{
	int i;
	int rtn;
	char **nbr; //더블포인터로 설정 해야하나?? 어떻게 하지
	
	i = 0;
	rtn = 1;
	*cptr++; //% 넘겨주기
	if (ft_form_cs(cptr, ap))
		*cptr++;
	else
	{
		while(1) //서식문자 찾기
		{
			if(ft_form(*cptr[i], ap, nbr))
				break;
			else if(*cptr[i] == '\0' || *cptr[i] == '%') //서식문자를 찾지 못하면 잘못된입력
			{
				rtn = -1;
				break;
			}
			i++;
		}
		if(i > 1 && rtn != -1) //i 가 1보다 크다면 플래그가 존재한다는 뜻
		{
			//while // 서식문자 flag에 맞게 편집
			// 플래그에 맞게 nbr 을 편집하여 새로운 nbr을 만들음
		}
		ft_putstr_fd(*nbr, 1);//nbr출력
		free(nbr);
		*cptr += i;
	}

	return (rtn);
}

int ft_form_cs(const char **cptr, va_list ap)
{
	char c;
	char *s;

	if (**cptr == '%')
		ft_putchar_fd('%', 1);
	else if (**cptr == 'c')
	{
		c = va_arg(ap, int);// char 은 int 로 접근 // 사유 찾기
		ft_putchar_fd(c, 1) 
	}
	else if (**cptr == 's')
	{
		s = va_arg(ap, char*); // string 은 어떻게 접근하지? 
		while (*s)
		{
			ft_putchar_fd(*s, 1);
			s++;
		}
	}
	else
		return (0);
	return (1);
}

int ft_form(char c, va_list ap, char **nbr)
{
	int rtn;

	rtn = 0;
	if (c == 'd' || c == 'i')
		rtn = ft_form_di(ap, nbr);
	else if (c == 'p')
		rtn = ft_form_p(ap, nbr);
	else if (c == 'u')
		rtn = ft_form_u(ap, nbr);
	else if (c == 'x')
		rtn = ft_form_xX(ap, nbr, "0x");
	else if (c == 'X')
		rtn = ft_form_xX(ap, nbr, "0X");
	return (rtn);
}

int ft_form_di(va_list ap, char **nbr)
{
	int n;

	// 부호 추가,,,
	n = va_arg(ap, int);
	*nbr = ft_itoa(n);
	if (*nbr == NULL)
		return(0);
	return (1);
}

int ft_form_p(va_list ap, char **nbr) //16진수 다루는 p, x, X 합칠수? 안될듯
{
	size_t n; //주소는 양수만
	void *p;
	
	p = va_arg(ap, void *);
	n = &p;
	*nbr = ft_conv_oct(n, 16); //n을 16진수로 변환
	// 앞에 0x 달아주기,,
	if (*nbr == NULL)
		return (0);
	return (1);
}

int ft_form_u(va_list ap, char *nbr)
{
	// 부호없이 10진법
}

int ft_form_xX(va_list ap, char *nbr)
{
	size_t n; //x, X는 부호 없는 16진법 정수
	char *tmp;
	int rtn;

	n = (size_t)va_arg(ap, int);
	rtn = 0;
	*tmp = ft_conv_oct(n, 16);
	if (tmp)
	{
		*nbr = (char *)malloc();
		if(nbr)
		{
			//nbr에 0x, 0X 붙이고, nbr + tmp
			rtn = 1;
		}
		free(tmp)
	}
	return(rtn);
}



