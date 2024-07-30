#include <iostream>
#include <vector>
#include <cmath>
#include <list>
 
using namespace std;
 
#define T unsigned int
#define SIZE 200000 + 2  // 2*10^5
 
#define DEBUG 0
 
struct node
{
    list<T> child;
    list<T> child_weight; // input weight
 
    T weight; // ^ of all weights from root to this node
    bool odd_floor;
};
 
struct bit_trie_node
{
    bit_trie_node* zero;
    bit_trie_node* one;
    T tree_node;        // node number from tree (not trie)
    T q;    // number of subsequent nodes
 
    bit_trie_node()
    {
        one = zero = NULL;
        tree_node = q = 0;
    }
 
    ~bit_trie_node()
    {
        if (zero != NULL)   delete zero;
        if (one != NULL)    delete one;
    }
};
 
struct bit_trie
{
    bit_trie_node* bit32;
 
    bit_trie()
    {
        bit32 = NULL;
    }
 
    void add_num(T num, T tree_node)
    {
        if (bit32 == NULL)
            bit32 = new bit_trie_node();
 
        bit_trie_node* curr_node = bit32;
 
        for (int i = 31; i >= 0; i--)
        {
            curr_node->tree_node = tree_node; // it is ok to rewrite value if there was something cause we would check q value
            curr_node->q++;
 
            int curr_num = (num >> i) & 1;
            if (curr_num == 0)
            {
                if (curr_node->zero == NULL) curr_node->zero = new bit_trie_node();
                curr_node = curr_node->zero;
            }
            else
            {
                if (curr_node->one == NULL) curr_node->one = new bit_trie_node();
                curr_node = curr_node->one;
            }
        }
 
        curr_node->tree_node = tree_node;
        curr_node->q++;
    }
 
    T find_num(T in, T tree_node) // returns maximum of in^value for this trie except for tree_node
    {
        bit_trie_node* curr_node = bit32;
        T ret = 0;
 
        if (curr_node->q == 1 && curr_node->tree_node == tree_node)
        {
            return 0; // 0 is okish value cause ret value is unsigned and ret value will we compared with another unsigned value
        }
 
        for (int i = 31; i >= 0; i--) // actually for 10^9 30 bits should be egough
        {
            int curr_num = (in >> i) & 1;
 
            // If only one variant available just choose it
            if (curr_node->zero != NULL && curr_node->one == NULL)
            {
                curr_node = curr_node->zero; 
                continue;
            }
 
            if (curr_node->zero == NULL && curr_node->one != NULL)
            {
                curr_node = curr_node->one;
                ret ^= 1 << i;
                continue;
            }
 
            // Should be impossible
            if (curr_node->zero == NULL && curr_node->one == NULL)
            {
               // cout << "Alarma: bit_trie conditions has problem: no bit value available" << endl;
                return *(T*)NULL;
            }
 
            // Both childs has same tree_node num - it is impossible
            if (curr_node->zero->tree_node == curr_node->one->tree_node)
            {
                return *(T*)NULL;
            }
 
            // If child has one value and the value belongs to tree_node - use the opposit
            if (curr_node->zero->q == 1 && curr_node->zero->tree_node == tree_node)
            {
                curr_node = curr_node->one;
                ret ^= 1 << i;
                continue;
            }
 
            if (curr_node->one->q == 1 && curr_node->one->tree_node == tree_node)
            {
                curr_node = curr_node->zero;
                continue;
            }
 
            // Both bit variants fully available - choose best
            if (curr_num == 1)
            {
                curr_node = curr_node->zero;
                continue;
            }
 
            if (curr_num == 0)
            {
                curr_node = curr_node->one;
                ret ^= 1 << i;
                continue;
            }
 
            //cout << "Alarma: bit_trie conditions has problem: no if condition worked" << endl;
            return *(T*)NULL;;
        }
 
        return ret ^ in;
    }
 
    void clear()
    {
        if (bit32 != NULL)  delete bit32;
        bit32 = NULL;
    }
};
 
vector<node> tree;
 
bit_trie even_trie;
bit_trie odd_trie;
 
void init_node(T i, T parent, bool odd_floor, T weight_to_root)
{
    tree[i].odd_floor = odd_floor;
    tree[i].weight = weight_to_root;
 
    if (odd_floor)
    {
        odd_trie.add_num(weight_to_root, i);
    }
    else
    {
        even_trie.add_num(weight_to_root, i);
    }
 
    auto it = tree[i].child.begin();
    auto it_w = tree[i].child_weight.begin();
    for (; it != tree[i].child.end(); it++, it_w++)
    {
        if (*it == parent)
        {
            //tree[i].child.erase(it);
            //tree[i].child_weight.erase(it_w);
        }
        else
        {
            init_node(*it, i, !odd_floor, weight_to_root ^ (*it_w));
        }
    }
 
    return;
}
 
void test()
{
    T n, m;
 
    cin >> n;
    cin >> m;
 
    tree.resize(n + 1);
    for (T i = 1; i <= n; i++) // clear nodes
    {
        tree[i].child.clear();
        tree[i].child_weight.clear();
        tree[i].odd_floor = false;
        tree[i].weight = 0;
    }
 
    for (T i = 1; i <= n - 1; i++) // tree input
    {
        T v, u, w;
        cin >> v;
        cin >> u;
        cin >> w;
 
        tree[v].child.push_back(u);
        tree[v].child_weight.push_back(w);
 
        tree[u].child.push_back(v);
        tree[u].child_weight.push_back(w);
    }
 
    init_node(1, 0, false, 0); // init full tree recursively and adds all weights_to_roots to odd_trie and even_trie
 
    T y_xored = 0;
 
    for (T i = 1; i <= m; i++) // read queries and print answers
    {
        char t;
        cin >> t;
 
        if (t == '^')
        {
            T y;
            cin >> y;
            y_xored ^= y;
        }
        else // t == '?'
        {
            T v, x;
            cin >> v;
            cin >> x;
 
            T odd_best, even_best, v_weight;
 
            bool v_odd = tree[v].odd_floor;
            v_weight = tree[v].weight;
 
            if (v_odd) // odd is 2k+1; even is 2k
            {
                odd_best = odd_trie.find_num(v_weight ^ x, v);   // odd_trie comlexicity is 64 iterations, so O(1). Overall complexicity whould be O(m) or O(n)
                even_best = even_trie.find_num(v_weight ^ x ^ y_xored, v);
            }
            else
            {
                odd_best = odd_trie.find_num(v_weight ^ x ^ y_xored, v);
                even_best = even_trie.find_num(v_weight ^ x, v);
            }
 
            cout << max<T>(odd_best, even_best) << " ";
        }
    }
 
    cout << endl;
 
    odd_trie.clear();
    even_trie.clear();
 
    for (T i = 1; i <= n - 1; i++) // clean tree
    {
        tree[i].child.clear();
        tree[i].child_weight.clear();
    }
 
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
