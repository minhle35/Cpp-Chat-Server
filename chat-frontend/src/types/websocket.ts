import type { Message, User } from './index'

// WebSocket message data types
export interface MessageData {
  message: Message
}

export interface UserJoinedData {
  user: User
  roomId: string
}

export interface UserLeftData {
  userId: string
  roomId: string
}

export interface TypingStartData {
  userId: string
  username: string
  roomId: string
}

export interface TypingStopData {
  userId: string
  roomId: string
}

// Union type for all possible data types
export type WebSocketData =
  | MessageData
  | UserJoinedData
  | UserLeftData
  | TypingStartData
  | TypingStopData

// Properly typed WebSocket message
export interface WebSocketMessage {
  type: 'message' | 'user_joined' | 'user_left' | 'typing_start' | 'typing_stop'
  data: WebSocketData
  timestamp: string
}

export interface TypingIndicator {
  userId: string
  username: string
  roomId: string
}

export interface UserPresence {
  userId: string
  username: string
  status: 'online' | 'away' | 'offline'
  lastSeen?: string
}

// Helper types for type-safe message handling
export type MessageWebSocketMessage = WebSocketMessage & {
  type: 'message'
  data: MessageData
}

export type UserJoinedWebSocketMessage = WebSocketMessage & {
  type: 'user_joined'
  data: UserJoinedData
}

export type UserLeftWebSocketMessage = WebSocketMessage & {
  type: 'user_left'
  data: UserLeftData
}

export type TypingStartWebSocketMessage = WebSocketMessage & {
  type: 'typing_start'
  data: TypingStartData
}

export type TypingStopWebSocketMessage = WebSocketMessage & {
  type: 'typing_stop'
  data: TypingStopData
}
