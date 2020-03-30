#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t get_data(char *arg){
    FILE *fp;
    uint32_t tmp;
    size_t result;
    if((fp=fopen(arg,"r")) == NULL){
        printf("Error : can't open file \n");
        exit(1);
    }
    if((result = fread(&tmp,1,sizeof (uint32_t),fp)) != 4){
        printf("Error : file error \n");
        exit(1);
    }
    fclose(fp);
    return tmp;
}

int main(int argc, char *argv[])
{
    uint32_t x, y, sum=0;
    if (argc != 3){
        printf("usage : ./add_nbo a.bin b.bin\n");
        exit(1);
    }
    x = get_data(argv[1]);
    y = get_data(argv[2]);

    x = ntohl(x);
    y = ntohl(y);
    sum = x + y;
    printf("%d(%#x) + %d(%#x) = %d(%#x)\n",x,x, y,y, sum,sum);
}
