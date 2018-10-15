# cpu-ex
simulator

powerpcの命令セットを参考にしたオリジナルの命令セットをシミュレートする

simulator: /simulatorでmake 実行方法 ./sim [inputfile]
assembler: /assemblerでmake 実行方法 ./asm [inputfile] [outputfile]

10/15
アセンブラの出力がバイナリになっていないのであとでかえる
読み込むファイルの最後に余計な改行があるとsegmentation fault
一通りの命令とラベルは読めてる
.txt .align .globlなどの調整

シミュレーターはまだ実行してない:アセンブラの出力をバイナリにしてその流れでtestするつもり

予定
simulatorのdebugが終わり次第step実行等便利な機能を実装する


