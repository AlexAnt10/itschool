#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

template <typename T>
string to_string(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

class Card {
public:
    int value;
    Suit suit;

    Card(int v, Suit s) : value(v), suit(s) {}

    string printCardToString() const {
        string cardValue;
        if (value == 1)
            cardValue = "Ace";
        else if (value == 11)
            cardValue = "Jack";
        else if (value == 12)
            cardValue = "Queen";
        else if (value == 13)
            cardValue = "King";
        else
            cardValue = to_string(value);

        string suitName;
        switch (suit) {
        case HEARTS: suitName = "Hearts"; break;
        case DIAMONDS: suitName = "Diamonds"; break;
        case CLUBS: suitName = "Clubs"; break;
        case SPADES: suitName = "Spades"; break;
        }

        return cardValue + " of " + suitName;
    }

    int getBlackjackValue() const {
        if (value > 10) {
            return 10;
        }
        return value;
    }
};

class Deck {
private:
    vector<Card> deck;
    int currentCardIndex;

public:
    Deck() {
        for (int suit = HEARTS; suit <= SPADES; ++suit) {
            for (int value = 1; value <= 13; ++value) {
                deck.push_back(Card(value, static_cast<Suit>(suit)));
            }
        }
        currentCardIndex = 0;
        srand(static_cast<unsigned int>(time(0)));
    }

    void shuffleDeck() {
        for (int i = 0; i < deck.size(); ++i) {
            int randIndex = rand() % deck.size();
            swap(deck[i], deck[randIndex]);
        }
    }

    Card dealCard() {
        if (currentCardIndex >= deck.size()) {
            shuffleDeck();
            currentCardIndex = 0;
        }
        return deck[currentCardIndex++];
    }
};

class Player {
public:
    vector<Card> hand;
    bool isDealer;
    string playerName;
    double balance;
    double currentBet;
    bool eliminated;
    bool doubledDown;

    Player(bool dealer = false, string name = "Player", double startBalance = 1000.0)
        : isDealer(dealer), playerName(name), balance(startBalance), currentBet(0.0), eliminated(false), doubledDown(false) {}

    void takeCard(Card card) {
        hand.push_back(card);
    }

    int getHandValue() const {
        int totalValue = 0;
        int aces = 0;

        for (const Card& card : hand) {
            int value = card.getBlackjackValue();
            totalValue += value;
            if (value == 1) {
                aces++;
            }
        }

        while (aces > 0 && totalValue + 10 <= 21) {
            totalValue += 10;
            aces--;
        }

        return totalValue;
    }

    bool isBusted() const {
        return getHandValue() > 21;
    }

    string getPlayerName() const {
        return playerName;
    }

    bool isDealerPlayer() const {
        return isDealer;
    }

    void placeBet() {
        if (eliminated || balance <= 0) {
            cout << playerName << " has been eliminated and cannot place a bet." << endl;
            return;
        }
        do {
            cout << playerName << ", you have $" << balance << ". Enter your bet: $";
            cin >> currentBet;
            if (cin.fail() || currentBet <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid bet amount. Please enter a positive number." << endl;
                currentBet = 0;
            }
            else if (currentBet > balance) {
                cout << "You cannot bet more than your current balance!" << endl;
            }
        } while (currentBet > balance || currentBet <= 0);

        balance -= currentBet;
    }

    void winBet() {
        balance += currentBet * (doubledDown ? 2 : 1);
        doubledDown = false;
    }

    void tieBet() {
        balance += currentBet;
        doubledDown = false;
    }

    void loseBet() {
        if (balance <= 0) {
            eliminated = true;
            cout << playerName << " has been eliminated from the game!" << endl;
        }
        doubledDown = false;
    }

    void resetHand() {
        hand.clear();
        currentBet = 0;
        doubledDown = false;
    }
};

void showPlayersHands(const vector<Player>& players, bool revealDealer = true) {
    cout << string(60, '-') << endl;
    for (const auto& player : players) {
        if (player.eliminated) continue;

        cout << setw(20) << left << player.getPlayerName() << endl;


        for (size_t j = 0; j < player.hand.size(); ++j) {
            if (j == 0 && player.isDealerPlayer() && !revealDealer) {
                cout << setw(20) << left << "Hidden Card" << endl;
            }
            else {
                cout << setw(20) << left << player.hand[j].printCardToString() << endl;
            }
        }


        if (!(player.isDealerPlayer() && !revealDealer)) {
            cout << setw(20) << left << "Total: " << player.getHandValue() << endl;
        }
        else {
            cout << setw(20) << left << "Total: ???" << endl;
        }

        cout << string(60, '-') << endl;
    }
}

bool isGameOver(const vector<Player>& players) {
    int activePlayers = 0;
    for (const auto& player : players) {
        if (!player.isDealerPlayer() && player.balance > 0) {
            activePlayers++;
        }
    }
    return activePlayers <= 1;
}

void playBlackjackRound(vector<Player>& players, Deck& deck) {
    for (auto& player : players) {
        if (!player.isDealerPlayer() && !player.eliminated) {
            player.placeBet();
        }
    }

    for (auto& player : players) {
        if (player.eliminated) continue;
        player.resetHand();
        player.takeCard(deck.dealCard());
        player.takeCard(deck.dealCard());
    }

    showPlayersHands(players, false);

    for (size_t i = 1; i < players.size(); ++i) {
        Player& player = players[i];
        if (player.eliminated) continue;

        while (true) {
            char choice;
            cout << player.getPlayerName() << ", do you want to (h)it, (s)tand, or (d)ouble down? ";
            cin >> choice;

            if (choice == 'h') {
                player.takeCard(deck.dealCard());
                showPlayersHands(players, false);
                if (player.isBusted()) {
                    cout << player.getPlayerName() << " busted!" << endl;
                    player.loseBet();
                    break;
                }
            }
            else if (choice == 's') {
                break;
            }
            else if (choice == 'd') {
                if (player.balance >= player.currentBet) {
                    player.balance -= player.currentBet;
                    player.currentBet *= 2;
                    player.takeCard(deck.dealCard());
                    showPlayersHands(players, false);
                    if (player.isBusted()) {
                        cout << player.getPlayerName() << " busted!" << endl;
                        player.loseBet();
                    }
                    break;
                }
                else {
                    cout << "Not enough balance to double down!" << endl;
                }
            }
            else {
                cout << "Invalid choice. Please enter 'h', 's', or 'd'." << endl;
            }
        }
    }

    cout << "Dealer's turn." << endl;
    Player& dealer = players[0];
    while (dealer.getHandValue() < 17) {
        dealer.takeCard(deck.dealCard());
    }
    showPlayersHands(players, true);

    for (size_t i = 1; i < players.size(); ++i) {
        Player& player = players[i];
        if (player.eliminated) continue;

        if (player.isBusted()) {

            continue;
        }
        else if (dealer.isBusted() || player.getHandValue() > dealer.getHandValue()) {
            cout << player.getPlayerName() << " wins!" << endl;
            player.winBet();
        }
        else if (player.getHandValue() < dealer.getHandValue()) {
            cout << player.getPlayerName() << " loses." << endl;
            player.loseBet();
        }
        else {
            cout << "It's a tie for " << player.getPlayerName() << "!" << endl;
            player.tieBet();
        }
    }

    for (auto& player : players) {
        if (player.eliminated) continue;
        cout << player.getPlayerName() << " has a balance of $" << player.balance << endl;
    }
}

void playBlackjack() {
    Deck deck;
    deck.shuffleDeck();

    vector<Player> players;
    int numPlayers;

    cout << "Welcome to Blackjack!" << endl;
    cout << "Enter the number of players (1-6): ";
    cin >> numPlayers;
    if (numPlayers < 1 || numPlayers > 6) {
        cout << "Invalid number of players. Defaulting to 1 player." << endl;
        numPlayers = 1;
    }

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    players.push_back(Player(true, "Dealer"));
    players.push_back(Player(false, playerName));

    for (int i = 1; i < numPlayers; ++i) {
        cout << "Enter player " << (i + 1) << " name: ";
        cin >> playerName;
        players.push_back(Player(false, playerName));
    }

    while (!isGameOver(players)) {
        playBlackjackRound(players, deck);
    }

    cout << "Game over! Thanks for playing!" << endl;
}

int main() {
    playBlackjack();
    return 0;
}