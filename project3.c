//Erik Steggall
//CMPE 110
//Project #3
//


void shiftleft2x(unsigned char out[32], unsigned char in[32]){
  int i;
  out[0] = 0;
  out[1] = 0;
  for(i = 1;i < 31;i++){
    out[i+1] = in[i];
  }
}

