#include <stdio.h>
#include "omp.h"

int
main(int argc, char **argv)
{
  int test = -1;
  int thread_id;
  int n_threads;
#pragma omp parallel private(test, thread_id, n_threads)
  {
    printf("Hello %d/%d test=%d\n", thread_id, n_threads, test);
    test = thread_id;
  }
  printf("test = %d\n", test);
}
