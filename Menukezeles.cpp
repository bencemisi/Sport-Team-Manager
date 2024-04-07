#include "Menukezeles.h"

void logo_rajz() {

    using namespace std;
    cout << "     .,::OOO::,.     .,ooOOOoo,.     .,::OOO::,." << endl;
    cout << "    .:'         `:. .8'         `8. .:'         `:." << endl;
    cout << "    :'           ': 8'           '8 :'           ':" << endl;
    cout << "    :,        .,:::''::,.     .,:o8OO::,.        ,:" << endl;
    cout << "     :,,    .:' ,:   8oo`:. .:'oo8   :,,`:.    ,,:" << endl;
    cout << "      `^OOoo:'O ^ '   `^88oo:'8^'     `^O':ooOO^'" << endl;
    cout << "            :,           ,: :,           ,:" << endl;
    cout << "             :,,       ,,:   :,,       ,,:" << endl;
    cout << "              `^Oo,,,oO^'     `^OOoooOO^'" << endl << endl;
    cout << "$$$$$$$$\\$$\\  $$\\    $$\\            $$$$$$\\ $$$$$$$$\\ " << endl;
    cout << "$$  _____\\__| $$ |   $$ |          $$  __$$\\$$  _____|" << endl;
    cout << "$$ |     $$\\$$$$$$\\$$$$$$\\         $$ /  \\__$$ |      " << endl;
    cout << "$$$$$\\   $$ \\_$$  _\\_$$  _|        \\$$$$$$\\ $$$$$\\    " << endl;
    cout << "$$  __|  $$ | $$ |   $$ |           \\____$$\\$$  __|   " << endl;
    cout << "$$ |     $$ | $$ |$$\\$$ |$$\\       $$\\   $$ $$ |      " << endl;
    cout << "$$ |     $$ | \\$$$$  \\$$$$  |      \\$$$$$$  $$$$$$$$\\ " << endl;
    cout << "\\__|     \\__|  \\____/ \\____/        \\______/\\________|" << endl;
    cout << "============================================================" << endl << endl;

}
void menukiiras()
{
    using namespace std;
  //  system("cls");                          //Kitörli a console-t hogy atlathatobb legyen a futas
    logo_rajz();
    cout << "\t\tMit szeretne csinalni?" << endl;
    cout << "============================================================" << endl << endl;
    cout << "[1] Uj csapat felvetele a nyilvantartasba" << endl;
    cout << "[2] Csapat torlese a nyilvantartasbol" << endl;
    cout << "[3] Csapatok kilistazasa" << endl;
    cout << "\t\t\t\t\t[4]   Kilepes a programbol" << endl;
    cout << "============================================================" << endl;
}
int menupontvalasztas()
{
    using namespace std;
    int valasztas;
    cout << "\nValasszon menupontot: ";

    std::cin >> valasztas;
    if (!cin)
    {
        cout << "Nem szamot adott meg \n Kerem adja meg ismet" << endl;
        cin.clear();    //Hiba flag resetelese
        cin.ignore(1000, '\n');   //Hibas kezdetû input utan ne foglalkozzon az inputtal
    }
    else if (valasztas >= 5 || valasztas < 1)
    {
        throw "Nincs ilyen menupont, kerem valasszon 1 es 4 kozott";
    }          
    return valasztas;
}
void Csapatkiiras()
{
    std::cout << "[1]Foci csapatot" << std::endl;
    std::cout << "[2]Kosar csapatot" << std::endl;
    std::cout << "[3]Kezi csapatot" << std::endl;
    std::cout << "[4]Vissza a kezdooldalra" << std::endl;

}