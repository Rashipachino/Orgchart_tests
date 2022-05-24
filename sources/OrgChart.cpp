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
                if((this->q.empty() && !rhs.q.empty()) || (!this->q.empty() && rhs.q.empty())){
                    return false;
                }
                if(this->q.empty() && rhs.q.empty()){
                    return true;
                }
                return this->q.front() == rhs.q.front();
                //return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::level_order_iterator::operator!=(const OrgChart::level_order_iterator& rhs) const{
                if(!this->q.empty() && rhs.q.empty()){
                    return true;
                }
                if(this->q.empty() && rhs.q.empty()){
                    return false;
                }
                return this->q.front() != rhs.q.front();  
            }
            OrgChart::level_order_iterator& OrgChart::level_order_iterator::operator=(const OrgChart::level_order_iterator& other){
                        if(this==&other){
                            return *this;
                        }
                        this->q = other.q;
                        return *this;
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
                if((this->reverse_stk.empty() && !rhs.reverse_stk.empty()) || (!this->reverse_stk.empty() && rhs.reverse_stk.empty())){
                    return false;
                }
                if(this->reverse_stk.empty() && rhs.reverse_stk.empty()){
                    return true;
                }
                return this->reverse_stk.top() == rhs.reverse_stk.top();
            }

            bool OrgChart::reverse_order_iterator::operator!=(const OrgChart::reverse_order_iterator& rhs) const{
                if(!this->reverse_stk.empty() && rhs.reverse_stk.empty()){
                    return true;
                }
                if(this->reverse_stk.empty() && rhs.reverse_stk.empty()){
                    return false;
                }
                return this->reverse_stk.top() != rhs.reverse_stk.top(); 
            }
            OrgChart::reverse_order_iterator& OrgChart::reverse_order_iterator::operator=(const reverse_order_iterator& other){
                if(this==&other){
                    return *this;
                }
                this->reverse_stk = other.reverse_stk;
                return *this;
            }

            string& OrgChart::preorder_order_iterator::operator*() const{
                return this->stk.top()->name;
            }
            string* OrgChart::preorder_order_iterator::operator->() const{
                return &(this->stk.top()->name);
            }

            OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(){
                cout << "++" << endl;
                if(stk.empty()){
                    return *this;
                }
                Node* top = new Node(stk.top()->name, stk.top()->subs);
                stk.pop(); //delete from stk
                if(!(top->subs.empty())){ //sub exists
                    for(unsigned long i = top->subs.size() - 1; i >= 0; i--){
                        stk.push(top->subs[i]);
                        cout << "after push top: " << stk.top()->name << endl;
                    }
                    cout << "whyyyyy" << endl;
                }
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
                if((this->stk.empty() && !rhs.stk.empty()) || (!this->stk.empty() && rhs.stk.empty())){
                    return false;
                }
                if(this->stk.empty() && rhs.stk.empty()){
                    return true;
                }
                return this->stk.top() == rhs.stk.top();
            }

            bool OrgChart::preorder_order_iterator::operator!=(const preorder_order_iterator& rhs) const{
                cout << "!=" << endl;
               if(!this->stk.empty() && rhs.stk.empty()){
                   cout << "inside if" << endl;
                    return true;
                }
                if(this->stk.empty() && rhs.stk.empty()){
                    cout << "here?" << endl;
                    return false;
                }
                return this->stk.top() != rhs.stk.top(); 
            }
            OrgChart::preorder_order_iterator& OrgChart::preorder_order_iterator::operator=(const preorder_order_iterator& other){
                if(this==&other){
                    return *this;
                }
                this->stk = other.stk;
                return *this;
            }


            OrgChart OrgChart::add_root(string name){
                if(this->root != nullptr){
                    throw invalid_argument("root already exists in this chart");
                }
                Node* new_root = new Node(name); //node with name and no subs yet
                this->root = new_root; 
                this->size = 1;
                return *this;
            }

            OrgChart OrgChart::add_sub(string higher, string lower){
                level_order_iterator it = begin_level_order();
                while(it != end_level_order()){
                    if(*it == higher){
                        break;
                    }
                    it++;
                }
                if(it == end_level_order()){
                    throw invalid_argument("higher person does not exist");
                }
                Node* sub =  new Node(lower);
                it.get_top()->subs.push_back(sub); //add lower to the vector subs or higher
                size ++; //increase size of chart
                return *this; //return chart once updates have finished
            }

            OrgChart::level_order_iterator OrgChart::begin_level_order() const{
                return level_order_iterator(this->root);
            }
            OrgChart::level_order_iterator OrgChart::end_level_order() const{
                return level_order_iterator(nullptr);
            }
            OrgChart::reverse_order_iterator OrgChart::begin_reverse_order(){
                return reverse_order_iterator(this->root);
            }
            OrgChart::reverse_order_iterator OrgChart::reverse_order(){
                return reverse_order_iterator(nullptr);
            }
            OrgChart::preorder_order_iterator OrgChart::begin_preorder(){
                cout << "begin_preorder" << endl;
                return preorder_order_iterator(this->root);
            }
            OrgChart::preorder_order_iterator OrgChart::end_preorder(){
                return preorder_order_iterator(nullptr);
            }
            std::ostream& operator<< (std::ostream& output, const OrgChart& o){
                output << o.root;
                for(unsigned long i = 0; i < o.root->subs.size(); i++){
                    output << "|     "; 
                }
                for(auto it = o.begin_level_order(); it != o.end_level_order(); it++){
                    output << *it;
                    output << "\n";
                    for(unsigned long i = 0; i < it.get_top()->subs.size(); i++){
                    output << "|     "; 
                    }
                    output << "\n";
                }
                return output;
            }
            OrgChart::level_order_iterator OrgChart::begin(){
                return begin_level_order();
            }
            OrgChart::level_order_iterator OrgChart::end(){
                return end_level_order();
            }
    };
