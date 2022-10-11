#include <iostream>
#include "../data-structures/Queue.cpp"
#include <string.h>

/* these are just here to make the code more legible */
#define TAM 8 // chessboard has 8x8 = 64 tiles
#define MAXMOVES 8 // maximum available moves for a knight is 8

int shortestPath(std::string init, std::string end);
void initializeMatrix(int* matrix);
void printMatrix(int* matrix);

int main()
{
    std::string init;
    std::string end;

    std::getline(std::cin, init);
    std::getline(std::cin, end);

    printf("Movimentos: %d\n", shortestPath(init, end));

    return 0;
}

int shortestPath(std::string init, std::string end)
{
    int x1 = init[0]-'a';
    int y1 = init[1]-'1';

    int* visited = new int[TAM*TAM];
    initializeMatrix(visited);
    Queue<std::string> q;
   
    int dist;
    q.enqueue(init);
    visited[TAM*y1 + x1] = 0;
    std::string val;
    
    bool found = false;
    while (!found)
    {
        val = q.dequeue();
        int x2 = val[0]-'a';
        int y2 = val[1]-'1';

        int moves[MAXMOVES][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        for (int i = 0; i < MAXMOVES; i++) {
            int addx = moves[i][0];
            int addy = moves[i][1];

            std::string temp = val;
            if (0 <= x2+addx && x2+addx <= 7 && y2+addy <= 7 && 0 <= y2+addy) {
                int index = TAM*(y2+addy) + (x2+addx);
                if (visited[index] == -1) {
                    visited[index] = visited[TAM*y2 + x2] + 1;
                    dist = visited[index];
                    
                    temp[0] = temp.at(0) + addx;
                    temp[1] = temp.at(1) + addy;
                    
                    if (strcmp(temp.c_str(), end.c_str()) == 0) {
                        found = true;
                        break;
                    }

                    q.enqueue(temp);
                }
            }
        }
    }
    return dist;
}

void initializeMatrix(int* matrix)
{
    for (int i = 0; i < TAM*TAM; i++)
        matrix[i] = -1;
}
