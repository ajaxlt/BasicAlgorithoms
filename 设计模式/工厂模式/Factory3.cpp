/*
 * 工厂模式: 3. 抽象工厂模式
 */
#include <iostream>

using namespace std;

//抽象产品: 苹果
class Apple {
public:
    virtual void show() = 0;
};
//中国苹果
class ChinaApple : public Apple {
public:
    virtual void show() {
        cout << "ChinaApple" << endl;
    }
};
//美国苹果
class AmericaApple : public Apple {
public:
    virtual void show() {
        cout << "AmericaApple" << endl;
    }
};
//日本苹果
class JapanApple : public Apple {
public:
    virtual void show() {
        cout << "JanpanApple" << endl;
    }
};

//抽象产品: 鸭梨
class Pea {
public:
    virtual void show() = 0;
};
//中国鸭梨
class ChinaPea : public Pea {
public:
    virtual void show() {
        cout << "ChinaPea" << endl;
    }
};
//美国鸭梨
class AmericaPea : public Pea {
public:
    virtual void show() {
        cout << "AmericaPea" << endl;
    }
};
//日本鸭梨
class JapanPea : public Pea {
public:
    virtual void show() {
        cout << "JanpanPea" << endl;
    }
};
//抽象工厂
class Factory {
public:
    virtual Apple* createApple ()  = 0;
    virtual Pea* createPea ()  = 0;
};
//中国工厂
class ChinaFactory : public Factory{
public:
    virtual Apple* createApple ()  {
        return new ChinaApple;
    }
    virtual Pea* createPea () {
        return new ChinaPea;
    }
};
//美国工厂
class AmericaFactory : public Factory{
public:
    virtual Apple* createApple () {
        return new AmericaApple;
    }
    virtual Pea* createPea () {
        return new AmericaPea;
    }
};

//日本工厂
class JapanFactory : public Factory{
public:
    virtual Apple* createApple () {
        return new JapanApple;
    }
    virtual Pea* createPea () {
        return new JapanPea;
    }
};

int main () {
    Apple* apple = nullptr;
    Pea* pea = nullptr;

    Factory* factory = nullptr;

    factory = new JapanFactory;
    apple = factory -> createApple();

    apple -> show();
}