//Reilly Zink
// 2/28/2017
// project #3 - college course linked list
//college.h


#include<string>
#include<iostream>
#include "node.h"
#include "course.h"
#ifndef COLLEGE_H
#define COLLEGE_H

class College{
    public:
        College();
        ~College();
        College(const College& other);
        College(std::string fullname = std::string(), node *y = NULL);

        College& operator = (const College& other);

        void add(course& c);
        void display(std::ostream& outs);
        void remove(std::string x);

        double hours();
        double gpa();

        void load(std::istream& ins);
        void save(std::ostream& outs);

    private:
	    std::string name;
        node *head;
};

#endif