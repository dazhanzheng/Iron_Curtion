#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

void log(const std::string& message)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::string time_str = std::ctime(&now_time);
    time_str.pop_back();
    
    std::ofstream log_file("logs.txt", std::ios::app);

    log_file << time_str << " - " << message << std::endl;
    log_file.close();
}

