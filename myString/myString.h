//
// Created by 焦泓玮 on 2019/3/21.
//
#include <assert.h>
#include <iostream>
#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

size_t mylen(const char* str);
char* mycpy(char* to, const char* from);
class myString {
public:
    myString(const char *str = nullptr); //构造函数
    myString(const myString& tmp);
    myString& operator=(const myString& tmp);
    ~myString();

    friend std::ostream& operator<< (std::ostream& output, const myString& str) {
        output << str.m_data << std::endl;
        return output;
    }
private:
    char* m_data;
};


#endif //MYSTRING_MYSTRING_H
