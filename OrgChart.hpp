#ifndef ORGCHART_HPP
#define ORGCHART_HPP
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
    class OrgChart
    {
        private:
            string name;
            vector <OrgChart*> children;
            static int size_of_tree;
        public:
            int size(){
                return 0;
            }
            class level_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                public:
                    level_order_iterator(OrgChart* ptr = nullptr)
                            : pointer_to_curr(ptr){
                            }
                    OrgChart& operator*() const{
                        return *pointer_to_curr;
                    }
                    OrgChart* operator->() const;

                    level_order_iterator& operator++();
                        //to do: write function for level order
                        //++i
        
                    const level_order_iterator operator++(int);
                        //to do: write function for level order
                        //i++
                    
                    bool operator==(const level_order_iterator& rhs) const{
                        return pointer_to_curr == rhs.pointer_to_curr;
                    }
                    bool operator!=(const level_order_iterator& rhs) const{
                        return pointer_to_curr != rhs.pointer_to_curr;
                    }
                    int size(){
                        return size_of_tree;
                    }
        };
        class reverse_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                public:
                    reverse_order_iterator(OrgChart* ptr = nullptr)
                            : pointer_to_curr(ptr){
                            }
                    OrgChart& operator*() const{
                        return *pointer_to_curr;
                    }
                    OrgChart* operator->() const{
                        return pointer_to_curr;
                    }
                    reverse_order_iterator& operator++();
                        //to do: write function for reverse order
                        //++i
                    
                    const reverse_order_iterator operator++(int);
                        //to do: write function for reverse order
                        //i++
                    
                    bool operator==(const reverse_order_iterator& rhs) const{
                        return pointer_to_curr == rhs.pointer_to_curr;
                    }
                    bool operator!=(const reverse_order_iterator& rhs) const{
                        return pointer_to_curr != rhs.pointer_to_curr;
                    }
                    int size(){
                        return size_of_tree;
                    }
        };
        class preorder_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                public:
                    preorder_order_iterator(OrgChart* ptr = nullptr)
                            : pointer_to_curr(ptr){
                            }
                    OrgChart& operator*() const{
                        return *pointer_to_curr;
                    }
                    OrgChart* operator->() const{
                        return pointer_to_curr;
                    }
                    preorder_order_iterator& operator++();
                        //to do: write function for preorder order
                        //++i
                    
                    const preorder_order_iterator operator++(int);
                        //to do: write function for preorder order
                        //i++
                    
                    bool operator==(const preorder_order_iterator& rhs) const{
                        return pointer_to_curr == rhs.pointer_to_curr;
                    }
                    bool operator!=(const preorder_order_iterator& rhs) const{
                        return pointer_to_curr != rhs.pointer_to_curr;
                    }
                    int size(){
                        return size_of_tree;
                    }
        };
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