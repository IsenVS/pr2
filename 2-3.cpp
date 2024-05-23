#include <iostream>
using namespace std;

/* Функция для нахождения НОД и мультипликативного обратного
 Принимает два числа a и b, а также ссылки на два числа x и y
 для хранения результатов уравнения ax + by = gcd(a, b) */
int extendedEuclid(int c, int d, int &x, int &y) {
    if (d == 0) {
        x = 1; // Базовый случай, когда одно из чисел становится нулем
        y = 0;
        return c;
    } else {
        int x1, y1;
        int gcd = extendedEuclid(d, c % d, x1, y1); 
        x = y1;
        y = x1 - (c / d) * y1; // Обновляем x и y согласно алгоритму
        return gcd;
    }
}

/* Функция для нахождения мультипликативного обратного по модулю m
 Принимает целые числа c и m, возвращает мультипликативный обратный, если он существует */
int modInverse(int c, int m) {
    int x, y;
    int gcd = extendedEuclid(c, m, x, y); // Вызов функции для получения коэффициентов x, y
    if (gcd != 1) {
        cout << "Обратный элемент не существует, так как НОД(" << c << ", " << m << ") != 1\n";
        return 0; // Возвращаем 0, если НОД не равен 1
    } else {
        // Возвращаем x по модулю m, учитывая, что x может быть отрицательным
        return (x % m + m) % m;
    }
}

int main() {
    int c, m;
    cout << "Введите c: "; cin >> c;
    cout << "Введите m: "; cin >> m;
    
    int inverse = modInverse(c, m); // Вызываем функцию для вычисления обратного
    if (inverse) {
        cout << "Мультипликативный обратный к " << c << " по модулю " << m << " равен " << inverse << "\n";
    }

    return 0; // Завершаем программу
}