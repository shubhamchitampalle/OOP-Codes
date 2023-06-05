#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    typedef map<string,int>mapType;
    mapType population;
    population.insert(pair<string,int>("Maharashtra",702635700));
    population.insert(pair<string,int>("GOA",1000000));
    population.insert(pair<string,int>("U.p",1254963));
    population.insert(pair<string,int>("Bihar",231568));
    population.insert(pair<string,int>("Kerala",1459347));
    
    mapType::iterator it;

    cout<<".........Population of States in India.........";
    cout<<"Size of Population Map"<<endl<<population.size()<<endl;

    string State_name;
    cout<<"Enter State name";
    cin>>State_name;
    it=population.find(State_name);
    if(it!=population.end())
        cout<<State_name<<"'s population is:"<<it->second;
    else
        cout<<"Key is not in Population map"<<endl;
        population.clear();
}