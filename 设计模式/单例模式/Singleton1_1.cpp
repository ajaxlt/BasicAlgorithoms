/*
 * 单例模式: 1_1 加锁的经典懒汉
 */
class Singleton {
private:
    Singleton() {
        pthread_mutex_init(&mutex);
    }
    static Singleton* m_data;

public:
    static pthread_mutex_t mutex;
    static Singleton* getInstance();
};

pthread_mutex_t singleton::mutex;
Singleton* Singleton::m_data = nullptr;
Singleton* Singleton::getInstance() {
    if (m_data == nullptr) {
        pthread_mutex_lock(&mutex);
        if (m_data == nullptr)
            m_data = new Singleton();
        pthread_mutex_unlock(&mutex);
    }
    return m_data;
}