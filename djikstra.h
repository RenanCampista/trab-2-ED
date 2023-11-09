#if !defined(_DJIKSTRA_H_)
#define _DJIKSTRA_H_

#include "problem.h"
#include "path.h"

#include "heap.h"
#include "vector.h"
#include "connection.h"

Vector *djikstra_solve(Problem *problem);

#endif // _DJIKSTRA_H_