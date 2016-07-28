//
//  main.cpp
//  OpenCLTest1
//

#include <stdio.h>

#ifdef __APPLE__
#include <OpenCL/OpenCL.h>
#else
#include <CL/cl.h>
#endif //__APPLE__

static void printPlatformInfo(const cl_platform_id platform_id);

/*-------------------------------------------------------------------------------------------------------------------
 */

int main(int argc, const char * argv[]) {
    // プラットフォームIDを取得する
    cl_platform_id platforms[10];
    cl_uint num_platforms;
    cl_int status;
    
    status = clGetPlatformIDs(sizeof(platforms)/sizeof(*platforms), platforms, &num_platforms);
    
    if(status != CL_SUCCESS){
        fprintf(stderr, "clGetPlatformIDs failed with status %d\n", status);
        return 1;
    }
    
    
    printf("Number of platform(s) : %d\n", num_platforms);
    for (int i = 0; i < (int)num_platforms; i++) {
        // プラットフォームIDについての情報を表示する
        printPlatformInfo(platforms[i]);
    }
    
    return 0;
}

/*-------------------------------------------------------------------------------------------------------------------
 * 引数で与えられたプラットフォームの情報を表示する
 * platform_id: 情報を表示するプラットフォームのID
 */

static void printPlatformInfo(const cl_platform_id platform_id)
{
    char buffer[1024];
    cl_int status;
    
    // プロファイル
    status = clGetPlatformInfo(platform_id, CL_PLATFORM_PROFILE, sizeof(buffer) - 1, buffer, NULL);
    
    printf("Platform profile   : ");
    if(status == CL_SUCCESS){
        printf("%s\n", buffer);
    }else{
        printf("Error: clGetPlatformInfo failed with status %d\n", status);
    }
    
    // バージョン
    status = clGetPlatformInfo(platform_id, CL_PLATFORM_VERSION, sizeof(buffer) - 1, buffer, NULL);
    
    printf("Platform version   : ");
    if(status == CL_SUCCESS){
        printf("%s\n", buffer);
    }else{
        printf("Error: clGetPlatformInfo failed with status %d\n", status);
    }
    
    // 名前
    status = clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, sizeof(buffer) - 1, buffer, NULL);
    
    printf("Platform name   : ");
    if(status == CL_SUCCESS){
        printf("%s\n", buffer);
    }else{
        printf("Error: clGetPlatformInfo failed with status %d\n", status);
    }
    
    // ベンダー
    status = clGetPlatformInfo(platform_id, CL_PLATFORM_VENDOR, sizeof(buffer) - 1, buffer, NULL);
    
    printf("Platform vendor   : ");
    if(status == CL_SUCCESS){
        printf("%s\n", buffer);
    }else{
        printf("Error: clGetPlatformInfo failed with status %d\n", status);
    }
    
    // 拡張機能
    status = clGetPlatformInfo(platform_id, CL_PLATFORM_EXTENSIONS, sizeof(buffer) - 1, buffer, NULL);
    
    printf("Platform extensions   : ");
    if(status == CL_SUCCESS){
        printf("%s\n", buffer);
    }else{
        printf("Error: clGetPlatformInfo failed with status %d\n", status);
    }
}
