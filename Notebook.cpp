#include "Notebook.hpp"
using namespace ariel;


void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction d ,string str){
    if(column > MAX_COLUMN || str.length() > MAX_COLUMN || (column + str.length()) > MAX_COLUMN){
        __throw_invalid_argument("Make sure the column and the string less than 100.");
    }

}
string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction d ,unsigned int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || (column + length) > MAX_COLUMN){
        __throw_invalid_argument("Make sure the column and the string less than 100.");
    }
    return "notebook-a";
}
void Notebook::erase(unsigned int page, unsigned int row, unsigned int column,Direction d ,unsigned int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || (column - length) > MAX_COLUMN){
        __throw_invalid_argument("Make sure the column and the string less than 100.");
    }
}
void Notebook::show(unsigned int page){

}