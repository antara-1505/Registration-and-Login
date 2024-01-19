#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class temp{
    private:
    string userName, Email, password;
    string searchName, searchemail, searchPass;
    fstream file;
    public:
    void login(){
        cout<<"---LOGIN-------\n";
        cout<<"Enter your User name:: ";
        cin>>searchName;
        cout<<"Enter your password :: ";
        cin>>searchPass;

        file.open("loginData.txt", ios::in);
        if (file.is_open()) {  // Check if file opened successfully
            bool found = false;  // Flag to track if a match is found

            while (!file.eof()) {  // Loop until end-of-file
                getline(file, userName);
                getline(file, Email);
                getline(file, password);

                if (userName == searchName && password == searchPass) {
                    cout << "\nAccount logged in!\n";
                    cout << "Username ::" << userName << endl;
                    cout << "Email ::" << Email << endl;
                    found = true;  // Set flag to indicate match found
                    break;         // Exit the loop as match found
                }
            }

            if (!found) {  // If no match found, print error message
                cout << "Invalid username or password" << endl;
            }

            file.close();  // Close the file
        } 
        else {
            cout << "Error opening file!" << endl;
        }
    }
    void signup();
    void forgotpassword();
 };

int main(){
    char choice;
    cout<<"\n 1. Login\n";
    cout<<"\n 2. Sign-up\n";
    cout<<"\n 3. forgot password\n";
    cout<<"\n 4. Exit\n";
    cout<<"\n Enter your choice::";
    temp obj;
    cin>>choice;
    switch(choice){
        case '1' :
            obj.login();
        break;

        case '2' :
            obj.signup();
        break;

        case '3' :
            obj.forgotpassword();
        break;

        case '4' :
            return 0;
        break;

        default:
        cout<<"enter a valid choice!";
    }

    return 0;
}
void temp :: signup(){
    cout<<"\nEnter Your Username::";
    // getline(cin,userName);
    cin>>userName;
    cout<<"\nEnter your email address ::";
    // getline(cin,Email);
    cin>>Email;
    cout<<"\n Enter your password ::";
    // getline(cin,password);
    cin>>password;

    file.open("loginData.txt",ios :: out | ios :: app); 
    file<<userName<<"\n"<<Email<<"\n"<<password<<endl;
    file.close();

}

void temp:: forgotpassword(){
    //string
    cout<<"\n Enter your username :: ";
    getline(cin, searchName);
    cout<<"\n Enter email id ::";
    getline(cin,searchemail);

    file.open("loginData.txt",ios :: in);
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');

    while(!file.eof()){
        if (userName==searchemail){
            if(Email==searchemail){
                cout<<"\n Account found....!"<<endl;
                cout<<"Your Paqssword is ::"<<password<<endl;
            }
            else{
                cout<<"Account not found!"<<endl; 
            }
        }else{
            cout<<"account not found!"<<endl;
        }
    }
    file.close();
}