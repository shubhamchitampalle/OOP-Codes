#include<iostream>
#include<string>
using namespace std;

class publications{
    public:
    string title;
    float price;

    
    publications()
    {
        cout<<"R.D Sharma publications"<<endl;
        cout<<"Enter the title:";
        cin>>title;
        cout<<"Enter the price:";
        cin>>price;
    }
};


class book : public publications
{
    public:
    int pages;
    void getdata()
    {
        cout<<"Enter the number of pages:";
        cin>>pages;
    }
    void putdata()
    {
        cout<<"Number of pages are :"<<pages;
    }

};
    

class tape : public publications
{
    public:
    float minutes;
    void getdata()
    {
        cout<<"Enter number of minutes u want for cd:";
        cin>>minutes;
    }
    void putdata()
    {
    
        cout<<"Minutes for CD are: "<<minutes;
    }
    

};

int main()
{
    book obj1;
    obj1.getdata();
    obj1.putdata();
    tape obj2;
    obj2.getdata();
    obj2.putdata();

    return 0;
}