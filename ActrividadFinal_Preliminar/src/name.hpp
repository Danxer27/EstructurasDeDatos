#ifndef __NAME_HPP__
#define __NAME_HPP__
#include <string>
#include <iostream>
class Name {
    private:
        std::string first;
        std::string last;
    public:
        Name();
        Name(const Name&);

        void setFirst(const std::string&);
        void setLast(const std::string&);
        std::string getFirst() const;
        std::string getLast()  const;
        std::string getFullName()  const;
        std::string toString() const;

        Name& operator=(const Name&);

        bool operator==(const Name&) const;
        bool operator!=(const Name&) const;
        bool operator<=(const Name&) const;
        bool operator>=(const Name&) const;
        bool operator<(const Name&) const;
        bool operator>(const Name&) const;

        int compareTo(const Name&);
        static int compare(const Name&, const Name&);
        static int comapreByFirst(const Name&, const Name&);
        static int compareByLast(const Name&, const Name&);

        friend std::ostream& operator << (std::ostream&, const Name&);
        friend std::istream& operator >> (std::istream&, Name&);
};


#endif //__NAME_HPP__