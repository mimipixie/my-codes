#include<bits/stdc++.h>
using namespace std;
#define size 100
int ct=0;// counter
char stk[size];// stack for postfix
char stk1[size][size];// stack for infix
char c[size];// input string
char pst[size];// postfix string
char in[size];// infix string
char str[size],str1[size],str2[size];// popped up strings
void push(char m);// for postfix function
char pop(); // for postfix function
void push1(char m[]);// for infix function
void pop1(int m);// for infix function
bool postfix();
bool infix();
int main()
{
    int i,j,k,y;
    bool b,bb;
    char x;
fflush(stdin);
do{
    printf("Press 1 for Infix to Postfix Conversion\n");
fflush(stdin);
    printf("Press 2 for Postfix to Infix Conversion\n");
fflush(stdin);
    printf("Press 3 for Infix to Postfix Conversion\n");
fflush(stdin);
    printf("        if you have variables or digits\n");
fflush(stdin);
    printf("        with more than 1 digit in your expression\n");
fflush(stdin);
    printf("Enter your choice : ");
fflush(stdin);
    scanf("%d",&y);
fflush(stdin);
    if(y==1)
    {
fflush(stdin);
    printf("Please enter your infix expression : ");
fflush(stdin);
    scanf("%[^\n]s",c);
fflush(stdin);
    ct=0;
    b=postfix();
    ct=0;
    bb=infix();
    if(b==true && bb==true)
    {
fflush(stdin);
        printf("Infix Expression     : ");
fflush(stdin);
        printf("%s\n",in);
fflush(stdin);
        printf("Postfix Expression   : ");
fflush(stdin);
        printf("%s\n",pst);
fflush(stdin);
    }
    else
        printf("Error in input expression. please try again.\n");
fflush(stdin);
    }
    else if(y==2)
    {
    printf("Please enter your postfix expression : ");
fflush(stdin);
    scanf("%s",pst);
fflush(stdin);
    ct=0;
    bb=infix();
    if(bb==true)
    {
fflush(stdin);
        printf("Postfix Expression   : ");
fflush(stdin);
        printf("%s\n",pst);
fflush(stdin);
        printf("Infix Expression     : ");
fflush(stdin);
        printf("%s\n",in);
fflush(stdin);
    }
    else
        printf("Error in input expression. please try again.\n");
fflush(stdin);
    }
    else if(y==3)
    {
    printf("Please enter your infix expression : ");
fflush(stdin);
    scanf("%[^\n]s",c);
fflush(stdin);
    ct=0;
    b=postfix();
    if(b==true)
    {
fflush(stdin);
        printf("Infix Expression     : ");
fflush(stdin);
        printf("%s\n",c);
fflush(stdin);
        printf("Postfix Expression   : ");
fflush(stdin);
        printf("%s\n",pst);
fflush(stdin);
    }
    else
        printf("Error in input expression. please try again.\n");
fflush(stdin);
    }

    else
        printf("invalid input. please try again. \n");

fflush(stdin);
    printf("Do you want to continue ? Press 'y' if yes and 'n' otherwise\n");
fflush(stdin);
    printf("Enter your choice : ");
fflush(stdin);
    scanf("%c",&x);
fflush(stdin);
}while(x=='y');


    return 0;
}
void push(char m)
{
    ct++;
    stk[ct]=m;
}
char pop()
{
    char m;
    if(ct)
    {
        m=stk[ct];
        ct--;
    }
    return m;
}
void push1(char m[])
{
    int i;
    ct++;
    for(i=0;m[i]!='\0';i++)
        stk1[ct][i]=m[i];
    stk1[ct][i]='\0';
}
void pop1(int m)
{
    int i;
    if(ct>=1)
    {
    if(m==1){
        for(i=0;stk1[ct][i]!='\0';i++)
            str1[i]=stk1[ct][i];
        str1[i]='\0';
        ct--;
    }
    else{
        for(i=0;stk1[ct][i]!='\0';i++)
            str2[i]=stk1[ct][i];
        str2[i]='\0';
        ct--;
    }
    }
}

bool infix()
{
    int i,j,k;
    char ch,inf[size];
    bool b=true;
    ct=0;
    for(i=0,k=0;pst[i]!='\0';i++){
    ch=pst[i];
        inf[0]=ch;
        inf[1]='\0';
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        if(ct>=2)
        {
            strcpy(str1,""),
            strcpy(str2,""),
            pop1(2);
            pop1(1);
            strcpy(str,""),
            str[0]='(';
            str[1]='\0';
            strcat(str,str1);
            strcat(str,inf);
            strcat(str,str2);
            strcpy(inf,""),
            inf[0]=')';
            inf[1]='\0';
            strcat(str,inf);
            push1(str);
        }
        else
            return false;
    }
    else
    {
        push1(inf);
    }
    }
    if(ct>1)
        return false;
    if(ct==1)
        strcpy(in,str);
    return b;
}

bool postfix()
{
    int i,j,k;
    char ch,pf;
    bool b=true;
    for(i=0,k=0;c[i]!='\0';i++){
    ch=c[i];
    switch(ch)
    {
        case '+':
            while(ct) // stack not empty
            {
                if(stk[ct]=='+' || stk[ct]=='-' ||
                   stk[ct]=='*' || stk[ct]=='/' )
                {
                    pf=pop();
                    if(pf=='(')
                        return false;
                    pst[k++]=pf;
                }
                else
                    break;
            }push(ch);
            break;
        case '-':
            while(ct) // stack not empty
            {
                if(stk[ct]=='+' || stk[ct]=='-' ||
                   stk[ct]=='*' || stk[ct]=='/' )
                {
                    pf=pop();
                    pst[k++]=pf;
                }
                else
                    break;
            }push(ch);
            break;
        case '*':
            while(ct) // stack not empty
            {
                if(stk[ct]=='*' || stk[ct]=='/' )
                {
                    pf=pop();
                    pst[k++]=pf;
                }
                else
                    break;
            }push(ch);
            break;
        case '/':
            while(ct) // stack not empty
            {
                if(stk[ct]=='*' || stk[ct]=='/' )
                {
                    pf=pop();
                    pst[k++]=pf;
                }
                else
                    break;
            }push(ch);
            break;
        case '(':
            push(ch);
            break;
        case ')':
            if(ct==0)
                return false;
            while(ct!=0) // stack not empty
            {
                if(stk[ct]!='(' ){
                pf=pop();
                pst[k++]=pf;
                if(ct==0)
                    return false;
                }
                else{
                    pf=pop();
                    break;
                }
            }
            break;
        default:
            pst[k++]=ch;
            break;

    }
    }
    while(ct!=0) // stack not empty
    {
        pf=pop();
        if(pf=='(')
            return false;
        pst[k++]=pf;
    }pst[k]='\0';
    return b;
}




/*
a+(b*c)
abc*+

a+(b+c-d+G+k*c*d-345*g+(b-c)*c-d/5)-55-39*a+v
abc+d-G+kc*d*+345g*-bc-c*+d5/-+55-39a*-v+

a+(b+c-d+G+k*c*d-3*g+(b-c)*c-d/5)-5-3*a+v
abc+d-G+kc*d*+3g*-bc-c*+d5/-+5-3a*-v+
((((a+(((((((b+c)-d)+G)+((k*c)*d))-(3*g))+((b-c)*c))-(d/5)))-5)-(3*a))+v)

2+3-(5-2)*6+3/6*5+(9/2+7)
23+52-6*-36/5*+92/7++
*/


