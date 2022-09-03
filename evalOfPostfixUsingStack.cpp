//A program to evaluate a postfix expression.
# include <iostream>
# include <string>
# include <stack>

using namespace std;

int evalExp(string Exp)
{
    stack <int> S; //Decalre an integer stack to store the operands.
    for(int i = 0 ; Exp[i] != '\0' ; i++) //Parse the passed Postfix expression.
    {
        if(Exp[i] == ' ')
        {
            continue;
        }

        else if(isdigit(Exp[i])) //If the read character is a digit / operand
        {
            int Num = 0;
            while(isdigit(Exp[i]))
            {
                Num = Num * 10 + (int)(Exp[i] - '0');
                i++;
            }
            i--;
            S.push(Num); //Push it into the stack.
        }

        else //When you encounter an operator, pop the first two values and perform an operation.
        {
            int Val2 = S.top();
            S.pop();
            int Val1 = S.top();
            S.pop();
            switch(Exp[i]) //After performing the resultant operation, push the result into the stack.
            {
                case '+' : S.push(Val1 + Val2);
                            break;
                case '-' : S.push(Val1 - Val2);
                            break;
                case '*' : S.push(Val1 * Val2);
                            break;
                case '/' : S.push(Val1 / Val2);
                            break;
            }
        }
    }
    return S.top(); //Return the topmost element of the stack to main() which also happens to be the only element present in the stack.
}

int main(void)
{
    string postFix;
    cout << "\nEnter the postfix expression : ";
    getline(cin, postFix);
    int Res = evalExp(postFix);
    cout << "Evluation Of the expression results in : " << Res;
    return 0;
}
