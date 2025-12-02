Problem: https://usaco.org/index.php?page=viewproblem2&cpid=992

Description: You are given a set of numbers that are not sorted. You need to sort them using "wormholes" (or edges in a graph) where in wormhole (a, b, w)
you can switch the number in indice a with the number in indice b. There is a weight of w to perform this. The goal is to maximize the weight of the smallest weight that must be used to sort the numbers.

Solution: Using binary search on a function, I pick a number as the lowest weight of a wormhole a cow go through. I then run this constraint on DFS where I mark each node with an id corresponding to it's connected component.
x is a certain number. If number 'x' at that indice 'b'  has the same id as indice 'x', they are in the same connected component. Checking if each number x's current indice is in the same connected component as indice number 'x',
is the same thing as checking if number 'x' can be placed into position 'x'. I perform DFS on different minimum weights until binary search finds the maximum lowest weight of a wormhole that must be used.
