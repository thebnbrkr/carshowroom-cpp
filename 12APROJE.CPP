#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<iomanip.h>
class store
{
	int price;
	char name[20];
 public:
	store()
	{price=0;

	}
	void list();
	void add();
	void dlt();
}s;
void store::list()
{
	cout<<"		       List Of CARS"<<endl;
	cout<<"==========================================================="<<endl;
	char ch[20];
	ifstream fin("cars.dat");
	while (fin)
	{
	fin.read((char*) & s, sizeof(s));
	if(fin.eof())
	break;
	cout<<ch<<endl;
	}
}
void store::dlt()
{       char ename[20];
	cout<<"Enter The Car To be Edited"<<endl;
	gets(ename);
	ofstream fout("temp.dat", ios::app);
	ifstream fin("cars.dat");
	while(fin) {
	fin.read((char*)&s, sizeof(s));
	if (fin.eof())
	break;
	if(strcmpi(s.name,ename)!=0)
	fout.write((char*)&s, sizeof(s));
	}
	fin.close();
	fout.close();
	remove("store.dat");
	rename("temp.dat", "store.dat");
}
void store::add()
{
	ofstream fout;
	fout.open("cars.dat",ios::app);
	cout<<"Enter The Model:";
	gets(name);
	fout.write((char*)&s, sizeof(s));
	fout.close();

}
void main()
{
	clrscr();
	char cah='y';
	int ch;char fname[30];
	do{
	clrscr();
	cout<<"                   EDISSON MOTORS"<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"\n\nMENU"<<endl;
	cout<<"=========="<<endl;
	cout<<"\n1)List"<<endl;
	cout<<"2)Add"<<endl;
	cout<<"4)delete"<<endl;
	cin>>ch;
	switch(ch)
	{

		case 1: s.list();
			break;
		case 2: s.add();
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout<<"input has successfully failed"<<endl;
			break;
	}
	cout<<"do you want to continue(y/n):";
	cin>>cah;
	}while(cah=='y'||cah=='Y');
	getch();
}








