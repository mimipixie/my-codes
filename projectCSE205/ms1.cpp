#include<stdio.h>
#include<iostream>>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
    int state,i=0,j,k,s,p;
    double balance=0.0,add=0.0,profit=0.05,a;
    for(;;){
    cout<<"-----------------------------------------------------------\n";
    cout<<"Enter 1 to show incoming messages\n";
    cout<<"Enter 2 to show outgoing messages\n";
    cout<<"Enter 3 to check balance\n";
    cout<<"Enter 0 to exit\n";
    cout<<"-----------------------------------------------------------\n";
    cin>>s;
    switch(s)
    {
        case 1:
        cout<<"Total number of money receive message: ";cin>>k;
        cout<<"Given amounts: \n";
        for(p=0;p<k;p++){cin>>a;add+=a;}
        break;
        case 2:cout<<"Total number of money deduction message: ";cin>>k;
        cout<<"Given amounts: \n";
        for(p=0;p<k;p++){cin>>a;add-=a;}
        break;
        case 3:balance+=add;
        add=0.0;
        if(balance<50000)
        {
            j=0;profit=0.05;
        }
        else if(balance<100000)
        {
            j=1;profit=0.08;
        }
        else
        {
            j=2;profit=0.11;
        }
        cout<<"************************************************************\n";
        printf("State change from %d to %d\n",i,j);
        printf("Account balance=%lf\n",balance);
        cout<<"************************************************************\n";
        i=j;
        break;
        case 0: exit(0);
        default:cout<<"Try again\n";
    }
}

    return 0;
}

