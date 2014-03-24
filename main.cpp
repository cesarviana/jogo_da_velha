#include <iostream>
#include <conio2.h>
#define BLOCO 'л'
#define ALTURA 40
#define LARGURA 80
#define H_MARGEM 10 // margem altura
#define V_MARGEM 5 // margem largura
#define A_QUADRADO 10 // altura quadrado
#define L_QUADRADO 20 // largura quadrado

#define CIMA     72
#define BAIXO    80
#define DIREITA  77
#define ESQUERDA 75

#define BOLA 1
#define XIS  2


using namespace std;

void desenhaFigura(int x, int y, int figura){
    switch(figura){
        case BOLA:
            gotoxy(x,  y); cout << "   /л\\  ";
            gotoxy(x,++y); cout << "  /ллл\\  ";
            gotoxy(x,++y); cout << " |ллллл| ";
            gotoxy(x,++y); cout << "  \\ллл/  ";
            gotoxy(x,++y); cout << "   \\л/  ";
            break;
        case XIS:
            cout << "  л л   \n";
            cout << "   л    \n";
            cout << "  л л   \n";
            break;
    }
}

void desenhaLinhaHorizontal(int y, int posIni, int posFim ){
    for( int x=posIni; x<posFim; x++){
        gotoxy(x,y);
        cout << BLOCO;
    }
}

void desenhaLinhaVertical(int x, int posIni, int posFim ){
    for( int y=posIni; y<posFim; y++){
        gotoxy(x,y);
        cout << BLOCO;
    }
}

void desenhaTela(){
    system( "mode 80, 40" );
    system( "color f1" );
}

void indicaPosicao(int x, int y){
    gotoxy(x,y);
    cout << BLOCO;
}

void desenhaCenario(){
    desenhaLinhaHorizontal(V_MARGEM + A_QUADRADO, H_MARGEM, LARGURA - H_MARGEM );
    desenhaLinhaHorizontal(V_MARGEM + A_QUADRADO * 2, H_MARGEM, LARGURA - H_MARGEM );
    desenhaLinhaVertical(H_MARGEM + L_QUADRADO, V_MARGEM, ALTURA - V_MARGEM );
    desenhaLinhaVertical(H_MARGEM + L_QUADRADO * 2, V_MARGEM, ALTURA - V_MARGEM );
}

void mover( int direcao, int &x, int &y ){
    switch(direcao){
        case CIMA:
            y -= A_QUADRADO;
            break;
        case BAIXO:
            y += A_QUADRADO;
            break;
        case DIREITA:
            x += L_QUADRADO;
            break;
        case ESQUERDA:
            x -= L_QUADRADO;
            break;
    }
    desenhaFigura(x,y,BOLA);
    //indicaPosicao(x, y);
}

int main()
{
    int tecla;
    int x = LARGURA/2 - 4, y = ALTURA/2 - 3;

    desenhaTela();
    desenhaCenario();
    indicaPosicao(x, y);

    while(tecla != 27){
        if(kbhit()){
            tecla = getch();
            mover( tecla, x, y );
        }
    }
}
