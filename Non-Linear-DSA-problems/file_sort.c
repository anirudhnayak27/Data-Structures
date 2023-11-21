#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*void file_input(char*file_name,int X)
{
    int i;
    FILE* file=fopen(file_name,"w");
    if(file==NULL)
    {
        printf("Can't open:%s\n",file_name);
        exit(1);
    }
    for (i=0;i<X;i++)
    {
        fprintf(file, "%d\n",rand()%1000+1);
    }
    fclose(file);
}*/
int generate_random_number(int p, int q)
{
    return rand()%(q-p+1)+p;
}
void bubble_sort(int arr[], int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selection_Sort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		if(min_idx != i)
        swap(&arr[min_idx], &arr[i]);
	}
}
void merge(int arr[],int left[],int l,int right[],int r)
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)
    {
        if (left[i]<right[j])
        {
            arr[k++]=left[i++];
        } else {
            arr[k++]=right[j++];
        }
    }
    while (i<l)
    {
        arr[k++]=left[i++];
    }
    while (j<r)
    {
        arr[k++]=right[j++];
    }
}

void merge_sort(int arr[], int n)
{
    if (n<=1)
    {
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n - mid];
    memcpy(left,&arr[0],mid*sizeof(int));
    memcpy(right,&arr[mid],(n-mid)*sizeof(int));
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    merge(arr,left,mid,right,n - mid);
}
int part(int arr[],int l,int h)
{
	int i,j;
	int pivot=arr[h];
    i=(l-1);
	for (j=l;j<=h-1;j++)
    {
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return (i+1);
}

void quick_Sort(int arr[],int l,int h)
{
	if (l<h)
    {
		int p=part(arr,l,h);
		quick_Sort(arr,l,p-1);
		quick_Sort(arr,p+1,h);
	}
}
void sort_time(const char* sort_type, int X)
{
    //char file_name[20];
    int i;
   /* sprintf(file_name, "input.txt");
    file_input(file_name, X);*/
    FILE* file = fopen("Input.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file: %s\n","Input.txt");
        exit(1);
    }
    int arr[X];
    for (i=0; i<X;i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    fclose(file);
     clock_t start_time=clock();
    if (strcmp(sort_type,"bubble")==0)
    {
        bubble_sort(arr,X);
    }
    else if (strcmp(sort_type,"merge")==0)
    {
        merge_sort(arr,X);
    }
    /*else if (strcmp(sort_type,"selection")==0)
    {
        selection_Sort(arr,X);
    }
    else if (strcmp(sort_type,"selection")==0)
    {
        quick_Sort(arr,0,X-1);
    }*/
    else
    {
        printf("Invalid sorting technique\n");
        exit(0);
    }
     clock_t end_time = clock();
    double elapsed_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

}
void main()
{
    int i,n,m,j;
    const char* sort_types[] = {"bubble", "merge"};
    int X_values[] = {100, 500, 1000};
    FILE*f=fopen("log.txt","w");
    if (f == NULL)
    {
        printf("Can't open log file\n");
        exit(1);
    }
     int k, p, q,num;
    printf("Enter the value of n: ");
    scanf("%d",&k);
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
    for (i=0;i<k;i++)
    {
        num = generate_random_number(p, q);
        fprintf(file, "%d\n", num);
    }
    fclose(file);
    printf("done\n");
    n=sizeof(sort_types)/sizeof(sort_types[0]);
    m=sizeof(X_values)/sizeof(X_values[0]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m; j++)
        {
            clock_t start_time=clock();
            sort_time(sort_types[i],X_values[j]);
            clock_t end_time=clock();
            double elapsed_time=(double)(end_time-start_time)/CLOCKS_PER_SEC;
            fprintf(f, "Sorting Technique: %s, X: %d, Time: %f seconds\n", sort_types[i], X_values[j], elapsed_time);
        }
    }
    fclose(f);
    printf("done\n");
}


