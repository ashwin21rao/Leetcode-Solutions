class Solution {
public:
    bool isRobotBounded(string instructions) {
        // facing up: 0, left: 1, down: 2, right: 3
        int dir = 0;
        // coordinates of robot's position
        int x = 0, y = 0;
        
        for (char &ch : instructions) {
            if (ch == 'G') {
                if (dir == 0) y++;
                else if (dir == 1) x--;
                else if (dir == 2) y--;
                else x++;
            }
            else if (ch == 'L')
                dir = (dir + 1) % 4;
            else
                dir = ((dir - 1) % 4 + 4) % 4;
        }
        
        // robot does not face up OR faces up and is at original position
        return dir != 0 || (dir == 0 && x == 0 && y == 0);
    }
};

/*
for the robot to be bounded in a circle, it must eventually reach its starting position
and orientation.
assume that the robot initially faces up.

if after performing all instructions once, the robot faces:
    - left or right: it will return to its original position and orientation 
      after performing the instructions 4 times.
    - down: it will return to its original position and orientation 
      after performing the instructions 2 times.
    - up: if the robot is not at its starting position, it will never reach that position.
    
hence, the robot will be bounded in a circle if after performing the instructions once:
    - it faces left, right or down
    - it faces up and is at its starting position.

- we store the current direction of the robot:
    - facing up: dir = 0
    - facing left: dir = 1
    - facing down: dir = 2
    - facing right: dir = 3

- when turning left, we increment dir: dir -> (dir + 1) % 4.
- when turning right, we decrement dir: dir -> (dir - 1) % 4.
- when going straight, we increment or decrement x or y coordinate
  based on the current direction of the robot.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/robot-bounded-in-circle/
*/