#include<bits/stdc++.h>
using namespace std;
#define size 1000
int A[size][size];
int main()
{
    int n,p[size],q[size],i,j,k,s,t,c,m;
    cout<<"array order : ";
    cin>>m;
    cout<<"Dust position (no.) : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p[i]>>q[i];
    }
    for(k=1,c=0,i=1;i<=m;i++)
    {
        if(k==1)
        for(j=1;j<=m;j++)
        {
            printf("position (%d,%d) :\n",i,j);
            cout<<"sense input"<<endl;
            for(s=1,t=1;s<=n;s++)
            {
                if(i==p[s] && j==q[s])
                {
                    t=0;
                    break;
                }
            }
            if(t==1)
            cout<<"no operation"<<endl;
            else
                cout<<"clean dust"<<endl;
            c++;
            if(c!=m*m)
            cout<<"go to next step"<<endl;
            else
                cout<<"end"<<endl;
            cout<<endl;
            cout<<endl;
            k=0;
        }
        else
        for(j=m;j>=1;j--)
        {
            printf("position (%d,%d) :\n",i,j);
            cout<<"sense input"<<endl;
            for(s=1,t=1;s<=n;s++)
            {
                if(i==p[s] && j==q[s])
                {
                    t=0;
                    break;
                }
            }
            if(t)
            cout<<"no operation"<<endl;
            else
                cout<<"clean dust"<<endl;
            c++;
            if(c!=m*m)
            cout<<"go to next step"<<endl;
            else
                cout<<"end"<<endl;
            cout<<endl;
            k=1;
        }
    }

    return 0;
}
