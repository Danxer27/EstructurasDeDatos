#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include "list.hpp"
#include "integer.hpp"

class Interface {
    private:
        List<Integer, 1000000> integers;
    public:
        Interface();
        Interface(const Interface&);
        void Menu();

};

#endif //__INTERFACE_HPP__
