#include <string>

class Name{
    public:
        std::string first;
        std::string last;
    private:
        Name();
        Name(const Name&);
        //Name& operator=(const Name&);
        void setFirst(const std::string&);
        void setLast(const std::string&);

        std::string toString();

        std::string getFirst() const;
        std::string getLast() const;

};