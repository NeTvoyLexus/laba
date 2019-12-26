#include "Stack.h"

int main()
{
    Stack <int> myStack(2);

	int k;
    // заполняем стек

	cout << "Razmer steka: \n";
	cin >> k ;
    cout << "Dobavim elementi v stek: \n";
    for(int i = 0; i <= k; i++){
        int temp;
        cin >> temp;
        myStack.push(temp);
    }
	cout << "Poluchivshiysy Stack: \n";

    myStack.printStack(); 

    cout << "\nUberem 2 verhnih:\n";

    myStack.pop();
    myStack.printStack();
    cout << "=========================\n";
    myStack.pop(); 
    myStack.printStack(); 

    return 0;
}