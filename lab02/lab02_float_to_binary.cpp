#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

 union u
    {
        unsigned i;
        float f;
    };

void to_binary (unsigned int num)
{
    unsigned int c = pow(2, 31);
    unsigned int count = 0;

    while (c) {
        cout << bool(num & c);
        c >>= 1;
        ++count;
    }
}

int main() {
    unsigned int a;

    u num;
    cin >> num.f;
    to_binary (num.i);


    return 0;
}
