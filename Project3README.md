# Multiplication Learning Game

## 1. Introduction

The Multiplication Learning Game is a console-based educational application designed to help users practice multiplication skills. Users are challenged with multiplication questions, and their performance is tracked across different difficulty levels. The game adjusts its difficulty based on the user's performance and provides feedback on their progress.

## 2. System Overview

The game provides the following functionalities:

1. **Start Game**: Begin a new game session where users answer multiplication questions.
2. **Help**: Access instructions and rules for playing the game.
3. **Show High Score**: View the highest score achieved in the game.
4. **Exit**: Close the game application.

## 3. Program Structure

The program contains the following:

- **Player struct**: A player struct contains the following information:

  - Name of the player.
  - Difficulty of the game (initialized as “easy”).
  - The player’s high score (initialized as 0).
  - The player’s current score (initialized as 0).
  - Number of successive correct answers (initialized as 0).
  - Number of successive incorrect answers (initialized as 0).
  - Question number (initialized as 0).

- **Reset Player function**:

  - **Purpose**: This function resets the struct variables to their initial values.
  - **Process**:
    1. Resets difficulty to “easy”.
    2. Resets current score to 0.
    3. Resets the number of successive correct answers to 0.
    4. Resets the number of successive incorrect answers to 0.
    5. Resets question number to 1.

- **Start Game function**:

  - **Purpose**: Starts a new game of multiplication questions.
  - **Process**:
    1. Calls reset player to start a fresh game every time.
    2. User is prompted to enter their name.
    3. Question number is incremented.
    4. Multiplication questions are generated based on the difficulty level.
       - **Difficulty levels**:
         - Easy: the numbers generated are between 1 and 5.
         - Normal: the numbers generated are between 5 and 10.
         - Hard: the numbers generated are between 5 and 15.
    5. User enters their answer, and it is checked for correctness.
       - If correct:
         1. The number of successive correct answers is incremented.
         2. The number of successive incorrect answers is set to 0.
         3. Current score is increased by 10.
       - If incorrect:
         1. The number of successive incorrect answers is incremented.
         2. The number of successive correct answers is set to 0.
    6. **High score adjustment**:
       - Checks if the current score is greater than the high score:
         - If true: high score = current score.
         - Else: high score remains unchanged.
    7. **Difficulty adjustment / Game ending**:
       - After 3 consecutive correct answers, the difficulty automatically increases, and the number of successive correct answers is reset. If this happens when the user is already at the most difficult level, the game exits to the menu with the message: “Congrats! You’ve completed the game!”.
       - After 3 consecutive incorrect answers, the game ends with the message: “Game over. Please ask your teacher for help,” and the high score is shown.
       - If the threshold of 20 questions is reached, the game ends.

- **Help function**:

  - **Purpose**: Help the user understand the game.
  - **Process**: Shows the game description and details on the difficulty levels.

- **Show high score function**:

  - **Purpose**: Shows the high score.
  - **Process**: Shows the highest number of correct answers in the last game played by the player.

- **End Game function**:
  - **Purpose**: Exits the program.
  - **Process**: Checks if the player is sure to exit the game:
    1. If the user answers ‘y’: Program is terminated.
    2. Else: Main menu is shown.

## 4. Error Handling

- **Invalid Menu Option**: If the user selects an invalid option, they are prompted to choose a valid option again.
- **Game Over**: The game ends if the user gets 3 consecutive wrong answers, and a “Game over. Please ask your teacher for help” message is displayed along with the high score.
- **Game Completed**: If the user answers 3 consecutive questions correctly while being in the “hard” difficulty, the game ends, and the message: “Congrats! You’ve completed the game!” is shown.

## 5. Code Details

- **Random Number Generation**: The game uses the `<cstdlib>` library for `std::rand()` and `std::srand()` to generate random numbers for question creation.
- **Time Seeding**: The `<ctime>` library provides `std::time()` for seeding the random number generator, ensuring that each game session generates unique questions.
