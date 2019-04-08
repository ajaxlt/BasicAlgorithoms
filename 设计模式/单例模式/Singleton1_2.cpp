/*
 * 单例模式: 1_1 内部静态变量的懒汉
 */
class Singleton {
private:
    Singleton() {
        pthread_mutex_init(&mutex);
    }
public:
    static pthread_mutex_t mutex;
    static Singleton* getInstance();
};

pthread_mutex_t singleton::mutex;

Singleton* Singleton::getInstance() {
    pthread_mutex_lock(&mutex);
    static Singleton obj;
    pthread_mutex_unlock(&mutex);
    return &obj;
}