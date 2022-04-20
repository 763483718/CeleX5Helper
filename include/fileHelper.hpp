/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-07 14:21:05
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-07 15:34:36
 */

#include <iostream>


#include <vector>
#include <dirent.h> //Dir头文件
#include <string.h>
#include <algorithm>


#include <unistd.h>
#include <sys/stat.h>
#include <string>
using std::string;

using namespace std;

// int access(const char* _Filename, int _AccessMode);
int makeFolder(string file);

int getFiles(std::string path, std::vector<std::string> &files);