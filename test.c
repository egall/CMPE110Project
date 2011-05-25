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
  int inner_itor;
  unsigned char write;
  unsigned char* in32;
  unsigned char* in232;
  unsigned char* operation;
  unsigned char* out32;
  unsigned char* in16;
  unsigned char* readout;
  unsigned char* writein;
  unsigned char* address;
  unsigned char** memcontents;
  in32 = malloc(32*sizeof(unsigned char) );
  in232 = malloc(32*sizeof(unsigned char) );
  in16 = malloc(32*sizeof(unsigned char) );
  out32 = malloc(32*sizeof(unsigned char) );
  writein = malloc(32*sizeof(unsigned char) );
  readout = malloc(32*sizeof(unsigned char) );
  address = malloc(32*sizeof(unsigned char) );
  operation = malloc(3*sizeof(unsigned char) );
  memcontents = malloc(8*sizeof(unsigned char*) );
  write = '1';
  operation[0] = '1'; operation[1] = '1'; operation[2] = '0';
  
  for(itor = 0; itor < 32; itor++){
    if(itor < 16){ in16[itor] = '0';}
    in32[itor] = '1';
    in232[itor] = '1';
    out32[itor] = '0';
    writein[itor] = '1';
    address[itor] = '1';
  }
  for(itor = 0; itor < 8; itor++){
    memcontents[itor] = malloc(4096*sizeof(unsigned char) ); 
    for(inner_itor = 0; inner_itor < 4096; inner_itor++){
      memcontents[itor][inner_itor] = '0';
    }
  }

  shiftleft2x(out32, in32);
  printf("shift left\n");
  print_bits(out32);
  signextend(out32, in16);
  printf("sign extend\n");
  print_bits(out32);

  /* first read, should read 0's, writing 1's */
  MemoryAccess(readout, address, writein, write, memcontents);
  /* reading same address, should now be 1's */
  MemoryAccess(readout, address, writein, write, memcontents);

  printf("ALU\n");
  ALU(out32, in32, in232, operation);
  print_bits(out32);

  printf("MULT32_1\n");
  MULT32_1(out32, in32, in232);
  print_bits(out32);

  free(in16);
  free(in32);
  free(out32);
  free(readout);
  free(writein);
  free(memcontents); 
  return 0;

}
