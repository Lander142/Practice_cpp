#include <iostream>
#include <cstdio>

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Usage: " << argv[0] << "data.txt" << std::endl;
        return 1;
    }
    FILE* f = fopen(argv[1],"r");
    if(!f){
        std::cout << "Cannot read that file!" << std::endl;
        return 1;
    }
    int c;
    int max_cnt = -1;
    char char_with_max_cnt;
    int cur_char = -1;
    int cur_cnt;
    int prev_char = -1;

    while((c = fgetc(f)) != EOF){
        if(std::isspace(cur_char)) continue;
        if(cur_char != prev_char){
            if(cur_char > max_cnt){
                max_cnt = cur_cnt;
                char_with_max_cnt = (char)prev_char;
            }
            prev_char = cur_char;
            cur_char = 1;
        }else cur_cnt++;
    }

    if(cur_char > max_cnt){
        max_cnt = cur_cnt;
        char_with_max_cnt = (char)prev_char;
    }

    if(max_cnt != -1){
        std::cout << char_with_max_cnt << ' ' << max_cnt << std::endl;
        return 0;
    }
    std::cout << "empty file!" << std::endl;
    return 1;
}