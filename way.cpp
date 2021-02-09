#include "way.hpp"

void SearchWay(int x, int y, int x_to, int y_to, std::vector<int> &way, int &type)
{
    const int size = 20;
    int matrix[size][size][3];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (Map::TileMap[i][j] == ' '  || Map::TileMap[i][j] == '-')
            {
                matrix[i][j][0] = -1;
            }
            else
            {
                matrix[i][j][0] = -2;
            }
            if (type == 2)
                if (Map::TileMap[i][j] == 'w')
                    matrix[i][j][0] = -1;
        }
    }

    int step;
    bool added = true, result = true;

    matrix[x_to][y_to][0] = 0;
    step = 0;                 

    while (added && matrix[x][y][0] == -1)
    {
        added = false;
        step++;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (matrix[i][j][0] == step - 1)
                {
                    int _i, _j;

                    _i = i + 1;
                    _j = j;
                    if (_i >= 0 && _j >= 0 && _i < size && _j < size)
                    {
                        if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
                        {
                            matrix[_i][_j][0] = step; 
                            matrix[_i][_j][1] = i;    
                            matrix[_i][_j][2] = j;    
                            added = true;             
                        }
                    }
                    _i = i - 1;
                    _j = j;
                    if (_i >= 0 && _j >= 0 && _i < size && _j < size)
                    {
                        if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
                        {
                            matrix[_i][_j][0] = step; 
                            matrix[_i][_j][1] = i;   
                            matrix[_i][_j][2] = j;    
                            added = true;             
                        }
                    }
                    _i = i;
                    _j = j + 1;
                    if (_i >= 0 && _j >= 0 && _i < size && _j < size)
                    {
                        if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
                        {
                            matrix[_i][_j][0] = step; 
                            matrix[_i][_j][1] = i;    
                            matrix[_i][_j][2] = j;    
                            added = true;             
                        }
                    }
                    _i = i;
                    _j = j - 1;
                    if (_i >= 0 && _j >= 0 && _i < size && _j < size)
                    {
                        if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
                        {
                            matrix[_i][_j][0] = step; 
                            matrix[_i][_j][1] = i;    
                            matrix[_i][_j][2] = j;    
                            added = true;             
                        }
                    }
                }
            }
        }
    }

    if (matrix[x][y][0] == -1)
    {
        result = false; 
    }
    if (result)
    {
        int X = x, Y = y;

        while (matrix[X][Y][0] != 0)
        {
           	way.push_back(X);
            way.push_back(Y);
            int li = matrix[X][Y][1];
            int lj = matrix[X][Y][2];
            X = li;
            Y = lj;
        }
    }
    way.push_back(x_to);
    way.push_back(y_to);
    way.push_back(x_to + 1);
    way.push_back(y_to);
    
}
