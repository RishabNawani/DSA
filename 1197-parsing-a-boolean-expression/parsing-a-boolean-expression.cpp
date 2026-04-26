class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression) {
            if (c == ',') continue;
            if (c != ')') {
                st.push(c);
            } else {
                int t = 0, f = 0;
                // count values inside current parentheses
                while (st.top() != '(') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') t++;
                    else if (val == 'f') f++;
                }
                st.pop(); // remove '('
                char op = st.top();
                st.pop();
                char result;
                if (op == '!') {
                    result = (f == 1) ? 't' : 'f';
                } else if (op == '&') {
                    result = (f == 0) ? 't' : 'f';
                } else { // '|'
                    result = (t > 0) ? 't' : 'f';
                }
                st.push(result);
            }
        }
        return st.top() == 't';
    }
};