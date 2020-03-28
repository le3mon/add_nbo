#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    uint32_t a, b, sum;
    FILE *fp, *fp2;
    if (argc != 3){
        printf("usage : ./add_nbo a.bin b.bin\n");
        exit(1);
    }
    fp = fopen(argv[1],"r");
    fp2 = fopen(argv[2],"r");
    if (((fp=fopen(argv[1],"r")) == NULL) || ((fp2=fopen(argv[2],"r")) == NULL) ){
        printf("Error : can't read file \n");
        exit(1);
    }
    fread(&a,1,sizeof (uint32_t),fp);
    fread(&b,1,sizeof (uint32_t),fp2);
    a = ntohl(a);
    b = ntohl(b);
    sum = a + b;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a, b,b, sum,sum);
}
