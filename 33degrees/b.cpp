#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <list>

using namespace std;

#define T int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

template<typename Type>
Type div_up(Type x, Type y)
{
    return x / y + (x % y ? 1 : 0);
}

T a[SIZE];

void test()
{
    T n, f, k;

    cin >> n;
    cin >> f;
    cin >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int bigger, lesser, equal;
    bigger = lesser = equal = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[f]) equal++;
        if (a[i] > a[f]) bigger++;
        if (a[i] < a[f]) lesser++;
    }

    if (k <= bigger) { cout << "no" << endl; return; }
    if (bigger < k && k < bigger + equal && equal != 1) { cout << "maybe" << endl; return; }
    cout << "yes" << endl;

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
