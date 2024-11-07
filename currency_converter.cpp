#include <iostream>
#include <unordered_map>
#include <string>

class CurrencyConverter {
public:
    CurrencyConverter() {
        // Initialize exchange rates (static rates for simplicity)
        exchangeRates["USD"] = 1.0;       // Base currency (USD)
        exchangeRates["EUR"] = 0.85;      // 1 USD to EUR
        exchangeRates["JPY"] = 110.0;     // 1 USD to JPY
        exchangeRates["GBP"] = 0.75;      // 1 USD to GBP
        exchangeRates["AUD"] = 1.35;      // 1 USD to AUD
        exchangeRates["INR"] = 73.0;       // 1 USD to INR
        exchangeRates["CAD"] = 1.25;      // 1 USD to CAD
        exchangeRates["CHF"] = 0.92;      // 1 USD to CHF
        exchangeRates["CNY"] = 6.5;       // 1 USD to CNY
        exchangeRates["NZD"] = 1.40;      // 1 USD to NZD
        exchangeRates["ZAR"] = 14.5;      // 1 USD to ZAR (South African Rand)
        exchangeRates["MXN"] = 20.0;      // 1 USD to MXN (Mexican Peso)
        exchangeRates["SGD"] = 1.36;      // 1 USD to SGD (Singapore Dollar)
        // Add more currencies as needed
    }

    void convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency) {
        if (exchangeRates.find(fromCurrency) == exchangeRates.end() || 
            exchangeRates.find(toCurrency) == exchangeRates.end()) {
            std::cout << "Error: Currency not supported." << std::endl;
            return;
        }

        // Convert amount to USD first, then to the target currency
        double amountInUSD = amount / exchangeRates[fromCurrency];
        double convertedAmount = amountInUSD * exchangeRates[toCurrency];

        std::cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << std::endl;
    }

    void displaySupportedCurrencies() {
        std::cout << "Supported currencies: ";
        for (const auto& pair : exchangeRates) {
            std::cout << pair.first << " ";
        }
        std::cout << std::endl;
    }

private:
    std::unordered_map<std::string, double> exchangeRates;
};

int main() {
    CurrencyConverter converter;
    converter.displaySupportedCurrencies();

    double amount;
    std::string fromCurrency, toCurrency;

    std::cout << "Enter amount: ";
    std::cin >> amount;

    std::cout << "Enter from currency (e.g., USD, EUR, JPY, GBP, AUD, INR, CAD, CHF, CNY, NZD, ZAR, MXN, SGD): ";
    std::cin >> fromCurrency;

    std::cout << "Enter to currency (e.g., USD, EUR, JPY, GBP, AUD, INR, CAD, CHF, CNY, NZD, ZAR, MXN, SGD): ";
    std::cin >> toCurrency;

    converter.convertCurrency(amount, fromCurrency, toCurrency);

    return 0;
}
