#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char n) {
	switch (n) {
	case '^':
		return 5;
	case '*':
		return 4;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 1;
	default:
		return 0;
	}
}
string infix_to_postfix(string exp) {
	stack<char> st;
	
	string res;
	for (char c : exp) {
		if (isdigit(c))
			res += c;
		else if (c == '(')
			st.push(c);
		else if (c == ')') {
			while (!st.empty() && st.top() != '(') {
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (!st.empty() && prec(c) < prec(st.top())) {
			while (!st.empty() && prec(c) < prec(st.top())) {
				res += st.top();
				st.pop();
			}
			st.push(c);
		}
		else
			st.push(c);
	}
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}


int main() {
	
	cout << infix_to_postfix("2*3/2+3-7") << endl;
}