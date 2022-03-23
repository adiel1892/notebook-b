
#include "Notebook.hpp"
using namespace ariel;

Notebook::Notebook(){
    
}

// void Notebook::makeRow(int page, int row){


// }



void Notebook::write(int page, int row,int column, Direction d ,string const& str){
    if(column > MAX_COLUMN || str.length() > MAX_COLUMN || row < 0 || column < 0 || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    if(d == Direction::Horizontal){
        if(column + str.length() > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
        // checking if i can write on the requested place
        for(int i = column; i < column + str.length(); i++){
            if(this->book.at(page).at(row)[i] != '_'){
                __throw_invalid_argument("Can't write on a written or deleten place.");
            }
        }
        // if the place is good so we can write
        int index = 0;
        for(int i = column; i < column + str.length(); i++){
            this->book.at(page).at(row)[i] = str[index];
            index++;
        }
    }else if(d == Direction::Vertical){
        // checking if i can write on the requested place
        for(int i = row; i < row + str.length(); i++){
            if(this->book.at(page).at(i)[column] != '_'){
                __throw_invalid_argument("Can't write on a written or deleten place.");
            }
        }
        // if the place is good so we can write
        for(int i = row; i < row + str.length(); i++){
            int index = 0;
            this->book.at(page).at(i)[column] = str[index];
            index++;
        }

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
    if(d == Direction::Horizontal){
        if(column + length > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
        int index = 0;
        for(int i = column; i < column + length; i++){
            this->book.at(page).at(row)[i] = '~';
            index++;
        }
    }else if(d == Direction::Vertical){
        // if the place is good so we can write
        for(int i = row; i < row + length; i++){
            int index = 0;
            this->book.at(page).at(i)[column] = '~';
            index++;
        }

    }
}
void Notebook::show(int page){

}