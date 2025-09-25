import type { User } from './user'

export interface Message {
  id: string
  content: string
  userId: string
  roomId: string
  createdAt: string
  user?: User
}