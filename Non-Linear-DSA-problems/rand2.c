#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int i,j=0,n;
    scanf("%d",&n);
    double x,y,pi;
    srand(time(NULL));
    for (i=0;i<n;i++)
    {
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        if (x*x+y*y<=1.0)
        {
            j++;
        }
    }
    pi=(double)j/n*4;
    printf("Estimated value of pi: %f\n", pi);
}
