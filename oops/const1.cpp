#include<iostream>

using namespace std;

class abc{
    // mutable int x;  //now x can be changed in a const function
    int x;
    int *y;
    int z;

public:
    // abc(){
    //     x = x;
    //     y = new int(0);
    // }

    //ctor:old way
    // abc(int _x, int _y, int _z=0){  //z is default argument
    //     x = _x;
    //     y = new int(_y);
    //     z = _z;
    // }

    //initialization list: new way
    abc(int _x, int _y, int _z=0): x(_x), y(new int(_y)), z(_z){ //z is default argument
        cout<<"in init list"<<endl;
        *y = *y * 2;
        // aconst var can't be reinitialized
    }

    // int getX() {
    //     x = 10; //this is allowed
    //     return x;
    // }
    int getX() const{ //the function is not going to change the value of x
        // x = 10;
        return x;
    }

    void setX(int _val){
        x = _val;
    }

    int getY() const{ //the function is not going to change the value of y
        return *y;
    }

    void setY(int _val){
        *y = _val;
    }

    int getZ() const{ //the function is not going to change the value of z
        return z;
    }
};

void printABC(const abc &a){
    cout<<a.getX()<<endl;
    cout<<a.getY()<<endl;
    cout<<a.getZ()<<endl;
}

int main(){
    // abc a;
    abc a(1,2,3);
    printABC(a);
    // cout<<a.getX()<<endl;
    // cout<<a.getY()<<endl;

    return 0;

}