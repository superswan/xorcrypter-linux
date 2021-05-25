#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void die(char* message);

int main(int argc, char *argv[]) {
    char *filename;
    char *filename_enc;
    FILE *fp;
    FILE *fp_enc;
    
    int i, j, c, keylength, max_size;
    char* key;
    char xor_c;

    if (argc < 4) {
        die("Usage\n");
    }

    filename = argv[1];
    filename_enc = argv[3];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        die("Error\n");
    }

    fp_enc = fopen(filename_enc, "w");
    if (fp == NULL) {
        die("Error\n");
    }

    key = argv[2];
    keylength = (strlen(key)) - 1;

    for (i = 0, j = 0, max_size=500000; i < max_size && (c = getc(fp)) != EOF; i++) {
        if (j > keylength) {
            j = 0;
        }

        if (c == 0) {
            xor_c = c;
        } 
        else xor_c = c ^ key[j];

        if (xor_c == 0) {
            xor_c = c;
        }

        j++;
        fputc(xor_c, fp_enc); 
    } 
    
    fclose(fp);
    fclose(fp_enc);

    return 0;
}

void die(char* message) {
    fprintf(stderr, message);
    exit(EXIT_FAILURE);
}
