#include<iostream>

using namespace std;

class abc {
    public:
        int x, y;
        // static int x, y; //static member variable

        abc(): x(0), y(0) {}

        // void print() const{
        //     //this
        //     // cout<<this->x<<" "<<this->y<<endl;
        //     cout<<x<<" "<<y<<endl;
        // }

        static void print() {
            // cout<<x<<" "<<y<<endl;
            // no this pointer is accessible
            printf("I am in Static Function %s\n", __FUNCTION__);
        }
};

// int abc::x; //static member variable
// int abc::y;

int main() {
    // abc obj1 = {10, 20};
    // abc obj2 = {30, 40};
    abc obj1;
    // abc::x = 10;
    // abc::y = 20;
    abc::print();

    abc obj2;
    // abc::x = 30; 
    // abc::y = 40;
    abc::print();

    abc::print();
    return 0;
}