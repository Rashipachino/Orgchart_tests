#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
namespace ariel{
            string& OrgChart::level_order_iterator::operator*() const{
                return this->q.front()->name;
                //return this->pointer_to_curr->name;
            }      
            string* OrgChart::level_order_iterator::operator->() const{
                return &(this->q.front()->name);
                //return &(this->pointer_to_curr->name);
            }  
            OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(){
                // q.push(this->pointer_to_curr);
                if(q.empty()){ //end of chart
                    return *this;
                }
                for(unsigned long i = 0; i < this->q.front()->subs.size(); i++){
                    q.push(this->q.front()->subs[i]); //push all subs into queue
                }
                //Node* top = q.front(); //this is will be next iterator
                q.pop(); //delete from queue
                //this->pointer_to_curr = top;
                return *this;
            }

            const OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int){
                level_order_iterator tmp= *this;
                if(q.empty()){ //end of chart
                    return tmp;
                }
                for(unsigned long i = 0; i < this->q.front()->subs.size(); i++){
                    q.push(this->q.front()->subs[i]); //push all subs into queue
                }
               // Node* top = q.front(); //this will be the next iterator
                q.pop(); //delete from queue
                //this->pointer_to_curr = top;
			    return tmp;
            }
            bool OrgChart::level_order_iterator::operator==(const OrgChart::level_order_iterator& rhs) const{
                return this->q.front() == rhs.q.front();
                //return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::level_order_iterator::operator!=(const OrgChart::level_order_iterator& rhs) const{
                return this->q.front() != rhs.q.front();
                //return pointer_to_curr != rhs.pointer_to_curr;
            }


            string& OrgChart::reverse_order_iterator::operator*() const{
                return this->reverse_stk.top()->name;
            }
            string* OrgChart::reverse_order_iterator::operator->() const{
                return &(this->reverse_stk.top()->name);
            }
            OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(){
                reverse_stk.pop();
                return *this;
            }
            const OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(int){
                reverse_order_iterator tmp = *this;
                reverse_stk.pop();
                return tmp;                
            }
            bool OrgChart::reverse_order_iterator::operator==(const OrgChart::reverse_order_iterator& rhs) const{
                return reverse_stk.top() == rhs.reverse_stk.top();
            }
            bool OrgChart::reverse_order_iterator::operator!=(const OrgChart::reverse_order_iterator& rhs) const{
                return reverse_stk.top() != rhs.reverse_stk.top();
            }

            string& OrgChart::preorder_order_iterator::operator*() const{
                return this->stk.top()->name;
            }
            string* OrgChart::preorder_order_iterator::operator->() const{
                return &(this->stk.top()->name);
            }

            OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(){
                if(stk.empty()){
                    return *this;
                }
                for(unsigned long i = this->stk.top()->subs.size() - 1; i >= 0; i--){
                    stk.push(this->stk.top()->subs[i]);
                }
                //Node* top = stk.top(); //this is will be next iterator
                stk.pop(); //delete from stk
                //this->pointer_to_curr = top;
                return *this;
            }
            
            const OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(int){
                preorder_order_iterator tmp = *this;
                if(stk.empty()){
                    //this->pointer_to_curr = nullptr;
                    return tmp;
                }
                for(unsigned long i = this->stk.top()->subs.size() - 1; i >= 0; i--){
                    stk.push(this->stk.top()->subs[i]);
                }
                //Node* top = stk.top(); //this is will be next iterator
                stk.pop(); //delete from stk
                //this->pointer_to_curr = top;
                return tmp;
            }
            bool OrgChart::preorder_order_iterator::operator==(const preorder_order_iterator& rhs) const{
                return stk.top() == rhs.stk.top();
            }
            bool OrgChart::preorder_order_iterator::operator!=(const preorder_order_iterator& rhs) const{
                return stk.top() != rhs.stk.top();
            }


            OrgChart OrgChart::add_root(string name){
                if(this->root != nullptr){
                    throw invalid_argument("root already exists in this chart");
                }
                Node new_root = Node(name); //node with name and no subs yet
                this->root = &new_root;
                this->size = 1;
                return *this;
            }

            OrgChart OrgChart::add_sub(string higher, string lower){
                level_order_iterator it = begin_level_order();
                while(it != end_level_order()){
                    if(*it == higher){
                        break;
                    }
                }
                if(it == end_level_order()){
                    throw invalid_argument("higher person does not exist");
                }
                Node sub = Node(lower);
                Node* subptr = &sub;
                it.get_top()->subs.push_back(subptr); //add lower to the vector subs or higher
                size ++; //increase size of chart
                return *this; //return chart once updates have finished
            }

            OrgChart::level_order_iterator OrgChart::begin_level_order(){
                return level_order_iterator(this->root);
            }
            OrgChart::level_order_iterator OrgChart::end_level_order(){
                return level_order_iterator(nullptr);
            }
            OrgChart::reverse_order_iterator OrgChart::begin_reverse_order(){
                return reverse_order_iterator(this->root);
            }
            OrgChart::reverse_order_iterator OrgChart::reverse_order(){
                return reverse_order_iterator(nullptr);
            }
            OrgChart::preorder_order_iterator OrgChart::begin_preorder(){
                return preorder_order_iterator(this->root);
            }
            OrgChart::preorder_order_iterator OrgChart::end_preorder(){
                return preorder_order_iterator(nullptr);
            }
            ostream& operator<< (ostream& output, const OrgChart& o){
                return output;
            }
            OrgChart::level_order_iterator OrgChart::begin(){
                return begin_level_order();
            }
            OrgChart::level_order_iterator OrgChart::end(){
                return end_level_order();
            }
    };
