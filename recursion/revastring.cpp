#include<bits/stdc++.h>

using namespace std;

void reverse(string &s, int start, int end){
    //base case
    if (start>=end)
    {
        return;
    }

    //one case
    swap(s[start],s[end]);
    //recursive case
    reverse(s,start+1,end-1);
    
}
//TC->N/2 calls -> O(N)
//SC->O(N) -> stack space
int main(){
    string s;
    cin>>s;
    reverse(s,0,s.size()-1);
    cout<<s<<endl;
}