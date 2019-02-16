#include<iostream>
#include "node.h"
#include "course.h"
using namespace std;

int main(){
     course c1;
     node * ptr;
     cout<<"Enter course info:\n";
     cin>>c1;
     ptr = new node(c1);
     cout<<ptr->data()<<endl;
     cout<<"Points = "<<ptr->data().get_number_grade() * ptr->data().get_hours();
return 0;
}

