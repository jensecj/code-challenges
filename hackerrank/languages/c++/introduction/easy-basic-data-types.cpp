/*
  tags:
  task: read some input, print some output
*/
#include <iostream>

using namespace std;

int main() {
  int i;
  long l;
  char c;
  float f;
  double d;
  scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);
  printf("%d\n%ld\n%c\n%f\n%lf\n", i, l, c, f, d);
}
