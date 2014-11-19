#include <iostream>

#define ROW 3
#define COL 4

void rotate_test(int (*p)[COL], int row, int col)
{
	int temp[COL][ROW];
	int desCol = ROW - 1;

	int i = 0;
	int j = 0;
	for(i = 0; i < row; ++i, --desCol)
	{
		for(j = 0; j < col; ++j)
		{
			temp[j][desCol] = *(*(p + i) + j);		
		}
	}

	for(i = 0; i < COL; ++ i)
	{
		for(j = 0; j < ROW; ++j)
		{
			*(*(p + i) + j) = temp[i][j];
		}
	}
	
}

void output_data(int **p, int row, int col)
{
	for(int i = 0; i < row; ++i)
	{
		for(int j =0; j < col; ++j)
		{
			std::cout << *(*(p + i) + j) << " " << std::endl;	
		}

		std::cout << std::endl;
	}

}


int main()
{
	int data[ROW][COL] = 
		{
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}
		};

	std::cout << "size of data" << sizeof(data) << std::endl;
	std::cout << "size of data[][]" << sizeof(data[ROW][COL]) << std::endl;

	//output_data(reinterpret_cast<int**>(data), ROW, COL);

	int i = 0;
	int j = 0;
	for(i = 0; i < ROW; ++i)
	{
		for(j =0; j < COL; ++j)
		{
			std::cout << " " << data[i][j]; 
		}

		std::cout << std::endl;
	}

	rotate_test(data, ROW, COL);
	//output_data(reinterpret_cast<int**>(data), ROW, COL);

	for(i = 0; i < COL; ++i)
	{
		for(j =0; j < ROW; ++j)
		{
			std::cout << " " << data[i][j]; 
		}

		std::cout << std::endl;
	}
	return 0;
}
