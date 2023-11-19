#include <iostream>
#include <locale> // ������ �������� ��� ������ � �������

class FractionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "���������� ������� �����!";
    }
};

int calculateIntegerPartNoException(int numerator, int denominator) {
    if (denominator == 0) {
        throw "�i����� �� ����!";
    }
    return numerator / denominator;
}

int calculateIntegerPartThrowSpec(int numerator, int denominator) {
    if (denominator == 0) {
        throw "�i����� �� ����!";
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
    // ������������ ��������� ����� ��� ������
    std::locale::global(std::locale(""));

    int numerator, denominator;

    std::cout << "����i�� ���������: ";
    std::cin >> numerator;

    std::cout << "����i�� ���������: ";
    std::cin >> denominator;

    try {
        int result;

        result = calculateIntegerPartNoException(numerator, denominator);
        std::cout << "��������� ��� ������i���i� ���������: " << result << std::endl;

        result = calculateIntegerPartThrowSpec(numerator, denominator);
        std::cout << "��������� �i ������i���i�� throw(): " << result << std::endl;

        result = calculateIntegerPartConcreteSpec(numerator, denominator);
        std::cout << "��������� � ���������� ������i���i��: " << result << std::endl;

        result = calculateIntegerPartCustomSpec(numerator, denominator);
        std::cout << "��������� � ������� ������i���i��: " << result << std::endl;

    }
    catch (const char* msg) {
        std::cerr << "�������: " << msg << std::endl;
    }
    catch (FractionException& e) {
        std::cerr << "������� �������: " << e.what() << std::endl;
    }

    return 0;
}
