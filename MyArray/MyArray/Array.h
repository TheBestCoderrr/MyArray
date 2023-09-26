#pragma once
class Array
{
private:
	int* arr;
	size_t size;
public:
	Array();
	Array(size_t size);
	Array(const int* arr, size_t size);
	Array(const Array& other);
	~Array();
	
	Array& operator=(const Array& other) noexcept;

	int* GetArr();

	void SetSize(size_t size);
	size_t GetSize();

	void Init();
	void Show();
	void SetSize();
	void Sort();
	void PrintMinMax();
};

