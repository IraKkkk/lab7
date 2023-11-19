#include <iostream>
#include <locale> // Додано бібліотеку для роботи з локаллю

class FractionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Некоректне дробове число!";
    }
};

int calculateIntegerPartNoException(int numerator, int denominator) {
    if (denominator == 0) {
        throw "Дiлення на нуль!";
    }
    return numerator / denominator;
}

int calculateIntegerPartThrowSpec(int numerator, int denominator) {
    if (denominator == 0) {
        throw "Дiлення на нуль!";
    }
    return numerator / denominator;
}

int calculateIntegerPartConcreteSpec(int numerator, int denominator) throw(FractionException) {
    if (denominator == 0) {
        throw FractionException();
    }
    return numerator / denominator;
}

int calculateIntegerPartCustomSpec(int numerator, int denominator) {
    if (denominator == 0) {
        throw FractionException();
    }
    return numerator / denominator;
}

int main() {
    // Встановлення української локалі для консолі
    std::locale::global(std::locale(""));

    int numerator, denominator;

    std::cout << "Введiть чисельник: ";
    std::cin >> numerator;

    std::cout << "Введiть знаменник: ";
    std::cin >> denominator;

    try {
        int result;

        result = calculateIntegerPartNoException(numerator, denominator);
        std::cout << "Результат без специфiкацiй виключень: " << result << std::endl;

        result = calculateIntegerPartThrowSpec(numerator, denominator);
        std::cout << "Результат зi специфiкацiєю throw(): " << result << std::endl;

        result = calculateIntegerPartConcreteSpec(numerator, denominator);
        std::cout << "Результат з конкретною специфiкацiєю: " << result << std::endl;

        result = calculateIntegerPartCustomSpec(numerator, denominator);
        std::cout << "Результат з власною специфiкацiєю: " << result << std::endl;

    }
    catch (const char* msg) {
        std::cerr << "Помилка: " << msg << std::endl;
    }
    catch (FractionException& e) {
        std::cerr << "Виникла помилка: " << e.what() << std::endl;
    }

    return 0;
}
