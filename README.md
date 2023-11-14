# 923-4FSC0PF001-Summative

Welcome to the 923-4FSC0PF001 Summative.

1. Find the issues in the repository and make it work.
2. Factorize that monolitihc main into functions and classes
3. 3 hours

The program is a "Space invader like".
A starship (black triangle at the bottom) can move from left to right (following the mouse)
You can shoot with left click and destroy some targets (Red squares into a grid at the top part of the screen)

https://github.com/SAE-Geneve/923-4FSC0PF001-Summative/assets/348225/860551fb-427a-465a-b1be-220db59471f7

**You have to make it work as described above**

## Task 1 : Find the issues in the repository and make it work.
There are 3 kinds of bugs :
* **syntax and linking issues :** the code does not compile. These issues can be complex mistakes, as they can be trivial typing errors. find them and make it compile.
* **runtime issues :** program compiles, run but crashes after a while
* **functional issues:** program compiles, run but does not do what it is expected, compare with description and video

### if you do not succeed to fix all required issues, you can download the following repository. As a consequence, your maximum note will be automatically truncated to 5. 

## Task 2 : Factorize
* Create the following class : game, projectile, invader, starship and move the related code
  * ``Game`` class handle the core programing elements :
    * 1 method setup : setup SFML variable and others classes
    * 1 method loop : handle all the cyclic and repeated programming elements
    * data structures
    * input events (trigerring other classes)
  * ``Projectile`` class handle ALL programming elements required to handle a single projectile logic entity
    * autonomus move functions
    * Graphical definition
    * constants values, numrical definitions relative to a projectile logic entity
  * ``Invader`` class handle ALL programming elements required to handle a single projectile logic entity
    * Graphical definition
    * constants values, numrical definitions relative to a invader logic entity
  * ``Starship`` class handle ALL programming elements required to handle the starship
    * player controlled move functions
    * Graphical definition
    * constants values, numerical definitions relative to the starship

## don't forget use all tools on your disposal, debug windows and tabs, breakpoints, or your own projects and lecture ressources.
## uses of Chat GPT, or student-to-student communication is strictly forbidden 

