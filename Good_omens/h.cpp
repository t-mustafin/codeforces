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

struct bd
{
    T b;
    T d;

    bd(T ib, T id)
    {
        b = ib;
        d = id;
    }
};
void assert(bool cond)
{
    if (!cond)
        T a = *(T*)NULL;
}

void test()
{
    T n, m;

    cin >> n;
    cin >> m;

    map<T, T> c; // soldier index; coordinate x
    multimap<T, bd> r; // rules: soldier index a; bd(b, d) rule.

    for (int i = 1; i <= m; i++)
    {
        T a, b, d;
        cin >> a;
        cin >> b;
        cin >> d;

        r.emplace(a, bd(b, d));
        r.emplace(b, bd(a, -d));
    }

    list<T> l;

    for (auto it = r.begin(); it != r.end(); it = r.begin())
    {
        T a = it->first;
        T b = it->second.b;
        T d = it->second.d;
        r.erase(it);

        assert(c.find(a) == c.end() && c.find(b) == c.end());

        c.emplace(a, 0);
        c.emplace(b, d);

        l.push_back(a);
        l.push_back(b);

        for (auto il = l.begin(); il != l.end(); il++)
        {
            for (auto ii = r.find(*il); ii != r.end(); ii = r.find(*il))
            {
                T ai = ii->first;
                T bi = ii->second.b;
                T di = ii->second.d;
                r.erase(ii);

                l.push_back(bi);

                assert(c.find(a) != c.end());

                if (c.find(bi) == c.end())
                {
                    c.emplace(bi, c[ai] + di);
                }
                else
                {
                    if (c[bi] != c[ai] + di)
                    {
                        cout << "no" << endl;
                        return;
                    }
                }
            }
        }

        l.clear();
    }

    cout << "yes" << endl;

    return;
}

int main() // H task
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
