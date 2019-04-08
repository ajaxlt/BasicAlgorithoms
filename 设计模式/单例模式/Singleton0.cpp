/*
 * 单例模式: 0. 教科书式
 */
class Singleton {
private:
    Singleton() {}
    static Singleton* m_data;

public:
    static Singleton* getInstance();
};

Singleton* Singleton::m_data = nullptr;
Singleton* Singleton::getInstance() {
    if (m_data == nullptr)
        m_data = new Singleton();
    return m_data;
}