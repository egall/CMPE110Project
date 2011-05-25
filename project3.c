//Erik Steggall
//CMPE 110
//Project #3
//


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


