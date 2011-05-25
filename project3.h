//Erik Steggall
//CMPE 110
//Project #3
//

void shiftleft2x(unsigned char out[32], unsigned char in[32]);

void signextend(unsigned char out[32], unsigned char in[16]);

void MemoryAccess(unsigned char readout[32], unsigned char address[32], unsigned char writein[32], unsigned char write, unsigned char** memcontents);


void mem_write(unsigned char address[32], unsigned char write[32], unsigned char** memcontents);


unsigned char* mem_read(unsigned char address[32], unsigned char readout[32], unsigned char** memcontents);

int decode_mem_addr(unsigned char address[32]);

unsigned char ALU(unsigned char result[32], unsigned char in1[32], unsigned char in2[32], unsigned char operation[3]);

void AND32_1(unsigned char* out, unsigned char* in1, unsigned char* in2);

void OR32_1(unsigned char* out, unsigned char* in1, unsigned char* in2);

void SUB32_1(unsigned char* out, unsigned char* in1, unsigned char* in2);

int SLT32_1(unsigned char* in1, unsigned char* in2);

void MULT32_1(unsigned char* out, unsigned char* in1, unsigned char* in2);
