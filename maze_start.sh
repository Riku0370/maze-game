#!/bin/zsh

gpp() {
  g++ -std=c++17 "$@"
}

gpp maze_game.cpp field.cpp player.cpp -o maze_game

if [ $? -eq 0 ]; then
  echo "コンパイル成功。ゲームを開始します。"
  ./maze_game
else
  echo "コンパイルに失敗しました。"
fi