class FooBar {
private:
    int n;
    std::mutex mtx;
    int state;
    std::condition_variable cv;

public:
    FooBar(int n):state{1} {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            {std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] {return state == 1;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();++state;}
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            {std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] {return state == 2;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar(); --state;}
            cv.notify_all();
        }
    }
};
