# PROJ_PROG_2

## Group Members:

- Fábio Araújo de Sá (up202007658)
- Pedro Pereira Ferreira (up202004986)

## Additional Specifications:

- Showing the winners: We have decided that the program will show all the winners of every maze (if the maze has at least a winner), and the time spent by each on as well;

- Robot collisions with fences: If a live robot collides with an electrified fence, it becomes a stuck robot and remains in its current position and also the fence changes its status (that is, it becomes a non-electrified post);

- Exit gates: Since it was easier to determine the win situation, in case the player has escaped trough an exit gate, we have decided to create a new class named as "Portal", which attributes are the coordinates and the status of the portal. It also makes that all the elements of the maze are objects of type Class;

- Records: We have devided to insert the name of the winner in case it does not exist in the Record's file of the corresponding maze or it exists but the player has completed the maze in a better time, which means it has a new record associated to that name. If the time spent by the user to complete the name is higher than the time on the file, nothing is modified on the Record's file; however, the user is informed that a better time already exists;

- Rewrite the Record's file: we have decided to use sets (set <int,string> records) in order to allocate temporarily the winners list to be rewritten, so that it could automatically remove the repeated winners lines; those lines are sorted by ascending order of the times spent to complete the maze, and are sorted lexicographically in case two or more winner have the same time. This also results in a better efficiency on file's load and store of .txt files to the STL container;

## Program Development State:

All the objectives of this project were completed:

- [X] Separate compilation: This objective was achieved since the all the class structures are written in .hpp files and the its methods are written in .cpp files, in addition of that the menu, the selection of the maze and the winners function are also in .cpp files;

- [X] "Object oriented" program paradigm: This objective was achieved since we created the classes Maze, Player, Post, Robot, Game and Portal, and almost all the functionality of the program was secured due to the use of the methods of those classes;

- [X] Management of invalid keyboard inputs: This objective was achieved, since all the possible invalid inputs, were taken from the buffer and the modified flags were cleared, thanks to cin.clear() and cin.ignore() commands, and also a error message is displayed on the screen, asking the user for a valid input until he/she types a valid command;

- [X] Development of simple program interfaces: This objective was completed because we displayed on the screen a menu which indicates the possible commands executable (show the rules, choose a maze to play, the winners and exit), asking the user to type the respective number of each command; while playing, the maze is displayed on the screen and asks the user to select a button in order to move on the maze in each play, by using cin and cout; if he/she wins, the user is asked to input its name, in order to display it on the records file, with a getline command;

- [X] Using of flags: Comparing to the previous project, we use "flags" (boolean variable that change its value according to certain situations) to prevent form the usage of the recursion: for example, if the user selects a valid maze, the flag want_play, which value is initially false, becomes true, and it allows to start the game it self;

- [X] Play again: Thanks to the using of the flags, we modified the program so that the user could play again without finishing the program's execution- at the end of the game, the user is asked if he/she wants to play again and according to the character inputed ('y'/'Y' if he/she wants to play again or 'n'/'N' in negative case) and the main menu is shown or not, in the respective cases;

## Main Dificults

- Maze selection: Due to invalid inputs on the selection of the maze, we struggle to create a function which was robust enough so that it could deal with that inputs.

### How we solved:

- We separate the conditions that makes the name of the maze valid and we use a boolean variable flag to control the corresponding repetition structure.

<br>