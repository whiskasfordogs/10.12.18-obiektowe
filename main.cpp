#include <iostream>
#include <cstring>
#include <sstream>
class Zwierze
{
protected:
    int glod;
    int pragnienie;
    int zmeczenie;
    int humor;
private:
    std::string mImie;

public:
    Zwierze(std::string imie_zwierzaka) : glod(0), pragnienie(0), zmeczenie(0), humor(0)
    {

        mImie = imie_zwierzaka;

    }
    void zmiana(std::string nowa_nazwa)
    {

        mImie = nowa_nazwa;
        std::cout << "Nadales nowe imie Twojemu zwierzakowi: "
                  << mImie << std::endl;
    }
    const std::string naLancuch() const
    {
        std::cout << glod << '\n';
        std::cout << pragnienie << '\n';
        std::cout << zmeczenie << '\n';
        std::cout << humor << '\n';


        return dajRodzajZwierzecia() + mImie  ;
    }
    const std::string imie() const
    {
        return mImie;
    }
    virtual std::string dajRodzajZwierzecia() const
    {
        return "Zwierzatko: " ;
    }
};
class FunkcjeZyciowe
{
public:
    virtual void jedz(int iloscPozywienia) = 0;
    virtual void pij(int iloscWody) = 0;
    virtual void spij(int czas) = 0;
    virtual void bawSie(int czas) = 0;
};
class Pies : public Zwierze, public FunkcjeZyciowe
{
public:
    Pies(std::string imie_zwierzaka) : Zwierze(imie_zwierzaka)
    {


    }
    void szczekaj()
    {
        std::cout << "Hau! Hau!"
                  << "\n Hau! Hau! Hau!"
                  << std::endl;

    }
    void dajLape()
    {
        std::cout << "daj mi lape!" << std::endl;
    }
    std::string dajRodzajZwierzecia()const
    {
        return "Pies: " ;
    }
    virtual void jedz(int iloscPozywienia)
    {
        glod-=iloscPozywienia;
    }
    virtual void pij(int iloscWody)
    {
        pragnienie-=iloscWody;
    }
    virtual void spij(int czas)
    {
        zmeczenie-=czas;
    }
    virtual void bawSie(int czas)
    {
        glod+=czas;
        pragnienie+=czas;
        zmeczenie+=czas;
        humor+=2*czas;
    }
};

class Kot : public Zwierze, public FunkcjeZyciowe
{
public:
    Kot(std::string imie_zwierzaka) : Zwierze(imie_zwierzaka)
    {


    }
    void mialcz()
    {
        std::cout << "miau! miau!" << std::endl;

    }
    void myjSie()
    {
        std::cout << "kot sie myje" << std::endl;
    }
    std::string dajRodzajZwierzecia()const
    {
        return "kot: " ;
    }
    virtual void jedz(int iloscPozywienia)
    {
        glod-=iloscPozywienia;
    }
    virtual void pij(int iloscWody)
    {
        pragnienie-=iloscWody;
    }
    virtual void spij(int czas)
    {
        zmeczenie-=czas;
    }
    virtual void bawSie(int czas)
    {
        glod+=czas;
        pragnienie+=czas;
        zmeczenie+=czas;
        humor+=2*czas;
    }


};


/*class SchroniskoDlaZwierzat
{
private:
    Zwierze* _schronisko[100];
public:
    SchroniskoDlaZwierzat(int rozmiar, Zwierze *tab[])
    {
        for (int i = 0;i<rozmiar;i++)
        {
            _schronisko[i] = tab[i];
        }
    }
    ~SchroniskoDlaZwierzat()
    {
        delete[] _schronisko;
    }
    Zwierze *dajZwierze(int index)
    {
        return _schronisko[index];
    }
};*/
int main()
{

    /*Zwierze *tab[2]={new Pies("Azor"), new Pies("Pimpus")};
    SchroniskoDlaZwierzat schronisko(2,tab);


    //dynamic_cast<Pies*>(schronisko.dajZwierze(0))->szczekaj();
    */
    Pies azor("Azor");
    azor.bawSie(2);
    azor.naLancuch();
    std::cout << "Po zabawie\n";
    azor.jedz(6);
    azor.naLancuch();
    std::cout << "Po jedzeniu\n";
    azor.pij(8);
    azor.naLancuch();
    std::cout << "Po piciu\n";
    azor.spij(12);
    azor.naLancuch();
    std::cout << "Po spaniu\n";

    Kot mruczek("mruczek");
    FunkcjeZyciowe& funkcje = mruczek;

    funkcje.bawSie(3);
    funkcje.jedz(5);
    funkcje.pij(7);
    funkcje.spij(2);
    dynamic_cast<Kot>


    return 0;
}
