#pragma once
#include <QString>
extern "C"{
    #include <winsock2.h> 
}

class TransHelper{
public:
    int BUF_SIZE = 30;
public:
    size_t getFileSize(FILE * fp);
    int ErrorHandling(const char* message);
};

size_t TransHelper::getFileSize(FILE * fp){
    long cur_offset=ftell(fp);
    fseek(fp,0,SEEK_END);
    size_t size = ftell(fp);
    fseek(fp,cur_offset,SEEK_SET);
    return size;
}

int TransHelper::ErrorHandling(const char* message){
    fputs(message,stderr);
    fputc('\n',stderr);
    return 1;
}