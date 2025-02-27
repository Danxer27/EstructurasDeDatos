#include "name.hpp"
#include <string>

class Student{
    public:
        Name nombre;
        int codigo;
    private:
        Student();
        Student(const Student&);

        void setName(const Name& n){
            this->nombre = n;
        }

        void setCodigo(const int& c){
            this->codigo = c;
        }

}