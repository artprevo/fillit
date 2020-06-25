# fillit
Can you feel it ? Tangram project !

usage : 

./fillit examples/...

This project is based around optimization of space.
The VM gives us a grid and pieces, and the goal is to organize pieces in the grid so we can take the minimum space.

The algorithm is kinda unique cause instead of a classical linked-list we made it with a char** to optimize time of process. It makes it quite simple, only using two lines of
recursion to place pieces. It results in a really fast program.
