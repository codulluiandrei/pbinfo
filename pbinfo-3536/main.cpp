#include <bits/stdc++.h>
using namespace std;
ifstream in("evaluareexpresie.in");
ofstream out("evaluareexpresie.out");
#define MAX 51
int prec(string c)
{
    if (c == "^")
        return 3;
    if (c == "*")
        return 2;
    return 1;//(c == "+" || c == "-")
}
vector<string> CreateTokens(string text)
{
    vector<string> tokens;
    int i = 0;
    string m = "";
    while (text[i])
    {
        if (strchr("+-*^", text[i]))
        {
            tokens.push_back(m);
            tokens.push_back(string(1, text[i]));
            m = "";
        }
        else
            m += text[i];
        i++;
    }
    tokens.push_back(m);
    return tokens;
}
vector<string> infixToPostfix(vector<string> tokens)
{
    vector<string> output;
    stack<string> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (!strchr("+*-^", tokens[i][0]))//operand
            output.push_back(tokens[i]);
        else {//operator
            while (!st.empty() && prec(tokens[i]) <= prec(st.top()))
            {
                string s = st.top();
                st.pop();
                output.push_back(s);
            }
            st.push(tokens[i]);
        }
    }
    while (!st.empty())
    {
        string s = st.top();
        st.pop();
        output.push_back(s);
    }
    return output;
}
long long int PostfixEval(vector<string> tokens)
{
    stack<long long int> nums;
    int len = tokens.size();
    for (int i = 0; i < len; i++) {
        if (strchr("+-*^", tokens[i][0])) //operator
        {
            long long int a = 0, b = 0;
            if (nums.size())
            {
                b = nums.top();
                nums.pop();
            }
            if (nums.size())
            {
                a = nums.top();
                nums.pop();
            }
            switch (tokens[i][0])
            {
                case '+': nums.push(a + b); break;
                case '-': nums.push(a - b); break;
                case '*': nums.push(a * b); break;
                case '^': nums.push(pow(a, b) + 0.5); break;
            }
        }
        else
            nums.push(stoll(tokens[i]));
    }
    if (nums.size())
        return nums.top();
    return 0;
}
int main()
{
    char exp[MAX];
    in.getline(exp, MAX);
    vector<string> tokens = CreateTokens(string(exp));
    vector<string> postfix = infixToPostfix(tokens);
    for (string i : postfix)
        out << i<<" ";
    out << "\n";
    out << PostfixEval(postfix);
    return 0;
}