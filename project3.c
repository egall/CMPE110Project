//Erik Steggall
//CMPE 110
//Project #3
//
#include "project1.h"
#include "project2.h"
#include "project3.h"


void shiftleft2x(unsigned char out[32], unsigned char in[32]){
  int itor;
  out[0] = '0';
  out[1] = '0';
  for(itor = 1;itor < 31;itor++){
    out[itor+1] = in[itor];
  }
}

void signextend(unsigned char out[32], unsigned char in[16]){
  int itor;
  unsigned char sign;
  if(in[15] == '1'){
    sign = '1';
  }else if(in[15] == '0'){
    sign = '0';
  }else{
    printf("Invalid bit\n");
  }
  for(itor = 0; itor < 32; itor++){
    if(itor < 16){
      out[itor] = in[itor];
    }else{
      out[itor] = sign;
    }
  }
}

void MemoryAccess(unsigned char readout[32], unsigned char address[32], unsigned char writein[32], unsigned char write, unsigned char** memcontents){
  unsigned char* read;
  read = malloc(32*sizeof(unsigned char) );
  read = mem_read(address, readout, memcontents);
  if(write == '1'){
    mem_write(address, writein, memcontents);
  } 
  print_bits(read);
  free(read);
}

void mem_write(unsigned char address[32], unsigned char writein[32], unsigned char** memcontents){
  int addr = 0;
  int itor = 0;
  addr = decode(address);
  for(itor = 0; itor < 31; itor++){
    memcontents[addr][itor] = writein[itor];
  }
}

unsigned char* mem_read(unsigned char address[32], unsigned char readout[32], unsigned char** memcontents){
  int addr;
  int itor;
  addr = decode(address);
  for(itor = 0; itor < 31; itor++){
    readout[itor] = memcontents[addr][itor];
  }
  return readout;
}

int decode_mem_addr(unsigned char address[32]){
  int itor = 0;
  int binary = 1;
  int addr = 0;
  for(itor = 0; itor < 4; itor++){
    if(address[itor] == '1'){
      addr += binary;
    }
    binary *= 2;
  }
  return addr;
  
}

unsigned char ALU(unsigned char result[32], unsigned char in1[32], unsigned char in2[32], unsigned char operation[3]){
  int slt;
  if(operation[0] == '0' && operation[1] == '1' && operation[2] == '0'){
    AddRCA_32(result, in1, in2, '0', 0);
  }
  else if(operation[0] == '0' && operation[1] == '0' && operation[2] == '0'){
     AND32_1(result, in1, in2); 
  }
  else if(operation[0] == '0' && operation[1] == '0' && operation[2] == '1'){
    OR32_1(result, in1, in2); 
  }
  else if(operation[0] == '1' && operation[1] == '1' && operation[2] == '0'){
    SUB32_1(result, in1, in2);
  }
  else if(operation[0] == '1' && operation[1] == '1' && operation[2] == '1'){
    slt = SLT32_1(in1, in2);
    if(slt == 1){
      printf("less than\n");
    }else{
      printf("more than\n");
    }
  }
}


void AND32_1(unsigned char* out, unsigned char* in1, unsigned char* in2){
  AND2_1(&out[0], in1[0], in2[0]);
  AND2_1(&out[1], in1[1], in2[1]);
  AND2_1(&out[2], in1[2], in2[2]);
  AND2_1(&out[3], in1[3], in2[3]);
  AND2_1(&out[4], in1[4], in2[4]);
  AND2_1(&out[5], in1[5], in2[5]);
  AND2_1(&out[6], in1[6], in2[6]);
  AND2_1(&out[7], in1[7], in2[7]);
  AND2_1(&out[8], in1[8], in2[8]);
  AND2_1(&out[9], in1[9], in2[9]);
  AND2_1(&out[10], in1[10], in2[10]);
  AND2_1(&out[11], in1[11], in2[11]);
  AND2_1(&out[12], in1[12], in2[12]);
  AND2_1(&out[13], in1[13], in2[13]);
  AND2_1(&out[14], in1[14], in2[14]);
  AND2_1(&out[15], in1[15], in2[15]);
  AND2_1(&out[16], in1[16], in2[16]);
  AND2_1(&out[17], in1[17], in2[17]);
  AND2_1(&out[18], in1[18], in2[18]);
  AND2_1(&out[19], in1[19], in2[19]);
  AND2_1(&out[20], in1[20], in2[20]);
  AND2_1(&out[21], in1[21], in2[21]);
  AND2_1(&out[22], in1[22], in2[22]);
  AND2_1(&out[23], in1[23], in2[23]);
  AND2_1(&out[24], in1[24], in2[24]);
  AND2_1(&out[25], in1[25], in2[25]);
  AND2_1(&out[26], in1[26], in2[26]);
  AND2_1(&out[27], in1[27], in2[27]);
  AND2_1(&out[28], in1[28], in2[28]);
  AND2_1(&out[29], in1[29], in2[29]);
  AND2_1(&out[30], in1[30], in2[30]);
  AND2_1(&out[31], in1[31], in2[31]);
}

void OR32_1(unsigned char* out, unsigned char* in1, unsigned char* in2){
  OR2_1(&out[0], in1[0], in2[0]);
  OR2_1(&out[1], in1[1], in2[1]);
  OR2_1(&out[2], in1[2], in2[2]);
  OR2_1(&out[3], in1[3], in2[3]);
  OR2_1(&out[4], in1[4], in2[4]);
  OR2_1(&out[5], in1[5], in2[5]);
  OR2_1(&out[6], in1[6], in2[6]);
  OR2_1(&out[7], in1[7], in2[7]);
  OR2_1(&out[8], in1[8], in2[8]);
  OR2_1(&out[9], in1[9], in2[9]);
  OR2_1(&out[10], in1[10], in2[10]);
  OR2_1(&out[11], in1[11], in2[11]);
  OR2_1(&out[12], in1[12], in2[12]);
  OR2_1(&out[13], in1[13], in2[13]);
  OR2_1(&out[14], in1[14], in2[14]);
  OR2_1(&out[15], in1[15], in2[15]);
  OR2_1(&out[16], in1[16], in2[16]);
  OR2_1(&out[17], in1[17], in2[17]);
  OR2_1(&out[18], in1[18], in2[18]);
  OR2_1(&out[19], in1[19], in2[19]);
  OR2_1(&out[20], in1[20], in2[20]);
  OR2_1(&out[21], in1[21], in2[21]);
  OR2_1(&out[22], in1[22], in2[22]);
  OR2_1(&out[23], in1[23], in2[23]);
  OR2_1(&out[24], in1[24], in2[24]);
  OR2_1(&out[25], in1[25], in2[25]);
  OR2_1(&out[26], in1[26], in2[26]);
  OR2_1(&out[27], in1[27], in2[27]);
  OR2_1(&out[28], in1[28], in2[28]);
  OR2_1(&out[29], in1[29], in2[29]);
  OR2_1(&out[30], in1[30], in2[30]);
  OR2_1(&out[31], in1[31], in2[31]);
}

void SUB32_1(unsigned char* result, unsigned char* in1, unsigned char* in2){
  int itor = 0;
  int inner_itor = 0;
  int bigger = 0;
  bigger = SLT32_1(in1, in2);
  if(bigger == 0){ 
    for(itor = 0; itor < 31; itor++){
      if(in1[itor] == '0' && in2[itor] == '0'){result[itor] = '0';}
      if(in1[itor] == '1' && in2[itor] == '1'){result[itor] = '0';}
      if(in1[itor] == '0' && in2[itor] == '1'){result[itor] = '1';}
      if(in1[itor] == '0' && in2[itor] == '1'){
        for(inner_itor = itor; inner_itor < 31; inner_itor++){
          if(in1[inner_itor] == '1'){
            in1[inner_itor] = '0';
             break;
           }
         }
         for(; inner_itor > itor; inner_itor--){
           in1[inner_itor] = '1';
         }
        }
      }
  }else{
    for(itor = 0; itor < 31; itor++){
      if(in2[itor] == '0' && in1[itor] == '0'){result[itor] = '0';}
      if(in2[itor] == '1' && in1[itor] == '1'){result[itor] = '0';}
      if(in2[itor] == '0' && in1[itor] == '1'){result[itor] = '1';}
      if(in2[itor] == '0' && in1[itor] == '1'){
        for(inner_itor = itor; inner_itor < 31; inner_itor++){
          if(in2[inner_itor] == '1'){
            in2[inner_itor] = '0';
            break;
          }
        }
        for(; inner_itor > itor; inner_itor--){
          in1[inner_itor] = '1';
        }
      }
    }
  }
}

int SLT32_1(unsigned char* in1, unsigned char* in2){
  int itor;
  int result;
  for(itor = 31; itor > 0; itor--){
    if(in1[itor] == '1' && in2[itor] == '0'){
      result = 1;
      break;
    }
    if(in1[itor] == '0' && in2[itor] == '1'){
      result = 0;
      break;
    }
  }
  return result;
}

void MULT32_1(unsigned char* out, unsigned char* in1, unsigned char* in2){
  int itor;
  int num;
  int binary = 1;
  unsigned char* adder;
  adder = malloc(32*sizeof(unsigned char) );
  adder = in2;
  for(itor = 0; itor < 31; itor++){
    if(in1[itor] == '1'){
      num += binary;
    }
    binary *= 2;
  }
  printf("num = %d\n", num);
  AddRCA_32(out, adder, in2, '0', 0);
}
