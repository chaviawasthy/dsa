#include<iostream>

using namespace std;

class Box{
    int width;

    public:

    Box (int w) : width(w) {}; //ctor
    int getWidth() const {
        return width;
    }

    void setWidth(int w){
        width = w;
    }

    friend class BoxFactory;
};

class BoxFactory{
    int count;
    public:
    Box getBox(int w){
        ++count;
        return Box(w);
    }
};

int main(){
    // Box b(5);
    // cout<<b.getWidth()<<endl;
    BoxFactory bf;
    Box b = bf.getBox(5);
    cout<<b.getWidth()<<endl;
    return 0;
}