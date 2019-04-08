/*
 * 单例模式: 2. 饿汉模式
 */
class Singleton {
private:
    Singleton() {}
    static Singleton* m_data;
public:
    static Singleton* getInstance();
    int a = 1;
};

Singleton* Singleton::m_data = new Singleton;
Singleton* Singleton::getInstance() {
    return m_data;
}

int main() {
    cout << Singleton::getInstance() -> a << endl;
    return 0;
}