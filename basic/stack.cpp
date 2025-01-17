#include <stdint.h>
#include <stdbool.h>
#include <string>
#include <iostream>


// stack can be implemeted in a fixed size array or linked list

// push
// --> S000000000
//      ^
//   top ptr

using namespace std;

template<typename T>
class ArrayStack {
    public:
    ArrayStack(int size) {
        this->data = new T[size];
        this->max_size = size;
        this->top_ptr = &this->data[0];
    }
    ~ArrayStack() {
        delete this->data;
    };
    bool pop(T * value) {
        if (this->isEmpty()) {
            return false;
        }
        *value = *this->top_ptr;
        this->top_ptr -= 1;
        return true;
    }
    bool push(T value) {
        if (this->isFull()) {
            return false;
        }
        this->top_ptr += 1;
        *this->top_ptr = value;
        return true;
    }
    bool isEmpty() {
        if (this->top_ptr == &this->data[0]) {
            return true;
        } else {
            return false;
        }
    }
    bool isFull() {
        int position = this->top_ptr - &this->data[0];

        if (position >= 10) {
            return true; 
        } else {
            return false;
        }
    }
    T peak() {
        return *this->top_ptr;
    }
    private:
    T * data;
    int max_size;
    int * top_ptr;
};

int main(int argc, char *argv[])
{
    int value = 0;

    ArrayStack<int> _as(10);

    if (_as.push(100) == false) {
        exit(1);
        std::cout << "push failed" << std::endl;
    }

    if (_as.push(50) == false) {
        exit(1);
        std::cout << "push failed" << std::endl;
    }

    if (_as.pop(&value) == false) {
        std::cout << "pop failed" << std::endl;
    }

    if (value != 50) {
        std::cout << "stack push and pop value inconsistent" << std::endl;
    }

    exit(0);

}

/*
Stack => Last in First out
Queue => First In first Out
Stack 1 => can only push
Stack 2 => can only pop

concat Stack 1 head to Stack 2 head
-> SSSSSSSSS
   ^       ^
   |       |
   A top    A end

<- SSSSSSSSS
   ^       ^
   |       |
  B top      B end

   SSSSSSSSS -> 
   ^       ^
   |       |
   B end   B top

Stack A head points Stack B end
Stack B head points Stack A end

push() => can only push to Stack A
pop() => can only pop from Stack B

Combine 2 stack into a queue
*/
