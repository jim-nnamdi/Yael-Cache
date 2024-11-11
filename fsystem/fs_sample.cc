#include <iostream>
#include <fstream>

#define FILE_ERROR "error"
#define DEF_CONTENT "no contents"

void fs_create(std::string filepath, std::string contents) {
    std::ofstream Yaelsample(filepath);
    if(!Yaelsample.is_open()) perror(FILE_ERROR);
    Yaelsample << contents;
    std::cout << std::endl;
}

std::string fs_read(std::string filepath) {
    std::ifstream Yaelsample(filepath);
    if(!Yaelsample.is_open()) {
        std::string contents((std::istreambuf_iterator<char>(Yaelsample)), 
        std::istreambuf_iterator<char>());
        Yaelsample.close();
        return contents;
    }
    return DEF_CONTENT;
}