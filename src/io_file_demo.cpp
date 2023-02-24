#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

void write_file_demo()
{
    auto p = static_cast<uint8_t*>(malloc(16 * 16));
    for (size_t i = 0; i < 256; i++)
    {
        *(p+i) = i;
    }
    int a[4] = {1,2,3,4};

    auto p2 = static_cast<uint8_t*>(malloc(16 * 16));
    for (size_t i = 0; i < 256; i++)
    {
        *(p2+i) = 255 - i;
    }
    int b[4] = {5,6,7,8};

    std::ofstream outfile;
    std::string file_path(TEMP_DIR);
    file_path += "domefile";
    outfile.open(file_path, std::ios::out | std::ios::binary);
    outfile.write(reinterpret_cast<char*>(p), 256);
    outfile.write(reinterpret_cast<char*>(a), 16);

    outfile.write(reinterpret_cast<char*>(p2), 256);
    outfile.write(reinterpret_cast<char*>(b), 16);
    
    std::cout<< "write done" <<std::endl;
    outfile.close();
    free(p);
    free(p2);
}

void read_raw_file()
{
    std::string file_path(TEMP_DIR);
    file_path += "domefile";
    std::ifstream infile(file_path, std::ios::in | std::ios::binary);
    // infile.open("D:/VS2019_projects/cmake_demo/temp/demofile", std::ios::in | std::ios::binary);
    infile.seekg(0, std::ios::end);
    int len = static_cast<int>(infile.tellg());
    std::cout << "len: " << len << std::endl;
    char* buffer = new char[len];
    infile.seekg(0, std::ios::beg);
    infile.read(buffer, len);
    infile.close();
    auto p = reinterpret_cast<unsigned char*>(buffer);
    for (size_t i = 0; i < 256; i++)
    {
        std::cout << static_cast<int32_t>(*p++) << std::endl;
    }
    auto p2 = reinterpret_cast<int*>(p);

    for (size_t i = 0; i < 4; i++)
    {
        std::cout << *p2++ << std::endl;
    }

    delete [] buffer;
}

int main()
{
    
    
    return 0;
}