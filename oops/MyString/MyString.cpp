#include "MySring.h"
#include <cstring> //strcpy

 //definitions of all the functions declared in MyString.h

 MyString::MyString() {
        data = new char[1];
        *data = '\0';
        length = 0;
 }

MyString::MyString(const char *s) {
        length = strlen(s);
        data = new char[length + 1];
        strcpy(data, s);
}

MyString::MyString(const MyString &source) {
        length = source.length;
        data = new char[length + 1];
        strcpy(data, source.data);
}

MyString::~MyString() {
        delete [] data;
}

int MyString::size() const {
        return length;
}

bool MyString::empty() const {
        return length == 0;
}

const char *MyString::c_str() const {
        return data;
}

std::ostream &operator<<(std::ostream &os, const MyString &str) {
        os << str.data;
        return os;
}