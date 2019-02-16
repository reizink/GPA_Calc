//Reilly Zink
// 2/28/2017
// project #3 - college course linked list
//college.h

#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include "node.h"
#include "course.h"
#include "college.h"
using namespace std;

        College::College(string x, node *y ){
            name = x;
            head = y;
        }

        College::~College(){
            node *rmptr;
            while(head != NULL ){
                rmptr = head;
                head = head->link();
                delete rmptr;
            }
        }


        College::College(const College& other){ //copy constructor
            name = other.name;
            if( other.head == NULL) head = NULL;

            else{
                node *sptr, *dptr;
                head = new node(other.head->data());
                sptr = other.head->link();
                dptr = head;

                while(sptr != NULL){
                    dptr->set_link(new node( sptr->data() ));
                    dptr = dptr->link();
                    sptr = sptr->link();
                }
            }

        }

        College& College::operator = (const College& other){ //assignment
            if( this == &other ) return *this;
            else{
                node *rmptr;
                name = other.name;
                while(head != NULL ){
                    rmptr = head;
                    head = head->link();
                    delete rmptr;
                }
                node *sptr, *dptr;
                if( other.head != NULL){
                    head = new node( other.head->data());
                    dptr = head;
                    sptr = other.head->link();
                    while( sptr != NULL){
                        dptr->set_link(new node(sptr->data()));
                        dptr = dptr->link();
                        sptr = sptr->link();
                    }
                }
                return *this;
            }
        }

        void College::add(course& c){ //sorted Insert
            node *current, *previous;
            current = head;

            if (head == NULL){
                head = new node;
                head->set_data(c);
                return;
            }
            else{
                previous = head;

                for(current = head; current != NULL; current = current->link()){
                    if( c < current->data()){
                        if(current == head){
                            current = new node;
                            current->set_link(head);
                            current->set_data(c);
                            head = current;
                            return;
                        }else{
                            node *cursor = new node;
                            cursor->set_link(cursor);
                            cursor->set_data(c);
                            previous->set_link(cursor);
                            return;
                        }
                    }
                    else if(current->link() == NULL){
                        node *cursor = new node;
                        cursor->set_data(c);
                        current->set_link(cursor);
                        return;
                    }
                    previous = current;
                }
            }
            /*else if(head->data().get_course_number() > c.get_course_number()){
                head = new node ( c );
                head->set_link(current);
            }
            else{
                while (current->link() != NULL ){
                    current = current->link();
                }
                if(current->link()->data().get_course_number() < c.get_course_number()){
                    current->set_link(new node(c));
                }
                while( current->link()->data().get_course_number() < c.get_course_number()){
                    previous = current;
                    current = current->link();
                }

                previous->set_link(new node (c));
                previous = previous->link();
                previous->set_link(current);

            }*/
        }

        void College::display(ostream& outs){
            for(node *tmp = head; tmp != NULL; tmp = tmp->link())
                outs << tmp->data();
        }

        void College::remove(string x){   // remove course
            
            for( size_t i = 0; i < x.length(); i++ ){
                x[i] = toupper( x[i] );
            }
            
            if( head->data().get_course_number() == x){
                node* tmp;
                tmp = head;

                head = head->link();
                delete tmp;
            }
            else{
                node* tmp = head->link();
                node* previous = head;

                while( tmp->data().get_course_number() != x ){
                    previous = tmp;
                    tmp = tmp->link();
                }

                previous->set_link( tmp->link());
                delete tmp;
            }
        }

        double College::hours(){
            double total = 0;
            node *cursor = head;

            while( cursor != NULL ){
                total += cursor->data().get_hours();
                cursor = cursor->link();
            }

            return total;
        }

        double College::gpa(){
            node* cursor;
            double total = 0;

            cursor = head;
            while( cursor != NULL ){
                total += cursor->data().get_number_grade() * cursor->data().get_hours();
                cursor = cursor->link();
            }
            return total / hours();
        }

        void College::load(istream& ins){
            course tmp;

            ins >> tmp;
            while( !ins.eof()){
                add(tmp);
                ins >> tmp;
            }
            
        }

        void College::save(ostream& outs){
            display(outs);
        }


