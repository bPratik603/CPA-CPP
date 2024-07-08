#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <errno.h> 
#include <string.h> 

#include <stdexcept>

class File{
    private: 
        FILE* fp; 
    public: 
        File(const char* path_name){
            struct stat st_buffer; 
            int sys_ret; 
            memset((void*)&st_buffer, 0, sizeof(struct stat)); 
            sys_ret = stat(path_name, &st_buffer); 
            if(sys_ret == -1)
                throw std::runtime_error(strerror(errno)); 
            if(!S_ISREG(st_buffer.st_mode))
                throw std::domain_error("File type must be a regular file");
            fp = fopen(path_name, "rw");  
            if(fp == NULL) 
                throw std::runtime_error(strerror(errno)); 
        }
}; 
