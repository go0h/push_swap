/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:06:26 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/13 12:27:23 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "push_swap.h"

#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define WIDTH_SCREEN 170
#define HEIGHT_SCREEN 48

void	ft_clear_screen(void);

void	ft_go_to_x_y(int x, int y);

#endif
