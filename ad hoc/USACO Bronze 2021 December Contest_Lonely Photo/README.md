Problem: Given a string with G and H. A lonely photo is a substring that has one G or one H that has a minimum length of three characters. How many lonely photos can you make?

Solution: Instead of looping through the substring creating strings of size 3, 4, 5... and so on which has a O(n^2) time complexity, we can
go through the whole substring once. I went through the substring once and created a vector that counts the repetitions of G and H. 
For example, "GHHHGG" would become [1, 3, 2] in the vector. 
While looping through the vector, I accounted for the edge case of there being a single G between two substrings of H by saying the product of the outer H substring lengths is how
many lonley photos that can be created with one G in between the two H substrings (this case also works vice versa, for a single H and two substrings of G).
The main case was doing the "(currentSubstring - 1) * 2" to find the amount of lonley photos that could be created. The -1 is there because the outer edges of the substring can't contribute to lonely photos because they are only 2 characters in length.
For example, in "GHHHG", the edge "GH" and "HG" on the ends can't be counted because they are outer edges which have lengths less than 3. The last edge case was using "(currentSubstring - 1)" to find how many lonely photos substrings that begin or end at edges of the original string.
For example "GGGHH" only contribute two lonley photos because there is no substring of H's to the left of the substring of G.
