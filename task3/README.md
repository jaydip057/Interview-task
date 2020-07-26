prisoner plans to escape from a prison He is a monkey man and is able to jump over a wall. He is able to jump X meter, but because of factors such as wind or rainfall, he loses Y meters from each jump. To escape from jail he has to cross N number of walls where the height of each wall is given in an array write a program to find out the total number of jumps he needs to make to escape from the jail.


input Specification:

Your program must read 4 arguments (climb up, climb Down ,no of Walls wall Heights []) where

inputs1: climb up is the number of meters he can jump
 (1<= climb up <= 104)

 input2: climb Down, is the number of meters he slides down
(1<=climb Down<=104)

input3: no of Walls is the number of walls he needs to jump to escape
 (1<= no of walls <= 104)

output Specification:
return the total number of jump

Example 1:

input1: 10
input2: 1
input 3: 1
input4: (10)

Output: 1

Explanation:

Here,  prisoner can jump a height of 10 meters but slides do by 1 meter He has 1 wall to jump and the height of the wall is 10 meters Since he umps 10 meters in the first attempt he cross the wall easily in the first attempt.

Example 2

input1: 5

Input2:1

Input 3: 2

input4:[9,11] 

Output: 5

Explanation:
Here prisoner can jump a height of 5 meters but slides down by 1 meter. He has 2 walls to jump and the height of each wall is 9 and 11 meters respectively While crossing the first wall prisoner makes 2 attempts, because at the first attempt he jumps 5 meters, but slides down by 1 meter, and does not cross the wall In the next attempt, he jumps 5 more meters from that position and this time he doesn't slide because he crossed the wall in this attempt because 4*5=9 and 9 meters is the actual height of the wall.
Similarly while crossing the second wall Jack Sparrow takes 3 attempts because at the second attempt on this wall,he  slides down by 1 meter So, 4+5=9, and the height of the wall is 11 meter  at this third attempt, prisoner is able to escape from the jail.
