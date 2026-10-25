#include <iostream>
#include <string>
using namespace std;
void display() {
	cout<<"1. Add Student\n";
	cout<<"2. Display All Students\n";
	cout<<"3. Search Student\n";
	cout<<"4. Update Student\n";
	cout<<"5. Delete Student\n";
	cout<<"0. Exit\n";
}
class Student {
public:
	string name;
	int id;
	int age;
	double marks;
	void setdata(int a,string b,int c,double d)
	{
		id    = a;
		name  = b;
		age   = c;
		marks = d;
	}
	void Display()
	{
		cout<<"Id of the student : "<<id<<endl;
		cout<<"Name of the student : "<<name<<endl;
		cout<<"Age of the student : "<<age<<endl;
		cout<<"Marks of the student : "<<marks<<endl;
	}
};
class StudentManagementSystem {
public:
	Student s[100];
	int count;
	StudentManagementSystem()
	{
		count=0;
	}
	void addstudent() {
		if(count>=100)
		{
			cout<<"List is already full\n";
			return;
		}
		int p,q;
		double r;
		string c;
		cout<<"Enter the Id of student : ";
		cin>>p;
		for(int i=0; i<count; i++)
		{
			if(s[i].id==p)
			{
				cout<<"Id already exists\n";
				return;
			}
		}
		cout<<"Enter the name of the student : ";
		cin.ignore();
		getline(cin, c);
		cout<<"Enter the age of the student : ";
		cin>>q;
		cout<<"Enter the marks of the student : ";
		cin>>r;
		if(q<=100&&q>0&&r<=100&&r>=0)
		{
			s[count].setdata(p,c,q,r);
			count++;
		}
		else
		{
			cout<<"Enter valid inputs\n";
			return;
		}
		cout<<"Student added sucessfully\n";
	}
	void Displayall() {
		if(count==0)
		{
			cout<<"List is empty\n";
			return;

		}
		for(int i=0; i<count; i++)
		{
			s[i].Display();
		}
		cout<<"The list has ended\n";
	}
	void searchstudent() {
		int j,i,found=0;
		cout<<"Enter the id of student to be searched : ";
		cin>>i;
		for(j=0; j<count; j++)
		{
			if(s[j].id==i)
			{
				found++;
				break;
			}
		}
		if(found)
		{
			cout<<"Student found at serial no "<<j+1<<" in the list\n";
			s[j].Display();
		}
		else
			cout<<"Student not found in the existing list\n";
	}
	void updatestudent()
	{
		int i,j,found=0;
		cout<<"Enter the id of student to be updated : ";
		cin>>i;
		for(j=0; j<count; j++)
		{
			if(s[j].id==i)
			{
				found++;
				break;
			}
		}
		if(!found)
		{
			cout<<"Id of the student not found\n";
			return;

		}
		else
		{
			cout<<"1.Id\n";
			cout<<"2.Name\n";
			cout<<"3.Age\n";
			cout<<"4.Marks\n";
			int y;
			cout<<"Enter the parameter no to be changed : ";
			cin>>y;
			cout<<"Enter the new value : ";

			switch(y)
			{
			case 1:{
				int g;
				cin>>g;
				s[j].id=g;}
				break;
			case 2:{string newname;
				cin.ignore(1000,'\n');
				getline(cin, newname);
				s[j].name=newname;}
				break;
			case 3:{
				int g;
				cin>>g;
				s[j].age=g;}
				break;
			case 4:{
				double g;
				cin>>g;
				s[j].marks=g;}
				break;
			}
		}
		cout<<"Record updated sucessfully\n";
	}
	void deletestudent() {
		int f,i;
		cout<<"Enter the Id of the student to be deleted : ";
		cin>>f;
		bool found=false;
		for(i=0; i<count; i++)
		{
			if(s[i].id==f)
			{
				found=true;
				break;
			}
		}
		if(!found)
		{
			cout<<"Id not found in the list\n";
			return;
		}
		for(int j=i; j<count-1; j++)
		{
			s[j].id=s[j+1].id;
			s[j].name=s[j+1].name;
			s[j].age=s[j+1].age;
			s[j].marks=s[j+1].marks;
		}
		count--;
		cout<<"Student with Id "<<f<<" deleted sucessfully\n";
	}
};
int main()
{
	int n=-1;
	StudentManagementSystem sms;
	while(n!=0) {
		display();
		cout<<"\nEnter your choice : ";
		cin>>n;
		switch (n)
		{
		case 1:
			sms.addstudent();
			break;
		case 2:
			sms.Displayall();
			break;
		case 3:
			sms.searchstudent();
			break;
		case 4:
			sms.updatestudent();
			break;
		case 5:
			sms.deletestudent();
			break;
		default :
			cout<<"Enter a valid choice\n";
			break;
		}
	}
	return 0;
}