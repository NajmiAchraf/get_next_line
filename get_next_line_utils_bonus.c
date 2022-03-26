/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:13:16 by anajmi            #+#    #+#             */
/*   Updated: 2021/12/04 23:13:13 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	char	*b;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	b = (char *) str;
	while (i < (count * size))
	{
		b[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int readsize)
{
	char			*cat;
	unsigned int	i;
	unsigned int	a;

	s2[readsize] = '\0';
	if (!s1)
		s1 = ft_substr("", 0, 1);
	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!cat)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		cat[i + a] = s2[a];
		a++;
	}
	cat[i + a] = '\0';
	freeing(&s1);
	return (cat);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*out;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && len > i)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	char	check;
	char	*out;
	size_t	len;

	check = (char) c;
	out = (char *) s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (*out == check)
			return (out);
		out++;
		len--;
	}
	if (len == 0 && *out == check)
		return (out);
	return (NULL);
}
