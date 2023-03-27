/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:27:41 by yuikim            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/21 09:50:55 by yuikim           ###   ########.fr       */
=======
/*   Updated: 2023/03/24 19:15:25 by yuikim           ###   ########.fr       */
>>>>>>> 3a466dac3023b8c79137419bc4f22deb35115200
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strdup(const char *src)
=======
char	*ft_strdup(char *src)
>>>>>>> 3a466dac3023b8c79137419bc4f22deb35115200
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (0);
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = 0;
	return (dest - src_len);
}
