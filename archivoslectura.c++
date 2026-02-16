#include "iostream"
#include "fstream"

using namespace std;

int main()
{
    ifstream archivo;

    archivo.open("prueba.txt");

    string nombre;
    int edad;

    archivo>>nombre;
    archivo>>edad;

    cout<<nombre<<endl;;
    cout<<edad<<endl;

    archivo.close();

    return 0;
}