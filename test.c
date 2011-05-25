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
  unsigned char* in32;
  unsigned char* out32;
  unsigned char* in16;
  in32 = malloc(32*sizeof(unsigned char) );
  in16 = malloc(32*sizeof(unsigned char) );
  out32 = malloc(32*sizeof(unsigned char) );

  for(itor = 0; itor < 31; itor++){
    if(itor < 16){ in16[itor] = '0';}
    in32[itor] = '1';
    out32[itor] = '0';
  }

  shiftleft2x(out32, in32);
  printf("shift left\n");
  print_bits(out32);
  signextend(out32, in16);
  printf("\nsign extend\n");
  print_bits(out32);
  return 0;

}
