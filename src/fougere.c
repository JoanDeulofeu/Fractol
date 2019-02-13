/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fougere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:25:59 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/13 16:28:46 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_lightup_fougere(t_s *s, t_thr *thr)
{
	int new_x;

	if (thr->x <= s->img_x && thr->y <= s->img_y && thr->x >= 0 && thr->y >= 0)
	{
		new_x = thr->x * 4 + ((s->img_x * 4) * thr->y);
		s->s_img[new_x + 0] = 255;
		s->s_img[new_x + 1] = 255;
		s->s_img[new_x + 2] = 255;
		s->s_img[new_x + 3] = 0;
	}
}

void	ft_fougere2(t_thr *thr, int r)
{
	r = rand() % 100;
	if (r < 2)
	{
		thr->fzr = 50;
		thr->fzi = 0.27 * thr->fzi;
	}
	else if (r < 17)
	{
		thr->fzr = -0.139 * thr->fzr + 0.263 * thr->fzi + 57;
		thr->fzi = 0.246 * thr->fzr + 0.224 * thr->fzi - 8.28;
	}
	else if (r < 30)
	{
		thr->fzr = 0.17 * thr->fzr - 0.215 * thr->fzi + 40.8;
		thr->fzi = 0.222 * thr->fzr + 0.176 * thr->fzi + 20.539;
	}
	else
	{
		thr->fzr = 0.781 * thr->fzr + 0.034 * thr->fzi + 10.75;
		thr->fzi = -0.032 * thr->fzr + 0.739 * thr->fzi + 62.1;
	}
	thr->y = 4 * (235 - thr->fzi);
	thr->x = 4 * (thr->fzr - 5) + 300;
}

void	ft_fougere(t_s *s, t_thr *thr)
{
	int k;
	int r;

	k = 0;
	thr->fzr = 50;
	thr->fzi = 0;
	r = 0;
	while (++k < s->itermax)
		ft_fougere2(thr, r);
	ft_lightup_fougere(s, thr);
}
