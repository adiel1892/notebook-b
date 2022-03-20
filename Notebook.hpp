#include "Direction.hpp"
#include <iostream>
#include <string>
using namespace std;
namespace ariel{
    class Notebook{
        private:
        public:
        void write(unsigned int page, unsigned int row, unsigned int column, Direction d , string str);
        string read(unsigned int page, unsigned int row, unsigned int column, Direction d ,unsigned int length);
        void erase(unsigned int page, unsigned int row, unsigned int column,Direction d ,unsigned int length);
        void show(unsigned int page);
    };
}