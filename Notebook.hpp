
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
using namespace std;
#define MAX_COLUMN 100
namespace ariel{
    class Notebook{
        private:
        map<unsigned int, map<unsigned int, char[100]>> book;
        
        public:
        static void write(unsigned int page, unsigned int row, unsigned int column, Direction d , string const str);
        static string read(unsigned int page, unsigned int row, unsigned int column, Direction d ,unsigned int length);
        static void erase(unsigned int page, unsigned int row, unsigned int column,Direction d ,unsigned int length);
        void show(unsigned int page);
    };
}