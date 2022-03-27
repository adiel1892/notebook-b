

#include "Notebook.hpp"
using namespace ariel;

Notebook::Notebook(){
    
}

void Notebook::makeRow(int page, int row){
    char *txt = new char[MAX_COLUMN];
    for(int i = 0; i < MAX_COLUMN; i++){
        txt[i] = '_';
    }
    this->book[page][row] = txt;
}

void Notebook::hasMade(int page, int row){
    try{
        this->book.at(page).at(row);
    }catch(exception e){
        makeRow(page,row);
    }
}

void Notebook::checkInput(int page, int row, int column, string const& str){
    if(column > MAX_COLUMN - 1 || row < 0 || column < 0 || page < 0 || str.length() < 0){
        __throw_invalid_argument("invalid page , row , column str.length. - write");
    }
    if(str.find('~') != std::string::npos){
        __throw_invalid_argument("Can't write ~");
    }
    for(unsigned int i = 0; i < str.length(); i++){
        if(str[i] < LIML || str[i] > LIMR){
            __throw_invalid_argument("invalid char - write");
        }
    }
    if(str.find('\n') != std::string::npos){
        __throw_invalid_argument("Can't write new line");
    }
}
void Notebook::write(int page, int row,int column, Direction d ,string const& str){
    checkInput(page,row,column,str);
    
    hasMade(page,row);
    int index = 0;
    unsigned int row_u = (unsigned int)(row);
    unsigned int column_u = (unsigned int)(column);

    if(d == Direction::Horizontal){
        if(column_u + str.length() > MAX_COLUMN || str.length() > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100. - write");
        }
        // checking if i can write on the requested place
        for(unsigned int i = column_u; i < column_u + str.length(); i++){
            if(this->book.at(page).at(row)[i] != '_'){
                __throw_invalid_argument("Can't write on a written or deleten place. - write");
            }
        }
        
        for(unsigned int i = column_u; i < column_u + str.length(); i++){
            unsigned int index = (unsigned int)(i - column_u);
            this->book.at(page).at(row)[i] = str[index];
            index++;
        }
    }else if(d == Direction::Vertical){
        int len = row + (int)(str.length());
        for(int i = row; i < len; i++){
            hasMade(page, i);
        }
        for(unsigned int i = row_u; i < row_u + str.length(); i++){
            if(this->book.at(page).at((int)i)[column] != '_'){
                __throw_invalid_argument("Can't write on a written or deleten place - write.");
            }
        }
        // if the place is good so we can write
        for(unsigned int i = row_u; i < row_u + str.length(); i++){
            unsigned int index = (unsigned int)(i - row_u);
            this->book.at(page).at((int)i)[column] = str[index];
            index++;
        }
    }
}
string Notebook::read(int page, int row,int column, Direction d , int length){
    if(column > MAX_COLUMN - 1|| row < 0 || column < 0  || page < 0 || length < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. - read");
    }
    hasMade(page,row);
    string output;
    if(d == Direction::Horizontal){
        if(column + length > MAX_COLUMN|| length > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100. - read");
        }
        for(int i = column; i < column + length; i++){
            output +=  this->book.at(page).at(row)[i];
        }
    }else if(d == Direction::Vertical){
        int len = row + length;
        for(int i = row; i < len; i++){
            hasMade(page, i);
        }
        for(int i = row; i < row + length; i++){
            output +=  this->book.at(page).at(i)[column];
        }
    }
    return output;
}
void Notebook::erase(int page,int row,int column,Direction d ,int length){
    if(column > MAX_COLUMN - 1 || row < 0 || column < 0  || page < 0 || length < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. - erase");
    }
    hasMade(page,row);
    if(d == Direction::Horizontal){
        if(column + length > MAX_COLUMN - 1 || length > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100. - erase");
        }
        int index = 0;
        for(int i = column; i < column + length; i++){
            this->book.at(page).at(row)[i] = '~';
            index++;
        }
    }else if(d == Direction::Vertical){
        int len = row + length;
        for(int i = row; i < len; i++){
            hasMade(page, i);
        }
        // if the place is good so we can write
        for(int i = row; i < row + length; i++){
            int index = 0;
            this->book.at(page).at(i)[column] = '~';
            index++;
        }
    }
}
void Notebook::show(int page){
    int line = 0;
    while(line < MAX_COLUMN){
        hasMade(page, line);
        cout << read(page, line , 0 , Direction::Horizontal , MAX_COLUMN) << "\n";
        line++;
    }
}