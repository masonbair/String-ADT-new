#ifndef STRING_ADT
#define STRING_ADT

#include <iostream>


static const int STRING_SIZE = 100;


class String{
private:
    char str[STRING_SIZE];

public: 
    String();
    String(char);
    String (const char[]);

    int capactity() const { return STRING_SIZE-1;}
    int length() const;
    String substr(int start, int end) const;
    int findChar(const char);

    String& operator=(const String&);
    String operator+(const String&);
    String& operator+=(const String&);
    char& operator[](int) const;
    char operator[](int);
    bool operator==(const String) const;

    friend std::ostream operator<<(std::ostream&, const String&);


};

#endif