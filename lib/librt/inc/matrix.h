/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:23:05 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/07 10:46:39 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

//	INCLUDES
# include "tuples.h"

//	DEFINES
# define MAX_MATRIX_SIZE (10000)
# define MAT4X4_SIZE (4)
# define MAT3X3_SIZE (3)
# define MAT2X2_SIZE (2)
# define X_AXIS (0)
# define Y_AXIS (1)
# define Z_AXIS (2)

//	ERROR/WARNING MESSAGES
# define MX_NULL_PTR_ERROR	"received NULL pointer: did not perform operation"
# define MX_INV_ERROR		"matrix determinant is 0: cannot invert matrix"
# define MX_AXIS_ERROR		"invalid axis: returning identity matrix"

//	TYPEDEFS
typedef struct s_matrix
{
	int		rows;
	int		cols;
	float	**data;
}			t_matrix;

typedef struct s_m4x4
{
	float	data[MAT4X4_SIZE][MAT4X4_SIZE];
}				t_m4x4;

typedef struct s_m3x3
{
	float	data[MAT3X3_SIZE][MAT3X3_SIZE];
}			t_m3x3;

typedef struct s_m2x2
{
	float	data[MAT2X2_SIZE][MAT2X2_SIZE];
}			t_m2x2;

//	PROTOTYPES
void	mx_error(const char *source, const char *msg);
t_m4x4	zero_matrix(void);
void	bzero_matrix(t_m4x4 *m);
bool	mx_equal(t_m4x4 a, t_m4x4 b);
t_m4x4	mx_mult(t_m4x4 left, t_m4x4 right);
t_tuple	mx_mult_tuple(t_m4x4 m, t_tuple t);
t_m4x4	mx_mult_float(t_m4x4 m, float f);
void	mx_set_to_identity(t_m4x4 *m);
t_m4x4	mx_identity(void);
t_m4x4	mx_transpose(t_m4x4 m);
t_m3x3	submatrix_4x4(t_m4x4 m4, int row, int col);
t_m2x2	submatrix_3x3(t_m3x3 m3, int row, int col);
float	cofactor_3x3(t_m3x3 m, int row, int col);
float	cofactor_4x4(t_m4x4 m, int row, int col);
float	determinant_2x2(t_m2x2 m);
float	determinant_3x3(t_m3x3 m);
float	determinant_4x4(t_m4x4 m);
t_m4x4	mx_adjugate(t_m4x4 m);
t_m4x4	mx_inversion(t_m4x4 m);
t_m4x4	mx_translation(float x, float y, float z);
t_m4x4	mx_scaling(float x, float y, float z);
t_m4x4	mx_reflection(int axis);
t_m4x4	mx_rotation(float radians, int axis);
t_m4x4	mx_shearing(int axis, float a, float b);
float	deg_to_rad(float degrees);
float	rad_to_deg(float radians);

/*	Matrix concatenation prototypes:
	To be called in the order of the desired transformation order.
	Internally applies the matrix multiplication in 'reverse' to avoid
	having to concatenate matrices in reverse manually.
*/
t_m4x4	mx_add_inversion(t_m4x4 m);
t_m4x4	mx_add_translation(t_m4x4 m, float x, float y, float z);
t_m4x4	mx_add_scaling(t_m4x4 m, float x, float y, float z);
t_m4x4	mx_add_reflection(t_m4x4 m, int axis);
t_m4x4	mx_add_rotation(t_m4x4 m, float radians, int axis);
t_m4x4	mx_add_shearing(t_m4x4 m, int axis, float a, float b);

#endif