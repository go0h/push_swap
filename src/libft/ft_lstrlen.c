/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:20:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/12 16:11:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_lstrlen(const int *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s < 128)
			++i;
		else if (*s < 2048)
			i += 2;
		else if (*s < 65536)
			i += 3;
		else if (*s < 1114112)
			i += 4;
		++s;
	}
	return (i);
}
