
#include "Notebook.hpp"
using namespace ariel;

Notebook::Notebook(){
    
}




void Notebook::write(int page, int row,int column, Direction d ,string const& str){
    if(column > MAX_COLUMN || str.length() > MAX_COLUMN || row < 0 || column < 0 || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    if(d == Direction::Horizontal){
        if(column + str.length() > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
       

        
        // for(int i = 0; i < str.length(); i++){
        //     if()
        // }

    }

}
string Notebook::read(int page, int row,int column, Direction d , int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || row < 0 || column < 0  || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    string output;
    if(d == Direction::Horizontal){
        if(column + length > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
        for(int i = column; i < column + length; i++){
            output +=  this->book.at(page).at(row)[i];
        }
    }else if(d == Direction::Vertical){
        for(int i = row; i < row + length; i++){
            output +=  this->book.at(page).at(i)[column];
        }
    }
    return output;
}
void Notebook::erase(int page,int row,int column,Direction d ,int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || row < 0 || column < 0  || page < 0 || (row - length) < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
}
void Notebook::show(int page){

}