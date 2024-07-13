#include<iostream>

using namespace std;

class abc{
    public:
    int a;
    int *b;

    abc(int _x, int_y) : x(_x), y(new int(_y)){}

    //default dumb copy constructor : it does shallow copy
    // abc(const abc &obj){
    //     a = obj.a;
    //     b = obj.b;
    // }

    smart copy constructor : it does deep copy
    abc(const abc &obj){
        a = obj.a;
        b = new int;
        *b = *(obj.b);
    }

    void print() const{
        printf("a: %d, b: %p\nContent of b,*b: %d\n", a, b, *b);
    }

    ~abc(){
        delete b;
    }
}

int main(){
    // abc obj1(10, 20);
    // obj1.print();

    // abc b = a;
    // b.print();
    // *b.y = 30;
    // b.print();
    // //printing a
    // a.print();

    abc *a = new abc(10, 20);
    abc b = *a;
    delete a;
    b.print();
    return 0;
}