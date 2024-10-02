#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h> 
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Funcție pentru curățarea ecranului 
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void setUtf8Encoding()
{
    SetConsoleOutputCP(CP_UTF8); // Seteaza codificarea la UTF-8 in terminal
}

void displayWelcome(const string& username, int balance) {
    cout << "*******************************" << endl;
    cout << "*    Welcome to Blackjack, " << username << "!   *" << endl;
    cout << "*    Try to beat the dealer!   *" << endl;
    cout << "*******************************" << endl;
    cout << "Current balance: $" << balance << endl;
    cout << "Rules: Try to get as close to 21 as possible without going over." << endl;
    cout << "      Dealer will keep drawing until at least 17." << endl;
    cout << "Good luck!" << endl << endl;
}
// clasa card reprezinta o carte de joc 
class Card { 
public:
    enum Form { Hearts, Diamonds, Clubs, Spades };
    enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

    Card(Rank r, Form s) : rank(r), form(s) {} // constructor implicit

    int getValue() const {
        if (rank >= Two && rank <= Ten)
            return rank;
        if (rank >= Jack && rank <= King)
            return 10;
        if (rank == Ace)
            return 11;
        return 0;
    }

    // Reprezentarea grafică a cărților în terminal
    void displayCard() const {
        const char* rankStr[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
        const char* formStr[] = { u8"♥", u8"♦", u8"♣", u8"♠" };
        const char* color = (form == Hearts || form == Diamonds) ? RED : RESET;
        

        cout << " _______" << endl;
        cout << "|" << rankStr[rank - 2] << "      |" << endl;
        cout << "|       |" << endl;
        cout << "|   " << formStr[form] << "   |" << endl; // Afișează forma
        cout << "|       |" << endl;
        cout << "|______" << rankStr[rank - 2] << "|" << endl;
    }

private:
    Rank rank;
    Form form;
};

// Clasa Deck reprezinta un pachet de 52 de carti de joc
class Deck {
public:
    Deck() {
        for (int s = Card::Hearts; s <= Card::Spades; ++s) {
            for (int r = Card::Two; r <= Card::Ace; ++r) {
                deck.push_back(Card(static_cast<Card::Rank>(r), static_cast<Card::Form>(s)));
            }
        }
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(deck.begin(), deck.end());
    }

    Card dealCard() {
        Card dealtCard = deck.back();
        deck.pop_back();
        return dealtCard;
    }

private:
    std::vector<Card> deck;
};

// Clasa Hand reprezinta o mana de carti pe care le are jucatorul/dealerul
class Hand {
public:
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    int getTotal() const {
        int total = 0;
        int aceCount = 0;

        for (const Card& card : hand) {
            total += card.getValue();
            if (card.getValue() == 11)
                aceCount++;
        }

        while (total > 21 && aceCount > 0) {
            total -= 10;
            aceCount--;
        }

        return total;
    }

    void displayHand() const {
        for (const Card& card : hand) {
            card.displayCard();
        }
        cout << "Total: " << getTotal() << std::endl;
    }

private:
    vector<Card> hand;
};

// reprezinta un jucator/dealer
class Player { 
public:
    void drawCard(Deck& deck) {
        hand.addCard(deck.dealCard());
    }

    void displayHand() const {
        hand.displayHand();
    }

    int getTotal() const {
        return hand.getTotal();
    }

private:
    Hand hand;
};

// Clasa Game reprezinta jocul in sine si gestioneaza interactiunea dintre jucator, dealer si pachet
class Game {
public:
    Game() : playerWins(0), dealerWins(0), ties(0), balance(100) {} //const
    void play();
    void displayScores() const;  // Declararea funcției
    void login();

    string getUsername() const {
        return username;
    }

    int getBalance() const {
        return balance;
    }

private:
    string username;
    int playerWins;
    int dealerWins;
    int ties;
    int balance;

    void displayResult(const Player& player, const Player& dealer, int bet);
};

// Implementarea funcției login
void Game::login() {
    cout << "Enter your username: ";
    cin >> username;
}

// Implementarea funcției displayScores
void Game::displayScores() const {
    cout << "Player Wins: " << playerWins << endl;
    cout << "Dealer Wins: " << dealerWins << endl;
    cout << "Ties: " << ties << endl;
}

void Game::displayResult(const Player& player, const Player& dealer, int bet) {
    cout << "Dealer's hand:" << endl;
    dealer.displayHand();

    if (player.getTotal() > 21) {
        cout << RED << "Player busts! Dealer wins." << RESET << endl;
        dealerWins++;
        balance -= bet; // Pierde pariul
    }
    else if (dealer.getTotal() > 21 || player.getTotal() > dealer.getTotal()) {
        cout << GREEN << "Player wins!" << RESET << endl;
        playerWins++;
        balance += bet; // Castiga pariul
    }
    else if (player.getTotal() < dealer.getTotal()) {
        cout << RED << "Dealer wins!" << RESET << endl;
        dealerWins++;
        balance -= bet; // Pierde pariul
    }
    else {
        cout << YELLOW << "It's a tie!" << RESET << endl;
        ties++;
    }

    displayScores();
    cout << "Current balance: $" << balance << endl;
}

void Game::play() {
    Deck deck;
    Player player;
    Player dealer;

    int bet;
    cout << "Your current balance is: $" << balance << endl;
    cout << "Enter your bet amount: $";
    cin >> bet;

    // Verifica daca pariu este valid
    if (bet > balance || bet <= 0) {
        cout << "Invalid bet amount. Please try again." << endl;
        return;
    }

    player.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);
    dealer.drawCard(deck);

    cout << "Player's hand:" << endl;
    player.displayHand();

    cout << "Dealer's hand:" << endl;
    dealer.displayHand();

    char choice;
    while (player.getTotal() < 21) {
        cout << "Do you want to (H)it or (S)tand? ";
        cin >> choice;

        if (choice == 'H' || choice == 'h') {
            player.drawCard(deck);
            cout << "Player's hand:" << endl;
            player.displayHand();
        }
        else {
            break;
        }
    }

    while (dealer.getTotal() < 17) {
        dealer.drawCard(deck);
    }

    displayResult(player, dealer, bet);

    if (balance <= 0) {
        cout << "You're out of money! Game over." << endl;
        return; // Iesire daca jucatorul ramane fara bani
    }
}

int main() {
    Game game;
    char playAgain = 'y';

    setUtf8Encoding();
    game.login();

    do {
        clearScreen();
        displayWelcome(game.getUsername(), game.getBalance());  // Afișează balanța actualizată
        game.play();

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
