#include <iostream>
#include <pthread.h>

#include <future>

//https://stackoverflow.com/questions/45601811/undefined-reference-to-pthread-clion

using namespace std;


void asyncFunction(){
    cout << "Async Thread: "<< this_thread::get_id() << endl;
    cout << "I am inside async" << endl;
}

int main() {

    bool a = false;
    while (true){
        if (not a){
            a = true;
            cout << "Main Thread: "<< this_thread::get_id() << endl;
            future<void> fn = async(launch::async, asyncFunction);

            fn.get();

        }

    }

}