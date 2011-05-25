#include <stdio.h>
#include <stdlib.h>

/* Print function */
void print_bits(unsigned char* in);

/* Prototype: NOT */
unsigned char NOT(unsigned char in);

/*Prototype: AND */
void AND2_1(unsigned char* output, unsigned char in1, unsigned char in2);
void AND3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3);
void AND4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4);
void AND6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6);
void AND8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

/*Prototype: NAND */
void NAND2_1(unsigned char* output, unsigned char in1, unsigned char in2);
void NAND3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3);
void NAND4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4);
void NAND6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6);
void NAND8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

/* Prototype: OR   */
void OR2_1(unsigned char* output, unsigned char in1, unsigned char in2);
void OR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3);
void OR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4);
void OR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6);
void OR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

/* Prototype: NOR  */
void NOR2_1(unsigned char* output, unsigned char in1, unsigned char in2);
void NOR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3);
void NOR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4);
void NOR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6);
void NOR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

/* Prototype: XOR   */
void XOR2_1(unsigned char* output, unsigned char in1, unsigned char in2);
void XOR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3);
void XOR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4);
void XOR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6);
void XOR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

/* Prototype: XNOR   */
void XNOR2_1(unsigned char* output, unsigned char in1, unsigned char in2);
void XNOR3_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3);
void XNOR4_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4);
void XNOR6_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6);
void XNOR8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

/* Control functions; used by every gate type */


void CTRL2_2(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control);
void CTRL2_4(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control);
void CTRL2_8(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control);
void CTRL2_16(unsigned char* output, unsigned char* in1, unsigned char* in2, int bit_num, char control);
void AND8_1(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char in3, unsigned char in4, unsigned char in5, unsigned char in6, unsigned char in7, unsigned char in8);

void CTRL3_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control);
void CTRL3_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control);
void CTRL3_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control);
void CTRL3_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, int bit_num, char control);

void CTRL4_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control);
void CTRL4_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control);
void CTRL4_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control);
void CTRL4_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, int bit_num, char control);

void CTRL6_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control);
void CTRL6_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control);
void CTRL6_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control);
void CTRL6_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, int bit_num, char control);

void AND8_2(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control);
void AND8_4(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control);
void AND8_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num, char control);
void AND8_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char* in3, unsigned char* in4, unsigned char* in5, unsigned char* in6, unsigned char* in7, unsigned char* in8, int bit_num);


