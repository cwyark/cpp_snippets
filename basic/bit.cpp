#include <iostream>
#include <string>
#include <stdio.h>

// #define BIT1 0x0001
// value &= ~ BIT1; => unset a bit
// value |= BIT1; => set a bit
// value & BIT1 => get a bit status

// mask = (1 << i) - 1; e.g. i = 3, mask = 0x1000 - 0x0001 = 0x111

int main(int args, char *argv[])
{
}

// N = 10001100 => 10 001100
// M = 11011          ^
//                  insert M
// i = 2, j = 6
// => 101101100

int prac_001(int M, int N, int i, int j)
{
    int _temp_N_head, _temp_N_end, _temp_M = 0;
    int _temp = 0;
    _temp_N_head = N & ~((1 << j) - 1); // 10 000000
    _temp_N_end = N & ((1 << j) - 1);   // 00 001100
    _temp_M = M << i;                   // 1101100
    _temp = _temp_N_head ^ _temp_M ^ (_temp_N_head >> i);
    return _temp;
}

int prac_004(int value)
{
    int counter = 0;
    int max_number, min_number = 0;
    int max_bits = sizeof(int) * 8;
    for (int i = 0; i < max_bits; i++)
    {
        if (value & (1 << i))
        {
            counter += 1;
        }
    }
    // Now we have the numbers of 1 bits in it's binary representatio.
    min_number = (1 << counter) - 1;
    max_number = min_number << (max_number - counter);
}

int prac_006(int a, int b)
{
    int _temp = 0;
    int counter = 0;
    int max_bits = sizeof(int) * 8;
    _temp = a ^ b;
    for (int i = 0; i < max_bits; i++)
    {
        if (_temp & (1 << i))
        {
            counter += 1;
        }
    }
    return counter;
}

int prac_007(int value)
{
    // 01 => 10 ===> 01 ^ 11 => 11 (01 is odd number)
    // 00 => 00 ===> 00 ^ 00 => 00 (00 is even number)
    // 10 => 01 ===> 10 ^ 11 => 01 (10 is odd number)
    // 11 => 11 ===> 11 ^ 00 => 11 (11 is even number)
    int max_bits = sizeof(int) * 8;
    int _temp = 0;
    for (int i = 0; i < max_bits; i += 2)
    {
        _temp = (value >> i) & 0x03;
        if (_temp != 3 || _temp != 0)
        {
            // do the swap
            value ^= (3 << i);
        }
    }
}

int drawLine_prac008(char * array, int width, int x1, int x2, int y) {
    char * ptr = array + (w / 8) * y;
    for (int i = 0; i < w; i++) {
        if (i <= x2 || i >= x1) {
            *ptr ^= (1 << i);
        }
    }
}

// size of array = 1024
// width = 32 ==> height = (1024 / 32) = 32

// --------------  ^
// |            |
// |   _______  |
// |   x1    x2 |  (sizeof array / w)
// |            |
// ______________  _
// |<-   w    ->|


// ______________   ________________ ...   ___^^^^^^^____
// |<  w .     ->   <-      w     -> ...  |< .   w .   >|