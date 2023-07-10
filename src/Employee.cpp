#include "Employee.h"

Employee::Employee(){

    id=-1;
    name="";
    phone="";
    email="";
    job_titel="";

    department = nullptr ;

}


Employee::~Employee(){

    for (int i = 0 ; i < benefit_cnt ; i++)
        delete benefit[i];

}


void Employee::input(){

     cout<<"Employee ID : "; cin>>id;
     cout<<"NAME : "; cin>>name;
     cout<<"PHONE : "; cin>>phone;
     cout<<"EMAIL : "; cin>>email;
     cout<<"JOB TITEL : "; cin>>job_titel;


}


void Employee::display_details(){

cout<<"\n________________________\n";
cout<<  "Data of Employee founded\n";
cout<<  "________________________\n";


    cout<<"Employee ID = "<<id;
    cout<<"\t\tNAME = "<<name;
    cout<<"\t\tPHONE = "<<phone<<endl;
    cout<<"EMAIL = "<<email;
    cout<<"\t\tJOB TITEL = "<<job_titel;

    if(department != nullptr)         // OR (department)
        department->print();

    if(benefit)
        print_benefit();

    cout<<endl;
}


void Employee::set_dept_to_employee(Department* ptr){

    department = ptr;
}





int Employee::get_id(){

    return id;
}


void Employee::add_benefit(){

    int n;
    cout<<"Enter the number of benefits  [max : 5] : ";
    cin>>n;

    for(int i = 0 ; i < n ; i++){

        int type;
cout<<"Enter the type of the benefit ( 1-Health , 2-Dental ) : ";
        cin>>type;

        if (type == 1){

            benefit[benefit_cnt] = new HealthBenefit;
            benefit[benefit_cnt++]->input();
        }

        else {

            benefit[benefit_cnt] = new DentalBenefit;
            benefit[benefit_cnt++]->input();
        }
    }

}


void Employee::print_benefit(){

  for(int i=0 ; i<benefit_cnt ; i++)
      benefit[i]->display_details();
}





double Employee::calculate_benefit(){

    double total = 0.0;

    for(int i = 0 ; i < benefit_cnt ; i++)
        total += benefit[i]->calculate_Benefit();

    return total;
}























