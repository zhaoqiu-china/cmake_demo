#include <Windows.h>
#include <string>
#include <stdexcept>
#include <iostream>

std::size_t count_files(const std::string &folder)
{
    size_t counter = 0;
    WIN32_FIND_DATAA ffd;

    // Start iterating over the files in the folder directory.
    HANDLE hFind = ::FindFirstFileA((folder + "\\*").c_str(), &ffd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do // Managed to locate and create an handle to that folder.
        {
            if (ffd.cFileName[0] != '.')
                counter++;
        } while (::FindNextFileA(hFind, &ffd) != 0);
        ::FindClose(hFind);
    }
    else
    {
        throw std::runtime_error("Failed open folder " + folder);
    }

    return counter;
}

int main()
{
    auto n = count_files("D:/VS2019_projects/cmake_demo/temp");
    std::cout << "file count: " << n << std::endl;
    return 0;
}