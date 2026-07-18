// Last updated: 18/07/2026, 20:02:35
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        // if(n==1)
        // {
        //     int temp;
        //     if(tokens[0][0] == '-')
        //     {
        //         temp  = stoi(tokens[0].substr(1));
        //     }
        //     else
        //     {
        //         temp = stoi(tokens[0]);
        //     }
        //     return temp;  
        // }
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "*" or tokens[i] == "/" or tokens[i] == "+" or tokens[i] == "-")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(tokens[i] == "*")
                {
                    st.push(temp1*temp2);
                }
                else if(tokens[i] == "/")
                {
                    st.push(temp2/temp1);
                }
                else if(tokens[i] == "+")
                {
                    st.push(temp1+temp2);
                }
                else
                {
                    st.push(temp2-temp1);
                }
                    
            }
            else
            {
                int temp;
                if(tokens[i][0] == '-')
                {
                    temp  = stoi(tokens[i].substr(1));
                    temp = temp*-1;
                }
                else
                {
                    temp = stoi(tokens[i]);
                }
                st.push(temp);
            }
        }
        return st.top();
    }
};