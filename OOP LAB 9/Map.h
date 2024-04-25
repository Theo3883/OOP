#pragma once
template <class Key, class Val>
class Map
{
private:
	struct pair
	{
		Key key;
		Val value;
		int index;
	};
	int count;
	int map_size;
	pair* map;
	void map_expand()
	{
		map_size *= 2;
		pair* temp = new pair[map_size];
		for (int i = 0; i <= count; i++)
			temp[i] = map[i];
		delete[] map;
		map = temp;
	}
	const pair* begin() const {
		return &map[0];
	}

	const pair* end() const {
		return &map[count + 1];
	}
public:
	Map()
	{
		count = -1;
		map_size = 1;
		map = new pair[map_size];
	}
	~Map()
	{
		delete[] map;
	}
	pair* begin() {
		return &map[0];
	}
	pair* end() {
		return &map[count + 1];
	}
	Val& operator[](const Key& keyy)
	{
		for (int i = 0; i < map_size; i++)
			if (map[i].key == keyy)
				return map[i].value;
		if (count + 1 >= map_size)
			map_expand();
		map[++count].key = keyy;
		map[count].index = count;
		return map[count].value;
	}
	void Set(Key key_set, Val value_set)
	{
		if (count + 1 >= map_size)
			map_expand();
		map[++count].key = key_set;
		map[count].value = value_set;
		map[count].index = count;
	}
	bool Get(const Key& key, Val& value)
	{
		for (int i = 0; i < map_size; i++)
			if (map[i].key == key)
			{
				map[i].value = value;
				return true;
			}
		return false;
	}
	int Count()
	{
		return count+1;
	}
	void Clear()
	{
		
	}
	bool Delete(const Key& key)
	{
		for(int i=0;i<count;i++)
			if (map[i].key == key)
			{
				for (int j = i; j < count; j++)
				{
					map[j] = map[j + 1];
					map[j].index--;
				}
				count--;
				return true;
			}
		return false;
	}
	bool Includes(const Map<Key, Val>& map_compare)
	{
		if (this->Count() != (map_compare.count +1))
			return false;
		for (auto [key, value, index] : map_compare)
			if(!this->Get(key,value))
				return false;
		return true;
	}
};