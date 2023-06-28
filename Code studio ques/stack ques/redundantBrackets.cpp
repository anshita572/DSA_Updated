//https://bit.ly/3srTkOv
//TC : O(n) SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    // Iterate through the input string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If the character is an opening bracket or an operator, push it to the stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            // If the character is a closing bracket
            if (ch == ')') {
                bool redundant = true;

                // Check if there are any operators between the opening and closing brackets
                while (st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        redundant = false;
                        st.pop();
                    }
                }

                // If no operators are found, the brackets are redundant
                if (redundant == true) {
                    return true;
                }

                st.pop(); // Pop the opening bracket
            }
        }
    }

    return false; // No redundant brackets found
}
