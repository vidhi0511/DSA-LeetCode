class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')'){
                int x = st.size();
                res = max(res, x);
                st.pop();
            }
        }
        return res;
    }
};