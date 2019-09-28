#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 255;
class HashNode
{
public:
	int key;
	string value;
	HashNode* next;
	HashNode(int key, string value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

class HashMap
{
private:
	HashNode * * htable;
public:
	HashMap()
	{
		htable = new HashNode*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			htable[i] = NULL;
	}
	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			HashNode* entry = htable[i];
			while (entry != NULL)
			{
				HashNode* prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
		delete[] htable;
	}

	int HashFunc(int key)
	{
		double A = 0.61803398863412439823150634765625;
		double exp = A * key;
		return key * (exp - (int)exp);
	}

	void Insert(int key, string value)
	{
		int hash_val = HashFunc(key);
		HashNode* prev = NULL;
		HashNode* entry = htable[hash_val];
		while (entry != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (entry == NULL)
		{
			entry = new HashNode(key, value);
			if (prev == NULL)
			{
				htable[hash_val] = entry;
			}
			else
			{
				prev->next = entry;
			}
		}
		else
		{
			entry->value = value;
		}
	}
	
	int Search(int key)
	{
		bool flag = false;
		int hash_val = HashFunc(key);
		HashNode* entry = htable[hash_val];
		while (entry != NULL)
		{
			if (entry->key == key)
			{
				cout << entry->value << " ";
				flag = true;
			}
			entry = entry->next;
		}
		if (!flag)
			return -1;
	}
};

int main()
{
	HashMap hash;
	int key;
	string value;
	int choice;
	while (1)
	{
		cout << "\n------------------------" << endl;
		cout << "Operations on Hash Table" << endl;
		cout << "\n------------------------" << endl;
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> value;
			cout << "Enter key at which element to be inserted: ";
			cin >> key;
			hash.Insert(key, value);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> key;
			cout << "Element at key " << key << " : ";
			if (hash.Search(key) == -1)
			{
				cout << "No element found at key " << key << endl;
				continue;
			}
			break;
		case 3:
			exit(1);
		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}
