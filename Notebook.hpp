
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
        void write(unsigned int page, unsigned int row, unsigned int column, Direction d , string const& str);
        string read(unsigned int page, unsigned int row, unsigned int column, Direction d ,unsigned int length);
        void erase(unsigned int page, unsigned int row, unsigned int column,Direction d ,unsigned int length);
        void show(unsigned int page);
        Notebook();
        unordered_map<unsigned int, unordered_map<unsigned int, char[100]>> book;
    };
}