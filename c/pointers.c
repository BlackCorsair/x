#include "stdio.h"

struct Equalizator {
  int highs;
  int mediums;
  int lows;
};

char* equalizator_to_string(struct Equalizator* eq) {
  char* string;
  if (0 >
      asprintf(&string,
               "Equalizator_ptr: \n\thighs: %d,\n\tmediums: %d,\n\tlows: %d\n",
               eq->highs, eq->mediums, eq->lows)) {
    return "something happened while creating the string!";
  }
  return string;
}

int main() {
  int a = 2;
  int* b = &a;

  printf("a: %d\n", a);
  printf("b = pointer to the content of a -> %d\n", b);
  printf("&a = address of a -> %d\n", &a);
  printf("&b = address of b, which is different than &a -> %d\n", &b);
  printf("*b = content of pointer b, which is a -> %d\n", *b);

  /***********************/
  printf("\n\n");
  /***********************/

  struct Equalizator eq = {20, 40, 30};
  struct Equalizator* eq_ptr = &eq;

  printf("Equalizator: \n\thighs: %d,\n\tmediums: %d,\n\tlows: %d\n", eq.highs,
         eq.mediums, eq.lows);
  printf(equalizator_to_string(&eq));

  return 0;
}
