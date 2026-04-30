#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

class book{  //book class
    public:
    string id,title,author;
    bool available;
    book(string i,string t,string a,bool av=true)
    {
    id=i;
    title=t;
    author=a;
    available=av;
    }

    string tostring(){
    return id+","+title+","+author+","+(available?"1":"0");
    }
};
class student{  //student class
public:
string id,name,issuedbooks;
student(string i,string n,string ib=""){
    id=i;
    name=n;
    issuedbooks=ib;
}
string tostring(){
    return id+","+name+","+issuedbooks;
}
};
class library{  //library class
public:
void addbook(){  //add book
string id,title,author;
cout<<"enter book ID:";
cin>>id;
cin.ignore();
cout<<"enter title:";
getline(cin,title);
cout<<"enter author:";
getline(cin,author);
std::ofstream
file("books.txt",std::ios_base::app);
file<<id<<","<<title<<","<<author<<",1\n";
file.close();
cout<<"book added successfully!\n";
}
void viewbooks(){  //view books
ifstream file("books.txt");
string line;
while(getline(file,line)){
    stringstream ss(line);
    string id,title,author,available;
    getline(ss,id,',');
    getline(ss,title,',');
    getline(ss,author,',');
    getline(ss,available,',');
    cout<<id<<"\t|"<<title<<"\t|"<<author<<"\t|"<<
    (available=="1"?"Available":"issued")<<endl;
}
file.close();
}
void addstudent(){  //add student
string id,name;
cout<<"enter student ID:";
cin>>id;
cin.ignore();
cout<<"enter name:";
getline(cin,name);
ofstream file("student.txt",ios::app);
file<<id<<","<<name<<",\n";
file.close();
cout<<"student added successfully!\n";
}
void issuebook(){  //issue books
string bookid,studentid;
cout<<"enter book ID:";
cin>>bookid;
cout<<"enter student ID:";
cin>>studentid;
vector<string>books;
ifstream file("books.txt");
string line;
bool found=false;
while(getline(file,line)){
    stringstream ss(line);
    string id,title,author,available;
    getline(ss,id,',');
    getline(ss,title,',');
    getline(ss,author,',');
    getline(ss,available,',');
    if(id==bookid&&available=="1"){
        available="0";
        found=true;
    }
    books.push_back(id+","+title+","+author+","+available);
}
file.close();
if(!found){
    cout<<"book not available!\n";
    return;
}
ofstream out("books,txt");
for(auto&b:books) out<<b<<"\n";
out.close();
vector<string>student;  //updating the student file
ifstream sfile("student.txt");
while(getline(sfile,line)){
 stringstream ss(line);
 string id,name,issued;
 getline(ss,id,',');
 getline(ss,name,',');
 getline(ss,issued,',');
 if(id==studentid){
     if(issued.empty())
     issued=bookid;
     else
     issued+="|"+bookid;
 }
 student.push_back(id+","+name+","+issued);
}
sfile.close();
ofstream sout("students.txt");
for (auto &s:student) sout<<s<<"\n";
sout.close();
cout<<"book issued successfully!\n";
}
void returnbook(){  //return book
string bookid,studentid;
cout<<"enter book ID:";
cin>>bookid;
cout<<"enter student ID:";
cin>>studentid;
vector<string>books;
ifstream file("books.txt");
string line;
while(getline(file,line)){
    stringstream ss(line);
    string id,title,author,available;
    getline(ss,id,',');
    getline(ss,title,',');
    getline(ss,author,',');
    getline(ss,available,',');
    if(id==bookid)
    available="1";
    books.push_back(id+","+title+","+author+","+available);
}
file.close();
ofstream out("books.txt");
for(auto&b:books)out<<b<<"\n";
out.close();
cout<<"book returned successfully!\n";
}
};
int main(){  //opening the main block
library lib;
int choice;
do{
    cout<<"\n====LIBRARY MENU====\n";
    cout<<"1.add book\n";
    cout<<"2.view books\n";
    cout<<"3.add student\n";
    cout<<"3.issue book\n";
    cout<<"4.return book\n";
    cout<<"5.exit\n";
    cout<<"enter choice:";
    cin>>choice;
    switch (choice){
        case 1:lib.addbook();break;
        case 2:lib.viewbooks();break;
        case 3:lib.issuebook();break;
        case 4:lib.returnbook();break;
        case 5:cout<<"exiting...\n";break;
        deafult:cout<<"invalid choice!\n";
    }
}while(choice!=5);
return 0;
}
