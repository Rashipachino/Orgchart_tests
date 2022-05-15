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
            class level_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                public:
                    string operator*() const;
                    OrgChart* operator->() const;
                    level_order_iterator operator++();
                        //to do: write function for level order
                        //++i
        
                    const level_order_iterator operator++(int);
                        //to do: write function for level order
                        //i++
                    bool operator==(const level_order_iterator& rhs) const;
                    bool operator!=(const level_order_iterator& rhs) const;
        };
        class reverse_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                public:
                    OrgChart& operator*() const;
                    OrgChart* operator->() const;
                    reverse_order_iterator operator++();
                        //to do: write function for reverse order
                        //++i
                    const reverse_order_iterator operator++(int);
                        //to do: write function for reverse order
                        //i++
                    bool operator==(const reverse_order_iterator& rhs) const;
                    bool operator!=(const reverse_order_iterator& rhs) const;
        };
        class preorder_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                public:
                    OrgChart& operator*() const;
                    OrgChart* operator->() const;
                    preorder_order_iterator operator++();
                        //to do: write function for preorder order
                        //++i
                    const preorder_order_iterator operator++(int);
                        //to do: write function for preorder order
                        //i++
                    bool operator==(const preorder_order_iterator& rhs) const;
                    bool operator!=(const preorder_order_iterator& rhs) const;
        };
            int size();
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