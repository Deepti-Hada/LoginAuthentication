#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class temp{
    string Name, Email, password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void Register();
    void passrecover();
}obj;


int main(){
    char select;
    int choose;
    cout<<"\t-------------------Welcome To Our Page--------------------\t\n";
    cout<<"1 : Login\n";
    cout<<"2 : Register\n";
    cout<<"3 : Forgot Password\n";
    cout<<"4 : EXIT\n";
    cout<<"Enter your Choice:";
    cin>>select;
    cout<<"\n";

    switch(select){
        case '1':
        obj.login();
        break;
        case '2':
         obj.Register();
        break;
        case '3':
        obj.passrecover();
        break;
        case '4':
        cout<<"Are you sure you want to Exit"<<endl;
        cout<<"1. YES"<<endl;
        cout<<"1. NO"<<endl;
        cout<<"Enter one option mention above: "<<endl;
        cin>>choose;
        switch(choose){
            case 1:
            cout<<"You made your Exit."<<endl;
            break;
            case 2:
            cout<<"Thanks for you continuity."<<endl;
            main();
            break;
        }
        break;
        default:
        cout<<"You have made some mistake, Kindly choose correct option\n";
    }
}

void temp :: Register(){
    cout<<"-----------Signup/Register-----------\n";
    cout<<"Enter your name :";
    cin>>Name;
    cout<<"Enter your Email :";
    cin>>Email;
    cout<<"Enter your password :";
    cin>>password;

    file.open("userData.txt",ios :: out | ios :: app);
    file<<Name<<' '<<Email<<' '<<password<<endl;
    file.close();
    cout<<"Your Registeration has been successfully done!\n";
    main();
}

void temp :: login(){
    cout<<"-----------Login-----------\n";
    cout<<"Enter your User name :";
    cin>>searchName;
    cout<<"Enter your password :";
    cin>>searchPass;

   file.open("userData.txt",ios :: in);
    getline(file,Name,' ');
    getline(file,Email,' ');
    getline(file,password,'\n');
    while(!file.eof()){
        if(Name == searchName){
            if(password == searchPass){
                cout<<searchName<<" You have Logged in Successfully !!"<<endl;
                main();
            }
            else{
                cout<<"Password Is Incorrect,Please Enter Correct Password\n"<<endl;
                login();
            }
        }
    getline(file,Name,' ');
    getline(file,Email,' ');
    getline(file,password,'\n');
    }
    
  file.close()  ;
}


void temp :: passrecover(){
   cout<<"Enter your userName:" ;
   cin>>searchName;
   cout<<"Enter your Email:" ;
   cin>>searchEmail;

   file.open("userData.txt",ios :: in);
   getline(file,Name,' ');
   getline(file,Email,' ');
   getline(file,password,'\n');
   while(!file.eof()){
    if(Name == searchName && Email == searchEmail){
         cout<<"Account found !!\n";
         cout<<"Password is:"<<password<<endl;
         main();
    }
    else{
            cout<<"Account Not Found\n";
            main();
        }
   getline(file,Name,' ');
   getline(file,Email,' ');
   getline(file,password,'\n');
   }

   file.close();
}
