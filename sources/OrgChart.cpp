#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
namespace ariel{
            string OrgChart::level_order_iterator::operator*() const{
                return "rashi";
            }      
            OrgChart* OrgChart::level_order_iterator::operator->() const{
                OrgChart* o;
                return o;
            }  
            //to do: write function for level order
            //++i
            OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(){
                OrgChart::level_order_iterator it;
                return it;
            }
            //to do: write function for level order
            //i++
            const OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int){
                OrgChart::level_order_iterator it;
                return it;
            }
            bool OrgChart::level_order_iterator::operator==(const OrgChart::level_order_iterator& rhs) const{
                return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::level_order_iterator::operator!=(const OrgChart::level_order_iterator& rhs) const{
                return pointer_to_curr != rhs.pointer_to_curr;
            }
            OrgChart& OrgChart::reverse_order_iterator::operator*() const{
                return *pointer_to_curr;
            }
            OrgChart* OrgChart::reverse_order_iterator::operator->() const{
                return pointer_to_curr;
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
            OrgChart& OrgChart::preorder_order_iterator::operator*() const{
                return *pointer_to_curr;
            }
            OrgChart* OrgChart::preorder_order_iterator::operator->() const{
                return pointer_to_curr;
            }
            //to do: write function for preorder order ++i
            OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(){
                OrgChart::preorder_order_iterator it;
                return it;
            }
            //to do: write funtion for preorder i++
            const OrgChart::preorder_order_iterator OrgChart::preorder_order_iterator::operator++(int){
                OrgChart::preorder_order_iterator it;
                return it;
            }
            bool OrgChart::preorder_order_iterator::operator==(const preorder_order_iterator& rhs) const{
                return pointer_to_curr == rhs.pointer_to_curr;
            }
            bool OrgChart::preorder_order_iterator::operator!=(const preorder_order_iterator& rhs) const{
                return pointer_to_curr != rhs.pointer_to_curr;
            }
            int OrgChart::size(){
                return 0;
            }
            OrgChart OrgChart::add_root(string name){
                OrgChart o;
                return o;
            }
            OrgChart OrgChart::add_sub(string higher, string lower){
                OrgChart o;
                return o;               
            }
            OrgChart::level_order_iterator OrgChart::begin_level_order(){
                OrgChart::level_order_iterator it; 
                return it;
            }
            OrgChart::level_order_iterator OrgChart::end_level_order(){
                OrgChart::level_order_iterator it; 
                return it;
            }
            OrgChart::reverse_order_iterator OrgChart::begin_reverse_order(){
                OrgChart::reverse_order_iterator it; 
                return it;
            }
            OrgChart::reverse_order_iterator OrgChart::reverse_order(){
                OrgChart::reverse_order_iterator it; 
                return it;
            }
            OrgChart::preorder_order_iterator OrgChart::begin_preorder(){
                OrgChart::preorder_order_iterator it; 
                return it;
            }
            OrgChart::preorder_order_iterator OrgChart::end_preorder(){
                OrgChart::preorder_order_iterator it; 
                return it;
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