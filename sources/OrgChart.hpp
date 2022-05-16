#ifndef ORGCHART_HPP
#define ORGCHART_HPP
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
namespace ariel{
    class OrgChart
    {
        private:
            string name;
            vector <OrgChart*> children;
        public:
            class level_order_iterator{
                private:
                    OrgChart* pointer_to_curr;
                    queue<OrgChart*> q;

                public:
                    string& operator*() const;
                    string* operator->() const;
                    level_order_iterator operator++();
                    const level_order_iterator operator++(int);
                    bool operator==(const level_order_iterator& rhs) const;
                    bool operator!=(const level_order_iterator& rhs) const;
            };
            class reverse_order_iterator{
                    private:
                        OrgChart* pointer_to_curr;
                    public:
                        string& operator*() const;
                        string* operator->() const;
                        reverse_order_iterator operator++();
                        const reverse_order_iterator operator++(int);
                        bool operator==(const reverse_order_iterator& rhs) const;
                        bool operator!=(const reverse_order_iterator& rhs) const;
            };
            class preorder_order_iterator{
                    private:
                        OrgChart* pointer_to_curr;
                    public:
                        string& operator*() const;
                        string* operator->() const;
                        preorder_order_iterator operator++();
                        const preorder_order_iterator operator++(int);
                        bool operator==(const preorder_order_iterator& rhs) const;
                        bool operator!=(const preorder_order_iterator& rhs) const;
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