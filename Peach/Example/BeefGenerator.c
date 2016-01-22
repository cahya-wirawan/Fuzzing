#include<stdio.h>
#include <stdlib.h>
#include "beef.h"

#define OUTFILENAME "test.bin"

int main(int argc, char *argv[])
{
  int counter;
  FILE *ptr_myfile;
  struct rec my_record;

  //printf("argc:%d\n", argc);
  if(argc != 3) {
    printf("%s <x y>\n", argv[0]);
    return 1;
  }
  ptr_myfile=fopen(OUTFILENAME,"wb");
  if (!ptr_myfile)
  {
    printf("Unable to open file!");
    return 1;
  }
  fwrite("BEEF", 4, 1, ptr_myfile);
  my_record.x = atoi(argv[1]);
  my_record.y = atoi(argv[2]);
  my_record.size = my_record.x * my_record.y;
  fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
  for ( counter=1; counter <= my_record.size; counter++)
  {
    fprintf(ptr_myfile, "%c", counter);
  }
  fclose(ptr_myfile);
  printf("%s has been generated\n", OUTFILENAME);
  return 0;
}
