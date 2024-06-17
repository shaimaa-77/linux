#include<iostream>
#include<array>
#include <string>
#define array_size   100
using namespace std;
void add_record();
void fetch_person();
enum class options
{
    add=1,
    fetch=2,
    quit=3
};
class person
{
private:
    /* data */
    string name;
    int age;

public:
  static int ID;
    person(/* args */);
    ~person();
    void set_name();
    void set_age();
    void set_ID();
    string get_name();
    int get_age();
    int get_ID(); 
    void operator=(person const& obj)
    {
        
        name = obj.name;
        age =  obj.age;
    }
};
int person::ID=-1;
person::person(/* args */)
{
    
}

person::~person()
{
}
void person::set_name()
{
   cout<<"Name: ";
   cin>> name;
}
void person::set_age()
{
      cout<<"Age: ";
      cin>> age;
}
void person::set_ID()
{
    cout<<"ID: ";
   cin>> ID;
}
string person::get_name()
{
    return name;
}
int person::get_age()
{
    return age;
}
int person::get_ID()
{
    return ID;
}
person people[array_size];
 void add_record()
 {
    person temp_person;
    cout<<"please enter person data\n";
    temp_person.set_name();
    temp_person.set_age();
    temp_person.ID++;
    people[temp_person.ID]=temp_person;
    cout<<"user record added successfully\n";
    cout<<"the user ID is "<<temp_person.get_ID()<<"\n";
    cout<<"-----------------------------\n";
 }
  
 void fetch_person()
 {
    person temp_person;
    int TEMP_ID;
    cout<<"please enter person ID from 0-100\n";
    cin>>TEMP_ID;
    if(TEMP_ID>temp_person.ID)
    {
        cout<<"no record for this id please try again";
    }
    else
    {
         temp_person=people[TEMP_ID];
         cout<<"the user ID : "<<temp_person.get_ID()<<"\n";
         cout<<"the user name : "<<temp_person.get_name()<<"\n";
        cout<<"the user age : "<<temp_person.get_age()<<"\n";
    }
    cout<<"-----------------------------\n";
}
   
 std::istream& operator>>(std::istream& is,  options& option)
 { 
    int input;
    is>>input;
    switch (input)
    {
    case 1:
         option=options::add;
        break;
    case 2:
         option=options::fetch;
        break;
    case 3:
         option=options::quit;
        break;
    
    default:
        break;
    }
     return is;
 }
 
int main(int argc, char const *argv[])
{
    options option_temp;
  
    /* code */
    cout<<"user setup application\n";
    cout<<"please select an option\n";
    while (1)
    {
        /* code */
        cout<<"1-add a record\n";
    cout<<"2-fetch a record\n";
    cout<<"3-quit\n";
    cin>> option_temp;
    switch (option_temp)
    {
    case options::add :
      add_record();
        break;
    case options::fetch :
      fetch_person();
        break;
    case options::quit :
    cout<<"quit \n ";
    cout<<"----------------------------------";
     return 0 ;
        break;
    default:
        cout<<"you entered a wrong value please try again\n";
     }
  }
    
    
    return 0;
}
