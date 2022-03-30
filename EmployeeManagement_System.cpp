#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

template<class T>
class Management
{
	public:
		int Id;
		string Name;
		int age;
		string Dept;
		Management()
		{
			
		}
		virtual void Display_List(Management emp[],int n) const
		{
			int i;
			cout<<setw(10)<<"Id"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(15)<<"Department"<<endl;
			cout<<endl;
			for(i<0;i<n;i++)
			{
				cout<<setw(10)<<emp[i].Id<<setw(10)<<emp[i].Name<<setw(10)<<emp[i].age<<setw(15)<<emp[i].Dept<<endl;
			}
		}
		void Search(Management emp[],int n)
		{
			int Id;
			bool flag=false;
			cout<<"Enter employee ID: ";
			cin>>Id;
			for(int i=0;i<n;i++)
			{
				if(emp[i].Id==Id)
				{
					flag=true;
					cout<<setw(10)<<"Id"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(15)<<"Department"<<endl;
					cout<<setw(10)<<emp[i].Id<<setw(10)<<emp[i].Name<<setw(10)<<emp[i].age<<setw(15)<<emp[i].Dept<<endl;
				}
			}
			if(flag==false)
			{
				cout<<"ID not Found!"<<endl;
			}
		}
		virtual int Add_Employee(Management emp[],int n) const{ }
		virtual T Edit_Employee(Management emp[],int n) const{ }
		virtual int Delete_Employee(Management emp[],int n) const{ }
		virtual T Add_Dept(Management emp[],int n) const{ }
		virtual T Edit_Dept(Management emp[],int n) const{ }
		virtual int Delete_Dept(Management emp[],int n) const{ }
};
template<class T>
class EmployeeManagement : public Management<T>
{
	private:
		string Name;
		int age;
	public:
		virtual int Add_Employee(Management<int> emp[],int n) const
		{
			cout<<"Enter employee ID: ";
			cin>>emp[n].Id;
			for(int i=0;i<n;i++)
			{
				if(emp[i].Id==emp[n].Id)
				{
					cout<<"Data already exists!"<<endl;
					return 0;
				}
			}
			cout<<"Enter employee Name: ";
			cin>>emp[n].Name;
			cout<<"Enter employee Age: ";
			cin>>emp[n].age;
			cout<<endl;
			n=n+1;
			
			return n;
		}
		virtual T Edit_Employee(Management<int> emp[],int n) const
		{
			int Id;
			bool flag=false;
			cout<<"Enter employee ID: ";
			cin>>Id;
			for(int i=0;i<n;i++)
			{
				if(emp[i].Id==Id)
				{
					cout<<"Enter employee Name: ";
					cin>>emp[i].Name;
					cout<<"Enter employee Age: ";
					cin>>emp[i].age;
					cout<<endl;
					flag=true;
				}
			}
			if(flag==false)
			{
				cout<<"Id Not found!"<<endl;
			}
		}
		virtual int Delete_Employee(Management<int> emp[],int n) const
		{
			int i,Id;
			bool flag=false;
			cout<<"Enter employee ID: ";
			cin>>Id;
			for(i=0;i<n;i++)
			{
				if(emp[i].Id==Id)
				{
					flag=true;
					break;
				}
			}
			if(i<n && flag==true)
			{
				n=n-1;
				for(int j=i;j<n;j++)
				{
					emp[j]=emp[j+1];
				}
			}
			else if(flag==false)
			{
				cout<<"ID not found!"<<endl;
			}
			return n;
		}	
};
template<class T>
class DepartmentManagement : public Management<T>
{
	private:
		
			string Name[30];
			int age;
			int Id;
			string Dept[30];
	public:
		virtual T Add_Dept(Management<int> emp[],int n) const
		{
			int Id;
			bool flag=false;
			cout<<"Enter employee ID: ";
			cin>>Id;
			for(int i=0;i<n;i++)
			{
				if(emp[i].Id==Id)
				{
					cout<<"Enter employee Department: ";
					cin>>emp[i].Dept;
					flag=true;
				}
			}
			if(flag==false)
			{
				cout<<"Id not Found!"<<endl;
				return 0;
			}
		}
		virtual T Edit_Dept(Management<int> emp[],int n) const
		{
			int Id;
			bool flag=false;
			cout<<"Enter employee ID: ";
			cin>>Id;
			for(int i=0;i<n;i++)
			{
				if(emp[i].Id==Id && !emp[i].Dept.empty())
				{
					cout<<"Enter employee Department: ";
					cin>>emp[i].Dept;
					cout<<endl;
					flag=true;
				}
			}
			if(flag==false)
			{
				cout<<"Id with Department not Found!"<<endl;
				return 0;
			}
		}
		virtual int Delete_Dept(Management<int> emp[],int n) const
		{
			int i,Id;
			bool flag=false;
			cout<<"Enter employee ID: ";
			cin>>Id;
			for(i=0;i<n;i++)
			{
				if(emp[i].Id==Id && !emp[i].Dept.empty())
				{
					flag=true;
					break;
				}
			}
			if(i<n && flag==true)
			{
				n=n-1;
				for(int j=i;j<n;j++)
				{
					emp[j]=emp[j+1];
				}
			}
			else if(flag==false)
			{
				cout<<"ID with Department not found!"<<endl;
			}
			return n;
		}
};
int main()
{
	Management<int> emp[30];
	Management<int>*e1= new Management<int>();
	int n=0;
	char Ans='Y';
	int Option;
	do
	{
		cout<<endl;
		cout<<setw(15)<<"MENU"<<setw(15)<<endl;
		cout<<setw(15)<<"-----------------------"<<setw(15)<<endl;
		cout<<"1. Add Employee"<<endl;
		cout<<"2. Edit Employee"<<endl;
		cout<<"3. Delete Employee"<<endl;
		cout<<"4. Add Department"<<endl;
		cout<<"5. Edit Department"<<endl;
		cout<<"6. Delete Department"<<endl;
		cout<<"7. Display Employee List"<<endl;
		cout<<"8. Search Employee"<<endl;
		cout<<endl;
		cout<<"Enter Your Option: ";
		cin>>Option;
		switch(Option)
		{
			case 1:
				e1= new EmployeeManagement<int>();
				n=e1->Add_Employee(emp,n);
				break;
			case 2:
				e1= new EmployeeManagement<int>();
				e1->Edit_Employee(emp,n);
				break;
			case 3:
				e1= new EmployeeManagement<int>();
				n=e1->Delete_Employee(emp,n);
				cout<<"Employee List:"<<endl;
				e1->Display_List(emp,n);
				break;
			case 4:
				e1= new DepartmentManagement<int>();
				e1->Add_Dept(emp,n);
				break;
			case 5:
				e1= new DepartmentManagement<int>();
				e1->Edit_Dept(emp,n);
				break;
			case 6:
				e1= new DepartmentManagement<int>();
				n=e1->Delete_Dept(emp,n);
				cout<<"Employee List:"<<endl;
				e1->Display_List(emp,n);
				break;
			case 7:
				cout<<"Employee List:"<<endl;
				e1->Display_List(emp,n);
				break;
			case 8:
				e1->Search(emp,n);
				break;
			default:
				cout<<"WRONG CHOICE!"<<endl;
		}
		
	}while(Option!=0);
	return 0;
}

