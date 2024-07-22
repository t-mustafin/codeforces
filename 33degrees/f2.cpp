#include <cmath>
#include <iostream>
#include <vector>
//#include <list>
#include <map>
#include <numeric>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

#define T unsigned int
#define TS unsigned long long

#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0

template<typename Type>
Type div_up(Type x, Type y)
{
    return x / y + (x % y ? 1 : 0);
}

T n, m, k;
TS w;

void test()
{
    cin >> n;
    cin >> m;
    cin >> k;

    w = 0;
    map<T, map<T, T>> f;

    T r, c;
    vector<TS> a(k + 1, 0);

    for (int i = 1; i <= k; i++)
    {
        cin >> r;
        cin >> c;

        if (f.find(c) == f.end())
        {
            map<T, T> ff;
            ff.emplace(r, i);

            f.emplace(c, ff);
        }
        else
        {
            f[c].emplace(r, i);
        }
    }

    T r_alice = 1;
    T c_alice = 1;

    T r_prev, c_prev; // for F2 hard version

    for (auto it = f.begin(); it != f.end(); it++)
    {
        T r_f = it->second.rbegin()->first;

        if (r_alice > r_f)
        {
            continue;
        }

        w += ((TS)n - r_alice + 1) * ((TS)(it->first) - c_alice);

        r_prev = r_alice - 1;

        r_alice = r_f + 1;
        c_alice = it->first;
        // a[it->second.rbegin()->second] = 1;

        if (it->second.size() != 1)
        {
            auto it_lesser = it->second.rbegin();
            it_lesser++;

            r_prev = max<T>(it_lesser->first, r_prev);
        }
        c_prev = it->first;

        auto jt = it; jt++;
        for (;; jt++)
        {
            if (jt == f.end())
            {
                a[it->second.rbegin()->second] += ((TS)it->second.rbegin()->first - r_prev) * ((TS)(m) - c_prev + 1);
                break;
            }

            T r_f_ = jt->second.rbegin()->first;

            if (r_prev > r_f_)
            {
                continue;
            }

            a[it->second.rbegin()->second] += ((TS)it->second.rbegin()->first - r_prev) * ((TS)(jt->first) - c_prev);

            if (r_f_ >= it->second.rbegin()->first) 
                break;

            r_prev = r_f_;
            c_prev = jt->first;
        }
    }

    if (n >= r_alice) 
    {
        w += ((TS)n - r_alice + 1) * ((TS)m - c_alice + 1);
    }

    cout << w << endl;
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

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
