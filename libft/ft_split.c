/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:59:09 by jiwolee           #+#    #+#             */
/*   Updated: 2022/01/21 23:36:54 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	**mk_arr(char const *s, char c);
static char	**split_words(char **arr, char const *s, char c);
static void	clear_words(char **arr, size_t cnt);

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = mk_arr(s, c);
	if (!arr)
		return (NULL);
	arr = split_words(arr, s, c);
	return (arr);
}

static char	**split_words(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	size_t	k;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			k = i;
			while (s[k] && s[k] != c)
				k++;
			arr[cnt] = ft_substr(s, i, k - i);
			if (!arr[cnt])
			{
				clear_words(arr, cnt);
				return (NULL);
			}
			cnt++;
		}
		i++;
	}
	arr[cnt] = NULL;
	return (arr);
}

static char	**mk_arr(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	char	**arr;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cnt++;
		i++;
	}
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (arr);
}

static void	clear_words(char **arr, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
