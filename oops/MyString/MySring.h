#ifdef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
    private:
    char *data; // pointer to a char[] that holds a C-style string
    int length; // length of the string

    public:
    //default ctor
    MyString();

    //param ctor
    MyString(const char *s);

    //copy ctor
    MyString(const MyString &source);

    //dtor
    ~MyString();

    int size() const;

    bool empty() const;

    const char *MyString::c_str() const{
        return data;
    }

    //ovrloading insertion operator
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
}


#endif // MYSTRING_H