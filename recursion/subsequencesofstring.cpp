// #include<bits/stdc++.h>

// using namespace std;

// void findSubsequence(string s, string output, int index){
//     // base case
//     if(index == s.length()){
//         //ans jo h, vo output string me buikd ho chuka h
//         //print krdo
//         cout<<"->"<<output<<endl;
//         return;
//     }

//     char ch = s[index];


// //approach 1
//     // //exclude
//     // findSubsequence(s, output, index+1);
//     // //include
//     // //output string me ch wale char ko add krdo
//     // output.push_back(ch);
//     // findSubsequence(s, output, index+1);

// //approach 2
//     //include
//     output.push_back(ch);
//     findSubsequence(s, output, index+1);

//     //exclude
//     output.pop_back();
//     findSubsequence(s, output, index+1);
// }

// int main(){
//     string str = "abc";
//     string output = "";
//     int index = 0;
//     findSubsequence(str, output, index);

//     return 0;

// }

// #include<bits/stdc++.h>

// using namespace std;

// void findSubsequence(string s, string output, int index, vector<string> &ans){
//     // base case
//     if(index == s.length()){
//         //ans jo h, vo output string me buikd ho chuka h
//         //print krdo
//         // cout<<"->"<<output<<endl;
//         ans.push_back(output);
//         return;
//     }

//     char ch = s[index];


// //approach 1
//     // //exclude
//     // findSubsequence(s, output, index+1);
//     // //include
//     // //output string me ch wale char ko add krdo
//     // output.push_back(ch);
//     // findSubsequence(s, output, index+1);

// //approach 2
//     //include
//     output.push_back(ch);
//     findSubsequence(s, output, index+1, ans);

//     //exclude
//     output.pop_back();
//     findSubsequence(s, output, index+1, ans);
// }

// int main(){
//     string str = "abc";
//     string output = "";
//     int index = 0;
//     vector<string> ans;
//     findSubsequence(str, output, index, ans);
//     cout<<"Printing the subsequences of the string in the vector: "<<endl;
//     for(auto i: ans){
//         cout<<"->"<<i<<endl;
//     }

//     return 0;

// }

//another approach->using bit manipulation
//TC: O(2^n)
//SC: O(1)
#include<bits/stdc++.h>

using namespace std;

void subseq(string&s){
    int num_subs = pow(2, s.size()); //no of subsequences
    for(int n = 0;n<num_subs;++n){
        string out;
        int num = n;
        //convert num to binary
        int i = 0;
        while (num)
        {
            int b = num&1;
            if(b) out.push_back(s[i]);
            ++i;
            num>>=1;
        }
        cout<<out<<endl;
    }
}

int main(){
    string s = "abc";
    subseq(s);
    return 0;
}