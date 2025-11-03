#include <iostream>
using namespace std;

int main() {
    cout << fixed;
    cout.precision(2);

    float x = 100000000.0;

    cout << "Start with: " << x << endl;
    cout << "Our goal: " << x + 100.0 << endl;
    cout << "Step size: 1.0" << endl << endl;

    int count = 0;

    while (x < 100000000.0 + 1000.0) {
        float old_x = x;
        x = x + 1.0;
        cout << x << '\n';


        count++;

        if (count <= 100) {
            cout << "Step " << count << ": x = " << x << endl;
        }


        if (count > 100) {
            cout << "Number doesn't change at all, so we'll stop counting.";
            break;
        }
    }

    return 0;
}
