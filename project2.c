#include "project1.h"
#include "project2.h"

unsigned char reg_file[32][32];

void reg_write(unsigned char write_addr[5], unsigned char write_in[32]){
  int address = 0;
  int itor = 0;
  address = decode(write_addr);
  for(itor = 0; itor < 31; itor++){
    reg_file[address][itor] = write_in[itor];
  }
}

unsigned char* reg_read(unsigned char read_addr[5], unsigned char read_out[32]){
  int address = 0;
  int itor = 0;
  address = decode(read_addr);
  for(itor = 0; itor <31; itor++){
    read_out[itor] = reg_file[address][itor];
  }
  return read_out;
}

int decode(unsigned char reg_addr[5]){
  int itor = 0;
  int binary = 1;
  int address = 0;
  for(itor = 0; itor < 5; itor++){
    if(reg_addr[5] == 1){
      address += binary;
    }
    binary *= 2;
  }
  return address;
}

void RegisterFileAccess(unsigned char read_out1[32], unsigned char read_out2[32], unsigned char read_addr1[5], unsigned char read_addr2[5], unsigned char write_addr[5], unsigned char write_in[32], int RW){
  unsigned char* read1;
  unsigned char* read2;
  read1 = malloc(32*sizeof(unsigned char) );
  read2 = malloc(32*sizeof(unsigned char) );
  read1 = reg_read(read_addr1, read_out1);
  read2 = reg_read(read_addr2, read_out2);
  if(RW != 0){
    reg_write(write_addr, write_in);
  }
}

void MUX2_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char S){
    unsigned char* A_Res;
    unsigned char* B_Res;
    A_Res = malloc(sizeof(unsigned char) );
    B_Res = malloc(sizeof(unsigned char) );
    unsigned char NOT_S = NOT(S);
    AND2_1(A_Res, A, NOT_S);
    AND2_1(B_Res, B, S);
    OR2_1(output, *A_Res, *B_Res);
}

void MUX4_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char S1, unsigned char S2){
    unsigned char* X_Res;
    unsigned char* Y_Res;
    X_Res = malloc(sizeof(unsigned char) );
    Y_Res = malloc(sizeof(unsigned char) );

    MUX2_1(X_Res, A, B, S1);
    MUX2_1(Y_Res, C, D, S1);
    MUX2_1(output, *X_Res, *Y_Res, S2);
    free(X_Res);
    free(Y_Res);
} 

void MUX8_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char E, unsigned char F, unsigned char G, unsigned char H, unsigned char S1, unsigned char S2, unsigned char S3){
    unsigned char* X_Res;
    unsigned char* Y_Res;
    X_Res = malloc(sizeof(unsigned char) );
    Y_Res = malloc(sizeof(unsigned char) );

    MUX4_1(X_Res, A, B, C, D, S1, S2);
    MUX4_1(Y_Res, E, F, G, H, S1, S2);
    MUX2_1(output, *X_Res, *Y_Res, S3);

}

void MUX16_1(unsigned char* output, unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char E, unsigned char F, unsigned char G, unsigned char H, unsigned char I, unsigned char J, unsigned char K, unsigned char L, unsigned char M, unsigned char N, unsigned char O, unsigned char P, unsigned char S1, unsigned char S2, unsigned char S3, unsigned char S4){
    unsigned char* X_Res;
    unsigned char* Y_Res;
    X_Res = malloc(sizeof(unsigned char) );
    Y_Res = malloc(sizeof(unsigned char) );

    MUX8_1(X_Res, A, B, C, D, E, F, G, H, S1, S2, S3);
    MUX8_1(Y_Res, I, J, K, L, M, N, O, P, S1, S2, S3);
    MUX2_1(output, *X_Res, *Y_Res, S4);
}

void MUX2_8(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char S, int offset){
    MUX2_1(&output[offset], A[offset], B[offset], S);
    MUX2_1(&output[offset+1], A[offset+1], B[offset+1], S);
    MUX2_1(&output[offset+2], A[offset+2], B[offset+2], S);
    MUX2_1(&output[offset+3], A[offset+3], B[offset+3], S);
    MUX2_1(&output[offset+4], A[offset+4], B[offset+4], S);
    MUX2_1(&output[offset+5], A[offset+5], B[offset+5], S);
    MUX2_1(&output[offset+6], A[offset+6], B[offset+6], S);
    MUX2_1(&output[offset+7], A[offset+7], B[offset+7], S);
}


void MUX2_16(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char S, int offset){
    MUX2_8(&output[offset], &A[offset], &B[offset], S, 0);
    MUX2_8(&output[offset], &A[offset], &B[offset], S, 8);
}


void MUX2_32(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char S, int offset){
    MUX2_16(&output[offset], &A[offset], &B[offset], S, 0);
    MUX2_16(&output[offset], &A[offset], &B[offset], S, 16);
}

unsigned char AddRCA(unsigned char* output, unsigned char A, unsigned char B, unsigned char Cin){

    unsigned char* X_Res;
    unsigned char* AB_Res;
    unsigned char* AC_Res;
    unsigned char* BC_Res;
    unsigned char* carry;
    X_Res = malloc(sizeof(unsigned char) );
    AB_Res = malloc(sizeof(unsigned char) );
    AC_Res = malloc(sizeof(unsigned char) );
    BC_Res = malloc(sizeof(unsigned char) );
    carry = malloc(sizeof(unsigned char) );

    XOR2_1(X_Res, A, B);
    XOR2_1(output, *X_Res, Cin);

    AND2_1(AB_Res, A, B);
    AND2_1(AC_Res, A, Cin);
    AND2_1(BC_Res, B, Cin);

    OR3_1(carry, *AB_Res, *AC_Res, *BC_Res);
    return *carry; 
    
}

unsigned char AddRCA_8(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char Cin, int offset){
    unsigned char Cin1;
    unsigned char Cin2;  
    unsigned char Cin3;  
    unsigned char Cin4;  
    unsigned char Cin5;  
    unsigned char Cin6;  
    unsigned char Cin7;  
    unsigned char Carryout;  

    Cin1 = AddRCA(&output[offset+0], A[offset+0], B[offset+0], Cin);
    Cin2 = AddRCA(&output[offset+1], A[offset+1], B[offset+1], Cin1);
    Cin3 = AddRCA(&output[offset+2], A[offset+2], B[offset+2], Cin2);
    Cin4 = AddRCA(&output[offset+3], A[offset+3], B[offset+3], Cin3);
    Cin5 = AddRCA(&output[offset+4], A[offset+4], B[offset+4], Cin4);
    Cin6 = AddRCA(&output[offset+5], A[offset+5], B[offset+5], Cin5);
    Cin7 = AddRCA(&output[offset+6], A[offset+6], B[offset+6], Cin6);
    Carryout = AddRCA(&output[offset+7], A[offset+7], B[offset+7], Cin7);
    return Carryout;
}
unsigned char AddRCA_16(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char Cin, int offset){
    unsigned char Cin1;
    unsigned char Carryout;

    Cin1 = AddRCA_8(&output[offset], &A[offset], &B[offset], Cin, 0);
    Carryout = AddRCA_8(&output[offset], &A[offset], &B[offset], Cin1, 8);

    return Carryout;
}



unsigned char AddRCA_32(unsigned char* output, unsigned char* A, unsigned char* B, unsigned char Cin, int offset){
    unsigned char Cin1;
    unsigned char Carryout;
   
    Cin1 = AddRCA_16(&output[offset], &A[offset], &B[offset], Cin, 0);
    Carryout = AddRCA_16(&output[offset], &A[offset], &B[offset], Cin1, 16);

    return Carryout;
}
