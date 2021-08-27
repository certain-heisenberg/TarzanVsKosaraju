set -e
g++ -std=c++14 graph_gen.cpp -o graph_gen
g++ -std=c++14 kosaraju.cpp -o kosaraju
g++ -std=c++14 tarzan.cpp -o tarzan
> kosaraju.txt
> tarzan.txt
for((i = 1; ; ++i)); do
    ./graph_gen $i > input.txt
    ./kosaraju < input.txt >> kosaraju.txt
    ./tarzan < input.txt >> tarzan.txt
    echo "Processed test: "  $i
done
