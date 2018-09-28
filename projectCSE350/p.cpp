#include<bits/stdc++.h>
using namespace std;
#define size 16
#define sz 100
int ll,kk=2,win=3,rr=0,fa=0,bf=0,fn=0;
char str[sz],frm[15][size],frm1[15][size];
char data[size],pd[4]={'1','1','0','1'},fcs[3]={'0','0','0'};
void crc();

int main()
{
    int i,j,k,l,m,n,rn;
    time_t t;
    srand((unsigned)time(&t));

    cout<<"Dataset : ";
    for(i=0;i<sz;i++)
    {
        rn=rand()%2;
        if(rn==0)
            str[i]='0';
        else
            str[i]='1';
        cout<<str[i];
    }cout<<endl;

    for(i=0,j=0;i<size && j<sz;i++)
    {
        k=i%4;
        if(k==0)
        {
            frm[i][0]='0';
            frm[i][1]='0';
        }
        else if(k==1)
        {
            frm[i][0]='0';
            frm[i][1]='1';
        }
        else if(k==2)
        {
            frm[i][0]='1';
            frm[i][1]='0';
        }
        else
        {
            frm[i][0]='1';
            frm[i][1]='1';
        }
        for(ll=2;j<sz && ll<13;ll++,j++)
        {
            frm[i][ll]=str[j];
            data[ll]=str[j];
        }
        for(l=ll;l<ll+3;l++)
        {
            data[l]='0';
        }
        crc();
        for(l=ll,m=0;l<ll+3;l++,m++)
        {
            frm[i][l]=fcs[m];
        }
        cout<<"Frame "<<i<<" : ";
        for(l=0;l<ll+3;l++)
            cout<<frm[i][l];

        cout<<endl;
    }
    fn=i;


    for(i=0;i<fn;i++)
    {
        cout<<"Transmit f"<<i<<endl;
        for(m=0;m<size;m++)
        {

            frm1[i][m]=frm[i][m];
        }
        cout<<"Frame upto "<<i<<" is transmitted by transmitter"<<endl;


        rn=rand()%2;
        if(rn==0)
        {
            bf++;
            if(fa==0)
            {
                cout<<"RR0"<<endl;
                cout<<"No frame has been acknowledged by receiver"<<endl;
            }
            else
            {
                rr=(fa+1)%4;
                cout<<"RR"<<rr<<endl;
                cout<<"Frame upto "<<fa<<" is acknowledged by receiver"<<endl;

            }
        }
        else
        {
            fa=i;
            rr=(fa+1)%4;
            cout<<"RR"<<rr<<endl;
            cout<<"Frame upto "<<fa<<" is acknowledged by receiver"<<endl;
        }
        if(bf==win)
        {
            cout<<"RNR"<<endl;
            for(j=0;j<100;j++){
                rn=rand()%2;
            if(rn==1)
            {
                fa=i;
                rr=(fa+1)r%4;
                cout<<"RR"<<rr<<endl;
                bf=0;
                break;
            }
            }
        }





    }








    return 0;
}














void crc()
{
    int i,j,k,l,st,m,n,a,aa,stt,c,z=0,f=0,y,yy,u,v,w;
    char temp[4],temp1[4];
    bool b=false,bb=false,bbb=false;
    int sizes=ll;
    for(i=0;i<sizes;i++)
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
        y=sizes-st;
        for(i=st,j=0;i<sizes && y>=4 && j<4;i++,j++)
        {
           temp[j]=data[i];
        }
        c=i;
        for(m=c;m<=sizes && f==0;)
        {
            for(a=0;a<4;a++)
            {
                if(temp[a]==pd[a])
                    temp1[a]='0';
                else
                    temp1[a]='1';
            }
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
                }
            }
            if(aa<4 && aa>=0)
            {
                while(m<sizes && aa<4)
                {

                    temp[aa]=data[m];
                    aa++;
                    m++;
                }
                if(m==sizes && aa<4)
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










