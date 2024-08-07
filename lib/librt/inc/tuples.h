/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:53:08 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:34:17 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

//	INCLUDES
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

//	DEFINES
# define VECTOR 	(0.0)
# define POINT		(1.0)
# define EPSILON	(0.00001)

//	ERROR/WARNING MESSAGES
# define TP_ADD_ERROR	"resulting .w value is > 1"
# define TP_SUB_ERROR	"resulting .w value is < 0"
# define TP_DIV_ERROR	"divide by 0: returning unchanged tuple"
# define TP_MAG_ERROR	"applying magnitude to non-vector"
# define TP_NORM_ERROR1	"normalizing non-vector"
# define TP_NORM_ERROR2	"zero-magnitude vector: returning unchanged vector"
# define TP_DOT_ERROR	"calculating dot product for non-vector"
# define TP_CROSS_ERROR	"applying cross product to non-vector"

//	TYPEDEFS
typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_tuple;

typedef t_tuple	t_vector;
typedef t_tuple	t_point;

//	PROTOTYPES
void		tp_error(const char *source, const char *msg);
t_tuple		vector(float x, float y, float z);
t_tuple		*alloc_vector(float x, float y, float z);
t_tuple		point(float x, float y, float z);
t_tuple		*alloc_point(float x, float y, float z);
bool		equal(float a, float b);
bool		equal_tuples(t_tuple a, t_tuple b);
t_tuple		add_tuple(t_tuple a, t_tuple b);
t_tuple		sub_tuple(t_tuple a, t_tuple b);
t_tuple		negate_tuple(t_tuple t);
t_tuple		multiply_tuple(t_tuple a, float f);
t_tuple		divide_tuple(t_tuple t, float d);
float		fsquaref(float f);
float		vector_magnitude(t_vector vec);
t_vector	normalize_vector(t_vector t);
float		vector_dot_product(t_vector a, t_vector b);
t_vector	vector_cross_product(t_vector a, t_vector b);

#endif