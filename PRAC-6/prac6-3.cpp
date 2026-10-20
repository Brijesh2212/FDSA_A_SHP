#include<iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;

    if(x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    string exp;
    getline(cin, exp);

    string result = "";

    for(int i=0;i<exp.length();i++)
    {
        char ch = exp[i];

        if(ch == ' ')
            continue;

        if((ch >= '0' && ch <= '9') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z'))
        {
            result = result + ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                result = result + pop();
            }

            if(top != -1)
                pop();
        }
        else
        {
            while(top != -1 && stack[top] != '(' &&
                  priority(stack[top]) >= priority(ch))
            {
                result = result + pop();
            }

            push(ch);
        }
    }

    while(top != -1)
    {
        result = result + pop();
    }

    cout << "Postfix: " << result << endl;

    return 0;
}