/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:35:59 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/07 19:36:13 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	res = (char *)malloc((s_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < s_len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substrp(char const *s, char const *start, size_t len)
{
	char	*sub_str;
	size_t	max_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	if (*start == '\0')
		return (ft_strdup(""));
	if (start < s || start > s + s_len)
		return (ft_strdup(""));
	max_len = ft_strlen(start);
	if (len < max_len)
		max_len = len;
	sub_str = malloc((max_len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	while (i < max_len && start[i])
	{
		sub_str[i] = start[i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
