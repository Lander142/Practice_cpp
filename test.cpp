#include <iostream>

int main(int argc, char** argv){
    for(int i = 0; i < argc; i++){
        char* str = argv[i];
        while(*str != '\0'){
            std::cout << *str;
            ++str;
        }
        std::cout << '\n';
    }
}