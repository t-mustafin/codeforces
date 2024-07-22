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
T b[SIZE];
T d[SIZE];

void test()
{
    T n, m;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    multiset<T> B;

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];

        if (b[i] == a[i])
            a[i] = 0; // Indicate element as possible
        else
            B.emplace(b[i]);
    }

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> d[i];

        auto it = B.find(d[i]);
        if (it != B.end())
            B.erase(it);
    }

    if (!B.empty())
    {
        cout << "no" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (d[m] == b[i])
        {
            cout << "yes" << endl;
            return;
        }
    }

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
