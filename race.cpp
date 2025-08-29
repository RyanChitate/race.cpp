#include <iostream>   // lets us print stuff on the screen
#include <string>     // lets us use words/text (strings)
#include <random>     // gives us random numbers (like dice rolls)
#include <chrono>     // lets us work with time
#include <thread>     // lets us pause the program (so race doesn’t go too fast)

using namespace std;  // shortcut so we don’t have to write std:: everywhere

/*
 * Function: randomOddStep
 * -----------------------
 * This function is like a dice roller for the race.
 * Every time we call it, it returns a random odd number: 1, 3, or 5.
 * That number tells us how many steps forward a car should move.
 */
int randomOddStep(mt19937 &rng, int maxStep = 5) {
    // "uniform_int_distribution<int> dist(0, maxStep / 2);"
    // means: pick a random number between 0 and 2 (if maxStep = 5).
    uniform_int_distribution<int> dist(0, maxStep / 2); 

    // Multiply by 2 and add 1:
    // 0 → 1, 1 → 3, 2 → 5 (always odd).
    return dist(rng) * 2 + 1;
}

/*
 * Function: drawTrack
 * -------------------
 * This function is the "artist".
 * It draws the race track and shows where Car A and Car B are right now.
 */
void drawTrack(int trackLength, int carAPos, int carBPos) {
    // Make a string (row of dashes) as the empty race track.
    string track(trackLength, '-');

    // If cars go too far past the end, snap them back to the finish line.
    if (carAPos >= trackLength) carAPos = trackLength - 1;
    if (carBPos >= trackLength) carBPos = trackLength - 1;

    // Copy the track twice: one for Car A, one for Car B.
    string lineA = track;
    string lineB = track;

    // Place Car A’s symbol on its current position.
    lineA[carAPos] = 'A';

    // Place Car B’s symbol on its current position.
    lineB[carBPos] = 'B';

    // Print both tracks so we can see where each car is.
    cout << lineA << "  <\n";
    cout << lineB << "  <\n";

    // Print a line of '=' signs to mark the finish line area.
    cout << string(trackLength, '=') << "\n";
}

/*
 * Function: main
 * --------------
 * This is where the program starts.
 * Think of it as the "brain" that controls the race.
 */
int main() {
    int trackLength;  // how long the race track is

    // Ask the user to type the track length (instead of using arguments).
    cout << "Enter the track length: ";
    cin >> trackLength;

    // Set up the random number generator.
    // It’s seeded with the current time so every race is different.
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Start positions: both cars begin at index 0 (the starting line).
    int carA = 0, carB = 0;

    // Print a starting message.
    cout << "\n🏁 Starting the Turbo Text Grand Prix! 🏁\n";
    this_thread::sleep_for(chrono::milliseconds(800)); // wait a moment for suspense

    // Draw the starting positions before the race begins.
    drawTrack(trackLength, carA, carB);

    // The race loop: runs again and again until one car crosses the finish line.
    while (carA < trackLength && carB < trackLength) {
        // Move Car A and Car B forward by random odd steps.
        carA += randomOddStep(rng);
        carB += randomOddStep(rng);

        // Move the cursor UP 3 lines in the terminal.
        // Why? Because we always print 3 lines (Car A, Car B, finish line).
        // This way, the new race frame OVERWRITES the old one.
        // Result: smooth animation instead of a wall of text.
        cout << "\033[3A";

        // Draw the race track again with updated positions.
        drawTrack(trackLength, carA, carB);

        // Wait a little before the next move (400 ms = 0.4 seconds).
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    // After the loop, at least one car has reached the finish line.
    cout << "\nRace Results: \n";

    // Decide who won.
    if (carA >= trackLength && carB >= trackLength) {
        cout << "It’s a tie!\n";       // both cars finished same time
    } else if (carA >= trackLength) {
        cout << "A wins!\n";       // only Car A finished
    } else {
        cout << "B wins!\n";       // only Car B finished
    }

    return 0; // end of program, everything went fine
}
