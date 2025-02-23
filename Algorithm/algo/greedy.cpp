#include <iostream>
#include <algorithm>

void coinExchangeGreedy(int coins[], int numCoins, int amount, int result[], int& resultSize) {
    // Sort coins in descending order using a simple bubble sort (or std::sort)
    for (int i = 0; i < numCoins - 1; ++i) {
        for (int j = 0; j < numCoins - i - 1; ++j) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    resultSize = 0;
    for (int i = 0; i < numCoins; ++i) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[resultSize++] = coins[i];
        }
    }

    if (amount != 0) {
        resultSize = -1; // Indicate failure
    }
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 49;
    int result[100]; // Assuming a maximum of 100 coins in the result
    int resultSize;

    coinExchangeGreedy(coins, numCoins, amount, result, resultSize);

    if (resultSize >= 0) {
        std::cout << "Coins to exchange for " << amount << ": ";
        for (int i = 0; i < resultSize; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Greedy algorithm failed to find a solution for " << amount << " using the given coins." << std::endl;
    }

    // Example with a coin set that fails greedy
    int coins2[] = {1, 3, 4};
    int numCoins2 = sizeof(coins2) / sizeof(coins2[0]);
    int amount2 = 6;
    int result2[100];
    int resultSize2;

    coinExchangeGreedy(coins2, numCoins2, amount2, result2, resultSize2);

    if(resultSize2 >= 0){
        std::cout << "Coins to exchange for " << amount2 << ": ";
        for (int i = 0; i < resultSize2; ++i) {
            std::cout << result2[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Greedy algorithm failed to find a solution for " << amount2 << " using the given coins." << std::endl;
    }

    return 0;
}