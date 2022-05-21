#ifndef ORGCHART_HPP
#define ORGCHART_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
namespace ariel{
    struct Node{
                string name;
                vector <Node*> subs;
                Node(const string& name) //constructor for Node
			: name(name){
		        }
            };
    class OrgChart
    {
        private:
            //fields
            Node* root; //head of OrgChart
            int size;

        public:
            class level_order_iterator{
                private:
                    Node* pointer_to_curr;
                    queue <Node*> q;
                public:
                    level_order_iterator(Node* ptr = nullptr)
                        : pointer_to_curr(ptr){
                    }
                    Node* get_curr(){
                        return this->pointer_to_curr;
                    }
                    void set_curr(Node* n){
                        this->pointer_to_curr = n;
                    }
                    string& operator*() const;
                    string* operator->() const;
                    level_order_iterator operator++();
                    const level_order_iterator operator++(int);
                    bool operator==(const level_order_iterator& rhs) const;
                    bool operator!=(const level_order_iterator& rhs) const;
            };
            class reverse_order_iterator{
                    private:
                        Node* pointer_to_curr;
                        //queue<OrgChart*> q;
                    public:
                    reverse_order_iterator(Node* ptr = nullptr)
                        : pointer_to_curr(ptr) {
                    }
                        string& operator*() const;
                        string* operator->() const;
                        reverse_order_iterator operator++();
                        const reverse_order_iterator operator++(int);
                        bool operator==(const reverse_order_iterator& rhs) const;
                        bool operator!=(const reverse_order_iterator& rhs) const;
            };
            class preorder_order_iterator{
                    private:
                        Node* pointer_to_curr;
                        stack<Node*> stk;
                    public:
                        preorder_order_iterator(Node* ptr = nullptr)
                            : pointer_to_curr(ptr) {
                        }
                        string& operator*() const;
                        string* operator->() const;
                        preorder_order_iterator operator++();
                        const preorder_order_iterator operator++(int);
                        bool operator==(const preorder_order_iterator& rhs) const;
                        bool operator!=(const preorder_order_iterator& rhs) const;
            };
            OrgChart(){
                this->root = nullptr;
                this->size = 0;
            }
            OrgChart add_root(string name);
            OrgChart add_sub(string higher, string lower);
            level_order_iterator begin_level_order();
            level_order_iterator end_level_order();
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