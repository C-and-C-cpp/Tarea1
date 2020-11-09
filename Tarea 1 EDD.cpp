#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void menu();
void textoAMorse();
void morseATexto();
char buscarMorse(string codigo);

char letras[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
string morse[] = { ".-", "-..." ,"-.-." ,"-.." ,"." ,"..-." ,"--." ,"...." ,".." ,".---" ,"-.-" ,".-.." ,"--" ,"-." ,"---" ,".--." ,"--.-" ,".-." ,"..." ,"-" ,"..-" ,"..-" ,".--" ,"-..-" ,"-.--" ,"--.." ,".----" ,"..---" ,"...--" ,"....-" ,"....." ,"-...." ,"--..." ,"---.." ,"----." , "-----" };

int main() {

    menu();
}

void menu() {

    cout << "Escoja una opcion\n0.- Texto -> Morse\n1.- Morse -> Texto\n";
    string respuesta;
    cin >> respuesta;
    if (respuesta.compare("0") == 0) {
        textoAMorse();
    }
    else if (respuesta.compare("1") == 0) {
        morseATexto();
    }
    else {
        cout << "Mi loco, coopere\n";
    }
}

void textoAMorse() {
    cout << "Ingrese una frase\n";
    string* fraseT = new string(); //aca se reserva memoria
    cin.ignore();
    getline(cin, *fraseT);
    string* fraseM = new string();
    bool esta = false;

    for (int i = 0; i < (*fraseT).size(); i++) {
        esta = false;
        if ((*fraseT)[i] == ' ') {
            *fraseM = *fraseM + "/ ";
            esta = true;
        }

        for (int f = 0; f < 36; f++) {
            if (toupper((*fraseT)[i]) == letras[f]) {
                *fraseM = *fraseM + morse[f]+' ';
                esta = true;
            }

        }
        if (!esta) {
            cout << "La frase contiene caracteres invalidos.";
            break;
        }
    }
    if (esta) cout << "Traduciendo texto a codigo morse.\nTexto: " + *fraseT + "\nTraduccion: " + *fraseM;

    delete fraseM;
    delete fraseT;
}

void morseATexto() {
    cout << "Ingrese una frase\n";
    string* fraseM = new string();
    string* fraseT = new string(); //aca se reserva memoria
    cin.ignore();
    getline(cin, *fraseM);
    string* aux = new string();
    string* letra = new string();
    *fraseM = *fraseM + " ";
    bool valido = true;
    for (int i = 0; i < (*fraseM).size(); i++) {
        if ((*fraseM)[i] == ' ') {
            *letra = buscarMorse(*aux);
            if ((*letra).compare(".") != 0){
                *fraseT = *fraseT + *letra;
                *aux = "";
            }
            else{
                cout << "Entrada invalida";
                valido = false;
                break;
            }
        }
        else if ((*fraseM)[i] == '/'){
             *fraseT = *fraseT + ' ';
             *aux = "";
             i++;
        }
        else{
            *aux = *aux + (*fraseM)[i];
        }
    }
    
    if (valido) cout << "Traduciendo codigo morse a texto.\nMorse: " + *fraseM + "\nTraduccion: " + *fraseT;
    delete aux;
    delete letra;
    delete fraseM;
    delete fraseT;


}

char buscarMorse(string codigo) {
    for (int i = 0; i < 36; i++) {
        if (codigo.compare(morse[i]) == 0) {
            return letras[i];
        }
    }
    return '.';
}