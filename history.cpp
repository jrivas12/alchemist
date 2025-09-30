#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Player {
public:
    string name;
    int points;
    Player(string n, int p = 0) : name(n), points(p) {}
};

vector<Player> load_players_from_file() {
    vector<Player> players;
    ifstream file("tournament_players.csv");
    if (file.is_open()) {
        string name;
        int points;
        while (file >> name >> points) {
            players.emplace_back(name, points);
        }
        file.close();
    }
    return players;
}

void save_players_to_file(const vector<Player>& players) {
    ofstream file("tournament_players.csv");
    if (file.is_open()) {
        for (const Player& player : players) {
            file << player.name << " " << player.points << "\n";
        }
        file.close();
    }
}

vector<pair<Player, Player>> generate_match_pairs(const vector<Player>& players) {
    vector<Player> shuffled_players = players;
    random_shuffle(shuffled_players.begin(), shuffled_players.end());
    vector<pair<Player, Player>> pairs;
    for (size_t i = 0; i < shuffled_players.size(); i += 2) {
        pairs.emplace_back(shuffled_players[i], shuffled_players[i + 1]);
    }
    return pairs;
}

int main() {
    vector<Player> players = load_players_from_file();
    vector<Player> winners;

    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1: Input Number of Players and Assign IDs\n";
        cout << "2: Start Tournament\n";
        cout << "3: View Standings\n";
        cout << "4: Save Players\n";
        cout << "0: Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int num_players;
            cout << "Enter the number of players: ";
            cin >> num_players;
            if (num_players < 2) {
                cout << "Need at least 2 players to create a match.\n";
            }
            else {
                players.clear();
                for (int i = 0; i < num_players; ++i) {
                    string name;
                    cout << "Enter the name of player " << i + 1 << ": ";
                    cin >> name;
                    players.emplace_back(name);
                }
                save_players_to_file(players);
                cout << "Players saved.\n";
            }
        }
        else if (choice == 2) {
            if (players.size() < 2) {
                cout << "Need at least 2 players to start the tournament.\n";
            }
            else {
                int round_number = 1;
                while (players.size() > 1) {
                    cout << "\nRound " << round_number << " Match Pairings:\n";
                    vector<pair<Player, Player>> pairing_table = generate_match_pairs(players);
                    for (size_t i = 0; i < pairing_table.size(); ++i) {
                        cout << "Match " << i + 1 << ": " << pairing_table[i].first.name << " vs " << pairing_table[i].second.name << "\n";
                    }
                    for (auto& match : pairing_table) {
                        cout << "Enter the winner for Match: " << match.first.name << " vs " << match.second.name << "\n";
                        cout << "1: " << match.first.name << "\n";
                        cout << "2: " << match.second.name << "\n";
                        cout << "0: Save and Exit\n";
                        int winner_choice;
                        cout << "Enter the winner (1, 2, or 0): ";
                        cin >> winner_choice;
                        if (winner_choice == 0) {
                            save_players_to_file(players);
                            cout << "Tournament progress saved.\n";
                            return 0;
                        }
                        else if (winner_choice == 1) {
                            winners.push_back(match.first);
                        }
                        else if (winner_choice == 2) {
                            winners.push_back(match.second);
                        }
                        else {
                            cout << "Invalid choice, skipping match.\n";
                            continue;
                        }
                        match.first.points += 2;
                        match.second.points += 2;
                    }
                    players = winners;
                    winners.clear();
                    ++round_number;
                }
            }
        }
        else if (choice == 3) {
            sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
                return a.points > b.points;
                });
            for (size_t i = 0; i < players.size(); ++i) {
                cout << i + 1 << ". " << players[i].name << " - Points: " << players[i].points << "\n";
            }
        }
        else if (choice == 4) {
            save_players_to_file(players);
            cout << "Players saved.\n";
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid choice. Please choose again.\n";
        }
    }

    return 0;
}