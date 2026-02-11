#include <vector>

// .h Файл - для удобного вынесения всего c++ кода в отдельный от связующего кода файл
class ClassTest
{
private:
	std::vector<std::vector<int>> Data;
	size_t n;
	size_t m;

public:
	ClassTest(int n, int m)
	{
		std::vector<std::vector<int>> d(n, std::vector<int>(m, 0));
		this->Data = d;
		this->n = n;
		this->m = m;
	}


	ClassTest(std::vector<std::vector<int>> &v)
	{
		Data = v;
		this->n = v.size();
		this->m = v[0].size();
	}

	size_t getRows()
	{
		return this->n;
	}
	size_t getCols()
	{
		return this->m;
	}

	std::vector<std::vector<int>> getData()
	{
		std::vector<std::vector<int>> dataCopy(Data);
		return dataCopy;
	}

	std::vector<std::vector<int>> add(std::vector<std::vector<int>> &v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			for (size_t j = 0; j < v[0].size(); ++j)
			{
				Data[i][j] = Data[i][j] + v[i][j];
			}
		}

		return Data;
	}

	std::vector<std::vector<int>> sub(std::vector<std::vector<int>> &v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			for (size_t j = 0; j < v[0].size(); ++j)
			{
				Data[i][j] = Data[i][j] - v[i][j];
			}
		}

		return Data;
	}
};


