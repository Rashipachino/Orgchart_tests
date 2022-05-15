#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
namespace ariel{
            OrgChart add_root(string name){
                OrgChart o;
                return o;
            }
            OrgChart add_sub(string higher, string lower){
                OrgChart o;
                return o;               
            }
            OrgChart::level_order_iterator begin_level_order(){
                OrgChart::level_order_iterator it; 
                return it;
            }
            OrgChart::level_order_iterator end_level_order(){
                OrgChart::level_order_iterator it; 
                return it;
            }
            OrgChart::reverse_order_iterator begin_reverse_order(){
                OrgChart::reverse_order_iterator it; 
                return it;
            }
            OrgChart::reverse_order_iterator reverse_order(){
                OrgChart::reverse_order_iterator it; 
                return it;
            }
            OrgChart::preorder_order_iterator begin_preorder(){
                OrgChart::preorder_order_iterator it; 
                return it;
            }
            OrgChart::preorder_order_iterator end_preorder(){
                OrgChart::preorder_order_iterator it; 
                return it;
            }
            ostream& operator<< (ostream& output, const OrgChart& o){
                return output;
            }
            OrgChart::level_order_iterator begin(){
                OrgChart::level_order_iterator it;
                return it;
            }
            OrgChart::level_order_iterator end(){
                OrgChart::level_order_iterator it;
                return it;
            }
    };