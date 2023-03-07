/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 17:16:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	expand_hooks(int key, t_FdF_info *fdf)
{
	if (key == KEY_I)
		i_hook(fdf);
	if (key == KEY_K)
		k_hook(fdf);
	if (key == KEY_Z)
		z_hook(fdf);
	if (key == KEY_X)
		x_hook(fdf);
	if (key == KEY_SPACE)
		space_hook(fdf);
	if (key == KEY_ARROW_LEFT)
		left_hook(fdf);
	if (key == (KEY_ARROW_RIGHT))
		right_hook(fdf);
}

static int	key_hook(int key, t_FdF_info *fdf)
{
	ft_printf("Valor de la key %d\n", key);
	if (key == KEY_A)
		a_hook(fdf);
	if (key == KEY_D)
		d_hook(fdf);
	if (key == KEY_ESCAPE)
		close_fdf(fdf);
	if (key == KEY_S)
		s_hook(fdf);
	if (key == KEY_W)
		w_hook(fdf);
	if (key == KEY_H)
		h_hook(fdf);
	if (key == KEY_Y)
		y_hook(fdf);
	if (key == KEY_U)
		u_hook(fdf);
	if (key == KEY_J)
		j_hook(fdf);
	expand_hooks(key, fdf);
	return (0);
}

void	ft_hooks(t_FdF_info *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_fdf, fdf);
	mlx_hook(fdf->win, 4, 0, scroll_hook, fdf);
	mlx_hook(fdf->win, 5, 0, scroll_hook, fdf);
}
