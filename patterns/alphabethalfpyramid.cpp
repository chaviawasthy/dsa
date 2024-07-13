//prints only alphabet half pyramid
// #include<iostream>

// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i+1; j++)
//         {
//             char ch = j+1+'A'-1;
//             cout<<ch;
//         }
//         cout<<endl;
//     }
    
// }

//palinfrom alphabet half pyramid
#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	for(int row=0; row<n; row=row+1) {
		char ch;
		for(int col=0; col<row+1; col=col+1) {
			int number = col+1;
			 ch = number + 'A' -1;
			cout << ch;
		}

		//jab tak A tk nahi pohochte
		//tab tk print krenge 

		for(char alphabet = ch; alphabet>'A'; ) {
			alphabet= alphabet-1;
			cout << alphabet;
		}
		cout << endl;
	}

    return 0;
}