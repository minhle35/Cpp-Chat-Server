#include <iostream>
#include "logger.hpp"
#include <thread>
#include <chrono>
#include <vector>

int main() {
    using namespace ChatServer;

    // Simple logging test
    LOG_INFO("Chat Server starting up...");
    LOG_DEBUG("Debug: Server configuration loaded");
    LOG_WARN("Warning: This is a test warning message");
    LOG_ERROR("Error: This is a test error message");

    LOG_INFO("Server initialized successfully");
    LOG_DEBUG("Database connection established");

    // Test thread safety (simulate multiple threads logging)
    LOG_INFO("Testing thread safety with multiple threads...");
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back([i]() {
            for (int j = 0; j < 3; ++j) {
                LOG_INFO("Thread " + std::to_string(i) + " logging message " + std::to_string(j));
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        });
    }

    // Wait for all threads to complete
    for (auto& thread : threads) {
        thread.join();
    }

    LOG_INFO("Chat Server shutdown complete");

    return 0;
}
