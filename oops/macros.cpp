#include <iostream>

using namespace std;

#define PI 3.14
#define MAX(a, b) (a > b ? a : b)

float areaOfCircle(float r){
    return PI*r*r;  //PI is a macro
}

void fun() {
    int a = 5, b = 10;
    int c = MAX(a,b);  //MAX is a macro
}

int main(){
    cout<<"The area of the circle is: "<<areaOfCircle(5)<<endl;
    fun();
    cout<<MAX(5, 10)<<endl;
    return 0;
}