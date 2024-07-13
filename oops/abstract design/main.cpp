#include<iostream>
#include "bird.h"

using namespace std;

void birddoesSomething(Bird *b){
    b->eat();
    b->fly();
}

int main(){
    Bird *b1 = new sparrow();
    birddoesSomething(b1);

    return 0;
}