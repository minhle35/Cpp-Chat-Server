#include "logger.hpp"
#include <sstream>

namespace ChatServer {

std::string Logger::getTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%H:%M:%S");
    return ss.str();
}

void Logger::log(const std::string& level, const std::string& message) {
    std::cout << "[" << getTimestamp() << "] [" << level << "] " << message << std::endl;
}

void Logger::info(const std::string& message) {
    log("INFO", message);
}

void Logger::debug(const std::string& message) {
    log("DEBUG", message);
}

void Logger::warn(const std::string& message) {
    log("WARN", message);
}

void Logger::error(const std::string& message) {
    log("ERROR", message);
}

} // namespace ChatServer
