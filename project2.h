#include <stdio.h>
#include <stdlib.h>

/* Multiplexors */

void reg_write(unsigned char write_addr[5], unsigned char write_in[32]);

unsigned char* reg_read(unsigned char read_addr[5], unsigned char read_out[32]);

int decode(unsigned char reg_addr[5]);

void RegisterFileAccess(unsigned char read_out1[32], unsigned char read_out2[32], unsigned char read_addr1[5], unsigned char read_addr2[5], unsigned char write_addr[5], unsigned char write_in[32], int reg_write);

void MUX2_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char S);

void MUX4_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char S1, unsigned char S2);

void MUX8_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char E, unsigned char F, unsigned char G, unsigned char H, unsigned char S1, unsigned char S2, unsigned char S3);

void MUX16_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char E, unsigned char F, unsigned char G, unsigned char H, unsigned char I, unsigned char J, unsigned char K, unsigned char L, unsigned char M, unsigned char N, unsigned char O, unsigned char P, unsigned char S1, unsigned char S2, unsigned char S3, unsigned char S4);

void MUX2_8(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char S, int offset);

void MUX2_16(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char S, int offset);

void MUX2_32(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char S, int offset);

unsigned char AddRCA(unsigned char* output, unsigned char in1, unsigned char in2, unsigned char Cin);

unsigned char AddRCA_8(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char Cin, int offset);

unsigned char AddRCA_16(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char Cin, int offset);

unsigned char AddRCA_32(unsigned char* output, unsigned char* in1, unsigned char* in2, unsigned char Cin, int offset);
