/*
 * 工厂模式: 2. 工厂方法模式
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

// 工厂方法有多个工厂
class Factory {
public:
    virtual Product* createProduct() = 0;
};

class FactoryA : public Factory {
public:
    virtual Product* createProduct() {
        return new ProductA;
    }
};

class FactoryB : public Factory {
public:
    virtual Product* createProduct() {
        return new ProductB;
    }
};

int main () {
    Factory* factory = nullptr;
    Product* product = nullptr;

    factory = new FactoryA();
    product = factory -> createProduct();
    product -> show();
    return 0;
}