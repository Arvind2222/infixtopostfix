/*===============================================================================================================
 
 Author : Arvind Mishra
 14CE7029
 
 This program implements a menu driven circular queue progeam :)
 https://github.com/Arvind2222/infixtopostfix
 
 The program is copyright under the GNU GPL v2.0
 
 ==============================================================================================================*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char s[SIZE];
int top = -1;

void push(char elem) {
    s[++top] = elem;
}

char pop() {
    return (s[top--]);
}

int pr(char elem) {
    switch (elem) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        default:
            return 1;
    }
}
void pushit(int ele){                    
    s[++top]=ele;
}

int popit(){
    return(s[top--]);
}

int main()
{
    char infx[50], pofx[50], ch, elem;
    int i = 0, k = 0, op1, op2,ele;
    printf("\n\nRead the Infix Expression  :  ");
    scanf("%s", infx);
    push('#');
    while ((ch = infx[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofx[k++] = ch;
        else if (ch == ')') {
            while (s[top] != '(')
                pofx[k++] = pop();
            elem = pop();      /* Remove ( */
        } else {       /* Operator */
            while (pr(s[top]) >= pr(ch))
                pofx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')     /* Pop from stack till empty */
        pofx[k++] = pop();
    pofx[k] = '\0'; /* Make pofx as valid string */
    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n", infx, pofx);
    
    while( (ch=pofx[i++]) != '\0')
    {
        if(isdigit(ch)) pushit(ch-'0');
        else
        {        /* Operator,pop two  operands */
            op2=popit();
            op1=popit();
            switch(ch)
            {
                case '+':pushit(op1+op2);break;
                case '-':pushit(op1-op2);break;
                case '*':pushit(op1*op2);break;
                case '/':pushit(op1/op2);break;
            }
        }
    }
    printf("\n Given Postfix Expn: %s\n",pofx);
}
/*===========================================output============================================================
 
 Arvinds-MacBook-Pro:infixtopostfix arvind$ make infixtopostfix
 cc     infixtopostfix.c   -o infixtopostfix
 Arvinds-MacBook-Pro:infixtopostfix arvind$ ./infixtopostfix
 
 
 Read the Infix Expression  :  A+B*C/D
 
 
 Given Infix Expn: A+B*C/D  Postfix Expn: ABC*D/+
 
 Given Postfix Expn: ABC*D/+
 
 =============================================================================================================*/

