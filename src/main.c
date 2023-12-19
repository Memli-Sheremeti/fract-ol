#include "../minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	// identificant de la connexion
	mlx_ptr = mlx_init();
	//Prend ainsi the connection identifier, size x and y + title.
	win_ptr = mlx_new_window(mlx_ptr, 1040, 280, "Windows");
	// give the event for the windows
	mlx_loop(mlx_ptr);
}
