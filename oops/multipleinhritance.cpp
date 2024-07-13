#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Person{
    public:
        void walk(){
            cout << "Person is walking" << endl;
        }
};

class Teacher : virtual public Person{
    public:
    void teach(){
        cout << "Teaching" << endl;
    }
};

class Researcher : virtual public Person{
    public:
    void research(){
        cout << "Researching" << endl;
    }
};

class Professor:public Teacher, public Researcher{
    public:
    void publish(){
        cout << "Publishing" << endl;
    }
};

//multiple inheritance
class Professor : public Teacher, public Researcher{
    public:
    void bored(){
        cout << "Bored" << endl;
    }
}

int main(){
    Professor p;
    // p.bored();
    // p.teach();
    // p.research();
    // p.publish();
    // p.walk(); //error because walk is not a member of Professor
    // p.Teacher::walk(); //this is how we can access walk
    // p.Researcher::walk(); //this is how we can access walk
    p.walk();
    return 0;
}