# include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


//Function to display user entered values
void displayUserInput (double iVest, double monthD, double intR, int Nyears) {
    cout << "**************************************" << endl;
    cout << "************Customer Input************" << endl;
    cout << "Initial Investment Amount: " << iVest << endl;
    cout << "Monthly Deposit: " << monthD << endl;
    cout << "Annual Interest: "  << intR << endl;
    cout << "Number of years: "  << Nyears << endl;
}
// Function to display Year-End info.
// The nested loop compounds interest monthly while the main loop prints to the screen.
void userChart (double iVest, double monthD, double intR, int Nyears) {
    int i;
    int j;
    double yEnd;
    double yStart;

    cout << endl << endl << endl;
    cout << "        Balance Without Additional Deposits        " << endl << endl ;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "Year       Year End Balance       Year End Interest" << endl;
    for (i = 1; i <= Nyears; ++i) {
        yStart = iVest;
        for (j = 0; j < 12; ++j) {
            iVest = iVest + (iVest*((intR/100)/12));
        }
        yEnd = iVest - yStart;
        cout << setw(2) << setfill ('0') << i << "    ";
        cout << "\t\t$" << setfill (' ') << iVest;
        cout << "\t\t$" << fixed << setprecision(2) <<  yEnd << endl;
    }
} 
//Function to display Year-End info WITH Additional deposits.  I was able to add the monthly deposit to the 
//loop that calculates the monthly compounded interest.
void userChartExtra (double iVest, double monthD, double intR, int Nyears) {
    int i;
    int j;
    double yEnd;
    double yStart;

    cout << endl << endl << endl;
    cout << "          Balance With Additional Deposits         " << endl << endl ;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "Year       Year End Balance       Year End Interest" << endl;
    for (i = 1; i <= Nyears; ++i) {
        yStart = iVest;
        for (j = 0; j < 12; ++j) {
            iVest = iVest + monthD +(iVest*((intR/100)/12));
        }
        yEnd = iVest - yStart;
        cout << setw(2) << setfill ('0') << i << "    ";
        cout << "\t\t$" << setfill (' ') << iVest;
        cout << "\t\t$" << fixed << setprecision(2) <<  yEnd << endl;
    }
} 


int main () {
    double initialInvestment = 1000;
    double monthlyDeposit = 100;
    double annualInterest = 6;
    int numberYears = 50;
    char userInput = 'y';
    char pause;
//I added a loop so the user can calculate several different inputs without restarting the program
    while (userInput == 'y'){
        cout << "***********Investment Calculator************"<<endl;
        cout << "Enter Initial Investment Amount"<< endl;
        cin >> initialInvestment;
        //I added input verification.  I checked all for string inputs and positive values.
        //I set upper limits for interest rate and years because if the user entered their deposit amount in by accident, it would cause the program to run wild.
        while(1) {
            if ((cin.fail())||(initialInvestment <= 0)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please enter a positive number" << endl;
                cin >> initialInvestment;
            }
            if ((!cin.fail())&&(initialInvestment > 0)){
            break;
            }
        }
        cout << "Enter Annual Interest Rate" << endl;
        cin >> annualInterest;
        while(1) {
            if ((cin.fail())||(annualInterest <= 0)||(annualInterest >= 20)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please enter a positive number less than 20" << endl;
                cin >> annualInterest;
            }
            if ((!cin.fail())&&(annualInterest > 0)&&(annualInterest < 20)){
            break;
            }
        }
        cout << "Enter Monthly Deposit" << endl;
        cin >> monthlyDeposit;
        while(1) {
            if ((cin.fail())||(monthlyDeposit < 0)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please enter a positive number or zero" << endl;
                cin >> monthlyDeposit;
            }
            if ((!cin.fail())&&(monthlyDeposit >= 0)){
            break;
            }
        }
        cout << "Enter Number of Years" << endl;
        cin >> numberYears;
        while(1) {
            if ((cin.fail())||(numberYears <= 0)||(numberYears >= 50)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Please enter a positive number less than 50" << endl;
                cin >> numberYears;
            }
            if ((!cin.fail())&&(numberYears > 0)&&(numberYears < 50)){
            break;
            }
        }
        cout << endl << endl;
        displayUserInput(initialInvestment, monthlyDeposit, annualInterest, numberYears);
        cout << endl << endl;
        cout << "Enter any character to continue.";
        // I used a char input to pause the program but would like to find a better way to do so in the future.
        cin >> pause;
        userChart(initialInvestment, monthlyDeposit, annualInterest, numberYears);
        cout << endl << endl;
        cout << "Enter any character to continue.";
        cin >> pause;
        userChartExtra(initialInvestment, monthlyDeposit, annualInterest, numberYears);
        cout << endl << endl;
        cout << "Enter y to continue or any other key to quit" << endl;
        cin >> userInput;
    
    }
}