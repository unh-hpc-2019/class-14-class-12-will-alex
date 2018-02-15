
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

// ----------------------------------------------------------------------
// struct vector

struct vector {
  double *vals;
  int n;
};

#define VEC(v, i) ((v)->vals[i])

struct vector *vector_create(int n);
struct vector *vector_create_and_set(int n, const double *vals);
void vector_destroy(struct vector *v);
double vector_dot(const struct vector *x, const struct vector *y);
void vector_add(int n, const double *x, const double *y, double *z);
void matrix_vector_mul(int n, const double A[][n], const double *x, double *y);

#endif
