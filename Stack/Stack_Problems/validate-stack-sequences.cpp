#include <vector>
#include <stack>

using namespace std;

// https://leetcode.com/problems/validate-stack-sequences/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int i = 0, j = 0;

        for (int num : pushed)
        {
            st.push(num);

            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};