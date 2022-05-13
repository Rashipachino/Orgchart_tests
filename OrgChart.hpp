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
        public:
            class iterator{
                private:
                    OrgChart* pointer_to_root;
                public:
                    iterator(OrgChart* ptr = nullptr)
                            : pointer_to_root(ptr){

                            }
                    

            }
            void add_root(string name);
            void add_sub(string higher, string lower);

    };
}
#endif