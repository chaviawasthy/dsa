#include<iostream>

using namespace std;

class Animal {
    public:
    virtual void sound() {
        cout << "Animal sound" << endl;
    }

    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

class Dog : public Animal {
    public:
    void sound() override{
        cout << "Dog sound" << endl;
    }

    ~Dog() {
        cout << "Dog destructor" << endl;
    }
};

class Cat : public Animal {
    public:
    void sound() override{
        cout << "Cat sound" << endl;
    }

    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

class Parrot : public Animal {
    public:
    void sound() override{
        cout << "Parrot sound" << endl;
    }

    ~Parrot() {
        cout << "Parrot destructor" << endl;
    }
};

void sound(Animal *a) {
    a->sound(); //polymorphism
}

int main(){
    // Dog d;
    // d.sound();
    // Dog *dog = new Dog();
    // dog->sound();
    // // Cat c;
    // // c.sound();
    // Cat *cat = new Cat();
    // cat->sound();
    Animal *a = new Dog();
    sound(a);
    // a = new Cat();
    // sound(a);

    // animal  = new Parrot();
    // sound(a);

    // delete a;
    return 0;
}