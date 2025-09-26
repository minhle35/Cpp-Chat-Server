#include "logger.hpp"
#include <sstream>

namespace ChatServer {

auto Logger::getTimestamp() -> std::string {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%H:%M:%S");
    return ss.str();
}

auto Logger::getLogFilename() -> std::string {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << "logs/chat_server_" << std::put_time(std::localtime(&time_t), "%Y%m%d_%H%M%S") << ".log";
    return ss.str();
}

auto Logger::log(const std::string& level, const std::string& message) -> void {
    std::string timestamp = getTimestamp();
    std::string log_line = "[" + timestamp + "] [" + level + "] " + message;

    std::cout << log_line << std::endl;

    // File output with timestamp-based filename
    static std::string log_filename = getLogFilename();
    static bool file_created = false;

    if (!file_created) {
        // Create logs directory if it doesn't exist
        std::filesystem::create_directories("logs");
        file_created = true;
    }

    std::ofstream log_file(log_filename, std::ios::app);
    if (log_file.is_open()) {
        log_file << log_line << std::endl;
        log_file.close();
    }
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
