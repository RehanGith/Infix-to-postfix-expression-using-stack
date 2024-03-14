#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char n) {
	switch (n) {
	case '(':
	case ')':
		return 4;
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

int main() {
	

}