#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

#include "nbis_lib.h"


int main()
{
    printf("메인에서 오는 메시지\n");
    char *lib_name = "./nbis_lib.dylib";
    void *lib_handle = dlopen(lib_name, RTLD_NOW);

    if (lib_handle) {
        printf("[%s] dlopen(\"%s\", RTLD_NOW): Successful\n", __FILE__, lib_name);
    }
    else {
        printf("[%s] Unable to open library: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }
    
    // Get the function addresses.
    void (*main_exe)() = dlsym(lib_handle, "main_exe");
    if (main_exe) {
        printf("[%s] dlsym(lib_handle, \"main_exe\"): Successful\n", __FILE__);
    }
    else {
        printf("[%s] Unable to get symbol: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }

    main_exe() ;//함수 실행 3
    
    return 0;

}