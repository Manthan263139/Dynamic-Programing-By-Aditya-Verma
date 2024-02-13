#include<bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, int val[], int wt[]) {
    int t[N+1][W+1];

    // Base condition initialization
    for(int i = 0; i < N+1; i++) {
        for(int j = 0; j < W+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    // Dynamic programming approach
    for(int i = 1; i < N+1; i++) {
        for(int j = 1; j < W+1; j++) {
            if(wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[N][W];
}

int main() {
    // 01 knapsack problem using top-down approach
    int N = 3;
    int W = 3;
    int val[3] = {1, 2, 3};
    int wt[3] = {4, 5, 6};

    int result = knapsack(N, W, val, wt);
    cout << result;

    return 0;
}
