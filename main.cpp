#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    int rollno;
    string name;
    int age;
    double marks;
};

int main(){
    while(true){
        cout<<"====== Student Management System ======\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display all Students\n";
        cout<<"3. Search Student by Roll Number\n";
        cout<<"4. Update Student\n";
        cout<<"5. Delete Student\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice == 6){
            cout<<"Exiting...\n";
            break;
        } else {
            cout<<"Feature not implemented yet.\n";
        }
    }
    return 0;
}