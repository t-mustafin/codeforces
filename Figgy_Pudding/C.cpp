#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <vector>

using namespace std;

#define T int
#define SIZE 200000 + 2  // 2*10^5

#define DEBUG 0
#define SIMPLE 0

void test()
{
    T n, s, m;

    cin >> n;
    cin >> s;
    cin >> m;

    bool ans = false;
    T cl, cr; // (CandidateRight, CandidateLeft) - free time segment

    cl = cr = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> cl;
        if (cl - cr >= s)
        {
            ans = true;
        }

        cin >> cr;
    }

    if (m - cr >= s)
    {
        ans = true;
    }

    if (ans)
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

    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++) {
        test();
    }

    return 0;
}
