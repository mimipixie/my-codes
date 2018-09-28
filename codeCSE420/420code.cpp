#include<bits/stdc++.h>
using namespace std;
#define PI 3.1416

double x1,x2,y11,y22,z1,z2,x,y,z,angle,a,b,c,bb,vv,phi1,phi2,pp[4],xr,yr,zr,rr;
double t1[4][4],t2[4][4],a1[4][4],a2[4][4],a11[4][4],a22[4][4],ry[4][4],out[4][4],res[4][4];

void setvar(){

    a=x2-x1;
    b=y22-y11;
    c=z2-z1;
    bb=sqrt(a*a+b*b);
    vv=sqrt(a*a+b*b+c*c);
    phi1=acos(b/bb);
    phi2=acos(bb/vv);
    pp[0]=x;
    pp[1]=y;
    pp[2]=z;
    pp[3]=1;


    if(bb==0 || vv==0){
        cout<<"sorry please try again\n";
        exit(0);
    }

//    cout<<endl;
//    cout<<bb<<" "<<vv<<" "<<phi1<<" "<<phi2<<endl;

}

void print(double *p){
    int i,j,k;

    cout<<"mat  :\n";
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%.2lf ",*(p+4*i+j));
        cout<<"\n";
    }

}
void setmat(double *p){
    int i,j,k;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            *(p+4*i+j)=0.0;

}

void setout(double *p){
    int i,j,k;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(i==j)
                *(p+4*i+j)=1.0;
}

void setT(double *p,double dx,double dy,double dz){
    *(p+4*0+3)+=dx;
    *(p+4*1+3)+=dy;
    *(p+4*2+3)+=dz;
}

void setRx(double *p,double ang){
    *(p+4*1+1)=cos(ang);
    *(p+4*1+2)=-sin(ang);
    *(p+4*2+2)=cos(ang);
    *(p+4*2+1)=sin(ang);
}
void setRz(double *p,double ang){
    *(p+4*1+1)=cos(ang);
    *(p+4*0+1)=-sin(ang);
    *(p+4*0+0)=cos(ang);
    *(p+4*1+0)=sin(ang);
}
void setRy(double *p,double ang){
    *(p+4*0+0)=cos(ang* PI / 180.0);
    *(p+4*0+2)=sin(ang* PI / 180.0);
    *(p+4*2+2)=cos(ang* PI / 180.0);
    *(p+4*2+0)=-sin(ang* PI / 180.0);
}

void mul(double *p){
    double *q,*r;
    q=out[0];
    r=res[0];
    setmat(r);

    int i,j,k;


    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                *(r+4*i+j)+=  (*(q+4*i+k)) * (*(p+4*k+j));
            }
        }
    }

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            out[i][j]=*(r+4*i+j);

//    printf("\n\n");
//    print(out[0]);
//    printf("\n\n");

}

void point(){

    double *p,*q,*r;
    q=out[0];
    r=res[0];
    p=pp;
    setmat(r);

    int i,j,k;

/*
    cout<<"mat Res before :\n";
    for(i=0;i<4;i++)
    {
        cout<<*(p+i)<<"\t";
        cout<<"\n";
    }
*/

    for(i=0;i<4;i++){
        for(k=0;k<4;k++)
        {
            *(r+4*i+0)+=  (*(q+4*i+k)) * (*(p+k));
        }
    }

    for(i=0;i<4;i++)
            pp[i]=*(r+4*i+0);



    cout<<"\n\nmat Res :\n";
    print(out[0]);

    cout<<"\n\nmat point :\n";
    for(i=0;i<4;i++)
    {
        printf("%.2lf ",*(p+i));
        cout<<"\n";
    }

    xr=pp[0];
    yr=pp[1];
    zr=pp[2];
    rr=pp[3];

    cout<<"\n\n\n\nmat point (x , y , z)  :\n\n";
    printf("%.2lf %.2lf %.2lf \n\n",xr/rr,yr/rr,zr/rr);


}

int main(){

    int i,j,k;
    double *p;

    cin>>x>>y>>z;
    cin>>x1>>y11>>z1>>x2>>y22>>z2;
    cin>>angle;

    setvar();

    p=out[0];
    setmat(p);
    setout(p);

    p=t1[0];
    setmat(p);
    setout(p);
    setT(p,-x1,-y11,-z1);

    p=t2[0];
    setmat(p);
    setout(p);
    setT(p,x1,y11,z1);

    p=a1[0];
    setmat(p);
    setout(p);
    setRz(p,phi1);

    p=a11[0];
    setmat(p);
    setout(p);
    setRx(p,-phi2);

    p=a22[0];
    setmat(p);
    setout(p);
    setRx(p,phi2);

    p=a2[0];
    setmat(p);
    setout(p);
    setRz(p,-phi1);

    p=ry[0];
    setmat(p);
    setout(p);
    setRy(p,angle);

    mul(t2[0]);
    mul(a2[0]);
    mul(a22[0]);
    mul(ry[0]);
    mul(a11[0]);
    mul(a1[0]);
    mul(t1[0]);

    print(t2[0]);
    print(a2[0]);
    print(a22[0]);
    print(ry[0]);
    print(a11[0]);
    print(a1[0]);
    print(t1[0]);

    print(out[0]);

    point();


return 0;
}
