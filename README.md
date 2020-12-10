 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Maze Game
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: Tyler Pastor, Andrew Middendorp, Daniel Nissan
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

> ## Project Description
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
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Abstract Factory Pattern
 > <img src="images/CS100AbstractFactoryDesignPattern.PNG?raw=true" width="600">
 
 > The Abstract Factory pattern encompasses our entire Maze Game project, due to its ability to call and display the correct interface based on the user movement and user choices. The pattern is used to create the borders and path of the maze(using the singleton class created by Daniel, which reads in a pre-set .txt file), displays the pause menu when chosen to do so by the user(implemented by Daniel with its own set of images and user controls), and the mini game interface(a choice interface to skip the game or play with the risk of losing character health which is implemented by Andrew).
 
 > ## Strategy Pattern
 > <img src="images/minigames.png?raw=true" width="600">
 
 > When the user lands on a “Mini Game” space throughout the maze, they are presented with a choice(play the game with the risk of losing health or gaining points OR they can skip the game for a loss of 30 points). The user interface for the mini game is prompted by the abstract factory strategy.
 
 > ## Singleton Pattern
 > <img src="images/singleton.png?raw=true" width="600">
 
 > Both the MinigameOptions and the PauseMenu classes should have just one instance each. The MinigameOptions class will be called upon to display a graphic urging the user to choose whether to play or skip the minigame. The PauseMenu class will be called to pause the game and display a menu graphic that will gave the user the ability to resume the game, save their progress, or exit to the start menu.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
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
 
 ## Installation/Usage
 > Instructions on installing and running your application 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
> * Minigame Testing
>   * The minigames were tested using one source file as a test suite.
>   * The first test takes user input in the same manner as it would in game, and the test checks to make sure that the required values are being updated.
>   * The second test makes sure that if a user loses enough health by losing minigames, that the program lets them know they died and that the game is over.

> * Pause Menu & Minigame Options Menu Testing
>   * To test the individual functions in these classes, multiple test files were made, each of which tests a single function.
>   * For those functions which display a graphic, they were tested to see whether the image could be located, and if so, a letter would be printed pertaining to which direction >     and which image the user decides to move to.
>   * The other functions do not have a return value, so they are tested on whether they save the correct information to a file, exit the menu and load it up at a later time, 
>     and return the right count value for the userControl function.
