/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:52:41 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 14:58:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_pixel_put(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img->adres + (y * img->line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
