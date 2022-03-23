
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
using namespace std;
#define MAX_COLUMN 100
namespace ariel{
    class Notebook{
        public:
        static void write(int page,int row,int column, Direction d , string const& str);
        string read(int page,int row,int column, Direction d ,int length);
        static void erase(int page,int row,int column,Direction d ,int length);
        void show(int page);
        Notebook();
        unordered_map<int, unordered_map<int, char[100]>> book;
    };
}