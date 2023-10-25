import random
import csv

class Player:
    def __init__(self, name, points=0, winner_bracket=True, eliminated=False):
        self.name = name
        self.points = points
        self.opponent = None
        self.winner_bracket = winner_bracket
        self.eliminated = eliminated

def load_players_from_csv():
    players = []
    try:
        with open("tournament_players.csv", "r") as csvfile:
            csv_reader = csv.reader(csvfile)
            for row in csv_reader:
                name, points = row
                players.append(Player(name, int(points)))
    except FileNotFoundError:
        pass
    return players

# ... (existing code)

def save_players_to_csv(players):
    with open("tournament_players.csv", "w", newline="") as csvfile:
        csv_writer = csv.writer(csvfile)
        for player in players:
            csv_writer.writerow([player.name, player.points])

def generate_match_pairs(players):
    random.shuffle(players)
    return [(players[i], players[i + 1]) for i in range(0, len(players), 2)]

def save_losers_to_csv(losers):
    with open("tournament_losers.csv", "w", newline="") as csvfile:
        csv_writer = csv.writer(csvfile)
        for loser in losers:
            csv_writer.writerow([loser.name, loser.points])

def load_losers_from_csv():
    losers = []
    try:
        with open("tournament_losers.csv", "r") as csvfile:
            csv_reader = csv.reader(csvfile)
            for row in csv_reader:
                name, points = row
                losers.append(Player(name, int(points), winner_bracket=False, eliminated=True))
    except FileNotFoundError:
        pass
    return losers

# ... (existing code)

def double_elimination(winners_bracket, losers_table):
    while len(winners_bracket) > 1:
        print("\nWinner's Bracket:")
        for index, player in enumerate(winners_bracket, start=1):
            print(f"{index}. {player.name}")

        print("\nLoser's Table:")
        for index, player in enumerate(losers_table, start=1):
            print(f"{index}. {player.name}")

        pairing_table_wb = generate_match_pairs(winners_bracket)
        for index, match in enumerate(pairing_table_wb, start=1):
            print(f"Winner's Bracket Match {index}: {match[0].name} vs {match[1].name}")
            # Process match winners and move losers to Loser's Table

    save_losers_to_csv(losers_table)  # Save updated losers to the file

    if len(losers_table) > 1:
        print("Do you want to start a match between the losers?")
        print("1: Yes")
        print("2: No")
        match_choice = int(input("Enter your choice: "))
        if match_choice == 1:
            print("Starting a match between the losers...")
            # Implement logic for matches between losers
            # Update points and manage winners and losers as needed
        else:
            print("Losers match skipped.")
def double_elimination(winners_bracket, losers_table):
    while len(winners_bracket) > 1:
        print("\nWinner's Bracket:")
        for index, player in enumerate(winners_bracket, start=1):
            print(f"{index}. {player.name}")

        print("\nLoser's Table:")
        for index, player in enumerate(losers_table, start=1):
            print(f"{index}. {player.name}")

        pairing_table_wb = generate_match_pairs(winners_bracket)
        for index, match in enumerate(pairing_table_wb, start=1):
            print(f"Winner's Bracket Match {index}: {match[0].name} vs {match[1].name}")
            # Process match winners and move losers to Loser's Table

    if len(losers_table) == 1:
        loser_winner = losers_table[0]
        print(f"The winner of the Loser's Table is: {loser_winner.name}")
        print("Do you want to compete against the single elimination winner?")
        print("1: Yes")
        print("2: No")
        compete_choice = int(input("Enter your choice: "))
        if compete_choice == 1:
            print("Time for a final showdown!")
            print(f"{loser_winner.name} vs {winners_bracket[0].name}")
            # Determine the overall winner based on points or other criteria
        else:
            print("Congratulations to the winners!")

    save_losers_to_csv(losers_table)  # Save updated losers to the file

def main():
    players = load_players_from_csv()
    winners = []
    losers = load_losers_from_csv()  # Load previously eliminated players

    while True:
        print("\nMain Menu:")
        print("1: Input Number of Players and Assign IDs")
        print("2: Start Tournament")
        print("3: View Standings")
        print("4: Save Players")
        print("0: Exit")
        
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            num_players = int(input("Enter the number of players: "))
            if num_players < 2:
                print("Need at least 2 players to create a match.")
            else:
                players = [Player(input(f"Enter the name of player {i + 1}: ")) for i in range(num_players)]
                save_players_to_csv(players)
                print("Players saved.")

       	elif choice == 2:
            if len(players) < 2:
                print("Need at least 2 players to start the tournament.")
            else:
                round_number = 1
                while len(players) > 1:
                    print(f"\nRound {round_number} Match Pairings:")
                    pairing_table = generate_match_pairs(players)
                    for index, match in enumerate(pairing_table, start=1):
                        print(f"Match {index}: {match[0].name} vs {match[1].name}")
                    for match in pairing_table:
                        print(f"Enter the winner for Match: {match[0].name} vs {match[1].name}")
                        print("1:", match[0].name)
                        print("2:", match[1].name)
                        print("0: Save and Exit")
                        winner_choice = int(input("Enter the winner (1, 2, or 0): "))
                        if winner_choice == 0:
                            save_players_to_csv(players)
                            print("Tournament progress saved.")
                            return
                        elif winner_choice == 1:
                            winner = match[0]
                            loser = match[1]
                        elif winner_choice == 2:
                            winner = match[1]
                            loser = match[0]
                        else:
                            print("Invalid choice, skipping match.")
                            continue
                        winners.append(winner)
                        winner.points += 2
                        winner.opponent = loser
                    players = winners
                    winners = []
                    round_number += 1
        elif choice == 3:
            for index, player in enumerate(sorted(players, key=lambda x: x.points, reverse=True), start=1):
                print(f"{index}. {player.name} - Points: {player.points}")
        elif choice == 4:
            save_players_to_csv(players)
            print("Players saved.")
        elif choice == 0:
            break
        else:
            print("Invalid choice. Please choose again.")

if __name__ == "__main__":
    main()
