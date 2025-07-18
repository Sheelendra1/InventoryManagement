#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// this function add records to the file student.txt
void addRecord() {
    string name, section;
    int rollNo;
    float marks;
    

    // taking input all the data
    cout << "Enter Student Name: ";
    cin.ignore(); //clear the input buffer
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Marks: ";
    cin >> marks;
    cout << "Enter Section: ";
    cin >> section;
    
    ofstream file("students.txt", ios::app);// if file students.txt exist it will write in that if file not present it will create new and ios::app means no previous data will be deleted new data will be append at the end
    if (file.is_open()) {
        file << name << "," << rollNo << "," << marks << "," << section << endl;
        file.close();
        cout << "Data added successfully"<<endl;
    } else {
        cout << "Error opening file"<<endl;
    }
}

void DisplayRecords(){
    string line;
    
    ifstream file("students.txt");
    if (file.is_open()){
        cout<<"Students Records: "<<endl;
        int count=1;
        while(getline(file, line)){
            string name, section;
            int rollno;
            float marks;

            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            size_t pos3 = line.find(",", pos2 + 1);
            name = line.substr(0, pos1);
            rollno = stoi(line.substr(pos1 + 1, pos2));
            marks = stof(line.substr(pos2 + 1, pos3));
            section = line.substr(pos3 + 1);
            cout<<"Student: "<<count<<endl;
            cout<<"-------------------"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll No.: "<<rollno<<endl;
            cout<<"Marks: "<<marks<<endl;
            cout<<"Section: "<<section<<endl;

            count++;
        }
        file.close();
    }
    else{
        cout<<"error on opening file"<<endl;
    }
}

int main() {
    int choice;
    
    while(1){
    cout << "Student Record Management System"<<endl;
    cout << "1. Add Record"<<endl;
    cout << "2. Display Records"<<endl;
    cout << "3. Exit"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            DisplayRecords();
        case 3:
            cout << "Exiting program..."<<endl;
            return 0;
        default:
            cout << "Invalid choice! Try again."<<endl;
    }
}
    
    return 0;
}