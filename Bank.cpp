#include <iostream>
#include <iomanip>//library used to display the balance with two decimal places
#include <cstdlib>//clear the system
#include <conio.h> /*(for _getch() and _putch() functions) headerfile reads a single character from the keyboard and 
allows the password to be entered without displaying (echoing) it*/
using namespace std;
void showbalance (double balance);/*indicates that the function does not return any value*/

/*It prompts the user to enter the deposit amount, validates the input, 
and returns the deposit amount as a double value*/
double deposit();

/*It handles the withdrawal operation and prompts the user to enter the withdrawal amount and
represents the current account balance*/
double withdrawn (double balance);
void Change_Password(string& Password);
double transfer(double balance);
double waterbills(double balance);
double electricbills(double balance);


int main () {
system("cls");
double balance = 500;
int choice = 0;
int newPassword;
int recipient_account;

/*string data type is used for storing and comparing the entered password. Also is used to
 store the password entered by the user (userPassword) and the correct password (password). 
 It provides convenient string manipulation and comparison operations.*/
string Password = "4851"; 
string userPassword;
/*By declaring ch as a char type, each character entered by the user is stored in the variable ch.
This allows the program to process the input character by character and perform actions accordingly,
such as appending the character to the userPassword string or displaying asterisks on the screen.*/
char ch;


 
for (int i = 1; i <= 3; i++)
{
// Prompt the user to enter a 4 digit password
      cout << "Enter the Your password (4 digits): ";
  
/*The while loop reads characters from the keyboard using _getch() until the
enter key '\r' is pressed.Each character is added to the userPassword string and replaced with 
an asterisk on the screen using cout */ 

/*If the password length is exactly four digits, it proceeds to check whether the entered password
 matches the actual password. Otherwise it'll display incorrect password*/
      while ((ch = _getch()) != '\r' && userPassword.length() < 4 ) {//If the length of the password exceeds 4 it assumes the fifth character as the enter key
        userPassword.push_back(ch);
        cout << '*';
    }
        cout <<endl;

              

/*If they match, an "Access granted" message is displayed, and the loop is exited using break.*/
          if (userPassword == Password) {
            cout << "Access granted. Welcome!" <<'\n';
            break;
        } else {
/*If the passwords don't match, it checks if it's the third attempt (i == 3). If it is, 
an "Access denied" message is displayed, and the program terminates*/
            if (i == 3) {
                cout << "Incorrect password. Access denied." <<'\n';
                return 0;
            } else {
                cout << "Incorrect password. Please try again." <<endl;
                userPassword.clear();/*userPassword is cleared so that the user can attempt to enter the password again*/
            }
        }
        }
        
        

/*The program utilizes a do-while loop to repeatedly display the menu and process the user's
 choice until the user decides to exit. The loop continues as long as the user's choice is not
equal to 4 (the exit option) */
     
do {
cout << "***********************" << '\n';
cout << "Enter your choice :" << '\n';
cout << "***********************" << '\n';
cout << "1. Change Password" << '\n';
cout << "2. Show Balance" << '\n';
cout << "3. Deposit Money" << '\n';
cout << "4. Withdraw Money" << '\n';
cout << "5. Transfer Money" << '\n';
cout << "6. Pay Water Bills" << endl;
cout << "7. Pay Electric Bills" << endl;
cout << "8. Exit" << '\n';
cin >> choice;
cin.clear();/*It is typically used in error handling scenarios to clear any error flags
that may have been set after an invalid input.*/
fflush(stdin);/*used to flush the input buffer, specifically for the standard input stream stdin.*/

switch (choice)
{
case 1: Change_Password(Password);
        break;
case 2: showbalance(balance);//showing the users balance using showbalance function
        break;
case 3: balance += deposit ();//Depositing (adding) money to users account
        showbalance(balance);
        break;
case 4: balance -= withdrawn(balance);//Withdawing (Subtracting) money from user account
        showbalance(balance);
        break;

case 5:
        balance = transfer(balance);
         showbalance(balance);
        break;
case 6:
        balance -= waterbills(balance);
        showbalance(balance);
        break;

case 7:
       balance -= electricbills(balance);
       showbalance(balance);
      break;
case 8: cout << "Thanks for visiting" << '\n';
        break;     
default: cout << "Invalid Choice please choose the options below" << '\n';//when the user enters options rather than the 4 given options
  break;
}
} while( choice !=8);//The loop continues as long as the user's choice is not equal to 4(exit option)


  return 0;
}

/*The purpose of the showbalance function is to display the balance value to the user.
 It takes the balance value as an argument, typically representing a user's account balance or 
 some other numerical value, and displays it in a user-friendly format.*/

void showbalance (double balance){
 cout << "Your balance is : $" << setprecision(2) << fixed <<   balance << '\n';
}


double deposit(){
      double amount;
      cout << "Enter the amount to be deposited: ";
      cin >> amount;
      if (amount > 0)//checks whether the given amount is valid (non negative)
      {
        return amount;//if the given amount is positive it returns the amount
      }
      else {//but if the given amount is non negative or invlaid charachter displays not valid
        cout << "Thats is not a valid amount: " << '\n';
        return 0;
      }
        
}
double withdrawn (double balance){
      double amount;
      cout << "Enter the amount to be withdtawn: " << '\n';
      cin >> amount;
      if (amount > balance)//checks wheather whithdrawn amount is greater than the actual balance
      {
        cout << "Insufficent balance\n";//if thats true outputs Inssuficent funds
        return 0;
      }
      else if (amount < 0)//checks wheather the withdrawn amount is negative
      {
        cout << "Invalid amount entered\n";//outputs Invalid amount entered
        return 0;
      }
      else{//otherwise without the 2 condition it returns the users data
        return amount;
      }
}
void Change_Password(string& Password){

    cout << "Enter the current password: ";
    string currentPassword;
    cin >> currentPassword;

    if (currentPassword == Password) { //Compares the current password and the input password
        cout << "Enter the new password: ";
        string newPassword;
        cin >> newPassword;

        // Update the password
        Password = newPassword;

        cout << "Password changed successfully!" << endl;
    } else {
        cout << "Incorrect password. Password change failed." << endl;
    }

}
double transfer(double balance) { //Transfers money to a specific account 
    double amount;
    cout << "Enter the amount to be transferred: ";
    cin >> amount;

    if (amount > balance) { //Check the amount of the money that is transfered that more than the users balance
        cout << "Insufficient balance to transfer." << endl; //If its more displays Insufficent balance
    } else if (amount < 0) {
        cout << "Invalid amount entered to transfer." << endl; //If the input is negative number displays Invalid amount entered
    } else {
        double recipient_account;
        cout << "Enter the recipient's account : "; //Enters recipents account
        cin >> recipient_account;

        
        balance -= amount;//Deduct the transfered amount from the balance

        cout << "Transfer successful!" << endl;
        cout << "Your updated balance is: $" << setprecision(2) << fixed << balance << endl;
    }

    return balance;//Finally returns remaining amount of money in the account
}
double waterbills(double balance) {
    double bill_number;
    cout << "Enter the bill number: " << '\n'; //Inputs the bill number service
    cin >> bill_number;
    double amount;
    cout << "Enter bill amount to pay : " << '\n';//Inputs the amount to be paid
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance\n";//If the amount is more than the users balance displays Insufficent balance
        return 0;
    } else if (amount < 0) {//If the input is negative number displays Invalid amount enter
        cout << "Invalid amount entered\n";
        return 0;
    } else {
        return amount;//Finally returns the proper value of the amount entered by the user
    }
}
double electricbills(double balance) {
    double bill_number;
    cout << "Enter the bill number: " << '\n';//Inputs the bill number service
    cin >> bill_number;
    double amount;        
    cout << "Enter the bill amount to pay : " << '\n';//Inputs the amount to be paid
    cin >> amount;
    if (amount > balance) {//If the amount is more than the users balance displays Insufficent balance
        cout << "Insufficient balance\n";
        return 0;
    } else if (amount < 0) {//If the input is negative number displays Invalid amount enter
        cout << "Invalid amount entered\n";
        return 0;
    } else {
        return amount;//Finally returns the proper value of the amount entered by the user
    }
}