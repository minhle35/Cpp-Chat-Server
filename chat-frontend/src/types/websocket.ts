export interface WebSocketMessage {
  type: 'message' | 'user_joined' | 'user_left' | 'typing_start' | 'typing_stop'
  data: any
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
