
#include "linear_algebra.h"

#include <stdio.h>
#include <math.h>

static double
f(double x)
{
  return sqrt(1. - x * x);
}

int
main(int argc, char **argv)
{
  const int N = 1E8;
  double dx = 1. / N;

  double tbeg = Wtime();
  double sum = 0.;
#pragma omp parallel
  {
    double local_sum = 0.;
#pragma omp for
    for (int i = 0; i < N; i++) {
      double x0 = i * dx;
      double x1 = (i + 1) * dx;
      local_sum += .5 * (f(x0) + f(x1)) * dx;;
    }
#pragma omp atomic
    sum += local_sum;
  }
  double tend = Wtime();
  printf("sum = %g, took: %g sec\n", sum, tend - tbeg);

  return 0;
}
