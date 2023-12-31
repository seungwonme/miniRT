/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:29:19 by seunan            #+#    #+#             */
/*   Updated: 2023/12/12 15:27:48 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len < start)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	else if (len > s_len - start)
		str = ft_calloc(s_len - start + 1, sizeof(char));
	else
		str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len && start < s_len)
	{
		str[i] = s[start];
		++i;
		++start;
	}
	return (str);
}
