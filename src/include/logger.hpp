#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <filesystem>

namespace ChatServer {

class Logger {
public:
    static void info(const std::string& message);
    static void debug(const std::string& message);
    static void warn(const std::string& message);
    static void error(const std::string& message);

private:
    static std::string getTimestamp();
    static std::string getLogFilename();
    static void log(const std::string& level, const std::string& message);
};

#define LOG_INFO(msg) ChatServer::Logger::info(msg)
#define LOG_DEBUG(msg) ChatServer::Logger::debug(msg)
#define LOG_WARN(msg) ChatServer::Logger::warn(msg)
#define LOG_ERROR(msg) ChatServer::Logger::error(msg)

} // namespace ChatServer
