#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    uint32_t a, b, sum;
    FILE *fp, *fp2;
    fp = fopen("a.bin","r");
    fp2 = fopen("b.bin","r");
    if ( (fp == NULL) || (fp2 == NULL) ){
        printf("usage : ./add_nbo a.bin b.bin");
        exit(0);
    }
    fread(&a,1,sizeof (uint32_t),fp);
    fread(&b,1,sizeof (uint32_t),fp2);
    a = ntohl(a);
    b = ntohl(b);
    sum = a + b;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a, b,b, sum,sum);
}
