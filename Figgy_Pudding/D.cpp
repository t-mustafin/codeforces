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
    string s, t;
    cin >> s; // s might have '?'
    cin >> t; // Need to find t as substring of s. '?' in s might be replaced with any symbol as t needs.

    bool found = false;

    int it, is; // index in t, index in s

    // Go over both t and s and check if every new t symobol exists in s or there is ? mark in s. O(n) solution.
    for (it = 0, is = 0; it < t.length(); it++)
    {
        found = false;

        for (; is < s.length();)
        {
            if (s[is] == '?' || s[is] == t[it]) // Use ? mark if found cause otherwise this opportunity will be lost.
            {
                s[is] = t[it]; // Replace s symbol with t symbol cause we need to print s candidate as answer.
                found = true;
                is++;
                break;
            }

            is++;
        }

        if (!found)
        {
            break;
        }
    }

    if (found)
    {
        for (; is < s.length(); is++)
            if (s[is] == '?')
                s[is] = 'a'; // Replace every ? left symbols with any english letter cause we need print s candidate as answer.

        cout << "yes" << endl;
        cout << s << endl;
    }
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
