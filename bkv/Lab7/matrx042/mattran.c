/*
*-----------------------------------------------------------------------------
*	file:	mattran.c
*	desc:	matrix mathematics
*	by:	ko shu pui, patrick
*	ref:
*       [1] Mary L.Boas, "Mathematical Methods in the Physical Sciene,"
*	John Wiley & Sons, 2nd Ed., 1983. Chap 3.
*
*-----------------------------------------------------------------------------
*/

#include <stdio.h>
#include "matrix.h"

/*
*-----------------------------------------------------------------------------
*	funct:	mat_tran
*	desct:	transpose of a matrix
*	given:	A = matrix A to be transposed
*	retrn:	allocated matrix for A^t
*	comen:
*-----------------------------------------------------------------------------
*/
MATRIX mat_tran( A )
MATRIX A;
{
	int	i, j;
	MATRIX	At;

	if ((At = mat_creat( MatCol(A), MatRow(A), UNDEFINED )) == NULL)
		return (NULL);

	/*
	*	Transposing ...
	*/
	for (i=0; i<MatCol(A); i++)
	for (j=0; j<MatRow(A); j++)
		{
		At[i][j] = A[j][i];
		}
	return (At);
}
