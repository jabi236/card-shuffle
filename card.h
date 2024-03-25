#ifndef CARD_H
#define CARD_H

#include <QIcon>
#include <QString>
#include <QObject>

class Card{

public:

    enum Suit {
        diamonds = 1, hearts, spades, clubs
    };

    enum Rank {
        ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
    };

    [[nodiscard]] static const std::array<Suit, 4> &suits();

    [[nodiscard]] static const std::array<Rank, 13> &ranks();

    explicit Card(Suit suit, Rank rank, QString iconName);

    [[nodiscard]] const QIcon &icon() const {
        static QIcon back(":/back.png");
        return m_up ? m_front : back;
    }

    Suit suit() const { return m_suit; }

    Rank rank() const { return m_rank; }

    void flip() {
        m_up = !m_up;
    };

    inline bool operator<(const Card &card) const;


private:
    Suit m_suit;
    Rank m_rank;
    QIcon m_front;
    bool m_up = true;

};
bool Card::operator<(const Card& card) const{
    if (m_suit == card.m_suit){
        return m_rank < card.m_rank;
    }else{
        return m_suit < card.m_suit;
    }
}




#endif // CARD_H
