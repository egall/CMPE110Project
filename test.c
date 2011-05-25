//Erik Steggall
//CMPE 110
//Project #3
//
#include <stdio.h>
#include <stdlib.h>
#include "project1.h"
#include "project2.h"
#include "project3.h"

int main(){
  int itor;
  unsigned char* in;
  unsigned char* out;
  in = malloc(32*sizeof(unsigned char) );
  out = malloc(32*sizeof(unsigned char) );

  for(itor = 0; itor < 31; itor++){
    in[itor] = '1';
    out[itor] = '0';
  }

  shiftleft2x(out, in);
  printf("shift left\n");
  print_bits(out);
  return 0;

}
