/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_project_template.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 18:01:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PROJECT_TEMPLATE_H
# define MLX_PROJECT_TEMPLATE_H

//	LIBRARIES
# include "libft.h"
# include "mlx.h"
# include "hex_colors.h"
# include <errno.h>
# include <stdio.h>

// DEFINES
# define WINDOW_NAME "unnamed project"

// OS specifics
# ifdef __APPLE__
#  include "macos_keycodes.h"
#  define WIN_WIDTH (1800)
#  define WIN_HEIGHT (1200)
#  define WIN_MID_X (800)
#  define WIN_MID_Y (600)
#  define LINUX (0)
# elif defined __linux__
#  include "linux_keycodes.h"
#  include <X11/X.h>
#  define LINUX (1)
#  define WIN_WIDTH (2400)
#  define WIN_HEIGHT (1600)
#  define WIN_MID_X (1200)
#  define WIN_MID_Y (800)
# else
#  error "Unsupported OS"
# endif

// TYPEDEFS
typedef struct s_mlx
{
	void	*xvar;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
}			t_mlx;

typedef struct s_data
{
	t_mlx	*mlx;
	//	ANY PROJECT RELEVANT DATA
}			t_data;

//	PROTOTYPES
void	exit_error(t_data *data, char *message);
t_data	*init_data(void);
t_mlx	*init_mlx(void);
void	reset_image(t_data *data);
void	destroy_data(t_data *data);
void	destroy_mlx(t_mlx *mlx);
int		close_editor(t_data *data);
void	set_hooks(t_data *data);
int		keypress(int keycode, t_data *data);
int		mouse_down(int keycode, t_data *data);
int		mouse_up(int keycode, t_data *data);
int		mouse_move(int x, int y, t_data *data);
void	set_pixel_color(t_data *data, int x, int y, int color);
void	render(t_data *data);

#endif