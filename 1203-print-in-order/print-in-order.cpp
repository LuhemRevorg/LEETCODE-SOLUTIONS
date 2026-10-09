class Foo {
    std::mutex mtx;
    std::condition_variable cv;
    int state;
public:
    Foo():state{1} {

    }

    void first(function<void()> printFirst) {
        {std::lock_guard<std::mutex> lck(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++state;}
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        {std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [&]{return state==2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++state;}
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [&]{return state==3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
