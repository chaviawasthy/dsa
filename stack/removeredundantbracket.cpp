#include<bits/stdc++.h>

using namespace std;

bool cheakRedundantBrackets(string &str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!s.empty() && s.top()!='(') {
                char temp = s.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                s.pop();
            }
            //yaha par you'll reach on;y if you find a '('
            s.pop();
            if (operatorCount == 0)
            {
                return true;
            }
            
        }
    }
    //if i have reached till here that means ki har ek breacket ke pair ke beech me ek operator pakka milega
    return false;
}

int main() {
    string str = "((a+b)*(c+d))";
    bool ans = cheakRedundantBrackets(str);

    if (ans == true)
    {
        cout<<"Redudant Brackets are present"<<endl;
    }
    else{
        cout<<"Redudant Brackets are not present"<<endl;
    }
    

    return 0;
}