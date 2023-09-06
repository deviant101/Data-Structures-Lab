#pragma once
class List
{
private:
	int* arr;
	int size;
public:
	List();
	void insert_start(int val);
	void insert_end(int val);
	void insert_at(int index, int val);
	void remove_start();
	void remove_end();
	void remove_at(int index);
	void print();
	bool is_empty();
	void replace_by_index();
	void replace_by_value();
	void clear();
	void sort();
	int search(int val);
	bool search_duplicate(int val);
};

