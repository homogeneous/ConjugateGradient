#ifndef CONJUGATEGRADIENT_H
#define CONJUGATEGRADIENT_H

#include <petsc.h>

#define boolean PetscBool
#define integer PetscInt
#define real PetscReal
#define scalar PetscScalar
#define True PETSC_TRUE
#define False PETSC_FALSE
#define ecode PetscErrorCode

/* I/O structure of the operator */
typedef ecode (*operator)(Vec Ax, Vec x, integer nvargs, va_list vargs);

/* initializes CG solver 
 * _size - vector size */
ecode ConjugateGradientInitialize(integer _size);

/* finalizes CG solver */
ecode ConjugateGradientFinalize();

/* solves Ax = b */
ecode ConjugateGradientSolve(Vec x, Vec b, integer nvargs, ...);

/* gets convergence flag, iteration count, relative error
 * cflag == 0 - converged
 * cflag == 1 - not converged
 * cflag == 2 - not Hermitian positive definite 
 * iter - number of iterations
 * err - relative error in L2, ||r||/||b|| */
ecode CojugateGradientGetConvInfo(integer* _cflag, integer* _iter, real* _err);

/* sets the operator A */
ecode ConjugateGradientSetOperator(operator _inA);

/* sets error tolerance, default: 1.0e-10 */
ecode CojugateGradientSetTolerance(real _errtol);

/* sets the maximum number of iterations, default: vector size */
ecode CojugateGradientSetMaxIter(integer _maxiter);

#endif
