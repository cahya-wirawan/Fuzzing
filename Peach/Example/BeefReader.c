#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "beef.h"

#define MAXARRAY 20
#define DEFAULTNAME "test.bin"


int lame(FILE *ptr_myfile) {
    uint8_t value[MAXARRAY];
    int counter;
    struct rec my_record;
    char header[5];
    struct color col;

    
    if (!ptr_myfile) {
        printf("Unable to open file!");
        return 1;
    }
    fread(header, 4, 1, ptr_myfile);
    fread(&my_record, sizeof(struct rec), 1, ptr_myfile);
    fread((void *)value, sizeof(struct rec), my_record.size, ptr_myfile);
    printf("Header: %s, ", header);
    printf("X:%d, Y:%d, Size: %d\n", my_record.x, my_record.y, my_record.size);
    for (counter = 0; counter < my_record.size && counter < MAXARRAY; counter++) {
        printf("%d, ", value[counter]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *ptr_myfile;
    int ret;
    char filename[100];
    if (argc != 2) strcpy(filename, DEFAULTNAME);
    else {
        strncpy(filename, argv[1], sizeof(filename) - 1);
        filename[sizeof(filename) - 1] = '\0';
    }
    ptr_myfile = fopen(filename, "rb");
    ret = lame(ptr_myfile);
    printf("Return from lame\n");
    printf("Will close the file\n");
    fclose(ptr_myfile);
    return ret;
}
