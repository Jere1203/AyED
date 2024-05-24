#include <iostream>
#include <limits>
using namespace std;

bool LeerInt(float&);

int main()
{
    float hola;
    if(!LeerInt(hola))
        cout<<"Anduvo";
    else 
        cout<<"Tu hermana";
    return 0;
}

bool LeerInt(float& valor)
{
    cin >> valor;

    bool ok = cin.good();

    if( ok )
    {
        char c = static_cast<char>(cin.peek());
        ok = (c == '\n' || c == ' ' );
    }

    if( !ok )
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    return ok;
}