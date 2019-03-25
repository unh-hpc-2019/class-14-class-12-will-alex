#include <stdio.h>
#include "omp.h"

int
main(int argc, char **argv)
{
  int test = -1;
#pragma omp parallel private(test, thread_id, n_threads)
  {
    int thread_id = omp_get_thread_num();
    int n_threads = omp_get_num_threads();
    printf("Hello %d/%d test=%d\n", thread_id, n_threads, test);
    test = thread_id;
  }
  printf("test = %d\n", test);
}
