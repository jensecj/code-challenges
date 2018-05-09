/*
  tags:
  task:
*/
#include <iostream>
#include <cmath>

using namespace std;

void update(int* a, int* b) {
  int aa = *a + *b;
  int bb = abs(*a - *b);
  *(a) = aa;
  *(b) = bb;
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;

  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d\n", a, b);
}
