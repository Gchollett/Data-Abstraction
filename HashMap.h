#ifndef HASHMAP
#define HASHMAP

#include <vector>
#include <utility>
#include <algorithm>

template<typename K,typename V,typename Hash>
class HashMap {
	Hash hashFunction;
	std::vector<std::vector<std::pair<K,V>>> table;
	unsigned int numElems;

public:
	typedef K key_type;
	typedef V mapped_type;
	typedef std::pair<K,V> value_type;

	class const_iterator;

	class iterator {
		decltype(table.begin()) mainIter;
		decltype(table.begin()) mainEnd;
		decltype(table[0].begin()) subIter;
	public:
		friend class const_iterator;
		iterator(const decltype(mainIter) mi,const decltype(mainEnd) me):mainIter(mi),mainEnd(me) {
			if(mainIter!=mainEnd) subIter = mainIter->begin();
			while(mainIter!=mainEnd && subIter == mainIter->end()) {
				++mainIter;
				subIter = mainIter->begin();
			}
		}
		iterator(const decltype(mainIter) mi, const decltype(mainEnd) me, const decltype(subIter) si):
				mainIter(mi),mainEnd(me),subIter(si) {}

		bool operator==(const iterator &i) const { return mainIter==i.mainIter && (mainIter==mainEnd || subIter==i.subIter); }
		bool operator!=(const iterator &i) const { return !(*this==i); }
		std::pair<K,V> &operator*() { return *subIter; }
		iterator &operator++() {
			++subIter;
			while(mainIter!=mainEnd && subIter==mainIter->end()) {
				++mainIter;
				subIter = mainIter->begin();
			}
			return *this;
		}
		iterator operator++(int) {
			iterator tmp(*this);
			++(*this);
			return tmp;
		}
		friend class HashMap;
	};

	class const_iterator {
		decltype(table.cbegin()) mainIter;
		decltype(table.cbegin()) mainEnd;
		decltype(table[0].cbegin()) subIter;
	public:
		const_iterator(const decltype(table.cbegin()) mi,const decltype(table.cbegin()) me):mainIter(mi),mainEnd(me) {
			if(mainIter!=mainEnd) subIter = mainIter->begin();
			while(mainIter!=mainEnd && subIter == mainIter->end()) {
				++mainIter;
				subIter = mainIter->begin();
			}
		}
		const_iterator(const decltype(table.begin()) mi,
			const decltype(table.begin()) me,
			const decltype(table[0].begin()) si):
				mainIter(mi),mainEnd(me),subIter(si) {}
		const_iterator(const iterator &i):mainIter(i.mainIter),
			mainEnd(i.mainEnd),subIter(i.subIter) {}

		bool operator==(const const_iterator &i) const { return mainIter==i.mainIter && (mainIter==mainEnd || subIter==i.subIter); }
		bool operator!=(const const_iterator &i) const { return !(*this==i); }
		const std::pair<K,V> &operator*() const { return *subIter; }
		const_iterator &operator++() {
			++subIter;
			while(mainIter!=mainEnd && subIter==mainIter->end()) {
				++mainIter;
				subIter = mainIter->begin();
			}
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		friend class HashMap;
	};

	HashMap(const Hash &hf):hashFunction(hf),table(11),numElems(0) {}
	HashMap(const Hash &hf,int tblsize):hashFunction(hf),table(tblsize),numElems(0) {}

	bool empty() const { return numElems == 0; }

	unsigned size() const { return numElems; }

	iterator find(const key_type& k);

	const_iterator find(const key_type& k) const;

	int count(const key_type& k) const;

	std::pair<iterator,bool> insert(const value_type& val);

	template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
		for(auto iter = first; iter!=last; ++iter) {
			K key = (*iter).first;
			int hc = hashFunction(key);
			int bin = hc % table.size();
			auto iter2 = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
			if(iter2==table[bin].end()) {
				++numElems;
				table[bin].push_back(*iter);
			}	
		}
	}

	iterator erase(const_iterator position);

	int erase(const key_type& k);

	void clear();

	mapped_type &operator[](const K &key);

	bool operator==(const HashMap<K,V,Hash>& rhs) const;

	bool operator!=(const HashMap<K,V,Hash>& rhs) const;

	iterator begin() { return iterator(table.begin(),table.end()); }

	const_iterator begin() const { return const_iterator(table.begin(),table.end()); }

	iterator end() { return iterator(table.end(),table.end()); }

	const_iterator end() const { return const_iterator(table.end(),table.end()); }

	const_iterator cbegin() const { return const_iterator(table.begin(),table.end()); }

	const_iterator cend() const { return const_iterator(table.end(),table.end()); }

private:
	void growTableAndRehash();
};

template <class K, class V, class Hash>
bool HashMap<K,V,Hash>::operator==(const HashMap<K,V,Hash>& rhs) const {
	if(numElems != rhs.numElems) return false;
	for(auto x:*this){
		K key = x.first;
		int hc = hashFunction(key);
		int bin = hc % rhs.table.size();
		auto iter = find_if(rhs.table[bin].begin(),rhs.table[bin].end(),[&x] (const std::pair<K,V> &p) { return p.first==x.first; });
		if(iter == rhs.table[bin].end() || iter->second != x.second) return false;
	}
	return true;
}

template <class K, class V, class Hash>
bool HashMap<K,V,Hash>::operator!=(const HashMap<K,V,Hash>& rhs) const {
	return !(*this==rhs);
}

template<typename K,typename V,typename Hash>
typename HashMap<K,V,Hash>::iterator HashMap<K,V,Hash>::find(const K& key) {
	int hc = hashFunction(key);
	int bin = hc % table.size();
	auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
	if(iter == table[bin].end())return end();
	return iterator(table.begin()+bin,table.end(),iter);
}

template<typename K,typename V,typename Hash>
typename HashMap<K,V,Hash>::const_iterator HashMap<K,V,Hash>::find(const K& key) const {
	int hc = hashFunction(key);
	int bin = hc % table.size();
	auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
	if(iter == table[bin].end()) return cend();
	return const_iterator(table.cbegin()+bin,table.cend(),iter);
}

template<typename K,typename V,typename Hash>
int HashMap<K,V,Hash>::count(const key_type& key) const {
	int hc = hashFunction(key);
	int bin = hc % table.size();
	auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
	if(iter == table[bin].end()) return 0;
	return 1;
}

template<typename K,typename V,typename Hash>
std::pair<typename HashMap<K,V,Hash>::iterator,bool> HashMap<K,V,Hash>::insert(const value_type& val) {
		int hc = hashFunction(val.first);
		int bin = hc % table.size();
		K key = val.first;
		auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
		if(iter==table[bin].end()) {
			// if(numElems > table.size()/2){
			// 	growTableAndRehash();
			// 	bin = hc % table.size();
			// }
			++numElems;
			table[bin].push_back(val);
			return std::make_pair(iterator(table.begin()+bin,table.end(),--table[bin].end()),true);
		} else {
			return std::make_pair(iterator(table.begin()+bin,table.end(),iter),false);
		}
}

template<typename K,typename V,typename Hash>
typename HashMap<K,V,Hash>::iterator HashMap<K,V,Hash>::erase(const_iterator position) {
	if(position==cend()) return end();
	K key = (*position).first;
	int hc = hashFunction(key);
	int bin = hc % table.size();
	auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
	table[bin].erase(iter);
	numElems--;
	return ++iterator(table.begin()+bin,table.end(),iter);
}

template<typename K,typename V,typename Hash>
int HashMap<K,V,Hash>::erase(const K& key) {
	int hc = hashFunction(key);
	int bin = hc % table.size();
	auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
	if(iter == table[bin].end()) return 0;
	table[bin].erase(iter);
	numElems--;
	return 1;
}

template<typename K,typename V,typename Hash>
void HashMap<K,V,Hash>::clear() {
	for(auto &x:table) x.erase(x.begin(),x.end());
	numElems = 0;
}

template<typename K,typename V,typename Hash>
typename HashMap<K,V,Hash>::mapped_type &HashMap<K,V,Hash>::operator[](const K &key) {
	int hc = hashFunction(key);
	int bin = hc % table.size();
	auto iter = find_if(table[bin].begin(),table[bin].end(),[&key] (const std::pair<K,V> &p) { return p.first==key; });
	if(iter == table[bin].end()){
		insert(std::make_pair(key,V()));
		return table[bin].back().second;
	}
	return iter->second;
}

template<typename K,typename V,typename Hash>
void HashMap<K,V,Hash>::growTableAndRehash() {
	HashMap<K,V,Hash> newHashMap(this->hashFunction,table.size()*2);
	newHashMap.insert(begin(),end());
	*this = newHashMap;
}


#endif