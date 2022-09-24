#include <iostream>
#include <cmath>

#define pi 3.1415

using namespace std;

int main()
{
    int r, l;
    cin >> r >> l;
    cout << floor(l/((4.0/3) * pi * r * r * r)) << endl;
    return 0;
}
