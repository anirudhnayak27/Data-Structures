#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generate_random_number(int p, int q)
{
    return rand()%(q-p+1)+p;
}

void main() {
    int n, p, q,num,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of p: ");
    scanf("%d",&p);
    printf("Enter the value of q: ");
    scanf("%d",&q);
    srand(time(0));
    FILE* file = fopen("Input.txt", "w");
    if (file == NULL)
    {
        printf("Failed to open file for writing.\n");
    }
    for (i=0;i<n;i++)
    {
        num = generate_random_number(p, q);
        fprintf(file, "%d\n", num);
    }
    fclose(file);
    printf("done\n");
}
