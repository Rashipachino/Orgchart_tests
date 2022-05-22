#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
namespace ariel{
            string& OrgChart::level_order_iterator::operator*() const{
                return this->pointer_to_curr->name;
            }      
            string* OrgChart::level_order_iterator::operator->() const{
                return &(this->pointer_to_curr->name);
            }  
            //to do: write function for level order
            //++i
            OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(){
                q.push(this->pointer_to_curr);
                if(q.empty()){ //end of chart
                    this->pointer_to_curr = nullptr;
                    return *this;
                }
                for(unsigned long i = 0; i < this->pointer_to_curr->subs.size(); i++){
                    q.push(this->pointer_to_curr->subs[i]); //push all subs into queue
                }
                Node* top = q.front(); //this is will be next iterator
                q.pop(); //delete from queue
                this->pointer_to_curr = top;
                return *this;
            }
            //to do: write function for level order
            //i++
            const OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int){
                level_order_iterator tmp= *this;
                if(q.empty()){ //end of chart
                    this->pointer_to_curr == nullptr;
                    return tmp;
                }
                for(unsigned long i = 0; i < this->pointer_to_curr->subs.size(); i++){
                    q.push(this->pointer_to_curr->subs[i]); //push all subs into queue
                }
                Node* top = q.front(); //this will be the next iterator
                q.pop(); //delete from queue
                this->pointer_to_curr = top;
			    return tmp;
            }
            bool OrgChart::level_order_iterator::operator==(const OrgChart::level_order_iterator& rhs) const{
                return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::level_order_iterator::operator!=(const OrgChart::level_order_iterator& rhs) const{
                return pointer_to_curr != rhs.pointer_to_curr;
            }


            string& OrgChart::reverse_order_iterator::operator*() const{
                return this->pointer_to_curr->name;
            }
            string* OrgChart::reverse_order_iterator::operator->() const{
                return &(this->pointer_to_curr->name);
            }
            //to do: write function for reverse order
            //++i
            OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(){
                OrgChart::reverse_order_iterator it;
                return it;
            }
            //to do: write function for reverse order
            //i++
            const OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(int){
                OrgChart::reverse_order_iterator it;
                return it;                
            }
            bool OrgChart::reverse_order_iterator::operator==(const OrgChart::reverse_order_iterator& rhs) const{
                return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::reverse_order_iterator::operator!=(const OrgChart::reverse_order_iterator& rhs) const{
                return pointer_to_curr != rhs.pointer_to_curr;
            }

            string& OrgChart::preorder_order_iterator::operator*() const{
                return this->pointer_to_curr->name;
            }
            string* OrgChart::preorder_order_iterator::operator->() const{
                return &(this->pointer_to_curr->name);
            }

            OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(){
                if(stk.empty()){
                    this->pointer_to_curr = nullptr;
                    return *this;
                }
                for(unsigned long i = this->pointer_to_curr->subs.size() - 1; i >= 0; i--){
                    stk.push(this->pointer_to_curr->subs[i]);
                }
                Node* top = stk.top(); //this is will be next iterator
                stk.pop(); //delete from stk
                this->pointer_to_curr = top;
                return *this;
            }
            
            const OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(int){
                preorder_order_iterator tmp = *this;
                if(stk.empty()){
                    this->pointer_to_curr = nullptr;
                    return tmp;
                }
                for(unsigned long i = this->pointer_to_curr->subs.size() - 1; i >= 0; i--){
                    stk.push(this->pointer_to_curr->subs[i]);
                }
                Node* top = stk.top(); //this is will be next iterator
                stk.pop(); //delete from stk
                this->pointer_to_curr = top;
                return tmp;
            }
            bool OrgChart::preorder_order_iterator::operator==(const preorder_order_iterator& rhs) const{
                return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::preorder_order_iterator::operator!=(const preorder_order_iterator& rhs) const{
                return pointer_to_curr != rhs.pointer_to_curr;
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
                Node* sub = &(Node(lower));
                it.get_curr()->subs.push_back(sub); //add lower to the vector subs or higher
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
                reverse_order_iterator rit = reverse_order_iterator(nullptr);
                rit.get_q().push(this->root);
                while(!rit.get_q().empty()){
                    Node* top = rit.get_q().front();
                    rit.get_stk().push(top); //push the top from q to stack
                    rit.get_q().pop(); //pop top
                    for(unsigned long i = top->subs.size() - 1; i >=0; i--){
                        rit.get_q().push(top->subs[i]);
                    }
                }
                rit.set_curr(rit.get_stk().top()); 
                rit.get_stk().pop(); //pop the value
                return rit;
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
                OrgChart::level_order_iterator it;
                return it;
            }
            OrgChart::level_order_iterator OrgChart::end(){
                OrgChart::level_order_iterator it;
                return it;
            }
    };
