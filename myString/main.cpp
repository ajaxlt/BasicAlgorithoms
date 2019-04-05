#include <iostream>
#include "myString.h"
using namespace std;


int main() {
    char a[] = {'a', 'a', 'a'};
    char b[] = {'d', 'e', 'f', 'g'};


    myString s1(a);
    myString s2(b);

    s2 = s1;
    cout << s1;
}