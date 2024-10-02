#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Card {
public:
    enum Form { Hearts, Diamonds, Clubs, Spades };
    enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

    Card(Rank r, Form s) : rank(r), form(s) {}

    int getValue() const {
        if (rank >= Two && rank <= Ten)
            return rank;
        if (rank >= Jack && rank <= King)
            return 10;
        if (rank == Ace)
            return 11;
        return 0;
    }

    void displayCard() const {
        const char* rankStr[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
        const char* formStr[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

        cout << rankStr[rank - 2] << " of " << formStr[form] << std::endl;
    }

private:
    Rank rank;
    Form form;
};

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

int main() {
    Deck deck;
    Player player;
    Player dealer;

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
            cout << "Player's hand:" << std::endl;
            player.displayHand();
        }
        else {
            break;
        }
    }

    while (dealer.getTotal() < 17) {
        dealer.drawCard(deck);
    }

    cout << "Dealer's hand:" << endl;
    dealer.displayHand();

    if (player.getTotal() > 21) {
        cout << "Player busts! Dealer wins." << endl;
    }
    else if (dealer.getTotal() > 21 || player.getTotal() > dealer.getTotal()) {
        cout << "Player wins!" << endl;
    }
    else if (player.getTotal() < dealer.getTotal()) {
        cout << "Dealer wins!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
