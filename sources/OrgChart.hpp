#ifndef ORGCHART_HPP
#define ORGCHART_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
namespace ariel{
    class OrgChart
    {
        private:
            struct Node{
                    string name;
                    vector <Node*> subs;
                    Node(const string& name){ //constructor for node
                        this->name = name;
                    }
                }; 
                // : name(name){
                //     }
                // };
            //fields
            Node* root; //head of OrgChart
            int size;

        public:
            class level_order_iterator{
                private:
                    //Node* pointer_to_curr;
                    queue <Node*> q;
                    Node* end_p;
                public:
                    level_order_iterator(Node* ptr){
                        if(ptr != nullptr){
                            q.push(ptr);
                        }
                        
                    }
                    level_order_iterator(const level_order_iterator& other){
                        this->q = other.q;
                    }
                    level_order_iterator& operator=(const level_order_iterator& other){
                        if(this==&other){
                            return *this;
                        }
                        this->q = other.q;
                        return *this;
                    }
                    // ~level_order_iterator(){
                    //     while(!q.empty()){
                    //         q.pop();
                    //     }
                    // }
                    Node* get_top(){
                        return this->q.front();
                    }


                    
                    // Node* get_curr(){
                    //     return this->pointer_to_curr;
                    // }
                    // void set_curr(Node* n){
                    //     this->pointer_to_curr = n;
                    // }
                    string& operator*() const;
                    string* operator->() const;
                    level_order_iterator operator++();
                    const level_order_iterator operator++(int);
                    bool operator==(const level_order_iterator& rhs) const;
                    bool operator!=(const level_order_iterator& rhs) const;
            };
            class reverse_order_iterator{
                    private:
                        //Node* pointer_to_curr;
                        stack<Node*> reverse_stk;
                        queue<Node*> reverse_q;
                    public:
                        reverse_order_iterator(Node* ptr = nullptr){
                            reverse_q.push(ptr);
                            while(!reverse_q.empty()){
                                Node* top = reverse_q.front();
                                reverse_stk.push(top);
                                reverse_q.pop();
                                for(unsigned long i = top->subs.size() - 1; i >=0; i--){
                                    reverse_q.push(top->subs[i]);
                                }
                            }
                        }
                        // stack<Node*> OrgChart::reverse_order_iterator::get_stk(){
                        //     return this->reverse_stk;
                        // }
                        // queue<Node*> OrgChart::reverse_order_iterator::get_q(){
                        //     return this->reverse_q;
                        // }
                        // // Node* get_curr(){
                        //     return this->pointer_to_curr;
                        // }
                        // void set_curr(Node* new_curr){
                        //     this->pointer_to_curr = new_curr;
                        // }                       
                        string& operator*() const;
                        string* operator->() const;
                        reverse_order_iterator operator++();
                        const reverse_order_iterator operator++(int);
                        bool operator==(const reverse_order_iterator& rhs) const;
                        bool operator!=(const reverse_order_iterator& rhs) const;
            };
            class preorder_order_iterator{
                    private:
                        //Node* pointer_to_curr;
                        stack<Node*> stk;
                    public:
                        preorder_order_iterator(Node* ptr = nullptr){
                            stk.push(ptr);
                        }
                        preorder_order_iterator(const preorder_order_iterator& other){
                            this->stk = other.stk;
                        }
                        preorder_order_iterator& operator=(const preorder_order_iterator& other){
                            if(this==&other){
                                return *this;
                            }
                            this->stk = other.stk;
                            return *this;
                        }
                        // ~preorder_order_iterator(){
                        //     while(!stk.empty()){
                        //         stk.pop();
                        //     }
                        // }
                        Node* get_top(){
                            return stk.top();
                        }



                        string& operator*() const;
                        string* operator->() const;
                        preorder_order_iterator operator++();
                        const preorder_order_iterator operator++(int);
                        bool operator==(const preorder_order_iterator& rhs) const;
                        bool operator!=(const preorder_order_iterator& rhs) const;
            };
            OrgChart():
                root(nullptr),
                size(0)
                {}
            // OrgChart(const OrgChart& other){
            //         root = other.root;
            //         size = other.size;
            //     }

            // OrgChart& operator=(const OrgChart& other){
            //     if(this==&other)
            //         return *this;
            //     if(this->root !=)
            // }


            

                
            // {
            //     this->root = nullptr;
            //     this->size = 0;
            // }
            ~OrgChart(){
                queue<Node*> del_q;
                del_q.push(root);
                while(!del_q.empty()){
                    Node* top = del_q.front();
                    for(unsigned long i = 0; i < top->subs.size(); i++){
                        del_q.push(top->subs[i]);
                    }
                    del_q.pop();
                    delete top;
                }
            }
            OrgChart add_root(string name);
            OrgChart add_sub(string higher, string lower);
            level_order_iterator begin_level_order() const;
            level_order_iterator end_level_order() const;
            reverse_order_iterator begin_reverse_order();
            reverse_order_iterator reverse_order();
            preorder_order_iterator begin_preorder();
            preorder_order_iterator end_preorder();
            friend ostream& operator<< (ostream& output, const OrgChart& o);
            level_order_iterator begin();
            level_order_iterator end();
    };
}
#endif