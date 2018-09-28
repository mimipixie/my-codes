#include<bits/stdc++.h>
using namespace std;
#define size 9
char data[size],pd[4]={'1','1','0','1'},fcs[3]={'0','0','0'};
void crc();

int main()
{
    int i,j,k,rn;
    time_t t;
    srand((unsigned)time(&t));
    cout<<"Dataset : ";
    for(i=0;i<size-3;i++)
    {
        rn=rand()%2;
        if(rn==0)
            data[i]='0';
        else
            data[i]='1';
        cout<<data[i];
    }cout<<endl;
    while(i<size)
    {
        data[i]='0';
        i++;
    }
    crc();
    cout<<"FCS = ";
    for(k=0;k<3;k++)
        cout<<fcs[k];
    cout<<endl;



    return 0;
}

void crc()
{
    int i,j,k,l,st,m,n,a,aa,stt,c,z=0,f=0,y,yy,u,v,w;
    char temp[4],temp1[4];
    bool b=false,bb=false,bbb=false;
    for(i=0;i<size;i++)
    {
        if(b==false)
        {
            if(data[i]=='1')
            {
                st=i;
                b=true;
            }
        }
        else break;
    }
    if(b==true)
    {
        y=size-st;
        for(i=st,j=0;i<size && y>=4 && j<4;i++,j++)
        {
           temp[j]=data[i];
cout<<temp[j];
        }
cout<<endl;
        c=i;
        for(m=c;m<=size && f==0;)
        {
            for(a=0;a<4;a++)
            {
                if(temp[a]==pd[a])
                    temp1[a]='0';
                else
                    temp1[a]='1';
cout<<temp1[a];
            }
cout<<endl;
            bb=false;
            stt=3;
            for(a=0;a<4;a++)
            {
                if(bb==false)
                {
                    if(temp1[a]=='1')
                    {
                        stt=a;
                        bb=true;
                        break;
                    }
                }
            }
            aa=0;
            if(bb==true)
            {
                for(a=stt,aa=0;a<4;a++,aa++)
                {
                    temp[aa]=temp1[a];
cout<<temp[aa];
                }
cout<<endl;
            }
            if(aa<4 && aa>=0)
            {
                while(m<size && aa<4)
                {

                    temp[aa]=data[m];
cout<<temp[aa];
                    aa++;
                    m++;
                }
cout<<endl;
                if(m==size && aa<4)
                {
                    for(u=aa-1,v=2,w=stt-1;v>=0;v--,u--)
                    {
                        if(u>=0)
                        {
                            fcs[v]=temp[u];
                        }
                        else
                        {
                            fcs[v]=temp1[w];
                            w--;
                        }
                    }
                    f=1;
                }
            }
        }
        for(a=0;a<3 && f==0;a++)
        {
            fcs[a]=temp1[a+1];
        }

    }
    else
    {
        fcs[0]='0';
        fcs[1]='0';
        fcs[2]='0';
    }

}


