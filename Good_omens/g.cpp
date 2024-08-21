#include <iostream>
#include <set>
#include <cmath>
#include <list>
#include <map>
#include <vector>

using namespace std;

#define T long long int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

void add_to_map(map<T, T> &m, T c)
{
    if (m.find(c) == m.end())
    {
        m.emplace(c, 1);
    }
    else
    {
        m[c]++;
    }
}

T count_pairs(map<T, T>& m)
{
    T res = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        res += (it->second * (it->second - 1));
    }

    return res;
}

void test()
{
    T n;

    cin >> n;

    map<T, T> X, Y, XmY, XpY; // const: x, y, x+y, x-y. this const is first; second is number of points in this group

    for (int i = 1; i <= n; i++)
    {
        T x, y;
        cin >> x;
        cin >> y;

        add_to_map(X, x);
        add_to_map(Y, y);
        add_to_map(XmY, x - y);
        add_to_map(XpY, x + y);
    }

    T pairs = 0;
    pairs += count_pairs(X);
    pairs += count_pairs(Y);
    pairs += count_pairs(XmY);
    pairs += count_pairs(XpY);

    cout << pairs << endl;

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
