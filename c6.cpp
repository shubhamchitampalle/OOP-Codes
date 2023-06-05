#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class personal
{
    public:
    string name;
    string birthdt;
    long telphno;

    void create()
        {
            cout<<"enter a name of person:"<<endl;
            cin>>name;
            cout<<"enter a date of birth of person:"<<endl;
            cin>>birthdt;
            cout<<"enter a telephone no of person:"<<endl;
            cin>>telphno;
        }
    void display()
    {
            cout<<"name of person:"<<name<<endl;
            cout<<"date of birth of person:"<<birthdt<<endl;
            cout<<"telephone no of person:"<<telphno<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter number of persons:"<<endl;
    cin>>n;
    vector<personal>pr(n);
    vector<string>name(n);
    vector<int>telphno(n);
    string target;
    int choice;
    char ans='y';
    do
        {
            cout << "\n Main Menu";
            cout<<"\n1. Insert data of person";
            cout << "\n2. Display data of person";
            cout << "\n3. sort the data";
            cout<<"\n4. search the data";
            cout<<"\n5. delete a particular data";
            cout<<"\n Enter your choice: ";
            cin >> choice;

            switch (choice)
                {
                    case 1:
                    for (int i = 0; i < n; i++)
                    {
                        pr[i].create();
                    }
                    break;
                    case 2:
                    for (int i=0; i<n;i++)
                    {
                        pr[i].display();
                    }
                    break;
                    case 3:
                    for (int i = 0; i < n; i++)
                    {
                        name[i] = (pr[i].name);
                    }
                        sort(name.begin(), name.end());
                        for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                        if (name[i] == pr[j].name)
                            {
                                pr[j].display();
                            }
                         }

                    }
                    break;
                    case 4:
                    for (int i = 0; i < n; i++)
                    {
                        name.push_back(pr[i].name);
                    }
                        cout << "Enter the name to be searched in the database:\n";
                        cin >> target;
                        if (binary_search(name.begin(), name.end(), target))
                    {
                        cout << "The person data present in database\n";
                    }
                        else
                    {
                        cout << "The person data is not present in database\n";
                    }
                        break;
                    case 5:
                    for (int i = 0; i < n; i++)
                    {
                        name.push_back(pr[i].name);
                    }
                        cout << "Enter the name to be deleted in the database:\n";
                        cin >> target;
                        if (binary_search(name.begin(), name.end(), target))
                    {
                        cout << "the person data is present in database\n";
                        cout << "the data of person is delete in the database.\n";
                        for (int i = 0; i < n; i++)
                        {
                            if (pr[i].name == target)
                            {
                                pr.erase(pr.begin() + i);
                            }
                        }
                    }
                        else
                    {
                        cout << "THE PERSON'S DATA IS NOT PRESENT IN THE RECORD\n";
                    }
                        break;
                        default: cout<<"Sorry...! Invalid choice"<<endl;
                        break;
                }
                        cout << "\n Do you want to continue?(y/n): ";
                        cin >> ans;
        } while (ans == 'y' || ans== 'Y');
        return 0;
}
