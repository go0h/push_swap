/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:53:37 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 11:54:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_merge(int *res, int *arr, int start, int end)
{
	int	i;
	int	j;
	int	mid;
	int	idx;

	mid = (start + end) / 2;
	i = start;
	j = mid;
	idx = start;
	while (idx < end)
	{
		if (j >= end || (i < mid && arr[i] < arr[j]))
			res[idx] = arr[i++];
		else
			res[idx] = arr[j++];
		++idx;
	}
	return (0);
}

static int		ft_sort(int *arr, int *res, int start, int end)
{
	int mid;

	if (end - start < 2)
		return (0);
	else if (end - start == 2)
	{
		if (res[start] > res[start + 1])
		{
			res[start] = res[start] ^ res[start + 1];
			res[start + 1] = res[start + 1] ^ res[start];
			res[start] = res[start] ^ res[start + 1];
		}
		return (0);
	}
	mid = (end + start) / 2;
	ft_sort(res, arr, start, mid);
	ft_sort(res, arr, mid, end);
	ft_merge(res, arr, start, end);
	return (0);
}

int				ft_merge_sort(int *arr, int len)
{
	int	*copy;
	int	i;

	if (!(copy = ft_memalloc(sizeof(int) * len)))
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = arr[i];
		++i;
	}
	ft_sort(copy, arr, 0, len);
	free(copy);
	return (1);
}
