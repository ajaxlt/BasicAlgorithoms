/*
 * 工厂模式: 1. 简单工厂
 */
#include <iostream>

using namespace std;
class Product { // 抽象产品
public:
    virtual void show() = 0;
};

class ProductA : public Product {
public:
    virtual void show() {
        cout << "Product A!" << endl;
    }
};
class ProductB : public Product {
    virtual void show() {
        cout << "Product B!" << endl;
    }
};

// 简单工厂只有一个工厂
class Factory {
public:
    Product* createProduct(char c) {
        switch (c) {
            case 'A':
                return new ProductA();
                break;
            case 'B':
                return new ProductB();
                break;
            default:
                break;
        }
    }
};

int main () {
    Factory *factory = new Factory();
    Product* A = factory -> createProduct('A');
    A -> show();
    return 0;
}