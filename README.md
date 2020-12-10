# Maze Game

 > Authors: Tyler Pastor, Andrew Middendorp, Daniel Nissan

> # Project Proposal Phase 1
> # Title: Maze Game

> Group Members: Andrew Middendorp, Tyler Pastor, Daniel Nissan (Section 23)

> Project Description:
> Why is it interesting: We've been interested in creating a video game in c++ for quite some time and this project gives us the ability to test our skills in creating a beginner game. This beginner game contains basic user control and features, however, it is seen as a bit of a challenge with the skills we have acquired so far throughout our college experience. We are excited to try something new with the knowledge we’ve gained and other skills we have obtained.

> Languages/Tools/Technologies: C++, OpenCV, Blender(Possibly audio software) 

> Input/Output: 
> * Input: User specified controls, future directional movement of their character, and user input for menu options/mini games.
> * Output: The animation of character movement/display directional movement and other interfaces(pause menu and mini games)

> Design Patterns: (Must pick two of these: Composite, Strategy, Abstract Factory, or Visitor)
> * Abstract Factory
>   * The Abstract Factory design pattern is used to create an interface which encapsulates a variety of different objects. The call to the different objects, such as pause menu, maze display, and mini game display can be found in the abstract factory pattern. It provides an organized call to each of the repsective classes based on the user input.
> * Strategy
>   * Strategy is used to implement the mini games at each location. The Strategy design pattern uses runtime decision to see which game is supposed to run at each space(the user choice). Moreover, the implementation of each mini game may use some of the functions or operations.
> * Singleton
>   * The Singleton pattern is best implemented when one class is instantiated once, which fits perfectly with the area/borders of the maze and the reusable pause menu interface.



 > ## Phase II
 
 > ## Abstract Factory Pattern
 > <img src="images/CS100AbstractFactoryPattern.jpg?raw=true" width="600">
 
 > The Abstract Factory pattern encompasses our entire Maze Game project, due to its ability to call and display the correct interface based on the user movement and user choices. The pattern is used to create the borders and path of the maze(using the singleton class created by Me, which reads in a pre-set .txt file), displays the pause menu when chosen to do so by the user(implemented by Daniel with its own set of images and user controls), a start Menu(implemented by Me), and the mini game interface(a choice interface to skip the game or play with the risk of losing character health which is implemented by Daniel).
 
 > ## Strategy Pattern
 > <img src="images/minigames.png?raw=true" width="600">
 
 > When the user lands on a “Mini Game” space throughout the maze, they are presented with a choice(play the game with the risk of losing health or gaining points OR they can skip the game for a loss of 30 points). The user interface for the mini game is prompted by the abstract factory strategy.
 
 > ## Singleton Pattern
 > <img src="images/singleton.png?raw=true" width="600">
 
 > Both the MinigameOptions and the PauseMenu classes should have just one instance each. The MinigameOptions class will be called upon to display a graphic urging the user to choose whether to play or skip the minigame. The PauseMenu class will be called to pause the game and display a menu graphic that will gave the user the ability to resume the game, save their progress, or exit to the start menu.

 > ## Final deliverable
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 > * Daniel's Screenshots:
 > <img src="daniel-tests/Screenshot_1.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_2.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_3.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_4.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_5.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_6.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_7.png?raw=true" width="600">
 > <img src="daniel-tests/Screenshot_8.png?raw=true" width="600">
 
 > * Andrew's Screenshot:
 > <img src="images/MinigameTest.png?raw=true" width="600">
 
  > * Tyler's Screenshots:
 
 ## Installation/Usage
 > Instructions on installing and running your application: 
 
 > In order to run the Maze Game a few things must be installed to your local machine. The first thing is an IDE that has the capability to run c++ code(Visual Studios - Community). Once you have installed that, you are going to want to download the free open source library used for the program called OpenCV. Follow the instructions on how to properly include all libraries and respective includes for your IDE. Lastly, you must download all images and video files to a known location on your local machine. These paths to these image and video files will allow specific images and/or videos to be displauyed based on the user input. Thank you for reading! Happy gaming and enjoy...
 # THE MAZE GAME
 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
> * Minigame Testing
>   * The minigames were tested using one source file as a test suite.
>   * The first test takes user input in the same manner as it would in game, and the test checks to make sure that the required values are being updated.
>   * The second test makes sure that if a user loses enough health by losing minigames, that the program lets them know they died and that the game is over.

> * Pause Menu & Minigame Options Menu Testing
>   * To test the individual functions in these classes, multiple test files were made, each of which tests a single function.
>   * For those functions which display a graphic, they were tested to see whether the image could be located, and if so, a letter would be printed pertaining to which direction
>     and which image the user decides to move to.
>   * The other functions do not have a return value, so they are tested on whether they save the correct information to a file, exit the menu and load it up at a later time, 
>     and return the right count value for the userControl function.
