Turbo Text Grand Prix
======================

A text-based race simulator written in C++ for a weekly mini-hackathon.  
Two cars race across an ASCII track, moving forward by random odd-numbered steps until one crosses the finish line.  
The program renders the race step by step in the terminal and announces the winner (or a tie).

----------------------
Features
----------------------
- Random movement using odd steps (1, 3, 5, …)  
- Live ASCII race track rendering in the terminal  
- Independent randomness for each car  
- Winner (or tie) announced at the end  

----------------------
Getting Started
----------------------

Requirements:
- A C++11 (or newer) compiler (e.g., g++)  
- A terminal to run the program  

Build and Run:
    g++ -std=c++11 race.cpp -o race
    ./race 30

- Replace 30 with the desired track length.  
- The race will display step by step until one car wins.  

----------------------
Example Output
----------------------
A-----------------------------
-B----------------------------
==============================
-----A------------------------
----B-------------------------
==============================
Car A wins!

----------------------
Future Enhancements
----------------------
- Add live commentary (e.g., "Car A takes the lead!")  
- Use ANSI escape codes for colorful output  
- Implement power-ups and additional racers  
- Tournament mode (--bestof N)  
- Export race results to a leaderboard file  

----------------------
License
----------------------
This project is open source and available under the MIT License.
