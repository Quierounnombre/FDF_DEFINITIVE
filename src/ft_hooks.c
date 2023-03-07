/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:39 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 11:35:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	key_hook(int key, t_FdF_info *fdf)
{
	ft_printf("Valor de la key %d\n", key);
	if (key == KEY_A)
		a_hook(fdf);
	if (key == KEY_D)
		d_hook(fdf);
	if (key == KEY_ESCAPE)
		close_fdf(fdf);
	return (0);
}

void	ft_hooks(t_FdF_info *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	//mlx_scroll_hook(fdf->mlx, scroll_hook, fdf);
	//mlx_close_hook(fdf->mlx, close_fdf, fdf);
}
