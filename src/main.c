#include "fractol.h"

int		main(int ac, char **av)
{
	t_s	*s;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("usage : ./fractol no_need_file");
		return (0);
	}
	if (!(s = (t_s *)malloc(sizeof(t_s))))
		return (0);
	s->init = 0;
	s->fract = 0;
	s->m_ptr = mlx_init();
	s->w_ptr = mlx_new_window(s->m_ptr, XWIN, YWIN, "Fractol");
	s->itermax = 50;
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	mlx_hook(s->w_ptr, 2, 0, key_hook, (void *)s);
	mlx_hook(s->w_ptr, 4, 0, mouse_hook, (void *)s);
	mlx_hook(s->w_ptr, 17, 0, ft_expose, (void *)s);
	mlx_loop(s->m_ptr);
	return (0);
}
