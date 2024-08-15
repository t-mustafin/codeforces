#include <iostream>
#include <set>
#include <cmath>
#include <list>
#include <map>
#include <vector>

using namespace std;

#define T unsigned int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

void test()
{
    T n;

    cin >> n;

    map<T, T> a;
    vector<T> c(n + 1, 0);

    T max = 0;
    T ones = 0;

    for (int i = 1; i <= n; i++)
    {
        T ai;
        cin >> ai;

        auto it = a.find(ai);
        if (it == a.end())
        {
            a.emplace(ai, 1);
        }
        else
        {
            a[ai]++;
        }
    }

    for (auto it = a.begin(); it != a.end(); it++)
    {
        if (it->first == 1)
        {
            ones += it->second;
            continue;
        }

        for (int j = it->first; j <= n; j += it->first)
        {
            c[j] += it->second;
            max = std::max<T>(max, c[j]);
        }
    }

    cout << max + ones << endl;

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
