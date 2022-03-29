#include "Direction.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
using namespace std;
#define MAX_COLUMN 100
#define LIML 32
#define LIMR 126
namespace ariel{
    class Notebook{
        public:
        void write(int page,int row,int column, Direction d , string const& str);
        string read(int page,int row,int column, Direction d ,int length);
        void erase(int page,int row,int column,Direction d ,int length);
        void show(int page);
        void makeRow(int page , int row);
        void hasMade(int page, int row);
        ~Notebook();
        static void checkInput(int page, int row, int column,string const& str);
        Notebook();
        unordered_map<int, unordered_map<int, char*>> book;
    };
}
