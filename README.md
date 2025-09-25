# C++ Chat Server
This is a real-time chat server in C++20 with JavaScript frontend, developed by the author to practice programming in C++

## Phase 1: Project Setup

### 1.1 Development Environment Setup
- Install C++20 compiler (GCC 11+ or Clang 13+)
- Setup CMake 3.20+ build system
- Install required dependencies:
  - PostgreSQL development libraries (libpqxx)
  - Redis C++ client (hiredis)
  - WebSocket library (websocketpp)
  - JSON library (nlohmann/json)
  - OpenSSL for security features
- Setup Docker environment for databases
- Configure IDE/editor with C++ language server

### 1.2 Project Structure
```
cpp_chat_server/
├── src/
│   ├── core/           # Main server logic
│   ├── networking/     # WebSocket handling
│   ├── database/       # PostgreSQL integration
│   ├── cache/          # Redis integration
│   ├── security/       # Authentication & validation
│   ├── utils/          # Logging, config, helpers
│   └── main.cpp
├── include/            # Public headers
├── tests/             # Unit and integration tests
├── frontend/          # JavaScript client
├── config/            # Configuration files
├── docker/            # Docker setup
├── docs/              # Documentation
└── CMakeLists.txt
```