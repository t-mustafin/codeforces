#include <iostream>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

#define T unsigned int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

void test()
{
    T a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    if (a + b > 9 || b + c > 9 || a + c > 9)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    //    std::cout << "Hello! N = " << N << " K = " << K << endl;

    for (int i = 0; i < t; i++) {
        test();
    }

    return 0;
}
