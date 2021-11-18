#Python 3.8
# Rock, paper, scissors with a computer.
import random
import sys

print("""Hello there
The game will continue until you press (q) or (Q)
Only the words rock, paper and scissors are allowed to use as a move
Rock beats scissors, scissors beat paper and paper beats rock.
""")

possible_moves = ["rock", "paper", "scissors", "q"]

user_move = input("Your move: ").lower()
computer_move = random.choice(possible_moves)
user_score = 0
computer_score = 0

while True:
    while user_move not in possible_moves:
        user_move = input("Please only use rock, scissors or paper as your answer. ").lower()
    if user_move == "q":
        sys.exit()
    if user_move == "rock":
        if computer_move == "paper":
            print("Computer chose paper", "Computer wins", sep=" ---> ")
            computer_score += 1
        if computer_move == "scissors":
            print("Computer chose scissors", "You win", sep=" ---> ")
            user_score += 1
        if computer_move == "rock":
            print("Computer chose rock", "Draw", sep=" ---> ")
    if user_move == "scissors":
        if computer_move == "paper":
            print("Computer chose paper", "You win", sep=" ---> ")
            user_score += 1
        if computer_move == "rock":
            print("Computer chose rock", "Computer wins", sep=" ---> ")
            computer_score += 1
        if computer_move == "scissors":
            print("Computer chose scissors", "Draw", sep=" ---> ")
    if user_move == "paper":
        if computer_move == "scissors":
            print("Computer chose scissors", "Computer wins", sep=" ---> ")
            computer_score += 1
        if computer_move == "rock":
            print("Computer chose rock", "You win", sep=" ---> ")
            user_score += 1
        if computer_move == "paper":
            print("Computer chose rock", "Draw", sep="  ---> ")
    print(f"""
    Computer Score ---> {computer_score}
    Player Score ---> {user_score}
    """)
    user_move = input("Your move: ").lower()
    computer_move = random.choice(possible_moves)

