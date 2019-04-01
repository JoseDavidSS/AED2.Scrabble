//
// Created by jose on 16/03/19.
//

#include "ASync.h"
#include <pthread.h>
#include <future>
#include <iostream>

using namespace std;

int ASync::toDo() {
    cout << "Async Thread: "<< this_thread::get_id() << endl;
    cout << "I am inside async" << endl;
}

int ASync::aSyncFunction() {
    cout << "Main Thread: " << this_thread::get_id() << endl;
    future<int> fn = async(launch::async, toDo);

    int a = fn.get();
    return a;
}

