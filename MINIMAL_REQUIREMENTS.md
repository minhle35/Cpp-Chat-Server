# Minimal Developer Requirements - C++ Real-time Chat System

## Overview
This document outlines the **absolute minimum requirements** for a single developer to build a production-ready C++ real-time chat system with JavaScript frontend.

## Core Technology Stack

### Backend (C++)
- **Language**: C++20 (GCC 11+ or Clang 13+)
- **Build System**: CMake 3.20+
- **WebSocket**: websocketpp library
- **Database**: PostgreSQL with libpqxx
- **Cache**: Redis with hiredis
- **JSON**: nlohmann/json
- **Security**: OpenSSL

### Frontend (JavaScript)
- **Vanilla JavaScript** (no frameworks required)
- **WebSocket API** (native browser support)
- **CSS3** for styling

### Infrastructure
- **Docker** for containerization
- **Docker Compose** for orchestration

## Essential Features (MVP)

### 1. Authentication & User Management
- [ ] User registration/login
- [ ] Password hashing (SHA-256 + salt)
- [ ] Session management with Redis
- [ ] Basic user profiles

### 2. Real-time Messaging
- [ ] WebSocket connection handling
- [ ] Message broadcasting to rooms
- [ ] Message persistence in PostgreSQL
- [ ] Message history retrieval

### 3. Room/Channel System
- [ ] Create/join/leave rooms
- [ ] Room-based message routing
- [ ] Basic room permissions
- [ ] User presence tracking

### 4. Security Essentials
- [ ] Input validation and sanitization
- [ ] SQL injection prevention
- [ ] Rate limiting (basic)
- [ ] XSS prevention in frontend

### 5. Basic UI
- [ ] Chat interface with message bubbles
- [ ] Room sidebar
- [ ] User list with online status
- [ ] Login/registration forms

## Development Phases (Simplified)

### Phase 1: Foundation (Week 1)
```
Priority: CRITICAL
├── Project setup with CMake
├── Basic logging system
├── PostgreSQL connection
├── Redis connection
└── Simple WebSocket server
```

### Phase 2: Core Features (Week 2-3)
```
Priority: HIGH
├── User authentication
├── Message system
├── Room management
├── Database schema
└── Basic frontend
```

### Phase 3: Polish (Week 4)
```
Priority: MEDIUM
├── Security hardening
├── Error handling
├── UI improvements
├── Basic testing
└── Docker setup
```

## Minimal Database Schema

### PostgreSQL Tables
```sql
-- Users table
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT NOW()
);

-- Rooms table
CREATE TABLE rooms (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description TEXT,
    is_private BOOLEAN DEFAULT FALSE,
    created_by INTEGER REFERENCES users(id),
    created_at TIMESTAMP DEFAULT NOW()
);

-- Messages table
CREATE TABLE messages (
    id SERIAL PRIMARY KEY,
    room_id INTEGER REFERENCES rooms(id),
    user_id INTEGER REFERENCES users(id),
    content TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT NOW()
);

-- Room memberships
CREATE TABLE room_members (
    room_id INTEGER REFERENCES rooms(id),
    user_id INTEGER REFERENCES users(id),
    joined_at TIMESTAMP DEFAULT NOW(),
    PRIMARY KEY (room_id, user_id)
);
```

### Redis Keys Structure
```
user:sessions:{user_id} -> session_data
user:presence:{user_id} -> online_status
room:members:{room_id} -> set of user_ids
```

## Code Structure (Minimal)

```
cpp_chat_server/
├── src/
│   ├── main.cpp              # Entry point
│   ├── server/               # WebSocket server
│   │   ├── websocket_server.cpp
│   │   └── websocket_server.hpp
│   ├── auth/                 # Authentication
│   │   ├── auth_manager.cpp
│   │   └── auth_manager.hpp
│   ├── database/             # Database layer
│   │   ├── db_manager.cpp
│   │   └── db_manager.hpp
│   ├── cache/                # Redis layer
│   │   ├── redis_manager.cpp
│   │   └── redis_manager.hpp
│   └── utils/                # Utilities
│       ├── logger.cpp
│       └── logger.hpp
├── frontend/
│   ├── index.html
│   ├── chat.js
│   ├── auth.js
│   └── styles.css
├── docker/
│   ├── Dockerfile
│   └── docker-compose.yml
└── CMakeLists.txt
```

## Performance Targets (Minimum)

### Scalability Goals
- **100 concurrent users** (start small, scale up)
- **1,000 messages/minute**
- **< 500ms response time** for typical operations
- **< 512MB memory usage**

### Optimization Priorities
1. Database connection pooling
2. Redis caching for sessions
3. Efficient WebSocket message handling
4. Basic memory management

## Security Checklist (Essential)

### Authentication
- [ ] Password hashing with salt
- [ ] Session token expiration
- [ ] Failed login attempt tracking
- [ ] Input validation

### Network Security
- [ ] Rate limiting (10 requests/second per IP)
- [ ] Message size limits (1KB per message)
- [ ] Origin validation for WebSocket
- [ ] SQL injection prevention

### Data Protection
- [ ] Parameterized SQL queries
- [ ] XSS prevention in frontend
- [ ] Secure session storage
- [ ] Input sanitization

## Testing Strategy (Minimal)

### Unit Tests (Priority: HIGH)
- [ ] Authentication logic
- [ ] Message validation
- [ ] Database operations
- [ ] Redis operations

### Integration Tests (Priority: MEDIUM)
- [ ] WebSocket connection flow
- [ ] End-to-end message delivery
- [ ] Database integration

### Manual Testing (Priority: HIGH)
- [ ] Multiple browser connections
- [ ] Message persistence
- [ ] Room functionality
- [ ] Authentication flow

## Deployment (Simplified)

### Docker Setup
```yaml
# docker-compose.yml
version: '3.8'
services:
  postgres:
    image: postgres:15
    environment:
      POSTGRES_DB: chatdb
      POSTGRES_USER: chatuser
      POSTGRES_PASSWORD: chatpass
    ports:
      - "5432:5432"

  redis:
    image: redis:7-alpine
    ports:
      - "6379:6379"

  chat-server:
    build: .
    ports:
      - "8080:8080"
    depends_on:
      - postgres
      - redis
```

## Success Metrics

### Technical Goals
- [ ] Application runs without crashes
- [ ] Handles 100 concurrent users
- [ ] Messages persist and load correctly
- [ ] Authentication works securely
- [ ] Docker deployment successful

### User Experience Goals
- [ ] Real-time message delivery (< 100ms)
- [ ] Intuitive chat interface
- [ ] Reliable connection handling
- [ ] Mobile-responsive design

## Development Timeline

### Week 1: Infrastructure
- Day 1-2: Project setup, CMake, dependencies
- Day 3-4: Database schema, basic connections
- Day 5-7: WebSocket server foundation

### Week 2: Core Features
- Day 1-3: Authentication system
- Day 4-5: Message handling
- Day 6-7: Room management

### Week 3: Integration
- Day 1-3: Frontend development
- Day 4-5: Backend-frontend integration
- Day 6-7: Testing and debugging

### Week 4: Polish & Deploy
- Day 1-2: Security hardening
- Day 3-4: Docker containerization
- Day 5-7: Documentation and final testing

## Risk Mitigation

### High-Risk Areas
1. **WebSocket connection management** - Start with simple implementation
2. **Database performance** - Use connection pooling from day 1
3. **Memory management** - Use smart pointers consistently
4. **Security vulnerabilities** - Implement basic security early

### Fallback Strategies
- Use proven libraries (websocketpp, libpqxx, hiredis)
- Start with single-threaded design, add threading later
- Implement basic features first, optimize later
- Use Docker for consistent development environment

## Resources & References

### Documentation
- [WebSocket++ Documentation](https://github.com/zaphoyd/websocketpp)
- [PostgreSQL libpqxx](https://github.com/jtv/libpqxx)
- [Redis hiredis](https://github.com/redis/hiredis)
- [nlohmann/json](https://github.com/nlohmann/json)

### Learning Materials
- C++20 features and best practices
- WebSocket protocol basics
- PostgreSQL administration basics
- Redis data structures
- Docker containerization

---

**Note**: This is a minimal viable product approach. Focus on getting core functionality working first, then iterate and improve. Perfect is the enemy of good - ship early, ship often!
