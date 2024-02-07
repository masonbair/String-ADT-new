#include <iostream>
#include "string.hpp"

String::String(){
    str[0] = 0;
}

String::String(char a){
    str[0] = a;
    str[1] = 0;
}

String::String(const char[] a){
    int i = 0;
    while(a[i] != 0){
        if(i >= capactity()) break;

        str[i] = a[i];
        ++i;
    }
    str[i] = 0;
}

int String::length(){
    int count = 0;
    while(str[count] != 0) ++count;   

    return count;
}

String String::substr(int start, int end) const{
    if(end >= capacity()){
        std::cerr << "End to big";
        break;
    }
    int length = end-start;
    char[length] a;
    for(int i = length; i < end; i++){
        a[i] = str[i];
    }
    String use(a);
    return use;
}

int String::findChar(const char s){
    int i = 0;
    while(str[i] != 0){
        if(str[i] == s) return i;
        ++i;
    }
    return -1;
}


String& String::operator=(const String& parStr){
    int count = 0;
    String use
    while(parStr.str[count] != 0){
        use.str[count] = parStr.str[count];
        ++count;
    }
    use.str[count] = 0;
    return use;
}

String String::operator+(const String& addTo){
    String finalStr(str);
    int i = length();

    while(addTo.str[i-length()] != 0){
        if(i >= capactity()) break;
        finalStr.str[i] = addTo.str[i-length()];
        ++i;
    }
    finalStr.str[i] = 0;
    return finalStr;
}

String& String::operator+=(const String& rhs){
    int offset = length();
    int rhsLen = rhs.length();
    int  i = 0;
    while(rhs.str[i] != 0){
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset+1] = 0;
    return *this;
}

bool String::operator==(const String testEqual) const{
    int i = 0;
    while(str[i] != 0 || testEqual.str[i] != 0){
        if(str[i] != testEqual[i]) return false;
        ++i;
    }
    return true;
}


//You need both [] operators just in case we do a call by const
// 0 <= i < length()
char String::operator[](int i) const{
    assert(i>=0);
    assert(i<length());
    return str[i];
}

// 0 <= i < length()
char& String::operator[](int i) {
    assert(i>=0);
    assert(i<length());
    return str[i];
}

std::ostream String::operator<<(std::ostream of, const String& print){
    int i = 0;
    while(print.str(i) != 0){
        of << str[i];
        ++i;
    }
    return of;
}
