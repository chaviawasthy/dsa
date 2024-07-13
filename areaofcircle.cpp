#include<iostream>

using namespace std;

float areaofcircle(float r){
    return 3.14*r*r;
}

int main(){
    float radius;
    cin>>radius;
    cout<<"Area of circle is: "<<areaofcircle(radius)<<endl;
}