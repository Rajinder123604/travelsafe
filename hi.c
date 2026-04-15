/*
#include <stdio.h>
int main()
{
printf("hello");

return 0;
}*/





#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity == 0) break;

        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            double fraction = (double)capacity / item.weight;
            totalValue += item.value * fraction;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)
    };
    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
