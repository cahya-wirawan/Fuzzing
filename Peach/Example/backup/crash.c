#include<stdio.h>

void lame (void) { 
  char small[10]; 
  gets (small); 
  printf("%s\n", small); 
}

int main() { 
  lame (); 
  return 0; 
}