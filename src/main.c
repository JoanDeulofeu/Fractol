#include "fractol.h"

int		main(int ac, char **av)
{
	t_s	*s;

	(void)av;
	if (ac != 1)
		ft_exit(2);
	if (!(s = (t_s *)malloc(sizeof(t_s))))
		return (0);
	s->init = 0;
	s->fract = 0;
	s->move = 0;
	s->savex = 0;
	s->savey = 0;
	s->m_ptr = mlx_init();
	s->w_ptr = mlx_new_window(s->m_ptr, XWIN, YWIN, "Fractol");
	s->itermax = 255;
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	mlx_hook(s->w_ptr, 2, 0, key_hook, (void *)s);
	mlx_hook(s->w_ptr, 4, 0, mouse_hook, (void *)s);
	// mlx_hook(s->w_ptr, 6, 0, mouse_move, (void *)s);
	mlx_hook(s->w_ptr, 17, 0, ft_expose, (void *)s);
	mlx_loop(s->m_ptr);
	return (0);
}

void	ft_exit(int error)
{
	if (error == 0)
		perror("pthread_create");
	if (error == 1)
		perror("pthread_join");
	if (error == 2)
		ft_putstr("usage : ./fractol no_need_file");
	exit(0);
}
