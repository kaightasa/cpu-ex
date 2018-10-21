# cpu-ex
simulator

powerpcの命令セットを参考にしたオリジナルの命令セットをシミュレートする

simulator: /simulatorでmake 実行方法 ./sim [inputfile]
assembler: /assemblerでmake 実行方法 ./asm [inputfile] [outputfile]

10/15
一通りの命令とラベルは読めてる
.txt .align .globlなどの調整

予定
simulatorのdebugが終わり次第step実行等便利な機能を実装する

10/21
バイナリファイルみたいとき　
コマンドラインで> xxd ~.bin
vim で :%!xxd  戻すときは :%!xxd -r

add.sを読み込んで実行できた。



