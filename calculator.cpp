#include<iostream>
using namespace std;
char op;
void addition()
{
    int sum = 0;
    int n;
    int numberitems;
    cout << "Enter number of items: \n";
    cin >> numberitems;

    for (int i = 0; i < numberitems; i++)
    {
        cout << "Enter number " << i << ":\n\n";
        cin >> n;
        sum += n;
    }
    cout << "sum is: " << sum << endl << endl;

}
void subtraction()
{
    int diff;
    int n1, n2;
    cout << "enter two numbers to find their difference:\n\n";
    cout << "enter first number:";
    cin >> n1;
    cout << "\nenter second number:";
    cin >> n2;
    diff = n1 - n2;
    cout << "\ndifference is:" << diff << endl << endl;
}
void multiplication()

{
    int pro = 1;
    int n;
    int numberitems;
    cout << "enter number of items:\n";
    cin >> numberitems;
    for (int i = 0; i < numberitems; i++)
    {
        cout << "\nenter item " << i << ":";
        cin >> n;
        pro *= n;
    }

    cout << "product is:" << pro << endl << endl;
}
void division()
{
    float div;
    int n1;
    int n2;
    cout << "enter 2 numbers to find their quotient\n\n";
    cout << "enter numerator:";
    cin >> n1;
    cout << "\nenter denominator:";
    cin >> n2;
    div = n1 / n2;
    cout << "\nquotient is:" << div << endl << endl;
}
void power()
{
    long int p;
    int res = 1, n;
    cout << "enter number:";
    cin >> n;
    cout << "\nenter power:";
    cin >> p;
    for (int i = 1; i <= p; i++)
    {
        res = n * res;
    }
    cout << n << "\n power " << p << " is :" << res << endl;
}
void HCF_()
{
    int n1, n2;

    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    while (n1 != n2)
    {
        if (n1 > n2)
            n1 -= n2;  //n1 = n1-n2
        else
            n2 -= n1; //n2 = n2-n1
    }

    cout << "HCF = " << n1 << endl;

}
int main()
{


    system("cls");
    while(op != '0')
    {

        system("pause");
        system("cls");
        cout << "***which operation you want to perform***\n";
        cout << "press 0 for exit\n";
        cout << "press 1 for addition \n";
        cout << "press 2 for subtraction\n";
        cout << "press 3 for multiplication\n";
        cout << "press 4 for division\n";
        cout << "press 5 for Power\n";
        cout << "press 6 for HCF\n";

        cout << "press option:";
        cin >> op;
        switch (op)
        {
        case '1':
            addition();

            break;
        case '2':
            subtraction();
            break;
        case '3':
            multiplication();
            break;
        case '4':
            division();
            break;
        case '5':
            power();
            break;
        case '6':
            HCF_();
            break;
        case '0':
            return 0;
        default:
            cout << "invalid input";
            system("cls");
        }
    } 
}
