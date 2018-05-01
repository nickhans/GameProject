# KaleidEscape - Current Version v1.0
## Info About The Game
### What is KaleidEscape?
KaleidEscape is a text-based escape room game. The objective of the game is simple, escape through a trapdoor! In order to unlock the trapdoor, the player must complete a series of small puzzle in order to find four metal shapes of which they must return to a trapdoor.
### Why is it called KaleidEscape?
The game starts in a circular room. Around the outside of the center room is 6 other rooms. As the player progresses through the game, the outside rooms swap around, sort of like the colors in a kaleidoscope.
### Who created KaleidEscape?
KaleidEscape is developed by Nick Hanselman and Nahum Tariku. This game was developed for a C-Programming course at the University of Colorado, Boulder.
## How Can I Play?
To play KaleidEscape, downloaded the latest build from the github master branch and double-click the file named KaleidEscape. This only works if you have the gcc compiler downloaded on your computer. An alternative way to run this is to open the file in the terminal and type './compile.sh'. You may have to change permissions on this shell file with 'chmod +x compile.sh'. This game was built on macOS but should work on any Unix system (unsure about WindowsOS).
## Instructions
The goal of the KaleidEscape is to find four shapes, square, circle, triangle, and star. Find these shapes and return them to the trapdoor in the center room. In this game there are objects, containers, and locations. Containers are objects that can hold other objects and locations can hold both objects and containers. Containers cannot be moved. The player may pick up one object at a time and place it into any room or any container. The player can move from the center room into any room numbered 1 through 6. In the numbered rooms, the player can move clockwise (cw), counter-clockwise (ccw), or to the center. The player may also examine the room or examine any object or container. 

Here is a list of the commands:
* examine
* go
* take
* drop
* put
* remove
* inventory
* help

The player may use the help command to get more information on each of the other commands.

This game is case sensitive and all commands, objects, containers, and locations are lower-case. Also, the game only reads the first two words of the player's input. This means that 'put trapdoor' and 'put trap door' are two completely different things. Make sure you enter commands accurately. When in doubt examine the room to find the names of the objects in that room.

## Main Features
1. Structures for Locations, Objects, Containers, and the Player
    * Locations, Objects, and Containers are stored in arrays for easy new additions
2. Move Mechanic - go command
    * Player can move from center to any numbered room 1-6
    * Player can move in numbered rooms clockwise (cw) or counter-clockwise (ccw)
    * Player can move from numbered rooms back to center
3. Examine Mechanic - examine command
    * Player can examine room to get a description of the room and a list of the objects/containers in the room 
    * Player can examine an object to get the description of the object
    * Player can examine a container to get the description of the container and a list of objects in the container
4. Object Management - take/drop commands
    * Player can take an object from a room and put it in their inventory with the take command
    * Player can remove the object in their inventory with the drop command
5. Inventory Management - inventory command
    * Player can check the contents of their inventory with the inventory command
6. Container Management - put/remove commands
    * Player can put the object in their inventory into a container with the put command
    * Player can remove an object from a container and put it in their inventory with the remove command
7. Help Mechanic - help command
    * Player can pull up a help guide on these commands with the help command
### Additional Features
* Room randomization of outside numbered rooms upon entering the center room
* End-of-game condition - Return all four shapes to the trapdoor in the center room
* Timer to keep track of total time to escape
* Event system to manage small puzzle challenges
* Highscore tracking system


