George is with his flock of goats on the bank of a river. He wants to spend them there, making no more than K courses with a raft of a certain capacity. The goats, are not all the same - some are small, some big, some sick, etc. George wants to calculate what is the minimum raft capacity that would allow him to get all his N goats across with no more than K courses.
Since it is not irrelevant which ones she will spend in the first course, which ones in the second, etc. he chooses the following strategy: in each course he first puts the largest untaken goat that fits, then the next largest that fits together with the first, then the next that fits together with the first two, etc. Once none of the others can fit, he brings them around to the other side, goes back and applies the same procedure with the others. If after the Kth course there are still goats not taken in, it means that the raft capacity is insufficient. It follows from the strategy described that the capacity of the raft must be at least as large as the largest of the ewes - otherwise it could not be carried on any of the courses. Help George to write a program raft , which calculates what the minimum raft capacity is given a number of courses K, a number of goats N and the weight of each A1, A2, ..., AN. Since it is a constant (and a small one at that), George's weight can be ignored.
