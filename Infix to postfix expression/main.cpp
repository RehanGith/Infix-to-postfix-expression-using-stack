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
		return -1;
	}
}
int solve_postfix(string exp) {
	stack<int> st;
	int op1, op2, res;
	for (char c : exp) {
		if (isdigit(c))
			st.push(atoi(&c));
		else  {
			op2 = st.top();
			st.pop();
			op1 = st.top();
			st.pop();
			switch (c) {
				case '^':
					res = op1 ^ op2;
					break;
				case '*':
					res = op1 * op2;
					break;
				case '/':
					res = op1 / op2;
					break;
				case '+':
					res = op1 + op2;
					break;
				case '-':
					res = op1 - op2;
					break;
				default:
					res = 0;
			}
			st.push(res);
		}
	}
	return res;
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
	
	string s = infix_to_postfix("2*3/2+3-2");
	cout << s << " " << solve_postfix(s) << endl;
}