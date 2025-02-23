#include <iostream>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double valuePerWeight;
};

// Comparison function for std::sort (needed for C-style arrays)  basic operation change with input
bool compareItems(const Item& a, const Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
}

double fractionalKnapsack(int capacity, Item items[], int numItems) {
    // Calculate valuePerWeight for each item
    for (int i = 0; i < numItems; ++i) {
        items[i].valuePerWeight = (double)items[i].value / items[i].weight;
    }

    // Sort the items using std::sort (works with C-style arrays too)
    std::sort(items, items + numItems, compareItems);

    double totalValue = 0.0;
    for (int i = 0; i < numItems; ++i) {
        if (capacity == 0) break; // Knapsack full

        int takeWeight = std::min(capacity, items[i].weight); // Take as much as possible
        totalValue += items[i].valuePerWeight * takeWeight;
        capacity -= takeWeight;
    }
    return totalValue;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int numItems = sizeof(items) / sizeof(items[0]); // Important: Calculate number of items

    int capacity = 50;
    double maxValue = fractionalKnapsack(capacity, items, numItems);  // Pass numItems
    std::cout << "Maximum value: " << maxValue << std::endl; // Output: 240
    return 0;
}