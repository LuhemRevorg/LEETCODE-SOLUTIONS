class Foo {
    std::mutex mtx;
    std::condition_variable cv;
    int state;
public:
    Foo():state{0} {}

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mtx);
        printFirst();
        state=1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return state == 1;});
        printSecond();
        state=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return state == 2;});
        printThird();
        state=3;
        cv.notify_all();
    }
};
