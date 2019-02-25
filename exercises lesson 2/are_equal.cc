#include <iostream>

bool are_equal(const char* r, const char* s);

int main(){
    char* r = new char;
    *r = 'a';
    *(r+1) = 'b';

    char* s = new char;
    *s = 'a';
    *(s+1) = 'b';
    *(s+2) = 'c';

    if(are_equal(r, s)){
        std::cout << "both strings are equal" << std::endl;
    } else {
        std::cout << "the strings are different" << std::endl;
    }

    return 0;
}

bool are_equal(const char* r, const char* s){
    int r_index = 0;
    int s_index = 0;

    for(;;){
        // end of both strings, and they are equal
        if(*(r+r_index) == '\0' && *(s+s_index) == '\0'){
            return true;
        }

        std::cout << "r[" << r_index << "]: " << *(r+r_index) <<
                     ", s[" << s_index << "]: " << *(s+s_index) <<
                     std::endl;

        if(*(r+r_index) != *(s+s_index)){
            return false;
        }

        r_index++;
        s_index++;
    }
}