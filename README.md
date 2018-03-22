# Keep Talking and Nobody Explodes Puzzle Aids
This console program can be used to solve 3 types of puzzles from the game *Keep Talking and Nobody Explodes*, based on the manual, http://www.bombmanual.com/manual/1/html/index.html. Both *Complicated Wires* can solve a puzzle perfectly, however *Morse Code* can only give possible suggestions of the answer but no guarantee.

The puzzles that can be solved are:

- Passwords
- Complicated Wires
- Morse Code

## Installation
This project contains the entire solution for visual studio. If visual studio is installed, then load up the solution and compile the project.

## Usage
Upon leading the .exe, the user will be prompted with 3 options. To select an option, press the number then press enter to confirm. Pressing / will return a selection back to the inital menu. 

Each type of puzzle solver has slightly different usage instructions.

- Password Cracker: In the game, there will be a word consisting of 5 positions with an assortment of possible letters in each position. Cycle through all of the letters in each position and enter each letter into the console application as requested. Afterwards, if the letters were inputed correctly, the password will be displayed. Duplicate letters have no negative bearing.

- Complicated Wires: 5 questions will be asked, each of which have a true or false answer. To select, press t for true or f for false, then press enter. Afterwards, if the inputs were correctly entered, the proper action will be displayed.

- Morse Code: A blank screen will appear. Based on actual morse code, enter **.** for a **dit** and **-** for a **dah**. Afterwards, press enter to confirm. A translated word in English will be displayed, with | representing an incorrect morse code. Beneath the English translation, two other sections will be displayed: *Count Letters* are any words that contain any of the letters inputed from morse code; *Matching Letters* are words that have the same letters in the same position as the inputed word. Next, a number within square brackets is displayed, representing the accuracy of the top words. Next, the top 3 likely words will be displayed along with their frequency required for the game. Finally, two ** represent that there are more than 3 words words matching the input word.   

## Outcome
This was a personal programming challange for me to solve, but it is my hope that it may inspire other programmers to find enjoyable ways of incorperating code into everyday activities.
