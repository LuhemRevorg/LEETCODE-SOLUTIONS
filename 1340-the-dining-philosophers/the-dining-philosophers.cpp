class DiningPhilosophers { // left, right
    std::vector<std::pair<bool, bool>> states;
    std::mutex mtx;
    std::condition_variable cv;
    
public:
    DiningPhilosophers(): states{std::vector<std::pair<bool,bool>>(5)} {

        for(int i = 0; i < 5; ++i) {
            states[i] = std::pair<bool, bool>(false, false);
        }

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        std::unique_lock<std::mutex> lock(mtx);
		int left = 0, right = 0;
        if (philosopher==0) {
            left = 4;
            right = 1;
        } else if (philosopher == 4) {
            left = 3;
            right = 0;
        } else {
            left = philosopher - 1;
            right = philosopher + 1;
        }

        cv.wait(lock, [&] {return !states[left].second;});
        states[philosopher].first = true;
        pickLeftFork();
        cv.wait(lock, [&]{return !states[right].first;});
        states[philosopher].second = true;

        pickRightFork();

        eat();

        states[philosopher].first = false;
        putLeftFork();
        cv.notify_all();
        states[philosopher].second = false;
        putRightFork();
        cv.notify_all();

    }
};
