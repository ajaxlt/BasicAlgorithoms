#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include "myString.h"
using namespace std;

int main() {
    char *a = "aaa";
    cout << bool(*(a + 2))<<endl;
    cout << bool(*(a + 3))<< endl;
}