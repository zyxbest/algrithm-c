#if !defined(c2_polynomial_h)
#define c2_polynomial_h

typedef struct PolyNode {
  int coefficient;
  int exponent;
  struct Polynode *next;
} PolyNode, *Polynomial;
// test
void testCompare();
#endif // c2_polynomial_h
