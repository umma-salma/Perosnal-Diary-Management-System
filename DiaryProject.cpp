#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;
enum Size {MAX1=6,MAX2=30,Max3=20,MAX4=12,MAX5=500};
class Personaldiary
{
protected:
    char time[MAX1];
    char name[MAX2];
    char place[Max3];
    char duration[MAX4];
    char note[MAX5];
    string p;
    string pass;
public:
    Personaldiary()
    {
        time[0]= {0};
        name[0]= {0};
        place[0]= {0};
        duration[0]= {0};
        note[0] = {0};
    }
    virtual void poem()=0;
    virtual void ShowPoem()=0;

    ~Personaldiary()
    { }

};


class owner : public Personaldiary
{
private:
    string date;
public:
    int login();
    int password();
    void editpassword();
    void addrecord();
    void viewrecord();
    void editrecord();
    void deleterecord();
    void poem();
    void ShowPoem();

};

/// start int password() function::
int owner:: password()
{
    string temp;
    char check[15]= {0};
    char ch;
    int i=0,j;

    cout<<"::FOR SECURITY PURPOSE::";
    cout<<"::ONLY THREE TRIALS ARE ALLOWED::";

    for(j=0; j<3; j++)
    {
        cout<<"\n\n\tENTER THE PASSWORD:";
        cin>>temp;
        if(pass==temp)
        {
            cout<<"\n\n\tACCESS GRANTED...\n";
            return 0;
        }
        else
        {
            cout<<"\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n";
        }
    }
    cout<<"\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...";
    getch();
    return 1;

}
///end int password function


void owner::poem()
{
    cout<< "\n\t\t\t\t    Write A Poem(stop press #)::";
    getline (cin, p,'#');
}



void owner::ShowPoem()
{
    cout<<"\n\t\t\t\t   My Poem :: ";
    cout<<"\n\t\t\t\t   ::"<<p<<endl;
    getchar();
}




/// start login() function::
int owner:: login()
{
    char ch;

    cout << "\n\t\t\t\t    PERSONAL   DIARY   MANAGEMENT";
    cout << "\n\n\t\t\t\t\tEnter Password:";
    ch = _getch();
    while(ch !=13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if(pass == "pass")
    {
        cout << "\n\n\nAccess Granted \n";
        system("PAUSE");
        system("CLS");
    }

    else
    {
        cout << "\nAccess Aborted...\n";
        system("CLS");
        login();
    }
}
/// end login() funtion




/// start void addrecord function::
void owner::addrecord()
{
    system("cls");
    char ch;
    do
    {
        cout<<"\n\n\t\t***************************\n";
        cout<<"\t\t* WELCOME TO THE MENU *";
        cout<<"\n\t\t***************************\n\n";
        cout<<"\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:";
        cin>>date;
        cout<< "\n\tENTER TIME:[hh:mm]:";
        cin>>time;
        cout<<"\tENTER NAME:";
        cin>>name;
        cout<<"\tENTER PLACE:";
        cin>>place;
        cout<<"\tENTER DURATION:";
        cin>>duration;
        cout<<"\n\tEXPLAIN THE INCIDENT :";
        cin>>note;
        cout<<"\nYOUR RECORD IS ADDED...\n";
        cout<<"\n\tADD ANOTHER STORY...(Y/N) "  ;
        cin>>ch;
        getchar();
    }
    while(ch=='n');
    cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
    return ;
}
/// end void addrecord function



/// start void veiwrcord() function::
void owner::viewrecord( )
{
    fstream file;
    file.open("diary.dat",ios::in|ios::out|ios::binary|ios::app);
    system("cls");
    string CurrentDate;
    char ch;
    int choice;
seeAgain:
    cout<<"\n\n\t\t*******************************\n";
    cout<<"\t\t* HERE IS THE VIEWING MENU *";
    cout<<"\n\t\t*******************************\n\n";

    choice=password();

    if(choice!=0)
    {
        return ;
    }
    system("cls");
    cout<<"\n\tHOW WOULD YOU LIKE TO VIEW:\n";
    cout<<"\n\t1.WHOLE STORY OF THE DAY.";
    cout<<"\n\t2.STORY OF FIX TIME.";
    cout<<"\n\t\tENTER YOUR CHOICE:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:";
        cin>>CurrentDate;
        cout<<"\n THE CURRENT DATE IS:"<<CurrentDate;
        cout<<"\nTHE WHOLE STORY FOR IS:"<<date;
        cout<<"\n";
        cout<<"\nTIME:"<<time;
        cout<<"\nMEETING WITH:"<<name;
        cout<<"\nMEETING AT:"<<place;
        cout<<"\nDURATION:"<<duration;
        cout<<"\nNOTE:"<<note;
        cout<<"\n";
        break;
    case 2:
        cout<<"\nENTER TIME:[hh:mm]:";
        cin>>time;
        cout<<"\nYOUR RECORD IS:";
        cout<<"\nTIME:"<<time;
        cout<<"\nMEETING WITH:"<<name;
        cout<<"\nMEETING AT:"<<place;
        cout<<"\nDUARATION:"<<duration;
        cout<<"\nNOTE:"<<note;
        break;
    default:
        cout<<"\nYOU TYPED SOMETHING ELSE...\n";
        break;
    }
    cout<<"\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):";
    cin>>ch;
    if(ch=='y'||ch=='Y')
        goto seeAgain;
    else
        return;

}

/// end viewrecord function

/// start editrecord::
void owner:: editrecord()
{
    system("cls");
    char time[6];
    char ch;
    int choice;
    int num,count=0;
    fstream file;
again:
    cout<<"\n\n\t\t*******************************\n";
    cout<<"\t\t* WELCOME TO THE EDITING MENU *";
    cout<<"\n\t\t*******************************\n\n";
    choice=password();
    if(choice!=0)
    {
        return ;
    }
    cout<<"\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:";
    cin>>date;
    cout<<"\n Current Date:"<<date;
    cout<<"\nYOUR OLD RECORD WAS AS:";
    cout<<"\nTIME: "<<time;
    cout<<"\nMEETING WITH:"<<name;
    cout<<"\nMEETING AT:"  <<place;
    cout<<"\nDURATION: "  <<duration;
    cout<<"\nNOTE:" <<note;
    cout<<"\n----------------------------------------------"<<endl;
    cout<<"\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..";
    cout<<"\n1.TIME.";
    cout<<"\n2.MEETING PERSON.";
    cout<<"\n3.MEETING PLACE.";
    cout<<"\n4.DURATION.";
    cout<<"\n5.NOTE.";
    cout<<"\n6.WHOLE RECORD.";
    cout<<"\n7.GO BACK TO MAIN MENU.";
    cout<<"\n\tENTER YOUR CHOICE:";
    cin>>num;
    switch(num)
    {
    case 1:
        cout<<"\nENTER THE NEW DATA:";
        cout<<"\nNEW TIME:[hh:mm]:";
        cin>>time;
        break;
    case 2:
        cout<<"\nENTER THE NEW DATA:";
        cout<<"\nNEW MEETING PERSON:";
        cin>>name;
        break;
    case 3:
        cout<<"\nENTER THE NEW DATA:";
        cout<<"\nNEW MEETING PLACE:";
        cin>>place;
        break;
    case 4:
        cout<<"\nENTER THE NEW DATA:";
        cout<<"\nDURATION:";
        cin>>duration;
        break;
    case 5:
        cout<<"ENTER THE NEW DATA:";
        cout<<"\nNOTE:";
        cin>>note;
        break;
    case 6:
        cout<<"\nENTER THE NEW DATA:";
        cout<<"\nNEW TIME:[hh:mm]:";
        cin>>time;
        cout<<"\nNEW MEETING PERSON:";
        cin>>name;
        cout<<"\nNEW MEETING PLACE:";
        cin>>place;
        cout<<"\nDURATION:";
        cin>>duration;
        cout<<"\nNOTE:";
        cin>>note;
        break;
    case 7:
        cout<<"\nPRESS ANY KEY TO GO BACK...\n";
        getch();
        return ;
        break;
    default:
        cout<<"\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n";
        break;
    }
    choice=9;
    if(choice==9)
    {
        system("cls");
        cout<<"\n\t\tEDITING COMPLETED...\n";
        cout<<"--------------------\n";
        cout<<"THE NEW RECORD IS:\n";
        cout<<"--------------------\n";
        cout<<"\nTIME:"<<time;
        cout<<"\nMEETING WITH:" <<name;
        cout<<"\nMEETING AT:"<<place;
        cout<<"\nDURATION:"<<duration;
        cout<<"\nNOTE:"<<note;
        cout<<"\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)";
        cin>>ch;
        count++;
    }
    else
    {
        cout<<"\nTHE RECORD DOES NOT EXIST::\n";
        cout<<"\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)";
        cin>>ch;
    }
    if(ch=='y'||ch=='Y')
        goto again;
    if(count==1)
        cout<<count<<" FILE IS EDITED...\n";
    else if(count>1)
        cout<<count<<" FILES ARE EDITED..\n";
    else
        cout<<"\nNO FILES EDITED...\n";
    cout<<"\tPRESS ENTER TO EXIT EDITING MENU.";
    getch();
}
/// end edit record




void owner:: deleterecord( )
{
    system("cls");
    char filename[15];
    char another = 'Y';
    char time1[10];
    int choice,check;
    string date1;
    fstream file;
    file.open("diary.dat",ios::in|ios::out|ios::binary|ios::app);
    cout<<"\n\n\t\t*************************\n";
    cout<<"\t\t* WELCOME TO DELETE MENU*";
    cout<<"\n\t\t*************************\n\n";
    check = password();
    if(check==1)
    {
        return ;
    }
    while ( another == 'Y' )
    {
        cout<<"\n\n\tHOW WOULD YOU LIKE TO DELETE.";
        cout<<"\n\n\t#DELETE WHOLE RECORD\t\t\t[1]";
        cout<<"\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]";
        do
        {
            cout<<"\n\t\tENTER YOU CHOICE:";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:";
                cin>>date1;
                if(date1==date)
                {
                    time[0]= {0};
                    name[0]= {0};
                    place[0]= {0};
                    duration[0]= {0};
                    note[0] = {0};
                    remove("diary.dat");
                    cout<<"\nDELETED SUCCESFULLY...";
                }
                else
                {
                    cout<<"\n Your Entered Date is not matched";
                    cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
                    getch();
                    return ;
                }
                break;
            case 2:
                cout<<"\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:";
                cin>>time;
                if(time1==time)
                {
                    time[0]= {0};
                    name[0]= {0};
                    place[0]= {0};
                    duration[0]= {0};
                    note[0] = {0};
                    remove("diary.dat");
                    cout<<"\nDELETED SUCCESFULLY...";
                }
                else
                {
                    cout<<"\n Your Entered Date is not matched";
                    cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
                    getch();
                    return ;
                }

                break;
            default:
                cout<<"\n\tYOU ENTERED WRONG CHOICE";
                break;
            }
        }
        while(choice<1||choice>2);
        cout<<"\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):";
        cin>>another;
    }
    cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
}

/// start editpassword function::
void owner:: editpassword()
{
    system("cls");
    cout<<"\n";
    string confirm;
    char ch='a';
again:
    cout<<"\n\n\tENTER THE NEW PASSWORD:";
    cin>>pass;
    cout<<"\n\tCONFIRM PASSWORD:";
    cin>>confirm;
    getchar();
    if(confirm==pass)
    {
        cout<<"\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...";
        getchar();
        return ;
    }
    else
    {
        cout<<"\n\tTHE NEW PASSWORD DOES NOT MATCH.";
        goto again;
    }
}
/// end editpassword function

///main() Function::
int main()
{
    fstream file;
    file.open("diary.dat",ios::in|ios::out|ios::app|ios::binary);
    owner ow1;
    ow1.login();
    int ch;
    cout<<"\n\n\t\t\t\t***********************************\n";
    cout<<"\t\t\t\t  *PERSONAL DIARY MANAGEMENT SYSTEM*\n";
    cout<<"\t\t\t\t***********************************";
    while(1)
    {
x:
        cout<<"\n\n\t\t\t\tMAIN MENU:";
        cout<<"\n\n\t\t\tADD STORY\t\t--[1]";
        cout<<"\n\t\t\tVIEW STORY\t\t--[2]";
        cout<<"\n\t\t\tEDIT STORY\t\t--[3]";
        cout<<"\n\t\t\tDELETE STORY\t\t--[4]";
        cout<<"\n\t\t\tEDIT PASSWORD\t\t--[5]";
        cout<<"\n\t\t\tWRITE POEM\t\t--[6]";
        cout<<"\n\t\t\tSHOW POEM\t\t--[7]";
        cout<<"\n\t\t\tEXIT\t\t\t--[8]";
        cout<<"\n\n\tENTER YOUR CHOICE:";
        cin>>ch;
        file.seekg(0, ios::end);
        switch(ch)
        {
        case 1:
            file.write(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.addrecord();
            break;
        case 2:
            file.read(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.viewrecord();
            break;
        case 3:
            file.write(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.editrecord();
            break;
        case 4:
            file.read(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.deleterecord();
            break;
        case 5:
            file.write(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.editpassword();
            break;
        case 6:
            file.write(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.poem();
            break;
        case 7:
            file.read(reinterpret_cast<char*>(&ow1),sizeof(ow1));
            ow1.ShowPoem();
            goto x;
        case 8:
            cout<<"\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ";
            getch();
            exit(0);
        default:
            cout<<"\nYOU ENTERED WRONG CHOICE..";
            cout<<"\nPRESS ANY KEY TO TRY AGAIN";
            getch();
            break;
        }
        system("cls");
    }
    return 0;
}
///end main() function

