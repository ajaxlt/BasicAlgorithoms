//
// Created by 焦泓玮 on 2019/3/21.
//

#include "myString.h"
size_t mylen(const char* str) {
    const char* s;
    for (s = str; *s; ++s);
    return s - str;
}

char* mycpy(char* to, const char* from) {
    assert(to != nullptr && from != nullptr);
    char* p = to;
    while((*p++ = *from++) != '\0');
    return p;
}

myString::myString(const char *str) {
    //普通构造函数，无论如何都要先 new 出来
    //1. 如果形参是 nullptr, 将 m_data 赋为 '\0'
    if (str == nullptr) {
        m_data = new char[1];
        if (m_data == nullptr) {
            std::cout << "申请内存失败!" << std::endl;
            exit(1);
        }
        *m_data = '\0';
        //m_data[0] = '\0';
    }
    //2. 否则，调用strcpy
    else {
        size_t len = mylen(str);
        m_data = new char[len + 1];
        if (m_data == nullptr) {
            std::cout << "申请内存失败!" << std::endl;
            exit(1);
        }
        mycpy(m_data, str);
    }
}

myString::myString(const myString &tmp) {
    // 拷贝构造函数不用考虑 nullptr 的情况
    // 因为 tmp 既然已经被生成，其必不为空
    size_t len = mylen(tmp.m_data);
    m_data = new char[len + 1];
    if (m_data == nullptr) {
        std::cout << "申请内存失败!" << std::endl;
        exit(1);
    }
    mycpy(m_data, tmp.m_data);
}

myString& myString::operator=(const myString &tmp) {
    //1. 如果被赋值的是自己， 返回 this 指针
    if (&tmp == this) return *this;
    delete [] m_data;
    m_data = nullptr; // 销毁后置空

    size_t len = mylen(tmp.m_data);
    m_data = new char[len + 1];
    if (m_data == nullptr) {
        std::cout << "申请内存失败!" << std::endl;
        exit(1);
    }
    mycpy(m_data, tmp.m_data);
    return *this;
}

myString::~myString() {
    delete [] m_data;
    m_data = nullptr;
}

size_t  myString::size() {
    return mylen(m_data);
}

std::ostream& operator<< (std::ostream& output, const myString& str) {
    output << str.m_data;
    return output;
}