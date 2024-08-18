# NeuronetiX-Projects-C++
# Pet Adoption Game

## 1. Introduction
The Pet Adoption Game is a console-based application that simulates the experience of adopting and taking care of a pet. Users can adopt a pet, feed it, play with it, and check its status. The game tracks the pet's hunger and happiness levels, and it ends if these levels drop to critical values.

## 2. System Overview
The game provides the following functionalities:
1. **Adopt a Pet:** Start the game by adopting a pet.
2. **Feed the Pet:** Increase the pet's hunger level by feeding it.
3. **Play with the Pet:** Increase the pet's happiness level by playing with it.
4. **Check Status:** View the current hunger and happiness levels of the pet.
5. **End Game:** End the game and view the final status of the pet.

## 3. Features and Functionality

### 3.1. Adopt a Pet
**Purpose:** To start the game by adopting a pet.  
**Process:**
- **Name:** Enter the name of the pet. This name will be used to identify the pet throughout the game.
- **Initial Levels:** Set the initial hunger and happiness levels to 50 each.
- **Confirmation:** The system confirms that the pet has been adopted and is ready to be cared for.

### 3.2. Feed the Pet
**Purpose:** To increase the pet's hunger level by feeding it.  
**Process:**
- **Increase Hunger:** If the pet's hunger level is below 90, feeding it will increase the hunger level by 10.
- **Full Condition:** If the hunger level is already at 90, the pet is considered full, and no further increase is allowed.

### 3.3. Play with the Pet
**Purpose:** To increase the pet's happiness level by playing with it.  
**Process:**
- **Increase Happiness:** If the pet's happiness level is below 90, playing with it will increase the happiness level by 10.
- **Satisfaction Condition:** If the happiness level is already at 90, the pet is considered too happy, and no further increase is allowed.

### 3.4. Check Status
**Purpose:** To view the current status of the pet.  
**Information Provided:**
- **Hunger Level:** Displays the current hunger level of the pet.
- **Happiness Level:** Displays the current happiness level of the pet.

### 3.5. End Game
**Purpose:** To end the game and view the final status of the pet.  
**Process:**
- **Final Status:** The system shows the final hunger and happiness levels before ending the game.
- **Game Over:** The game ends, and the user is informed that the game is over.

## 4. How to Use

### 4.1. Using the Menu:
- **Adopt Pet:** Choose this option to adopt a new pet. Enter the pet's name when prompted.
- **Feed Pet:** Select this option to feed the pet and increase its hunger level.
- **Play with Pet:** Choose this option to play with the pet and increase its happiness level.
- **Check Status:** Use this option to view the pet's current hunger and happiness levels.
- **End Game:** Select this to end the game and view the final status of the pet.

### 4.2. Example Workflow:
- **Adopt:** Adopt a pet named "Buddy". The pet's hunger and happiness are set to 50.
- **Feed:** Feed "Buddy" to increase its hunger level.
- **Play:** Play with "Buddy" to increase its happiness level.
- **Check Status:** Check "Buddy"'s current hunger and happiness levels.
- **End:** End the game and see "Buddy"'s final status.

## 5. Troubleshooting
- **Invalid Actions:** Ensure that actions like feeding and playing are only performed after adopting a pet. The system
