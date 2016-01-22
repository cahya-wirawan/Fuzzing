#include<stdio.h>
#include "beef.h"


int main()
{
  int counter;
  FILE *ptr_myfile;
  struct rec my_record;
  char header[5];
  struct color col;

  ptr_myfile=fopen("test.bin","rb");
  if (!ptr_myfile)
  {
    printf("Unable to open file!");
    return 1;
  }
  fread(header, 4, 1, ptr_myfile);
  fread(&my_record, sizeof(struct rec), 1, ptr_myfile);
  for ( counter=1; counter <= my_record.size; counter++)
  {
    fread(&col, sizeof(struct color), 1, ptr_myfile);
    printf("%d, ", col.value);
  }
  printf("\n");
  fclose(ptr_myfile);
  return 0;
}
