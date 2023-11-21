#include <stdio.h>
#include <stdlib.h>
typedef struct Item
{
    int weight;
    int value;
    float ratio;
} Item;
int compare(const void* a,const void* b)
{
    Item* item1=(Item*)a;
    Item* item2=(Item*)b;
    if (item1->ratio < item2->ratio) return 1;
    else if (item1->ratio > item2->ratio) return -1;
    else return 0;
}

int main() {
    int c,num,i;
    float max=0;
    Item* arr; // array of arr
    scanf("%d",&c);
    scanf("%d",&num);
    arr=(Item*)malloc(num*sizeof(Item));
    for (i=0;i<num;i++)
    {
        scanf("%d%d",&arr[i].weight,&arr[i].value);
        arr[i].ratio=(float) arr[i].value/arr[i].weight;
    }
    qsort(arr, num, sizeof(Item), compare);
    for (i = 0; i < num; i++) {
        if (c >= arr[i].weight) {
            max+= arr[i].value;
            c -= arr[i].weight;
        } else {
            max += arr[i].ratio * c;
            break;
        }
    }
    printf("The maximum value that can be obtained is: %.2f\n", max);
    free(arr);
    return 0;
}
