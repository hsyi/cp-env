CUR=`pwd`
compile() {
cd ..
cr || cd $CUR
}
#compile; exit 0
mv ../a.out .
python croupier.py "python judge.py" "./a.out"
#python croupier.py "python croupier/samples/hello/hello.py" "bash croupier/samples/hello/hello.sh"
