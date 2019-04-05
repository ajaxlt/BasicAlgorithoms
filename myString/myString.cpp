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
    if (str == nullptr) {
        m_data = new char[1];
        *m_data = '\0';
    }
    else {
        size_t len = mylen(str);
        m_data = new char[len + 1];
        mycpy(m_data, str);
    }
}

myString::myString(const myString &tmp) {
    size_t len = mylen(tmp.m_data);
    m_data = new char[len + 1];
    mycpy(m_data, tmp.m_data);
}

myString& myString::operator=(const myString &tmp) {
    if (&tmp == this) {
        return *this;
    }
    delete []m_data;
    size_t len = mylen(tmp.m_data);
    m_data = new char[len + 1];
    mycpy(m_data, tmp.m_data);
    return *this;
}

myString::~myString() {
    delete []m_data;
}

