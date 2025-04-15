#ifndef MAPWRAPPER_H
#define MAPWRAPPER_H
#include <iostream>
#include <map>

template <typename Key, typename Value> class Map {
public:
  Map();                                           // Default constructor
  Map(const Map &other);                           // Copy constructor
  Map &operator=(const Map &other);                // Copy assignment operator
  ~Map();                                          // Destructor
  void insert(const Key &key, const Value &value); // insert Value
  bool contains(const Key &key) const;             // check Value if inside map
  Value &at(const Key &key);
  const Value &at(const Key &key) const;
  void erase(const Key &key);
  void clear();
  int size() const;
  void print() const;

private:
  std::map<Key, Value> m_map;
};

#endif // MAPWRAPPER_H

// Default constructor
template <typename Key, typename Value> Map<Key, Value>::Map() {}

// Copy constructor
template <typename Key, typename Value> Map<Key, Value>::Map(const Map &other) {
  m_map = other.m_map;
}

// Copy assignment operator
template <typename Key, typename Value>
Map<Key, Value> &Map<Key, Value>::operator=(const Map &other) {
  if (this != &other) {
    m_map = other.m_map;
  }
  return *this;
}

// Destructor
template <typename Key, typename Value> Map<Key, Value>::~Map() {}

// Insert or update
template <typename Key, typename Value>
void Map<Key, Value>::insert(const Key &key, const Value &value) {
  m_map[key] = value;
}

// Check existence
template <typename Key, typename Value>
bool Map<Key, Value>::contains(const Key &key) const {
  return m_map.find(key) != m_map.end();
}

// Get value (non-const)
template <typename Key, typename Value>
Value &Map<Key, Value>::at(const Key &key) {
  return m_map.at(key);
}

// Get value (const)
template <typename Key, typename Value>
const Value &Map<Key, Value>::at(const Key &key) const {
  return m_map.at(key);
}

// Erase key
template <typename Key, typename Value>
void Map<Key, Value>::erase(const Key &key) {
  m_map.erase(key);
}

// Clear map
template <typename Key, typename Value> void Map<Key, Value>::clear() {
  m_map.clear();
}

// Get size
template <typename Key, typename Value> int Map<Key, Value>::size() const {
  return m_map.size();
}

// Print contents
template <typename Key, typename Value> void Map<Key, Value>::print() const {
  for (const auto &[key, value] : m_map) {
    std::cout << key << " : " << value << '\n';
  }
}
