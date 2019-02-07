#include "fractol.h"

void *ft_thread_6(void *arg)
{
	t_thr	*thr6;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr6 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 650;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr6);
		thr6 = ft_calcul(s, thr6);
		if (thr6->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr6->i * 255 / s->itermax);
	}
	free(thr6);
	pthread_exit(NULL);
}

void *ft_thread_7(void *arg)
{
	t_thr	*thr7;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr7 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 780;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr7);
		thr7 = ft_calcul(s, thr7);
		if (thr7->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr7->i * 255 / s->itermax);
	}
	free(thr7);
	pthread_exit(NULL);
}

void *ft_thread_8(void *arg)
{
	t_thr	*thr8;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr8 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 910;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr8);
		thr8 = ft_calcul(s, thr8);
		if (thr8->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr8->i * 255 / s->itermax);
	}
	free(thr8);
	pthread_exit(NULL);
}
