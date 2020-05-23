-> Batman will look for the hostages on a given building by jumping from one window to another using his grapnel gun. Batman's goal is to jump to the window where the hostages are located in order to disarm the bombs. Unfortunately he has a limited number of jumps before the bombs go off...

-> Before each jump, the heat-signature device will provide Batman with the direction of the bombs based on Batman current position:
    U (Up)
    UR (Up-Right)
    R (Right)
    DR (Down-Right)
    D (Down)
    DL (Down-Left)
    L (Left)
    UL (Up-Left

-> Aim for this code practice is to implement BinarySerch algorithm in 2-dimension array with c++ language.

Algorithm Explain:-
  
   0 1 2 3
0 |@| | | |      Here @ -> currenr location and * ->  desire location
1 | | | | |
2 | | | |*|      at initial     left=0, right=3, top=0, bottom=4          index(0,0)
3 | | | | |
4 | | | | | 

=> now hint is DR (Down-Right)
   -> we can reduce search area like below(no need to search in portion filled with '-')

   0 1 2 3
0 |-|-|-|-|           old index(0,0)
1 |-| | | |                            left=1, right=3, top=1, bottom=4
2 |-| |@|*|           row=(top+bottom)/2   col=(left+right)/2
3 |-| | | |           row=2                col=2
4 |-| | | |           new index(2,2)


=> now hint is R (Right)
   -> we can reduce search area like below(no need to search in portion filled with '-')

   0 1 2 3
0 |-|-|-|-|           old index(2,2)
1 |-|-|-|-|                              left=3, right=3, top=1, bottom=4
2 |-|-|@|*|           row=(top+bottom)/2   col=(left+r)ight/2
3 |-|-|-|-|           row=2                col=3
4 |-|-|-|-|           new index(2,3) which is desire location


Usefull points form example: 

-> opposite of given hint, respective field need to change.
   ex:- in hint of UL(Up-Left) we need to change(bottom and right)
   ex:- in hint of R(Right) we need to change only (right)

-> left will increase by one on column of old index
-> right will decrease by one on column of old index
-> top will increase by one on row of old index
-> bottom will decrease by one on row of old index







