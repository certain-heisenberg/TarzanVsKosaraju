set -e
g++ graph_gen.cpp -o graph_gen
g++ kosaraju.cpp -o kosaraju
g++ tarzan.cpp -o tarzan
> kosaraju.txt
> tarzan.txt
for((i = 1; ; ++i)); do
    ./graph_gen $i > int.txt
    ./kosaraju < int.txt >> kosaraju.txt
    ./tarzan < int.txt >> tarzan.txt
    echo "Processed test: "  $i
done
