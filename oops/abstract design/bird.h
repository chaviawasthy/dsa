#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

class Bird{
    public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    //classes that inherist from this class has to implement pure virtual files.

};

class sparrow:public Bird{
    public:
    void eat(){
        std::cout << "Sparrow is eating" << std::endl;
    }
    void fly(){
        std::cout << "Sparrow is flying" << std::endl;
    }
};

class penguin:public Bird{
    public:
    void eat(){
        std::cout << "Penguin is eating" << std::endl;
    }
    void fly(){
        std::cout << "Penguin is flying" << std::endl;
    }
};

#endif // BIRD_H