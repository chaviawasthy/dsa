#include<iostream>

using namespace std;

class Student{
    private:
        string gf; //private member
        string cheating;

    public:
        int id;
        int age;
        string name;
        int nos;
        int *v; //pointer to int

        //ctor
        Student(){
            cout << "Default constructor called" << endl;
        }

        //Parameterized constructor
        Student(int _id, int _age, string _name, int _nos){
            // id = _id;
            // age = _age;
            // name = _name;
            // nos = _nos;
            // cout << "Parameterized constructor called" << endl;
            this->id = _id;
            this->age = _age;
            this->name = _name;
            this->nos = _nos;
            this->gf = "Riya";
            this->v = new int[5];
            cout << "Parameterized constructor called" << endl;
        }

        //copy ctor
        Student(const Student&srcobj) {
            cout<<"Student Copy constructor called"<<endl;
            this->name = srcobj.name;
            this->age = srcobj.age;
            this->gf = srcobj.gf;
            this->id = srcobj.id;
            this->nos = srcobj.nos;
            cout << "Copy constructor called" << endl;
        }

        //getter setter
        string getGf(){
            return gf; //this->gf will also work
        }

        void setGf(string _gf){
            gf = _gf;
        }

    void study(){
        cout << "Student is studying" << endl;
    }

    void sleep(){
        cout << "Student is sleeping" << endl;
    }

    void bunk(){
        cout << "Student is bunking" << endl;
    }

    ~Student(){
        cout << "Destructor called" << endl; //prevents memory leakage
        delete v;
    }

    private:
        void gfchat(){
            cout << "Student is chatting with gf" << endl;
        }

        void cheating(){
            cout << "Student is cheating" << endl;
        }

};

int main(){
    Student s1;
    s1.study();
    s1.sleep();
    s1.bunk();

    // Student s2(1, 20, "Rahul", 5); //Parameterized constructor called

    //copy ctor
    // Student s3 = s2; //Copy constructor called
    // cout<<s3.name<<endl;
    // cout << s3.name << endl;

    //dtor
    // {
    //     Student s2(1, 20, "Rahul", 5); //Parameterized constructor called
    //     cout<<s2.name<<endl;
    // }
    // Student s3;
    Student s2(1, 20, "Rahul", 5); //Parameterized constructor called
    cout<<s2.name<<endl;
    // cout<<s2.getGf()<<endl;
    s2.setGf("Riya");
    cout<<s2.getGf()<<endl;

    // Student *s3 = new Student(2, 21, "Rohit", 6); //Parameterized constructor called
    // cout<<s3->name<<endl;
    // cout << s3->id << " " << s3->age << " " << s3->name << " " << s3->nos << endl;
    // delete s3; //destructor called to free the memory or prevent memory leak
    return 0;
}