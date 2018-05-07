#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main ()
{
    int loanAmount = 0;
    int numberOfYears = 0;

    double balance = 0.00;
    double annualInterestRate = 0.00;
    double k = 0.00;

    cout<<"Loan Amount: ";
    cin>>loanAmount;

    balance = loanAmount;
    cout<<"Number of Years: ";
    cin>>numberOfYears;

    cout<<"Annual Interest Rate In Percent: ";
    cin>> k;

    annualInterestRate = k / 100;

    double monthlyInterestRate = annualInterestRate / 12;
    double monthlyPayment = loanAmount * monthlyInterestRate / (1 - 1 / pow(1 + monthlyInterestRate, numberOfYears * 12));
    double totalPayment = monthlyPayment * numberOfYears * 12;

    printf("\n");
    printf("------------------------------------------------------------------\n");
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payments: $%.2f\n", totalPayment);
    printf("Payment # Interest Principal Balance\n");

    for (int month = 1; month <= numberOfYears * 12; month++) {
        double monthlyInterest = monthlyInterestRate * balance;
        double principal = monthlyPayment - monthlyInterest;
        balance = balance - principal;

        printf("%d $%.2f $%.2f $%.2f\n", month, monthlyInterest, principal, balance);
    }

    getchar();

    return 0;
}
