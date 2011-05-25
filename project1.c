#include "project1.h"

void print_bits(unsigned char* in){
  printf("Printing\n");
  int itor = 0;
  for(itor = 0; in[itor] != '\0'; itor++){
    if( (itor%32) == 0){ printf("\n");}
    printf("%c", in[itor]);
  }
  printf("\n");
}

unsigned char NOT(unsigned char in){
  unsigned char output;
  if(in == '0'){
    output = '1';
  }
  else{
    output = '0';
  }
  return output;
}

void AND2_1(unsigned char* output, unsigned char in1, unsigned char in2){
  printf("AND\n");
  if(in1 == '\0' || in2 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}
void NAND2_1(unsigned char* output, unsigned char in1, unsigned char in2){
  printf("NAND\n");
  if(in1 == '\0' || in2 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void OR2_1(unsigned char* output, unsigned char in1, unsigned char in2){
  printf("OR\n");
  if(in1 == '\0' || in2 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}


void NOR2_1(unsigned char* output, unsigned char in1, unsigned char in2){
  printf("NOR\n");
  if(in1 == '\0' || in2 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void XOR2_1(unsigned char* output, unsigned char in1, unsigned char in2){
  printf("XOR\n");
  if(in1 == '\0' || in2 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '0'){
    *output = '1';
  }
  else if(in1 == '0' && in2 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}



void XNOR2_1(unsigned char* output, unsigned char in1, unsigned char in2){
  printf("XNOR\n");
  if(in1 == '\0' || in2 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '0'){
    *output = '0';
  }
  else if(in1 == '0' && in2 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void CTRL2_2(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control){
  if( control == 'A'){
    AND2_1(&output[bit_num], in1[bit_num], in2[bit_num]);
    AND2_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1]);
  }
  else if(control == 'a'){
    NAND2_1(&output[bit_num], in1[bit_num], in2[bit_num]);
    NAND2_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1]);
  }
  else if(control == 'O'){
    OR2_1(&output[bit_num], in1[bit_num], in2[bit_num]);
    OR2_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1]);
  }
  else if(control == 'o'){
    NOR2_1(&output[bit_num], in1[bit_num], in2[bit_num]);
    NOR2_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1]);
  }
  else if(control == 'X'){
    XOR2_1(&output[bit_num], in1[bit_num], in2[bit_num]);
    XOR2_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1]);
  }
  else if(control == 'x'){
    XNOR2_1(&output[bit_num], in1[bit_num], in2[bit_num]);
    XNOR2_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1]);
  }
  else{
    printf("CTRL2_2 error\n");
  }
}

void CTRL2_4(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control){
  CTRL2_2(output, in1, in2, bit_num, control);
  CTRL2_2(output, in1, in2, bit_num+2, control);
}

void CTRL2_8(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control){
  CTRL2_4(output, in1, in2, bit_num, control);
  CTRL2_4(output, in1, in2, bit_num+4, control);
}

void CTRL2_16(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control){
  CTRL2_8(output, in1, in2, bit_num, control);
  CTRL2_8(output, in1, in2, bit_num+8, control);
}
void AND3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3){
  if(in1 == '\0' || in2 == '\0' || in3 == '\0'){
    printf("Bits are NULL\n");
    output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1'){
    output[0] = '1';
  }
  else{
    output[0] = '0';
  }
}
void NAND3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3){
  printf("NAND\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void OR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3){
  printf("OR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}


void NOR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3){
  printf("NOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void XOR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3){
  printf("XOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if( (in1 == '0' && in2 == '1' && in3 == '0') ||
      (in1 == '1' && in2 == '0' && in3 == '0') ||
      (in1 == '0' && in2 == '0' && in3 == '1') ){
    *output = '1';
  }
  else{
    *output = '0';
  }
}

void XNOR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3){
  printf("XNOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if( (in1 == '0' && in2 == '1' && in3 == '0') ||
      (in1 == '1' && in2 == '0' && in3 == '0') ||
      (in1 == '0' && in2 == '0' && in3 == '1') ){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void CTRL3_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control){
  if( control == 'A'){
    AND3_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num]);
    AND3_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1]);
  }
  else if(control == 'a'){
    NAND3_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num]);
    NAND3_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1]);
  }
  else if(control == 'O'){
    OR3_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num]);
    OR3_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1]);
  }
  else if(control == 'o'){
    NOR3_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num]);
    NOR3_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1]);
  }
  else if(control == 'X'){
    XOR3_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num]);
    XOR3_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1]);
  }
  else if(control == 'x'){
    XNOR3_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num]);
    XNOR3_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1]);
  }
  else{
    printf("CTROL3_2 error\n");
  }
}

void CTRL3_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control){
  CTRL3_2(output, in1, in2, in3, bit_num, control);
  CTRL3_2(output, in1, in2, in3, bit_num+2, control);
}

void CTRL3_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control){
  CTRL3_4(output, in1, in2, in3, bit_num, control);
  CTRL3_4(output, in1, in2, in3, bit_num+4, control);
}

void CTRL3_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control){
  CTRL3_8(output, in1, in2, in3, bit_num, control);
  CTRL3_8(output, in1, in2, in3, bit_num+8, control);
}

void AND4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0'){
    printf("Bits are NULL\n");
    output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1' && in4 == '1'){
    output[0] = '1';
  }
  else{
    output[0] = '0';
  }
}
void NAND4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
  printf("NAND\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1' && in4 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void OR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
  printf("OR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1' || in4 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}


void NOR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
  printf("NOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1' || in4 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void XOR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
  printf("XOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if( (in1 == '1' && in2 == '0' && in3 == '0' && in4 == '0') ||
      (in1 == '0' && in2 == '1' && in3 == '0' && in4 == '0') ||
      (in1 == '0' && in2 == '0' && in3 == '1' && in4 == '0') ||
      (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '1') ){
    *output = '1';
  }
  else{
    *output = '0';
  }
}

void XNOR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4){
  printf("XNOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if( (in1 == '1' && in2 == '0' && in3 == '0' && in4 == '0') ||
      (in1 == '0' && in2 == '1' && in3 == '0' && in4 == '0') ||
      (in1 == '0' && in2 == '0' && in3 == '1' && in4 == '0') ||
      (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '1') ){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void CTRL4_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control){
  if( control == 'A'){
  AND4_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num]);
  AND4_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num]);
  }
  else if(control == 'a'){
    NAND4_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num]);
    NAND4_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1]);
  }
  else if(control == 'O'){
    OR4_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num]);
    OR4_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1]);
  }
  else if(control == 'o'){
    NOR4_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num]);
    NOR4_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1]);
  }
  else if(control == 'X'){
    XOR4_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num]);
    XOR4_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1]);
  }
  else if(control == 'x'){
    XNOR4_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num]);
    XNOR4_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1]);
  }
  else{
    printf("CTRL4_2 error\n");
  }
}

void CTRL4_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control){
  CTRL4_2(output, in1, in2, in3, in4, bit_num, control);
  CTRL4_2(output, in1, in2, in3, in4, bit_num+2, control);
}

void CTRL4_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control){
  CTRL4_4(output, in1, in2, in3, in4, bit_num, control);
  CTRL4_4(output, in1, in2, in3, in4, bit_num+4, control);
}

void CTRL4_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control){
  CTRL4_8(output, in1, in2, in3, in4, bit_num, control);
  CTRL4_8(output, in1, in2, in3, in4, bit_num+8, control);
}

void AND6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6){
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0'){
    printf("Bits are NULL\n");
    output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1' && in4 == '1' && in5 == '1' && in6 == '1'){
    output[0] = '1';
  }
  else{
    output[0] = '0';
  }
}
void NAND6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6){
  printf("NAND\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1' && in4 == '1' && in5 == '1' && in6 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void OR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6){
  printf("OR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1' || in4 == '1' || in5 == '1' || in6 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}


void NOR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6){
  printf("NOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1' || in4 == '1' || in5 == '1' || in6 == '1'){
    *output = '1';
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void XOR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6){
  printf("XOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(
    (in1 == '1' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '1' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '1' && in4 == '0' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '1' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '1' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                                             in6 == '1') ){
    *output = '1';
  }
  else{
    *output = '0';
  }
}

void XNOR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6){
  printf("XNOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(
    (in1 == '1' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '1' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '1' && in4 == '0' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '1' && in5 == '0' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '1' &&
                                                             in6 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                                             in6 == '1') ){
    *output = '0';
  }
  else{
    *output = '1';
  }
}


void CTRL6_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control){
  if(control == 'A'){
  AND6_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num]);
  AND6_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num], in5[bit_num+1], in6[bit_num+1]);
  }
  else if(control == 'a'){
    NAND6_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num]);
    NAND6_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1]);
  }
  else if(control == 'O'){
    OR6_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num]);
    OR6_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1]);
  }
  else if(control == 'o'){
    NOR6_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num]);
    NOR6_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1]);
  }
  else if(control == 'X'){
    XOR6_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num]);
    XOR6_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1]);
  }
  else if(control == 'x'){
    XNOR6_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num]);
    XNOR6_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1]);
  }
  else{
    printf("CTRL6_2 error\n");
  }
}

void CTRL6_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control){
  CTRL6_2(output, in1, in2, in3, in4, in5, in6, bit_num, control);
  CTRL6_2(output, in1, in2, in3, in4, in5, in6, bit_num+2, control);
}

void CTRL6_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control){
  CTRL6_4(output, in1, in2, in3, in4, in5, in6, bit_num, control);
  CTRL6_4(output, in1, in2, in3, in4, in5, in6, bit_num+4, control);
}

void CTRL6_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control){
  CTRL6_8(output, in1, in2, in3, in4, in5, in6, bit_num, control);
  CTRL6_8(output, in1, in2, in3, in4, in5, in6, bit_num+8, control);
}

void AND8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0' || in7 == '\0' || in8 == '\0'){
    printf("Bits are NULL\n");
    output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1' && in4 == '1' && in5 == '1' && in6 == '1' && in7 == '1' && in8 == '1'){
    output[0] = '1';
  }
  else{
    output[0] = '0';
  }
}
void NAND8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
  printf("NAND\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0' || in7 == '\0' || in8 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' && in2 == '1' && in3 == '1' && in4 == '1' && in5 == '1' && in6 == '1' && in7 == '1' && in8 == '1'){
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void OR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
  printf("OR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0' || in7 == '\0' || in8 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1' || in4 == '1' || in5 == '1' || in6 == '1' || in7 == '1' || in8 == '1'){
    *output = '1';
  }
  else{
    *output = '0';
  }
}


void NOR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
  printf("NOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0' || in7 == '\0' || in8 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(in1 == '1' || in2 == '1' || in3 == '1' || in4 == '1' || in5 == '1' || in6 == '1'){
    *output = '1';
    *output = '0';
  }
  else{
    *output = '1';
  }
}

void XOR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
  printf("XOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0' || in7 == '\0' || in8 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(
    (in1 == '1' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '1' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '1' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '1' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '1' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '1' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '1' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '1') ){
    *output = '1';
  }
  else{
    *output = '0';
  }
}

void XNOR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8){
  printf("XNOR\n");
  if(in1 == '\0' || in2 == '\0' || in3 == '\0' || in4 == '\0' || in5 == '\0' || in6 == '\0' || in7 == '\0' || in8 == '\0'){
    printf("Bits are NULL\n");
    *output = '\0';
  }
  if(
    (in1 == '1' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '1' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '1' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '1' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '1' &&
                                 in6 == '0' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '1' && in7 == '0' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '1' && in8 == '0') ||
    (in1 == '0' && in2 == '0' && in3 == '0' && in4 == '0' && in5 == '0' &&
                                 in6 == '0' && in7 == '0' && in8 == '1') ){
    *output = '0';
  }
  else{
    *output = '1';
  }
}



void CTRL8_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control){
  if(control == 'A'){
    AND8_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num], in7[bit_num], in8[bit_num]);
    AND8_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num], in5[bit_num+1], in6[bit_num+1], in7[bit_num+1], in8[bit_num+1]);
  }
  else if(control == 'a'){
    NAND8_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num], in7[bit_num], in8[bit_num]);
    NAND8_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1], in7[bit_num+1], in8[bit_num+1]);
  }
  else if(control == 'O'){
    OR8_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num], in7[bit_num], in8[bit_num]);
    OR8_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1], in7[bit_num+1], in8[bit_num+1]);
  }
  else if(control == 'o'){
    NOR8_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num], in7[bit_num], in8[bit_num]);
    NOR8_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1], in7[bit_num+1], in8[bit_num+1]);
  }
  else if(control == 'X'){
    XOR8_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num], in7[bit_num], in8[bit_num]);
    XOR8_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1], in7[bit_num+1], in8[bit_num+1]);
  }
  else if(control == 'x'){
    XNOR8_1(&output[bit_num], in1[bit_num], in2[bit_num], in3[bit_num], in4[bit_num], in5[bit_num], in6[bit_num], in7[bit_num], in8[bit_num]);
    XNOR8_1(&output[bit_num+1], in1[bit_num+1], in2[bit_num+1], in3[bit_num+1], in4[bit_num+1], in5[bit_num+1], in6[bit_num+1], in7[bit_num+1], in8[bit_num+1]);
  }
  else{
    printf("CTRL8_2 error\n");
  }
}

void CTRL8_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control){
  CTRL8_2(output, in1, in2, in3, in4, in5, in6, in7, in8, bit_num, control);
  CTRL8_2(output, in1, in2, in3, in4, in5, in6, in7, in8, bit_num+2, control);
}

void CTRL8_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control){
  CTRL8_4(output, in1, in2, in3, in4, in5, in6, in7, in8, bit_num, control);
  CTRL8_4(output, in1, in2, in3, in4, in5, in6, in7, in8, bit_num+4, control);
}

void CTRL8_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control){
  CTRL8_8(output, in1, in2, in3, in4, in5, in6, in7, in8, bit_num, control);
  CTRL8_8(output, in1, in2, in3, in4, in5, in6, in7, in8, bit_num+8, control);
}

