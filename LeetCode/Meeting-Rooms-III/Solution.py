1class Solution:
2    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
3        # Sort meetings by start time
4        meetings.sort()
5      
6        # Min heap to track busy rooms: (end_time, room_number)
7        busy_rooms = []
8      
9        # Min heap to track available rooms by room number
10        available_rooms = list(range(n))
11        heapify(available_rooms)
12      
13        # Counter for number of meetings held in each room
14        meeting_count = [0] * n
15      
16        # Process each meeting
17        for start_time, end_time in meetings:
18            # Free up rooms that have finished their meetings
19            while busy_rooms and busy_rooms[0][0] <= start_time:
20                freed_room = heappop(busy_rooms)[1]
21                heappush(available_rooms, freed_room)
22          
23            # If there's an available room, use it
24            if available_rooms:
25                room_id = heappop(available_rooms)
26                meeting_count[room_id] += 1
27                heappush(busy_rooms, (end_time, room_id))
28            else:
29                # No available rooms, wait for the earliest room to finish
30                earliest_end_time, room_id = heappop(busy_rooms)
31                meeting_count[room_id] += 1
32                # Schedule meeting right after current meeting ends
33                # Duration is (end_time - start_time)
34                new_end_time = earliest_end_time + (end_time - start_time)
35                heappush(busy_rooms, (new_end_time, room_id))
36      
37        # Find the room with the most meetings (smallest index if tie)
38        most_used_room = 0
39        for room_id, count in enumerate(meeting_count):
40            if meeting_count[most_used_room] < count:
41                most_used_room = room_id
42      
43        return most_used_room