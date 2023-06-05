#include<iostream>
using namespace std;
class complex{
    public:
        int real,imag;
    complex(int r=0,int i=0){
        r=real;
        i=imag;
    }
    complex operator + (complex const &obj){
      complex obj1;
      obj1.real=real + obj.real;
      obj1.imag=imag + obj.imag;
      return obj1;    
    }
    complex operator * (complex const &obj){
       complex obj1;
       obj1.real=((real)*(obj.real))-((imag)*(obj.imag));
       obj1.imag=((real)*(obj.imag))+((imag)*(obj.real)); 
       return obj1;
    }
void add(){
    cout<<"Addition of complex no is:"<<endl;
    cout<<real<<"+"<<imag<<"i"<<endl;
}
void mult(){
    cout<<"Multiplication of complex no is:"<<endl;
    cout<<real<<"*"<<imag<<"i"<<endl;
}
};
int main(){
while(true){
    complex c1,c2,c3,c4;
    cout<<"Enter real part of first complex no:";
    cin>>c1.real;
    cout<<"Enter imag part of first complex no:";
    cin>>c1.imag;
    cout<<"Enter real part of second complex no:";
    cin>>c2.real;
    cout<<"Enter imag part of second complex no:";
    cin>>c2.imag;
    int ch;
    cout<<"Which operation do you want to perform \n 1.Addition \n 2.Multiplication";
    cin>>ch;

switch (ch)
{
case 1:
    c3=c1+c2;
    c3.add();
    break;
case 2:
    c4=c1*c2;
    c4.mult();
    break;       
default:
    cout<<"error\n";
    break;
    return 0;
}
}
}  