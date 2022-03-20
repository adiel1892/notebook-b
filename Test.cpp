#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <algorithm>
#include <string>

using namespace ariel;

TEST_CASE("Good Notebook"){
    // fir~t line of notebook
    // i__~c_________________
    // '__~p_________________
    // m__~p_________________
    //  __~ _________________
    // w___v_________________
    // r___e_________________
    // i___r_________________
    // t___t_________________
    // i___i_________________
    // n___c_________________
    // g___a_________________
    //  ___l_________________
    // v_____________________
    // e_____________________
    // r_____________________
    // t_____________________
    // i_____________________
    // c_____________________
    // a_____________________
    // l_____________________
    Notebook a;
    CHECK(a.read(0,0,0,Direction::Horizontal,22) == "______________________");
    a.write(0,0,0,Direction::Horizontal,"first line of notebook");    
    CHECK(a.read(0,0,0,Direction::Horizontal,22) == "first line of notebook");
    CHECK(a.read(0,0,0,Direction::Horizontal,25) == "first line of notebook___");
    a.erase(0,0,0,Direction::Horizontal,6);
    CHECK(a.read(0,0,0,Direction::Horizontal,25) == "~~~~~~line~~~~notebook___");
    a.erase(0,0,10,Direction::Horizontal,4);
    a.write(0,1,0,Direction::Vertical,"i'm writing vertival"); 
    CHECK(a.read(0,0,0,Direction::Vertical,22) == "_i'm writing vertival_");
    CHECK(a.read(0,1,0,Direction::Horizontal,5) == "i____");
    CHECK(a.read(0,3,0,Direction::Horizontal,5) == "m____");
    CHECK(a.read(0,12,0,Direction::Horizontal,5) == " ____");
    a.write(0,1,4,Direction::Vertical,"cpp vertical"); 
    CHECK(a.read(0,1,0,Direction::Horizontal,5) == "i___c");
    a.erase(0,0,3,Direction::Vertical,5);
    CHECK(a.read(0,0,3,Direction::Vertical,5) == "~~~~~");
    CHECK(a.read(0,1,0,Direction::Horizontal,5) == "i__~c");






}

TEST_CASE("writing on a writen or deleaten place is illegal"){
    Notebook a;
    CHECK(a.read(0,0,0,Direction::Horizontal,22) == "______________________");
    a.write(0,0,0,Direction::Horizontal,"first line of notebook"); 
    CHECK_THROWS(a.write(0,0,10, Direction::Vertical , "checking"));
    CHECK_THROWS(a.write(0,0,3, Direction::Vertical , "checking"));
    CHECK_THROWS(a.write(0,0,6, Direction::Vertical , "checking"));
    CHECK_THROWS(a.write(0,0,2, Direction::Vertical , "checking"));
    CHECK_THROWS(a.write(0,0,0, Direction::Vertical , "checking"));
    CHECK_THROWS(a.write(0,0,8, Direction::Vertical , "checking"));
    a.write(0,4,0,Direction::Horizontal,"second line of notebook"); 
    CHECK_THROWS(a.write(0,3,0, Direction::Vertical , "aba"));
    CHECK_THROWS(a.write(0,3,10, Direction::Vertical , "aba"));
    CHECK_THROWS(a.write(0,3,4, Direction::Vertical , "aba"));
    CHECK_THROWS(a.write(0,3,6, Direction::Vertical , "aba"));
    CHECK_THROWS(a.write(0,3,5, Direction::Vertical , "aba"));

}