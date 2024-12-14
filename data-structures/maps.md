# Maps in C++

In C++, **maps** are associative containers that store elements in key-value pairs, where each key is unique. The Standard Template Library (STL) provides two primary map types:

1. **`std::map`**: An ordered map implemented typically as a **Red-Black Tree**.
2. **`std::unordered_map`**: An unordered map implemented using **hash tables**.

This guide will cover both types, their characteristics, usage, and when to choose one over the other.

---

## Table of Contents

1. [Introduction to Maps](#1-introduction-to-maps)
2. [`std::map` (Ordered Map)](#2-stdmap-ordered-map)
    - [2.1. Characteristics](#21-characteristics)
    - [2.2. Basic Operations](#22-basic-operations)
    - [2.3. Implementation Details](#23-implementation-details)
    - [2.4. Usage Examples](#24-usage-examples)
3. [`std::unordered_map`](#3-stdunordered_map)
    - [3.1. Characteristics](#31-characteristics)
    - [3.2. Basic Operations](#32-basic-operations)
    - [3.3. Implementation Details](#33-implementation-details)
    - [3.4. Usage Examples](#34-usage-examples)
4. [Comparison Between `std::map` and `std::unordered_map`](#4-comparison-between-stdmap-and-stdunordered_map)
5. [Advanced Topics](#5-advanced-topics)
    - [5.1. Custom Comparators](#51-custom-comparators)
    - [5.2. Custom Hash Functions](#52-custom-hash-functions)
6. [Conclusion](#6-conclusion)

---

## 1. Introduction to Maps

Maps are associative containers that store elements formed by a combination of a **key** value and a **mapped** value, following a specific order. They allow for efficient retrieval, insertion, and deletion of elements based on keys.

**Key features:**

- **Associative**: Elements are accessed by keys, not by positions.
- **Unique Keys**: Each key is unique; duplicates are not allowed.
- **Key-Value Pairs**: Each element is a pair consisting of a key and a value.

---

## 2. `std::map` (Ordered Map)

### 2.1. Characteristics

- **Ordered**: Elements are stored in a specific order, typically ascending based on the key.
- **Implementation**: Usually implemented as a **Red-Black Tree** or other self-balancing binary search trees.
- **Time Complexity**:
  - Insertion: O(log n)
  - Deletion: O(log n)
  - Search: O(log n)
- **Iterators**: Provide bidirectional iterators.

### 2.2. Basic Operations

- **Insertion**: Inserts a key-value pair.
- **Access**: Retrieve the value associated with a key.
- **Deletion**: Remove elements by key.
- **Traversal**: Iterate over elements in order.

### 2.3. Implementation Details

`std::map` is typically implemented as a Red-Black Tree, which ensures that the tree remains balanced after operations, maintaining O(log n) time complexity.

**Properties of Red-Black Trees:**

1. Nodes are either **red** or **black**.
2. The root is **black**.
3. All leaves (NIL nodes) are **black**.
4. Red nodes cannot have red children (no two reds in a row).
5. Every path from a node to its descendant NIL nodes contains the same number of black nodes.

### 2.4. Usage Examples

**Including the Header:**

```cpp
#include <map>
```

**Declaration:**

```cpp
std::map<KeyType, ValueType> myMap;
```

**Example with `int` keys and `std::string` values:**

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Insertion
    myMap.insert(std::make_pair(1, "One"));
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Access
    std::cout << "Key 2 maps to value: " << myMap[2] << std::endl;

    // Iteration
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Search
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Found key 2 with value: " << it->second << std::endl;
    }

    // Deletion
    myMap.erase(2);

    return 0;
}
```

**Output:**

```
Key 2 maps to value: Two
1: One
2: Two
3: Three
Found key 2 with value: Two
```

---

## 3. `std::unordered_map`

### 3.1. Characteristics

- **Unordered**: Elements are not stored in any particular order.
- **Implementation**: Implemented using **hash tables**.
- **Time Complexity**:
  - Average Case:
    - Insertion: O(1)
    - Deletion: O(1)
    - Search: O(1)
  - Worst Case (when collisions occur):
    - O(n)
- **Iterators**: Provide forward iterators.

### 3.2. Basic Operations

Similar to `std::map`, but without the ordering guarantee.

### 3.3. Implementation Details

`std::unordered_map` uses a hash table to store elements. The key is hashed into an index of a bucket where the value is stored.

**Hash Table Characteristics:**

- **Buckets**: Arrays or linked lists where elements with the same hash value are stored.
- **Load Factor**: A measure of how full the hash table is.
- **Rehashing**: Process of resizing the table to maintain performance.

### 3.4. Usage Examples

**Including the Header:**

```cpp
#include <unordered_map>
```

**Declaration:**

```cpp
std::unordered_map<KeyType, ValueType> myUnorderedMap;
```

**Example with `std::string` keys and `int` values:**

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myUnorderedMap;

    // Insertion
    myUnorderedMap.insert(std::make_pair("One", 1));
    myUnorderedMap["Two"] = 2;
    myUnorderedMap["Three"] = 3;

    // Access
    std::cout << "Key 'Two' maps to value: " << myUnorderedMap["Two"] << std::endl;

    // Iteration
    for (const auto& pair : myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Search
    auto it = myUnorderedMap.find("Two");
    if (it != myUnorderedMap.end()) {
        std::cout << "Found key 'Two' with value: " << it->second << std::endl;
    }

    // Deletion
    myUnorderedMap.erase("Two");

    return 0;
}
```

**Output (order may vary):**

```
Key 'Two' maps to value: 2
Three: 3
One: 1
Two: 2
Found key 'Two' with value: 2
```

---

## 4. Comparison Between `std::map` and `std::unordered_map`

| Feature                 | `std::map`                 | `std::unordered_map`       |
|-------------------------|----------------------------|----------------------------|
| **Order of Elements**   | Ordered (by key)           | Unordered                  |
| **Implementation**      | Red-Black Tree (BST)       | Hash Table                 |
| **Search Complexity**   | O(log n)                   | Average: O(1), Worst: O(n) |
| **Insertion Complexity**| O(log n)                   | Average: O(1), Worst: O(n) |
| **Deletion Complexity** | O(log n)                   | Average: O(1), Worst: O(n) |
| **Iterator Type**       | Bidirectional              | Forward                    |
| **Memory Overhead**     | Higher per node (tree pointers) | Lower per element          |

**When to Use:**

- Use **`std::map`** when:
  - You need the elements to be sorted.
  - You need to traverse elements in order.
  - Predictable performance is required.

- Use **`std::unordered_map`** when:
  - Order doesn't matter.
  - You need faster average case performance.
  - Memory overhead should be minimized.

---

## 5. Advanced Topics

### 5.1. Custom Comparators

For `std::map`, you can define a custom comparator to change the ordering of the keys.

**Example:**

```cpp
#include <iostream>
#include <map>
#include <string>

struct ReverseOrder {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs; // Reverse order
    }
};

int main() {
    std::map<int, std::string, ReverseOrder> myMap;

    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

**Output:**

```
3: Three
2: Two
1: One
```

### 5.2. Custom Hash Functions

For `std::unordered_map`, you can define custom hash functions and equality predicates.

**Example:**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

struct CustomHash {
    std::size_t operator()(const std::string& key) const {
        // Simple hash function (not suitable for production)
        return key.length();
    }
};

struct CustomEqual {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return lhs == rhs;
    }
};

int main() {
    std::unordered_map<std::string, int, CustomHash, CustomEqual> myUnorderedMap;

    myUnorderedMap["One"] = 1;
    myUnorderedMap["Two"] = 2;
    myUnorderedMap["Three"] = 3;

    for (const auto& pair : myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

**Note:** Custom hash functions should be well-designed to minimize collisions.

---

## 6. Conclusion

Maps in C++ are powerful tools for managing key-value pairs efficiently. Choosing between `std::map` and `std::unordered_map` depends on your specific needs regarding element ordering and performance.

- **Use `std::map`** when:
  - You need elements to be sorted by keys.
  - You require predictable performance.
  - You need bidirectional iterators.

- **Use `std::unordered_map`** when:
  - The order of elements is irrelevant.
  - You need faster average-case performance for large datasets.
  - You want to minimize memory overhead per element.

**Key Takeaways:**

- **Understand your requirements**: Order vs. performance.
- **Know the underlying implementations**: Helps in optimizing performance.
- **Utilize advanced features**: Custom comparators and hash functions can tailor the maps to your needs.

---

**Further Reading:**

- **C++ Reference for `std::map`**: [cppreference.com/std/map](https://en.cppreference.com/w/cpp/container/map)
- **C++ Reference for `std::unordered_map`**: [cppreference.com/std/unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)
- **Effective STL** by Scott Meyers: Provides insights into using STL containers effectively.

---

**Example: Word Frequency Count Using `std::unordered_map`**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

int main() {
    std::unordered_map<std::string, int> wordCount;
    std::string text = "this is a sample text with several words this is a test";

    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        ++wordCount[word];
    }

    for (const auto& pair : wordCount) {
        std::cout << "'" << pair.first << "': " << pair.second << std::endl;
    }

    return 0;
}
```

**Possible Output:**

```
'this': 2
'is': 2
'a': 2
'sample': 1
'text': 1
'with': 1
'several': 1
'words': 1
'test': 1
```

This example demonstrates how `std::unordered_map` can be used for efficient counting of word frequencies in text data.

---

