#include <string>
#include "fecha.hpp"

class Producto {
    private:
        std::string codigoBarra;
        std::string nombre;
        float peso;
        Fecha fechaEntrada;
        float precioMayoreo;
        float precioMenudeo;
        int existencia;
    public:
        Producto();
        Producto(const Producto &p);

        void setCodigoBarra(std::string&);
        void setNombre(std::string&);
        void setPeso(float&);
        void setFechaEntrada(Fecha&);
        void setPrecioMayoreo(float&);
        void setPrecioMenudeo(float&);
        void setExistencia(int&);
        
        std::string toString();

        std::string getCodigoBarra();
        std::string getNombre();
        float getPeso();
        Fecha getFechaEntrada();
        float getPrecioMayoreo();
        float getPrecioMenudeo();
        int getExistencia();
};