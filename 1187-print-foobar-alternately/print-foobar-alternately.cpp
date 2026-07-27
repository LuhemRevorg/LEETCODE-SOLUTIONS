class FooBar {
private:
    int state;
    std::mutex mtx;
    std::condition_variable cv;
    int n;
    
public:
    FooBar(int n):state{0} {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            cv.wait(lock, [&] {return state==0;});
            state=1;
        	printFoo();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
        	// printBar() outputs "bar". Do not change or remove this line.
            cv.wait(lock, [&] {return state==1;});
            state=0;
        	printBar();
            cv.notify_one();
        }
    }
};
