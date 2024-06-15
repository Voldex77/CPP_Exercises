#include "Player.hpp"
int main()
{
    //Card c1 {8, "Pique"};
    const Card c1 {8, "Pique"};
    //c1.print();
    std::cout << c1 << std::endl;
    const Card c2 { 8, "Carreau" };
    std::cout << (c2 == c1) << std::endl; // -> 1
    const Card c3 { 10, "Carreau" };
    std::cout << (c2 == c3) << std::endl; // -> 0 

    std::cout << (c1 < c2) << std::endl; // -> 0
    std::cout << (c1 < c3) << std::endl; // -> 1
    std::cout << (c3 < c1) << std::endl; // -> 0

    Player p1 { "Gerald" };
    Player p2 { "Julien" };
    Player::deal_all_cards(p1, p2);

    for (auto i = 0; i < 16; ++i)
    {
        /*p1[i].print();
        std::cout << std::endl;
        p2[i].print();
        std::cout << std::endl;*/
        Player::play(p1, p2);
    }
    if (p1.get_score() < p2.get_score()) {
        std::cout << p1.get_name() << " win" << std::endl;
    } else if (p1.get_score() == p2.get_score()) {
        std::cout << "DRAW" << std::endl;
    } else {
        std::cout << p2.get_name() << " win" << std::endl;
    }
    return 0;
}