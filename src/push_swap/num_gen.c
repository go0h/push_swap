/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:25:09 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/22 12:12:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <time.h>

static void		num_gen(int fd, int low, int high, int len)
{
	int i;

	if (low < 0)
		high = ft_abs(high) + ft_abs(low);
	srand(time(NULL));
	i = 0;
	len -= 1;
	while (i < len)
	{
		ft_fprintf(fd, "%d ", low + rand() % high);
		++i;
	}
	ft_fprintf(fd, "%d", low + rand() % high);
}

int				main(int argc, char **argv)
{
	int	fd;
	int	a;
	int	b;

	if (argc != 4)
	{
		ft_printf("Usage: ./num_gen a b len\n");
		return (0);
	}
	if (!(fd = open("num", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
	{
		ft_printf("Can't create file. Please try again.\n");
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);
	if (a >= b || ft_atoi(argv[3]) == 0)
	{
		ft_printf("Wrong input! Please follow next instuctions:\
				a < b and len < 0\n");
		return (0);
	}
	num_gen(fd, a, b, ft_atoi(argv[3]));
	close(fd);
	return (0);
}
