#include<bits/stdc++.h>

using namespace std;

int main(){
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};

    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        //answer
        while(!q.empty()){
            char frontChar = q.front();
            if(freq[frontChar - 'a'] > 1){
                q.pop();
            }
            else{
                cout<<frontChar<<" ";
                break;
            }
        }

        if(q.empty()){
            cout<<"# ";
        }
    }

    return 0;
}