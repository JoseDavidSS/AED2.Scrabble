//
// Created by jose on 16/03/19.
//

#include "ASync.h"
#include <pthread.h>
#include <future>
#include <iostream>

using namespace std;

void ASync::toDo() {
    cout << "Async Thread: "<< this_thread::get_id() << endl;
    cout << "I am inside async" << endl;
}

void ASync::aSyncFunction() {
    cout << "Main Thread: " << this_thread::get_id() << endl;
    future<void> fn = async(launch::async, toDo);

    fn.get();
}

