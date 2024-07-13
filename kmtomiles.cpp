#include<iostream>

using namespace std;

float kmtoMiles(float kilom){
    float miles = kilom * 0.621371;
    return miles;
}

int main(){
    float kilom;
    cout<<"Enter the distance in kilometers: "<<endl;
    cin>>kilom;
    float miles = kmtoMiles(kilom);
    cout<<"Distance in miles: "<<miles<<" miles"<<endl;
}