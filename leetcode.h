#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
