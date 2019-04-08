/*/////////////////////////////////////////////////////////////////////////////////////////
								Program start
*/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>		//in and out stream
#include <string>		//string

using namespace std;		//standard libary namespace 

int* Options();		//function declareation
void transaction(int* balance, int difference);			//function declareation
int state;		//state of program
///////////////////////////////////////////////////////////////////////////////////////// Start main function
int main()		//start main function
{
	int accountBalance = 0;		//declare accountBalance and initalize it to 0
	int* rAccountBalance = &accountBalance;		//declare pointer for accountBalance
	string usersName;		//usersName string
	string* rusersName = &usersName;		//declare pointer for usersName

	cout << "---Online Banking---\n";		//start program 
	cout << " What's your name? \n";		//ask question
	cin >> *rusersName;		//get imput into rusersName
	cout << "\n Welcome, " << usersName << ".\n";		//welcome to account
	cout << "Your acount balance is: " << accountBalance << "\n\n";		//display accountBalance

	char loop = 'n';		//inisalize loop = to n
	do {

		state = *Options();		// state = options

		if (state == 1) {		//if state is = to 1
			cout << "How much would you like to deposit?: \n";		//display message
		}
		else if (state == 2) {		//if state is = to 2
			cout << "How much would you like to withdrawal?: \n";		//display message
		}

		int amount;		// declare amount 
		cin >> amount;		// take in how much they would like to Withdraw or deposit


		transaction(rAccountBalance, amount);		//do transaction

		do {
			cout << "--------------------------------------------------\n ";	//separator
			cout << "Would you like to make another transaction? (y/n): ";		//ask if they would like to make another trasaction
			cin >> loop;		//user input into loop state
			cout << endl << endl;		//spacer
		} while (loop != 'y' && loop != 'n');		//while loop state is not y and n
	} while (loop == 'y');		//while loop state = y

	cout << "Thanks for coming!\n\n";		//display message
	system("pause");						//pause screen

	return 0;			//end program
}
/////////////////////////////////////////////////////////////////////////////////////////////		start options function
int* Options() {		//helper function options
	int* pstate = &state;		//declare state as a pointer

	do {		//do loop
		cout << "To Deposit:	Enter 1.\nTo Withdrawal:	 Enter 2.\n";		//display choice
		cin >> *pstate;		//user input into pstate
	} while (*pstate != 1 && *pstate != 2);		//while pstate
	cout << "You selected: ";		//user selection
	if (*pstate == 1) {		//if choice was deposit
		cout << "Deposit.\n\n";
	}
	else {
		cout << "Withdrawal\n\n";	//if choice was withdraw
	}
	return pstate;		//return value
}
////////////////////////////////////////////////////////////////////////////////////////////		start trasaction function
void transaction(int* balance, int difference) {	//helper function for trasactions
	if (state == 1) {		//if state is 1
		
		*balance += difference;		// deposit
	}
	else if (state == 2) {	//if state is 2
		
		*balance -= difference;		// withdrawal
	}
	cout << "Your new balance is: " << *balance << "\n\n";		//show new balance
	return;		//return values
}

/*/////////////////////////////////////////////////////////////////////////////////////////
								Program End
*/////////////////////////////////////////////////////////////////////////////////////////