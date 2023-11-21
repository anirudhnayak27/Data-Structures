#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_W 1000

int n, w;
int v[MAX_N], wt[MAX_N];
int best_val=0,cur_val=0,cur_wt=0;

void branch(int i) {
    if (i == n) {
        if (cur_val > best_val) {
            best_val = cur_val;
        }
        return;
    }
    if (cur_wt + wt[i] <= w) {
        cur_wt += wt[i];
        cur_val += v[i];
        branch(i + 1);
        cur_wt -= wt[i];
        cur_val -= v[i];
    }
    branch(i+1);
}

int main() {
    scanf("%d %d", &n, &w);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&v[i],&wt[i]);
    }
    branch(0);
    printf("\n");
    printf("%d\n", best_val);
}

