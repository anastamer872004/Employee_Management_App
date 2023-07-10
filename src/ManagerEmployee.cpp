#include "ManagerEmployee.h"

ManagerEmployee::ManagerEmployee()
{
    //ctor
}

ManagerEmployee::~ManagerEmployee()
{
    //dtor
}
void ManagerEmployee::input()
{
    SalariedEmployee::input();
    cout<<"Bouns : "; cin>>bouns;
}

void ManagerEmployee::display_details()
{
   SalariedEmployee::display_details();
    cout<<"\t\tBouns = "<<bouns<<endl;

}

double ManagerEmployee::calculate_pay()
{
   double total = Employee::calculate_benefit();

    return (salary + bouns) + total ;
}

