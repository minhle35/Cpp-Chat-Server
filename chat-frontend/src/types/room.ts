export interface Room {
  id: string
  name: string
  description?: string
  isPrivate: boolean
  createdAt: string
  memberCount?: number
  createdBy?: string
}
