/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-07 14:21:15
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-07 19:48:56
 */
#include "fileHelper.hpp"


//   ./a/b/c
int makeFolder(string file)
{
    string temp = file;
    if(access(temp.c_str(), 0))
    {
        int pos = temp.find_last_of('/');
        temp = temp.substr(0, pos);
        makeFolder(temp);
    }
    return ::mkdir(file.c_str(),0755);
}

int getFiles(string path,vector<string>& filenames)
{
    DIR *pDir;
    struct dirent* ptr;
    string filename, second;

    if(!(pDir = opendir(path.c_str())))
        return 0;

    while((ptr = readdir(pDir))!=0) {
        //跳过.和..文件
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        filename = ptr->d_name;
//        if(con)//也可以添加对文件名的要求
//            filenames.push_back(filename);        
        filenames.push_back(filename);
    }
    closedir(pDir);
    sort(filenames.begin(), filenames.end());

    return filenames.size();
}
