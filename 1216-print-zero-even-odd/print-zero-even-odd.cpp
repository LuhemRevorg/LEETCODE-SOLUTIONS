class ZeroEvenOdd {
private:
    bool state;
    bool isOdd;
    std::mutex mtx;
    std::condition_variable cv;
    int n;

public:
    ZeroEvenOdd(int n):state{true}, isOdd{true} {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
    for (int i = 1; i <= n; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{ return state; });
        printNumber(0);          // fix 1: print 0, not 1
        state = false;
        cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return !state && !isOdd; });
            printNumber(i);          // fix: print actual number
            state = true;
            isOdd = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return !state && isOdd; });
            printNumber(i);          // fix: print actual number
            state = true;
            isOdd = false;
            cv.notify_all();
        }
    }
};
