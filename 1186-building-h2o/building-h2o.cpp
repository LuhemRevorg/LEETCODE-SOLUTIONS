class H2O {
    int count;
    std::mutex mtx;
    std::condition_variable cv;
public:
    H2O():count{2} {}

    void hydrogen(function<void()> releaseHydrogen) {
        
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return count > 0;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        --count;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return count == 0;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        count=2;
        cv.notify_all();
    }
};
