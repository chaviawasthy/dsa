#include<bits/stdc++.h>

using namespace std;

void lastOccLTR(string s, char x, int i, int &ans){
    if(i>=s.length()){
        return;
    }
    if(s[i]==x){
        ans = i;
    }
    lastOccLTR(s,x,i+1,ans);
}

void lastOccRTL(string s, char x, int i, int &ans){
    if(i<0){
        return;
    }
    if(s[i]==x){
        ans = i;
        return;
    }
    lastOccRTL(s,x,i-1,ans);
}

int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;
    int ans = -1;
    lastOccLTR(s,x,0,ans);  //left to right
    lastOccRTL(s,x,s.size()-1,ans);  //right to left
    cout<<ans<<endl;
}