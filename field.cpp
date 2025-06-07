#include<iostream>
#include <random>
#include"field.hpp"
using namespace std;

//(1,1)以外の全てのマスを壁にするプログラム
void field::field_zero(){
    for (int i = 0; i < 15; i++){
        for (int k = 0; k < 15; k++){
            field_side[i][k] = 1;
        }
        field_side[1][1] = 0;
    }
}

//次の二つ先のマスが掘ることができるか確認しながら掘っていく
void field::field_dig(int x, int y){
    random_device rd;
    mt19937 gen(rd());
    shuffle(randomNumber, randomNumber + 4, gen);
    for (int i = 0; i < 4; i++){
        int nx = x + 2 * dx[randomNumber[i]];
        int ny = y + 2 * dy[randomNumber[i]];
        if (nx > 0 && ny > 0 && nx < 15 && ny < 15 && field_side[nx][ny] == 1){
            field_side[x + dx[randomNumber[i]]][y + dy[randomNumber[i]]] = 0;
            field_side[nx][ny] = 0;
            x = nx;
            y = ny;
            field_dig(x, y);
        }
    }
}

//上3つでフィールドを完成させる
void field::field_set(){
    field_zero();
    field_side[1][1] = 0;
    field_dig(x, y);

}

void field::print_field() {
    for (int i = 0; i < 15; i++) {
        for (int k = 0; k < 15; k++) {
            cout << field_side[i][k];
        }
        cout << endl;
    }
}