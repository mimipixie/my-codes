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
room r[25]={"c01","c02","c03","c04","c05",
            "b01","b02","b03","b04","b05",
            "b06","b07","b08","b09","b10",
            "b11","b12","b13","b14","b15",
            "b16","b17","b18","b19","b20"};

room temp;
int i,p,c=0;
char type[20];

ofstream w("PatientInfo.txt");
for(i=0;i<25;i++)
    w.write((char *)&r[i],sizeof(r[i]));
w.close();

fstream f("PatientInfo.txt",ios::in|ios::out);
for(i=0;i<20;i++)
{
    cout<<"Enter type of room you prefer : ";
    cin>>type;
    while(f.read((char *)&temp,sizeof(temp)))
    if(temp.check(type)==0)
    {
        temp.admit_patient();
        p=f.tellg();
        p=p-sizeof(temp);
        f.seekp(p,ios::beg);
        f.write((char *)&temp,sizeof(temp));
        c++;
        break;
    }

    cout<<c<<" patient have been admitted\n";
}
f.close();

return 0;
}


