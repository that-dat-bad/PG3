#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int step = 1;

void print_message(int thread_id) {
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [thread_id] { return step == thread_id; });
    std::cout << "thread " << thread_id << std::endl;


    step++;

    lock.unlock();
    cv.notify_all();
}

int main() {
    std::thread t1(print_message, 1);
    std::thread t2(print_message, 2);
    std::thread t3(print_message, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}