#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;

class patient{
    char name[20],serial_no[20],sex[20],
         address[20],contact_no[20];
    int age,d1,m1,y1,d2,m2,y2;
public:
    patient()
    {
        strcpy(serial_no,"");
        strcpy(name,"");
        age=0;d1=0;m1=0;y1=0;d2=0;m2=0;y2=0;
        strcpy(sex,"");
        strcpy(address,"");
        strcpy(contact_no,"");
    }
    void in()
    {
        cout<<"\n----------------------------------------\n"
            <<"Enter info of patient :"
            <<"\n----------------------------------------\n"
            <<"Serial No         : ";cin>>serial_no;
        cout<<"Name              : ";cin>>name;
        cout<<"Age               : ";cin>>age;
        cout<<"Sex               : ";cin>>sex;
        cout<<"Address           : ";cin>>address;
        cout<<"Contact No        : ";cin>>contact_no;
        cout<<"Format of Date (dd mm yyyy)\n";
        cout<<"Date of Admit     : ";cin>>d1>>m1>>y1;
        cout<<"Date of Discharge : ";cin>>d2>>m2>>y2;
        cout<<"\n----------------------------------------\n";
    }
    void out()
    {
        cout<<"\n----------------------------------------\n"
            <<"\n          Serial No "<<serial_no
            <<"\n----------------------------------------\n"
            <<"\nName              : "<<name
            <<"\nAge               : "<<age
            <<"\nSex               : "<<sex
            <<"\nAddress           : "<<address
            <<"\nContact No        : "<<contact_no
            <<"\nDate of Admit     : "<<d1<<"/"<<m1<<"/"<<y1
            <<"\nDate of Discharge : "<<d2<<"/"<<m2<<"/"<<y2
            <<"\n----------------------------------------\n";
    }
    void re_initialize()
    {
        strcpy(serial_no,"");
        strcpy(name,"");
        age=0;d1=0;m1=0;y1=0;d2=0;m2=0;y2=0;
        strcpy(sex,"");
        strcpy(address,"");
        strcpy(contact_no,"");
    }
    int check_name(char * A)
    {
        if(strcmp(name,A)==0)
            return 0;
        else
            return 1;
    }
    int get_days()
    {
        int days,y=y2-y1;
        days=y*365+m2*30+d2-m1*30-d1+1;
        return days;
    }
};

class room:public patient{
    char room_type[20],seat_no[20],booking[20];
    int rent,medicine,treatment,expenses,bill;
public:
    room()
    {
        strcpy(seat_no,"");
        strcpy(room_type,"");
        strcpy(booking,"");
        rent=0;
        medicine=0;
        treatment=0;
        expenses=0;
        bill=0;
    }
    room(char *no)
    {
        strcpy(seat_no,no);
        if(seat_no[0]=='c')
        {
            strcpy(room_type,"Cabin");
            rent=600;
        }
        else
        {
            strcpy(room_type,"Ward");
            rent=50;
        }
        strcpy(booking,"Not booked");
        medicine=0;
        treatment=0;
        expenses=0;
        bill=0;
    }
    void out()
    {
        patient::out();
        cout<<"\n--------------------------------------\n";
        cout<<"\nRoom Type          : "<<room_type;
        cout<<"\nSeat N0            : "<<seat_no;
        cout<<"\nRoom rent per day  : "<<rent;
        cout<<"\nMedicine           : "<<medicine;
        cout<<"\nTreatment          : "<<treatment;
        cout<<"\nOther Expenses     : "<<expenses;
        cout<<"\nTotal Bill         : "<<bill;
        cout<<"\n--------------------------------------\n";
    }
    int check_booking()
    {
        if(strcmp(booking,"Not booked")==0)
            return 0;
        else
            return 1;
    }
    int check(char *type)
    {
        if(strcmp(room_type,type)==0 && strcmp(booking,"Not booked")==0)
            return 0;
        else
            return 1;
    }
    void admit_patient()
    {
        patient::in();
        strcpy(booking,"Booked");
        out();
    }
    void discharge()
    {
        out();
        re_initialize();
        medicine=0;
        treatment=0;
        expenses=0;
        bill=0;
        strcpy(booking,"Not booked");
    }
    void update()
    {
        int s;
        char b;
        int add;
        cout<<"Enter 1 to update info of patient\n"
            <<"Enter 2 to add bill\n";
        cin>>s;
        switch(s)
        {
            case 1:
                patient::in();
                break;
            case 2:
                cout<<"Enter 'm' to add bill for medicine\n"
                    <<"Enter 't' to add bill for treatment\n"
                    <<"Enter 'e' to add bill for expenses\n";
                cin>>b;
                cout<<"Enter amount of bill : ";
                cin>>add;
                switch(b)
                {
                    case 'm': medicine+=add;
                        break;
                    case 't': treatment+=add;
                        break;
                    case 'e': expenses+=add;
                        break;
                }
                break;
        }
    }
    void total_bill()
    {
        int days= get_days();
        bill=rent*days+medicine+treatment+expenses;
    }
};




int main()
{
room r;
fstream f("PatientInfo.txt",ios::in|ios::out);
int i,c,s,n,p;
char type[20],A[20];

while(true)
{
cout<<"Enter 1 to admit a patient\n";
cout<<"Enter 2 to discharge a patient\n";
cout<<"Enter 3 to display a patient's information\n";
cout<<"Enter 4 to update a patient's information\n";
cout<<"Enter 0 to exit\n";
cin>>s;
switch(s)
{
case 1:
    n=0;
    f.seekg(0,ios::beg);
    while( f.read((char *)&r,sizeof(r)) )
    {
        if( r.check_booking() == 0 )
        {
            n=1;
            break;
        }
    }
    if( n==0 )
    {
        cout<<"No room is available!\n";
        goto failed;
    }
    cout<<"Please enter type of room preference(Cabin or Ward):\n";
    cin>>type;
    if(strcmp(type,"Cabin")==0)
    {
        n=0;
        f.seekg(0,ios::beg);
        while( f.read((char *)&r,sizeof(r)) )
        {
            if( r.check(type) == 0 )
            {
                n=1;
                break;
            }
        }
        if( n==0 )
        {
            cout<<"No cabin available!\n";
            n=0;
            f.seekg(0,ios::beg);
            while( f.read((char *)&r,sizeof(r)) )
            {
                strcpy(type,"Ward");
                if( r.check(type) == 0 )
                {
                    n=1;
                    break;
                }
            }
            if( n==1 )
            {
                cout<<"Would you like to take a seat in ward?\n";
                cout<<"If yes, enter 'Ward' , otherwise enter 'No' :\n";
                cin>>type;
                if(strcmp(type,"No")==0)
                    goto failed;
            }
        }
    }
    else if(strcmp(type,"Ward")==0)
    {
        n=0;
        f.seekg(0,ios::beg);
        while( f.read((char *)&r,sizeof(r)) )
        {
            if( r.check(type) == 0 )
            {
                n=1;
                break;
            }
        }
        if( n==0 )
        {
            cout<<"No seat available!\n";
            n=0;
            f.seekg(0,ios::beg);
            while( f.read((char *)&r,sizeof(r)) )
            {
                strcpy(type,"Cabin");
                if( r.check(type) == 0 )
                {
                    n=1;
                    break;
                }
            }
            if( n==1 )
            {
                cout<<"Would you like to take a cabin?\n";
                cout<<"If yes, enter 'Cabin' , otherwise enter 'No' :\n";
                cin>>type;
                if(strcmp(type,"No")==0)
                    goto failed;
            }
        }
    }
    else
        goto failed;

    f.seekg(0,ios::beg);
    while(f.read((char *)&r,sizeof(r)))
    if(r.check(type)==0)
    {
        r.admit_patient();
        p=f.tellg();
        p=p-sizeof(r);
        f.seekp(p,ios::beg);
        f.write((char *)&r,sizeof(r));
        break;
    }
    failed:
    break;
case 2:
    cout<<"Please enter patient's name :\n";
    cin>>A;
    c=0;
    f.seekg(0,ios::beg);
    while(f.read((char *)&r,sizeof(r)))
    if(r.check_name(A)==0)
    {
        r.discharge();
        p=f.tellg();
        p=p-sizeof(r);
        f.seekp(p,ios::beg);
        f.write((char *)&r,sizeof(r));
        c=1;
        break;
    }
    if(c==0)
        cout<<"Sorry! Patient not found\n";

    break;
case 3:
    cout<<"Enter patient's name : ";
    cin>>A;
    f.seekg(0,ios::beg);
    c=0;
    while( f.read((char *)&r,sizeof(r)) )
    {
        if( r.check_name(A) == 0 )
            {
                r.out();
                c=1;
            }
    }
    if(c==1)
        cout<<"Sorry! Patient not found\n";

    break;
case 4:
    cout<<"Enter patient name : ";
    cin>>A;
    f.seekg(0,ios::beg);
    c=0;
    while( f.read((char *)&r,sizeof(r)))
    {
        if(r.check_name(A) == 0)
        {
            r.update();
            p=f.tellg();
            p=p-sizeof(r);
            f.seekp(p,ios::beg);
            f.write((char *)&r,sizeof(r));
            c=1;
        }
    }
    if(c==1)
        cout<<"Sorry! Patient not found\n";

    break;
case 0:
    f.close();
    exit(0);
default:
    cout<<"\n\nNo match found! Try again\n\n\n";
    break;
}
}

return 0;
}




