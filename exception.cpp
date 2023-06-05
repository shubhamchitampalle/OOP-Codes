#include<iostream>
#include<string.h>
using namespace std;

#define max 100;

class personalInfo
{
    string licence,DOB,Bloodgroup;
    public:
    personalInfo();
    personalInfo(personalInfo &);
    ~personalInfo()
    {
        cout<<"\n Destructor is called."<<endl;    
    }
    friend class student;
};

class student {
    public:
        string name, address,year;
        char division;
        int Rollno;
        long mobileno;
        static int counter;
    public:
        void create(personalInfo &);
        void display(personalInfo &);
        inline static void increment() {
            counter++;           
        }
        inline static void showinc() {
            cout<<"No. of records are :"<<counter<<endl;
        }
    public:
        student();
        student(student &);
        ~student() {
            cout<<"Destructor called"<<endl;      
        }

};

int student::counter=0;
student::student() {
    name = "sampada";
    address = "Pune";
    year = "SE COMP 1";
    division = 'A';
    Rollno = 056;
    mobileno = 8669886347;
}
personalInfo::personalInfo() {
    licence = "LN8979";
    DOB = "20/11/2002";
    Bloodgroup = 'A';  
}

student::student(student &obj1){
    this->name = obj1.name;
    this->address = obj1.address;
    this->year = obj1.year;
    this->division = obj1.division;
    this->Rollno = obj1.Rollno;
    this->mobileno = obj1.mobileno;

}

personalInfo::personalInfo( personalInfo & obj1) {
    this->licence = obj1.licence;
    this->DOB = obj1.DOB;
    this->Bloodgroup = obj1.Bloodgroup;
}

void student::create(personalInfo &obj1) {

cout<<"\nNAME : "<<endl;
cin>>name;
cout<<"\nADDRESS : "<<endl;
cin>>address;
cout<<"\nDATE OF BIRTH : "<<endl;
cin>>obj1.DOB;
cout<<"\nYEAR : "<<endl;
cin>>year;
cout<<"\nDIVISION: "<<endl;
cin>>division;
cout<<"\nROLL NUMBER : "<<endl;
cin>>Rollno;
cout<<"\nBLOOD GROUP : "<<endl;
cin>>obj1.Bloodgroup;
cout<<"\nLICEINCE NUMBER : "<<endl;
cin>>obj1.licence;
cout<<"\nPHONE NUMBER : "<<endl;
cin>>mobileno; 

try
{
    if(mobileno<1000000000)
        throw 1;
    if (Rollno<=100)
        throw 2;  

}
catch(int e)
{
    if(e==1){
    cout<<"Invalid mobile no.enter 10 digit no."<<endl;
    cin>>mobileno;
    }
    else
    {
        cout<<"Invalid roll no. enter again";
        cin>>Rollno;
    } 
}

}

void student::display(personalInfo &obj1) {
    cout<<"\n*********"<<endl;
cout<<"\nNAME OF STUDENT : "<<name<<endl;
cout<<"\nADDRESS OF STUDENT : "<<address<<endl;
cout<<"\nDATE OF BIRTH : "<<obj1.DOB<<endl;
cout<<"\nYEAR : "<<year<<endl;
cout<<"\nDIVISION : "<<division<<endl;
cout<<"\nROLL NO : "<<Rollno<<endl;
cout<<"\nBLOOD GROUP : "<<obj1.Bloodgroup<<endl;
cout<<"\nLICEINCE NUMBER : "<<obj1.licence<<endl;
cout<<"\nPHONE NUMBER : "<<mobileno<<endl;
cout<<"$$$$"<<endl;
}

int main()
{
    int n;
    int ch;
    char answer;

    cout<<"Enter no of students"<<endl;
    cin>>n;
    student *sObj = new student[n];
    personalInfo *pObj = new personalInfo[n];

do
 {
	cout<<"\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)";
	cout<<"\n Enter your Choice: ";
	cin>>ch;
	switch(ch)
	{
	case 1: 
	{
		for(int i=0;i<n;i++)
		{
		       sObj[i].create(pObj[i]);
		       sObj[i].increment();
               
               
               
 
		}
	}
		break;
 	case 2: 
  		{
			sObj[0].showinc(); 
			for(int i=0;i<n;i++)
			{
				sObj[i].display(pObj[i]);
			}
    	}
    	break;
	  case 3: 
		{
			student obj1;
		    personalInfo obj2;
			obj1.create(obj2);
			student obj3(obj1);		
 
		    personalInfo obj4(obj2);		
			cout<<"\n Copy Constructor is called ";
			obj3.display(obj4);
 		}
        break;
	case 4:
 		{
			student obj1;	
		    personalInfo obj2;	
			cout<<"\n Default Constructor is called ";
			obj1.display(obj2);
 		}
 		break;
	case 5: 
 
			delete [] sObj;			
 		     delete [] pObj;		
 	}				
 	cout<<"\n Want to continue:(y/n)";
 	cin>>answer;
  }while(answer=='y') ;
 
 
 return 0;

}