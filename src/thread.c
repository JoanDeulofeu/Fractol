/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:28:24 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/13 16:28:33 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_thread_1(void *arg)
{
	t_thr	*thr1;
	t_s		*s;
	int		i;

	i = 0;
	if (!(thr1 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr1->pxl = 0;
	while (i++ < (s->img_y / 8) * s->img_x)
	{
		ft_resetmand(s, thr1);
		if (s->fract != 2)
		{
			thr1 = ft_calcul(s, thr1);
			ft_lightup_pixel(s, thr1);
		}
		else
			ft_fougere(s, thr1);
	}
	free(thr1);
	pthread_exit(NULL);
}

void	*ft_thread_2(void *arg)
{
	t_thr	*thr2;
	t_s		*s;
	int		i;

	i = 0;
	if (!(thr2 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr2->pxl = (s->img_y / 8) * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x)
	{
		ft_resetmand(s, thr2);
		if (s->fract != 2)
		{
			thr2 = ft_calcul(s, thr2);
			ft_lightup_pixel(s, thr2);
		}
		else
			ft_fougere(s, thr2);
	}
	free(thr2);
	pthread_exit(NULL);
}

void	*ft_thread_3(void *arg)
{
	t_thr	*thr3;
	t_s		*s;
	int		i;

	i = 0;
	if (!(thr3 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr3->pxl = (s->img_y / 8) * 2 * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x)
	{
		ft_resetmand(s, thr3);
		if (s->fract != 2)
		{
			thr3 = ft_calcul(s, thr3);
			ft_lightup_pixel(s, thr3);
		}
		else
			ft_fougere(s, thr3);
	}
	free(thr3);
	pthread_exit(NULL);
}

void	*ft_thread_4(void *arg)
{
	t_thr	*thr4;
	t_s		*s;
	int		i;

	i = 0;
	if (!(thr4 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr4->pxl = (s->img_y / 8) * 3 * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x)
	{
		ft_resetmand(s, thr4);
		if (s->fract != 2)
		{
			thr4 = ft_calcul(s, thr4);
			ft_lightup_pixel(s, thr4);
		}
		else
			ft_fougere(s, thr4);
	}
	free(thr4);
	pthread_exit(NULL);
}

void	*ft_thread_5(void *arg)
{
	t_thr	*thr5;
	t_s		*s;
	int		i;

	i = 0;
	if (!(thr5 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr5->pxl = (s->img_y / 8) * 4 * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x)
	{
		ft_resetmand(s, thr5);
		if (s->fract != 2)
		{
			thr5 = ft_calcul(s, thr5);
			ft_lightup_pixel(s, thr5);
		}
		else
			ft_fougere(s, thr5);
	}
	free(thr5);
	pthread_exit(NULL);
}
