
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

void Notebook::write(int page, int row,int column, Direction d ,string const& str){
    if(column > MAX_COLUMN || str.length() > MAX_COLUMN || row < 0 || column < 0 || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    if(str.find('~') != std::string::npos){
        __throw_invalid_argument("Can't write ~");
    }
    hasMade(page,row);
    int index = 0;
    unsigned int row_u = (unsigned int)(row);
    unsigned int column_u = (unsigned int)(column);

    if(d == Direction::Horizontal){
        if(column_u + str.length() > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
        // checking if i can write on the requested place
        for(unsigned int i = column_u; i < column_u + str.length(); i++){
            if(this->book.at(page).at(row)[i] != '_'){
                __throw_invalid_argument("Can't write on a written or deleten place.");
            }
        }
        
        for(unsigned int i = column_u; i < column_u + str.length(); i++){
            unsigned int index = (unsigned int)(i - column_u);
            this->book.at(page).at(row)[i] = str[index];
            index++;
        }
    }else if(d == Direction::Vertical){
        for(int i = row; i < row + MAX_COLUMN; i++){
            hasMade(page, i);
        }
        // checking if i can write on the requested place
        for(unsigned int i = row_u; i < row_u + str.length(); i++){
            if(this->book.at(page).at((int)i)[column] != '_'){
                __throw_invalid_argument("Can't write on a written or deleten place.");
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
    if(column > MAX_COLUMN || length > MAX_COLUMN || row < 0 || column < 0  || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    hasMade(page,row);
    string output;
    if(d == Direction::Horizontal){
        if(column + length > MAX_COLUMN){
            __throw_invalid_argument("Make sure the column and the string less than 100.");
        }
        for(int i = column; i < column + length; i++){
            output +=  this->book.at(page).at(row)[i];
        }
    }else if(d == Direction::Vertical){
        for(int i = row; i < row + MAX_COLUMN; i++){
            hasMade(page, i);
        }
        for(int i = row; i < row + length; i++){
            output +=  this->book.at(page).at(i)[column];
        }
    }
    return output;
}
void Notebook::erase(int page,int row,int column,Direction d ,int length){
    if(column > MAX_COLUMN || length > MAX_COLUMN || row < 0 || column < 0  || page < 0){
        __throw_invalid_argument("page , row , column str.length must be >= 0. \n Make sure the column and the string less than 100.");
    }
    hasMade(page,row);
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
        for(int i = row; i < row + MAX_COLUMN; i++){
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
    // showing the first 100 lines.
    int line = 0;
    while(line < MAX_COLUMN){
        hasMade(page, line);
        cout << read(page, line , 0 , Direction::Horizontal , MAX_COLUMN) << "\n";
        line++;
    }
}