# C++ Projects

This repo is a collection of projects I have developed in C++ at my spare time during my undergrad in order to practice my C++ programming skills. Most of the programs here are relatively simple and are developed in nature to sharpen my skills. I do intend however, to add more C++ projects to this repo in the future as a graduate student and as a post graduate to further expand my C++ programming capabilities related both to procedural and object-oriented programming as well as taking a jab possibly at IOT or other embedded sysmtes. Repetitio est mater studiorum.

## Folder/File Structure

```plaintext
├── GPA_calculator
├── Trucks
├── Website
├── carpet_area
├── coffee_shop
├── computer_labs
├── count_capital_letters
├── shopping_list
├── tic_tac_toe
└── tipping_calculator
```

## Projects

1. GPA Calculator
- This program allows the user to calculate their GPA. The user can calculate their GPA in two ways:
  - The user can enter all of their grades with the respective weights for each grade.
    - This option allows the user to compute all of their grades one by one.
  - The user can enter the number of earned credits and the number of how many credits the student could have possibly earned.
    - This option allows the user to compute their "average" grade.
2. Trucks
- This program opens a file containing information about trucks. The purpose of this program is to develop classes, in this case two for a Vehicle and a Truck. When the file is opened and the data is read in from the file, the respective information about the trucks such as year, manufacturer, model, mile per gallon and towing capacity are extracted and are then displayed on the screen in the terminal.
3. Website
- This program prompts the user to enter their name and a short description about themself, which will then create for the user a simple `index.html` file, which the user can choose if they like, to be a starting point for developing a personal website. 
4. Carpet Area
- This program very simply prompts the user to enter the length and width of a carpet in order to calculate the carpet's area. Once the two inputs have been made, the area is calculated and displayed on the screen.
5. Coffee Shop
- This program prompts the user to enter the number of coffee(s), bagel(s), and donut(s) they would like to purchase and once those numbers are recieved by the program, the price for each is computed, the total price is computed, and the total price including the tax is also computed. This number is then displayed to the user where they now have two routes:
  - The user pays a number that is less than the total computed number, and the user recieves an error message and is prompted again to pay a price that is either the same or more than the computed price.
  - The user pays a number that is the same or more than the computed price in the program, and the user then sees a receipt on the screen with their name, the number of each product they ordered, the total price before and after taxes, the amount the user paid, and how much change the user will recieve if any. 
6. Computer Labs
- This program simulates a basic login, logout, search and exit of a user wanting to know how many computers are free to use or are in use in a computer lab. The number of labs is harde-coded to be 4, however the user is able to input however many computers are in each lab. Once this information is complete, the user has a choice to login, logout or search for a computer being used based on a computer ID that each user inputs. 
7. Count Capital Letters
- This program simply asks the user to input a file or a sentence they would like to analyze and count the number of capital letters that are present. Once the user passes a file or sentence (based on the choice they make), a numerical output will be returned accurately letting the user know of how many capital letters there are. 
8. Shopping List
- This is a simple program in which the user inputs information for 5 items (5 is hard-coded). The information the user inputs for each item are the item's name, how much of that item, and the price per item. Once all of these inputs have been passed in for 5 separate items, the total cost of all 5 items is calculated, and all the information and total price is printed on the screen. 
9. Tic Tac Toe
- This is a Tic Tac Toe Game developed in C++. All of the rules and functionality of Tic Tac Toe have been considered here, namely:
  - Prompting two users to enter their names
  - Deciding which player goes fist (random) and switching turns for each player to go.
  - Displaying the game.
  - Checking all conditions of a user winning (diagonals, rows, and columns).
  - Checking if the board is full without a win or lose state of the game (draw).
10. Tipping Calculator
- This program allows the user to not only to input a tip for a bill presented after a meal or service, but it allows the user to split the bill with others depending on how many other people have partaken in the meal or service. If the user decides to leave a tip based on a percentage of the total, the user can then make three decisions:
  - Keep the calculated tip amount (with change).
  - Round down the calculated tip amount (smallest number without change).
  - Round up the calculated tip amount (highest number including extra change).
- Depending on what the user chooses, and how many other people are splitting the bill, a calculation will be made letting the user know how much money each person should pay, equally spliting the bill and leeting the user know how much money has been lost, saved, or neither depending on which one of the three choices was decided upon.
