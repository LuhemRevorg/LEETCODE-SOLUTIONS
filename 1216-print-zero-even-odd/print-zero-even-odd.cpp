class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    bool od;
    bool zro;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        od = false;
        zro = true;
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            {std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{return zro;});
            zro = false;
            od = !od;
            printNumber(0);
            }
            cv.notify_all();

        }
    }

    void even(function<void(int)> printNumber) {
         for (int i = 2; i <= n; i+=2) {
            {std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{return !zro && !od;});
            zro = true;
            printNumber(i);
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+=2) {
            {std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{return !zro && od;});
            zro = true;
            printNumber(i);
            }
            cv.notify_all();
        }
    }
};
