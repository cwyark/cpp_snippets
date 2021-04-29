#include <iostream>
#include <stdlib.h>
#include <unistd.h>

// Reference: https://liam.page/2017/01/17/layers-and-operation-system/

using namespace std;

void onParentProcess(int working) {
    cout << "I'm on parent process: " << working << endl;
}

void onChildProcess(int working) {
    cout << "I'm on child process: " << working << endl;
}

int main() {
    const int index = 42;
    pid_t pid = fork();
    if (pid < 0) {
        cerr << "Fork error" << endl;
    }  else if (pid == 0) {
        onChildProcess(index);
    } else {
        onParentProcess(index);
    }
    exit(EXIT_SUCCESS);
}