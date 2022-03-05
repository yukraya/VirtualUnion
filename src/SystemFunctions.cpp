#include "SystemFunctions.hpp"

std::string getProjectRootPath()
{
    return std::filesystem::canonical("/proc/self/exe").parent_path().parent_path().string();
}

std::string getExecutablePath()
{
    return std::filesystem::canonical("/proc/self/exe").string();
}