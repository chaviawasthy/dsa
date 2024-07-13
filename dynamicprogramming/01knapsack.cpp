#include <bits/stdc++.h>

using namespace std;

int solveUsingRecursion (int capacity, int wt[], int profit[], int index, int n){
    //base case
    // if (index == n-1)
    // {
    //     if (wt[index]<=capacity)
    //     {
    //         return profit[index];
    //     }
    //     else{
    //         return 0;
    //     }
    // }
    if (index >= n)
    {
        return 0;
    }
    
    //inc //exc
    int include = 0;
    if (wt[index]<=capacity)
    {
        include = profit[index] + solveUsingRecursion(capacity-wt[index], wt, profit, index+1, n);
    }
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index+1, n);
    int ans = max(include, exclude);
    return ans;
}

int solveUsingMem (int capacity, int wt[], int profit[], int index, int n, vector<vector<int>>&dp){
    //base case
    // if (index == n-1)
    // {
    //     if (wt[index]<=capacity)
    //     {
    //         return profit[index];
    //     }
    //     else{
    //         return 0;
    //     }
    // }
    if (index >= n)
    {
        return 0;
    }

    //already exists
    if (dp[capacity][index] != -1)    return dp[capacity][index];
    
    //inc //exc
    int include = 0;
    if (wt[index]<=capacity)
    {
        include = profit[index] + solveUsingMem(capacity-wt[index], wt, profit, index+1, n, dp);
    }
    int exclude = 0 + solveUsingMem(capacity, wt, profit, index+1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int solveUsingTabulation(int capacity, int wt[], int profit[], int n){
    vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));
    for(int row = 0;row<=capacity;row++)
    {
        dp[row][n] = 0;
    }
    for(int i = 0;i<=capacity;i++){
        for (int j = n-1; j >= 0; j--)
        {
            //inc //exc
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + dp[i-wt[j]][j+1];
            }
            int exclude = 0 + dp[i][j+1];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[capacity][0];
}

int solveUsingTabulationSO(int capacity, int wt[], int profit[], int n){
    // vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));
    vector<int>next(capacity+1, 0);
    vector<int>curr(capacity+1, -1);

    for(int j = n-1; j >= 0; j--){
        for (int i = 0;i<=capacity;i++)
        {
            //inc //exc
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        //shift
        next = curr;
    }
    return curr[capacity];
}

int solveUsingTabulationSO2(int capacity, int wt[], int profit[], int n){
    // vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));
    vector<int>next(capacity+1, 0);
    // vector<int>curr(capacity+1, -1);

    for(int j = n-1; j >= 0; j--){
        for (int i = capacity;i>=0;i--)
        {
            //inc //exc
            int include = 0;
            if(wt[j] <= i){
                include = profit[j] + next[i-wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include, exclude);
        }
        //shift
        // next = curr;
    }
    return next[capacity];
}

int main(){
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int profit[] = {50, 100, 120};
    // int index = 0;
    int n = 3;
    //capacity aur index xhange ho rahe hai toh use 2d array
    vector<vector<int>>dp(capacity+1, vector<int>(n+1, -1));

    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    // int ans = solveUsingMem(capacity, wt, profit, index, n, dp);
    // int ans = solveUsingTabulation(capacity, wt, profit, n);
    // int ans = solveUsingTabulationSO(capacity, wt, profit, n);
    int ans = solveUsingTabulationSO2(capacity, wt, profit, n);
    cout << "max profit:" << ans << endl;

    return 0;
}