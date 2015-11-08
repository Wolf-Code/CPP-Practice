#include <iostream>
#include <string>

using namespace std;

int main( int argc, char** argv )
{
    for ( int x = 0; x < argc; x++ )
        cout << argv[ x ] << endl;

    string test;
    cin >> test;
    cout << "hai " << test << "!" << endl;

    cin.ignore( numeric_limits<streamsize>::max( ), '\n' );
    cin.get( );
    return 0;
}