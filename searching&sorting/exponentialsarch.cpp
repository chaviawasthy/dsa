#include<bits/stdc++.h>

using namespace std;

int bs(int a[], int l, int r, int x){
    if(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] == x) return mid;
        else if(a[mid] > x) return bs(a,l,mid-1,x);
        else return bs(a,mid+1,r,x);
    }
    return -1;
}

int expSearch(int a[], int n, int x){
    if(a[0] == x) return 0;

    int i = 1;
    while (i<n && a[i] <= x)
    {
        i = i*2; //i*=2 or i = i<<1
    }
    return bs(a,i/2,min(i,n-1),x);
}

int main(){
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 13;
    int ans = expSearch(a, n, x);
    cout<<ans<<endl;
    return 0;
}