
#include "Notebook.hpp"
using namespace ariel;

Notebook::Notebook(){
    
}


void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction d ,string const& str){
    if(column > MAX_COLUMN || str.length() > MAX_COLUMN || row < 0 || column < 0 || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    if(d == Direction::Horizontal){
        if(column + str.length() > 100){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
        
        // for(int i = 0; i < str.length(); i++){
        //     if()
        // }

    }

}
string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction d ,unsigned int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || row < 0 || column < 0  || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    char txt[100];
    this->book[page][row] = txt;
    return "notebook-a";
}
void Notebook::erase(unsigned int page, unsigned int row, unsigned int column,Direction d ,unsigned int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || row < 0 || column < 0  || page < 0 || (row - length) < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
}
void Notebook::show(unsigned int page){

}