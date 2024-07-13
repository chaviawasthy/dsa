#include<bits/stdc++.h>

using namespace std;

class Bird{
    public:
    int age, weight;
    int nol;
    int color;

    void eat(){
        cout << "Bird is eating" << endl;
    }

    void fly(){
        cout << "Bird is flying" << endl;
    }
};

// class Sparrow:public Bird{
//     public:
//     void sing(){
//         cout << "Sparrow is singing" << endl;
//     }
// };

// class Sparrow:private Bird{
//     public:
//     void sing(){
//         cout << "Sparrow is singing" << endl;
//     }
// };

// class Sparrow:public Bird{
//     public:
//     Sparrow(int age, int weight, int nol, int color){
//         this->age = age;
//         this->weight = weight;
//         this->nol = nol;
//         this->color = color;
//     }
//     void sing(){
//         cout << "Sparrow is singing" << endl;
//     }
// };

class Sparrow:private Bird{
    public:
    Sparrow(int age, int weight, int nol, int color){
        this->age = age;
        this->weight = weight;
        this->nol = nol;
        this->color = color;
    }

    int getNol(){
        return this->nol;
    }
    void sing(){
        cout << "Sparrow is singing" << endl;
    }
};

class Pigion:public Bird{
    public:
    void coo(){
        cout << "Pigion is cooing" << endl;
    }
};

class Parrot:public Bird{
    public:
    void talk(){
        cout << "Parrot is talking" << endl;
    }
};

int main(){
    // Sparrow s;
    // Sparrow s(1,1, 2,"brown");
    // cout<<s.color<<endl;
    // s.eat();
    // s.eat();

    Sparrow s(1,1, 2,"brown");
    s.sing();//only possible rest all are private
    Pigion p;
    p.fly();
    return 0;
}