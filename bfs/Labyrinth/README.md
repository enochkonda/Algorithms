Problem: https://cses.fi/problemset/task/1193

Problem Summary:
You are given n x m grid representing a maze. Each cell can be open or blocked and the goal is to move from point A to target B. 
Movement, up, down, left, and right is allowed.
Goal:
Determine whether A can reach B.
If not, output "NO".
If yes, output "YES", the shortest path length, and a sequence of moves (L, R, U, D) describing the shortest route.

Solution:
I used direction arrays called dx and dy to simulate choosing the four cardinal direcitons. 
While using BFS, I used a 2D array that, given a node (coordinate pair) gives that parent of that node.
To recover the shortest path, I set current node as B, and looped through it's parents using the 2D array
until I found node A
