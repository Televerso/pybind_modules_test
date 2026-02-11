#include <pybind11/pybind11.h>
#include <pybind11/numpy.h> // Вот тут

namespace py = pybind11;

// .h файл с кодом на c++
// Поскольку тутвведется работа с массивами numpy, подключает соответствующую библиотеку ^
class NumpyClassTest
{
private:
	py::array_t<int> Data; // Массив numpy живет тут
	size_t n;
	size_t m;

// И тут нужно небольшое отступление...

/* Дело в том, что массивы numpy хранятся не совсем как обычные массивы. При обращении к массиву мы на самом деле
обращаемся к "буферу" (скорее заголовку/оглавлению, но он зовется буфером. Он содержит:
- Размерность массива (его измерения),
- Размер массива (число элементов),
- Минимальное и максимальное значение,
- Тип данных,
- И указатель на структуру, содержащую наши данные (причем в этих данных могут быть пробелы (strides - шаги) и разная
 адресация (c или Fortran), и это тоже нужно учитывать).
*/
	
public:
	NumpyClassTest(int n, int m)
	{
		py::array_t<int> d(n * m); // Создаем массив с размером n*m
		int* ptr = (int*)d.request().ptr; // Получаем буфер командой request() и достаем из него указатель на массив .ptr

        // Заполняем массив нулями
		for (size_t i = 0; i < n*m; ++i)
		{
			ptr[i] = 0;
		}

        // Устанавливаем размерность
		d.resize({ n,m });
		// Сохраняем в поля класса
		this->Data = d;
		this->n = n;
		this->m = m;
	}

    // Поскольку в массиве могут быть пробелы или структура, при получении нового массива в функцию (метод) указываем
    // стиль адресации (c_style или f_style) и приводим массив к сплошным значениям
	NumpyClassTest(py::array_t<int, py::array::c_style | py::array::forcecast> arr)
	{
		py::buffer_info buf = arr.request(); // Считываем буфер
		this->Data = py::array_t<int>(buf); // Массив можно копировать по буферу
		this->n = buf.shape[0]; // Размерности
		this->m = buf.shape[1];
	}


	size_t getRows()
	{
		return this->n;
	}
	size_t getCols()
	{
		return this->m;
	}

	py::array_t<int> getData()
	{
		return Data;
	}

	py::array_t<int> add(py::array_t<int, py::array::c_style | py::array::forcecast> arr)
	{
		py::buffer_info buf1 = this->Data.request();
		py::buffer_info buf2 = arr.request();

		if (buf1.size != buf2.size)
			throw std::runtime_error("Input sizes must match");

		if (buf1.shape != buf2.shape)
			throw std::runtime_error("Input shapes must match");

		int* ptr1 = (int*)buf1.ptr;
		int* ptr2 = (int*)buf2.ptr;

		size_t X = buf1.shape[0];
		size_t Y = buf1.shape[1];


		for (size_t i = 0; i < X; ++i)
		{
			for (size_t j = 0; j < Y; ++j)
			{
				ptr1[i * Y + j] = ptr1[i * Y + j] + ptr2[i * Y + j];
			}
		}
		this->Data.resize({ X,Y });
		return Data;
	}


	py::array_t<int> sub(py::array_t<int, py::array::c_style | py::array::forcecast> arr)
	{
		py::buffer_info buf1 = this->Data.request();
		py::buffer_info buf2 = arr.request();

		if (buf1.size != buf2.size)
			throw std::runtime_error("Input shapes must match");

		if (buf1.shape != buf2.shape)
			throw std::runtime_error("Input shapes must match");

		int* ptr1 = (int*)buf1.ptr;
		int* ptr2 = (int*)buf2.ptr;

		size_t X = buf1.shape[0];
		size_t Y = buf1.shape[1];


		for (size_t i = 0; i < X; ++i)
		{
			for (size_t j = 0; j < Y; ++j)
			{
				ptr1[i * Y + j] = ptr1[i * Y + j] - ptr2[i * Y + j];
			}
		}
		this->Data.resize({ X,Y });
		return Data;
	}

	py::array_t<int> mul(int n)
	{
		py::buffer_info buf1 = this->Data.request();

		int* ptr1 = (int*)buf1.ptr;

		size_t X = buf1.shape[0];
		size_t Y = buf1.shape[1];


		for (size_t i = 0; i < X; ++i)
		{
			for (size_t j = 0; j < Y; ++j)
			{
				ptr1[i * Y + j] = ptr1[i * Y + j]*n;
			}
		}
		this->Data.resize({ X,Y });
		return Data;
	}

	py::array_t<int> div(int n)
	{
		if(n == 0)
			throw std::runtime_error("Division by 0");

		py::buffer_info buf1 = this->Data.request();

		int* ptr1 = (int*)buf1.ptr;

		size_t X = buf1.shape[0];
		size_t Y = buf1.shape[1];


		for (size_t i = 0; i < X; ++i)
		{
			for (size_t j = 0; j < Y; ++j)
			{
				ptr1[i * Y + j] = (int) ptr1[i * Y + j] / n;
			}
		}
		this->Data.resize({ X,Y });
		return Data;
	}


	py::array_t<int> matMul(py::array_t<int, py::array::c_style | py::array::forcecast> arr)
	{
		py::buffer_info buf1 = this->Data.request();
		py::buffer_info buf2 = arr.request();

		if (sizeof(buf1.shape) != sizeof(buf1.shape))
			throw std::runtime_error("Dimensions must match");

		if (buf1.shape[1] != buf2.shape[0])
			throw std::runtime_error("Axies must match");

		int* ptr1 = (int*)buf1.ptr;
		int* ptr2 = (int*)buf2.ptr;

		size_t X = buf1.shape[0];
		size_t Y = buf1.shape[1];
		size_t Z = buf2.shape[1];

		py::array_t<int> result = py::array_t<int>(X * Z);
		py::buffer_info buf3 = result.request();
		int* ptr3 = (int*)buf3.ptr;


		for (size_t i = 0; i < X; ++i) {
			for (size_t j = 0; j < Z; ++j) {
				ptr3[i * Z + j] = 0;
				for (size_t k = 0; k < Y; ++k)
					ptr3[i * Z + j] += ptr1[i * Y + k] * ptr2[k * Z + j];
			}
		}
		result.resize({ X,Z });
		return result;
	}
};


