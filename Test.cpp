#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Constructing OrgChart"){
    OrgChart org;
    org.add_root("andy");
    org.add_sub("andy", "bert");
    org.add_sub("beth", "carry");
    CHECK_NOTHROW(org.add_sub("andy", "beth"));
    CHECK_THROWS(org.add_root("liam"));
    CHECK_THROWS(org.add_sub("sam", "pearl"));
    CHECK_NOTHROW(org.add_sub("beth", "jon"));
}

TEST_CASE("Level Order"){
    OrgChart fam;
    fam.add_root("Bubby");
    fam.add_sub("Bubby","Uncle Mel");
    fam.add_sub("Bubby","Abba");
    fam.add_sub("Bubby","Uncle Seth");
    fam.add_sub("Bubby","Aunt Sue");
    fam.add_sub("Abba", "Rashi");
    fam.add_sub("Rashi", "Mocha");
    auto it = fam.begin_level_order();
    CHECK(*it == "Bubby");
    CHECK(it->substr(0, 5) == "Bubby");
    it++;
    CHECK(*it == "Uncle Mel");
    CHECK(it->substr(0, 5) == "Uncle Mel");
    it++;
    CHECK(*it == "Abba");
    CHECK(it->substr(0, 5) == "Abba");
    it++;
    CHECK(*it == "Uncle Seth");
    CHECK(it->substr(0, 5) == "Uncle Seth");
    it++;
    CHECK(*it == "Aunt Sue");
    CHECK(it->substr(0, 5) == "Aunt Sue");
    it++;
    CHECK(*it == "Rashi");
    CHECK(it->substr(0, 5) == "Rashi");
    it++;
    CHECK(*it == "Mocha");
    CHECK(it->substr(0, 5) == "Mocha");
    it++;
    CHECK(it == fam.end_level_order());
}

TEST_CASE("Reverse Order"){
    OrgChart school;
    school.add_root("Principal");
    school.add_sub("Principal", "Math Dep. Head");
    school.add_sub("Principal", "English Dep. Head");
    school.add_sub("Math Dep. Head", "Ms Smith");
    school.add_sub("Math Dep. Head", "Ms Raulston");
    school.add_sub("English Dep. Head", "Ms Roe");
    school.add_sub("Ms Roe", "student 1");
    school.add_sub("Ms Roe", "student 2");
    school.add_sub("Ms Roe", "student 3");
    auto it = school.begin_reverse_order();
    CHECK(*it == "student 1");
    CHECK(it->substr(0, 5) == "student 1");
    it++;
    CHECK(*it == "student 2");
    CHECK(it->substr(0, 5) == "student 2");
    it++;
    CHECK(*it == "student 3");
    CHECK(it->substr(0, 5) == "student 3");
    it++;
    CHECK(*it == "Ms Smith");
    CHECK(it->substr(0, 5) == "Ms Smith");
    it++;
    CHECK(*it == "Ms Raulston");
    CHECK(it->substr(0, 5) == "Ms Raulston");
    it++;
    CHECK(*it == "Ms Roe");
    CHECK(it->substr(0, 5) == "Ms Roe");
    it++;
    CHECK(*it == "Math Dep. Head");
    CHECK(it->substr(0, 5) == "Math Dep. Head");
    it++;
    CHECK(*it == "English Dep. Head");
    CHECK(it->substr(0, 5) == "English Dep. Head");
    it++;
    CHECK(*it == "Principal");
    CHECK(it->substr(0, 5) == "Principal");
    it++;
    CHECK(it == school.reverse_order());
}

TEST_CASE("PreOrder"){
    // OrgChart bakery;
    // bakery.add_root("Owner");
    // bakery.add_sub("Owner", "Manager");
    // bakery.add_sub("Manager1", "Cashier");
    // bakery.add_sub("Manager1", "Busboy");
    // bakery.add_sub("Owner", "Manager2");
    // bakery.add_sub("Cashier", "new employee");
    OrgChart organization;
    organization.add_root("CEO")
      .add_sub("CEO", "CTO")  
      .add_sub("CEO", "CFO")        
      .add_sub("CEO", "COO")        
      .add_sub("CTO", "VP_SW") 
      .add_sub("COO", "VP_BI");  
      auto it = organization.begin_preorder();
    CHECK(*it == "CEO");
    CHECK(it->substr(0, 5) == "CEO");
    it++;
    CHECK(*it == "CTO");
    CHECK(it->substr(0, 5) == "CTO");
    it++;
    CHECK(*it == "VP_SW");
    CHECK(it->substr(0, 5) == "VP_SW");
    it++;
    CHECK(*it == "CFO");
    CHECK(it->substr(0, 5) == "CFO");
    it++;
    CHECK(*it == "COO");
    CHECK(it->substr(0, 5) == "COO");
    it++;
    CHECK(*it == "VP_BI");
    CHECK(it->substr(0, 5) == "VP_BI");
    it++;
    CHECK(it == organization.end_preorder());
}

