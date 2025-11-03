#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

union u
{
    unsigned i;
    float f;
};

void to_binary(unsigned int num)
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
    cout << fixed;
    cout.precision(2);

    u num;
    float ch = 1.0;

    for (int i = 1; i <= 30; i++) {
        ch = ch * 10.0;
        num.f = ch;

        cout << num.f << ' ';
        to_binary(num.i);
        cout << '\n';

        }

    return 0;
}
