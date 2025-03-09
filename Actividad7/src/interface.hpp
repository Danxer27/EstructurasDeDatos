#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include "list.hpp"
#include "integer.hpp"

class Interface {
    private:
        List<Integer>* listRef;
    public:
        Interface(List<Integer>&);

};

#endif //__INTERFACE_HPP__
