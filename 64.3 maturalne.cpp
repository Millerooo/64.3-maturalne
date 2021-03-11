#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;
#define RZM 20
typedef short obrazek[RZM+1][RZM+1]; 


class file
{
		int tab[5][5];
        ifstream inFile;
        string data;    
        public:
                file();
                ~file();
                void loop();
                void sumaParzystych();
                void bledneBity();
};

file::file()
{
        inFile.open("dane_obrazki.txt"); 
        if (!inFile.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}

file::~file()
{
        inFile.close();
}

void file::loop()
{
        while (!inFile.eof()) 
        {
                inFile >> data;
           
        }
}

void file::sumaParzystych()
{
    int suma = 0;
    for( int i = 0; i < 5; i++ )
    {
        for( int j = 0; j < 5; j++ ) {
            if( tab[ i ][ j ] % 2 == 0 )
                 suma +=tab[ i ][ j ];
           
        }
       
        cout << "elementy parzyste w kazdym wierszu: " << i + 1;
        cout << ": " << suma;
        cout << endl;
        suma = 0;
    }
}

void file::bledneBity();
	int stanPoprawnosci(obrazek pobraz){  // sprawdzanie stanu poprawnosci, parzystosc = 0
 int parzw,parzk;
 int ileBlWiersz, ileBlKol;
 ileBlWiersz=0;
 ileBlKol=0;
 for(int i=0; i<RZM; i++){
 parzw=parzk=0;
 for(int j=0; j<RZM; j++){
 parzw=parzw+pobraz[i][j];
 parzk=parzk+pobraz[j][i];
 }
 if ((parzw%2)!=pobraz[i][RZM]) ileBlWiersz++;
 if ((parzk%2)!=pobraz[RZM][i]) ileBlKol++;
 }
 if (ileBlWiersz+ileBlKol==0) return 0;
 if (ileBlWiersz<=1 && ileBlKol<=1) return 1;
 return ileBlWiersz+ileBlKol; 
}

int main()
{
        file f;
        f.loop();
        f.sumaParzystych();
        f.bledneBity();
        return 0;
}
