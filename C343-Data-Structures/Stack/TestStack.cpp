#include "Stack.hpp"
#include <iostream>

using namespace std;

int main() {
	Stack1<int> stk1;
	cout << "STACK ONE\nSTK1:";
	stk1.outputStack();
	cout << "\nTESTING PUSH, LENGTH, POP, AND TOP\n";

	//TESTING PUSH
	cout << "\nPUSHING 23 ONTO THE STACK \nSTK1:";
	int xi;
	xi = 23;
	stk1.push(xi);
	stk1.outputStack();

	cout << "\n\nPUSHING 10 ONTO THE STACK \nSTK1:";
	xi = 10;
	stk1.push(xi);
	stk1.outputStack();

	cout << "\n\nPUSHING 7 ONTO THE STACK \nSTK1:";
	xi = 7;
	stk1.push(xi);
	stk1.outputStack();

	//TESTING REPLACEETOP
	cout << "\n\nREPLACING TOP WITH 4\nSTK1:";
	xi = 4;
	stk1.replaceTop(xi);
	stk1.outputStack();

	//TESTING LENGTH
	cout << "\nSIZE:"<<stk1.length();
	//TESTING TOP 
	cout << "\nTOP:" << stk1.top();

	//TESTING POP
	cout << "\n\nPOPPING STACK ONE";
	stk1.pop(xi);
	cout<< "\nThe Value Popped:"<<xi<<"\nSTK1:"; 
	stk1.outputStack();

	stk1.pop(xi);
	cout << "\n\nThe Value Popped:" << xi << "\nSTK1:";
	stk1.outputStack();

	stk1.pop(xi);
	cout << "\n\nThe Value Popped:" << xi << "\nSTK1:";
	stk1.outputStack();
	cout << "\nSIZE:" << stk1.length();
	
	//TESTING TRANFERFROM 
	cout << "\n\nTESTING TRANFERFROM WITH STK1 AND STK2\nSTK2:";
	Stack1<int>stk2;
	stk2.outputStack();
	cout << "\nFilling STK1 with <10,20,40>\nSTK1:";

	xi = 40;
	stk1.push(xi);
	xi = 20;
	stk1.push(xi);
	xi = 10;
	stk1.push(xi);
	stk1.outputStack();
	cout << "\n\nFilling STK2 with <5,60,300>\nSTK2:";

	xi = 300;
	stk2.push(xi);
	xi = 60;
	stk2.push(xi);
	xi = 5;
	stk2.push(xi);
	stk2.outputStack();

	cout << "\n\nTRANFERING STK1 TO STK2\nSTK2:";
	stk2.transferFrom(stk1);
	stk2.outputStack();
	cout << "\nSTK1:";
	stk1.outputStack();

	//TESTING OPERATOR=
	cout << "\n\nTESTING OPERATOR=\n\nSETTING STK1=STK2\nSTK1:";
	stk1 = stk2;
	stk1.outputStack();

	//TESTING CLEAR
	cout << "\n\nTESTING CLEAR\nSTK1:";
	stk1.clear();
	stk2.clear();
	stk1.outputStack();
	cout << "\nSTK2:";
	stk2.outputStack();
}
