/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:26:16 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/13 16:28:29 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_frac(t_s *s)
{
	if (s->dolink == 0 || s->dolink > 4)
	{
		s->img_x = XWIN;
		s->img_y = YWIN;
	}
	else
	{
		s->img_x = 160;
		s->img_y = 160;
	}
	if (s->init == 0)
	{
		if (s->fract == 0)
			ft_init_mand(s);
		if (s->fract == 1)
			ft_init_julia(s, s->julia);
		s->zoomx = (s->img_x / (s->right - s->left));
		s->zoomy = (s->img_y / (s->low - s->high));
		if (s->fract == 3)
			ft_init_joan(s);
		s->diffx = (s->right - s->left) / 2;
		s->diffy = (s->low - s->high) / 2;
		s->zoom_coef = 0.2;
	}
	s->init = 1;
}

void	ft_resetmand(t_s *s, t_thr *thr)
{
	thr->i = 0;
	thr->x = thr->pxl < s->img_x ? thr->pxl : thr->pxl % s->img_x;
	thr->y = thr->pxl / s->img_x;
	thr->zr = 0;
	thr->zi = 0;
	thr->cr = thr->x / s->zoomx + s->left;
	thr->ci = thr->y / s->zoomy + s->high;
	if (s->fract == 1 || s->fract == 3)
	{
		ft_swap_double(&thr->zr, &thr->cr);
		ft_swap_double(&thr->zi, &thr->ci);
		thr->cr = s->movex;
		thr->ci = s->movey;
	}
	if (s->fract == 2)
	{
		thr->zr = 50;
		thr->zi = 0;
	}
	thr->pxl++;
}

void	ft_fin(t_s *s)
{
	if (s->dolink == 0 || s->dolink == 42)
		mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->img, 0, 0);
	if (s->dolink == 0)
		ft_do_link(s);
	if (s->dolink == 42 && s->afflink == 0)
		ft_affiche_link(s);
	ft_dply_menu(s);
}

int		ft_fractales(t_s *s, int i)
{
	pthread_t thread[8];

	ft_init_frac(s);
	if (pthread_create(&thread[i++], NULL, ft_thread_1, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_2, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_3, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_4, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_5, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_6, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_7, (void *)s) == -1)
		ft_exit(0, s);
	if (pthread_create(&thread[i++], NULL, ft_thread_8, (void *)s) == -1)
		ft_exit(0, s);
	while (i++ < 16)
		if (pthread_join(thread[i - 9], NULL) == -1)
			ft_exit(1, s);
	ft_fin(s);
	return (0);
}
