#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Прототипи функцій
void task1();
void task2();
void my_insert(char* str, int pos, const char* s);
bool is_valid(const string& str);
void process_string(string& s, const string& s1, const string& s2);

int main() {
    int choice;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Завдання 1 (Вставка рядка)\n";
        cout << "2. Завдання 2 (Заміна підрядків у файлі)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            task1();
        } else if (choice == 2) {
            task2();
        }
    } while (choice != 0);
    return 0;
}

void my_insert(char* str, int pos, const char* s) {
    int len_str = 0;
    while(str[len_str] != '\0') len_str++;
    int len_s = 0;
    while(s[len_s] != '\0') len_s++;

    if (pos > len_str || pos < 0) return;

    for(int i = len_str; i >= pos; i--) {
        str[i + len_s] = str[i];
    }
    
    for(int i = 0; i < len_s; i++) {
        str[pos + i] = s[i];
    }
}

void task1() {
    cout << "\nВиконання Завдання 1\n";
    char str_c[100] = "Hello world";
    string str_cpp = "Hello world";
    const char* s = "beautiful ";
    int pos = 6;

    cout << "Вхідний рядок: " << str_c << "\n";
    cout << "Рядок для вставки: " << s << " на позицію " << pos << "\n";

    my_insert(str_c, pos, s);
    cout << "Результат my_insert: " << str_c << "\n";

    str_cpp.insert(pos, s);
    cout << "Результат string::insert: " << str_cpp << "\n";
}

bool is_valid(const string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];
        bool is_letter = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        bool is_digit = (c >= '0' && c <= '9');
        bool is_space = (c == ' ');
        bool is_underscore = (c == '_');
        
        if (!is_letter && !is_digit && !is_space && !is_underscore) {
            return false;
        }
    }
    return true;
}

void process_string(string& s, const string& s1, const string& s2) {
    if (s1.empty()) return;
    size_t pos = 0;
    while ((pos = s.find(s1, pos)) != string::npos) {
        s.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
}

void task2() {
    cout << "\nВиконання Завдання 2\n";
    string s1, s2;
    cout << "Введіть рядок S1 (який замінюємо): ";
    getline(cin, s1);
    cout << "Введіть рядок S2 (на який замінюємо): ";
    getline(cin, s2);

    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Файл input.txt не знайдено. Створюємо тестовий...\n";
        ofstream temp("input.txt");
        temp << "Hello test string 1\n";
        temp << "test string 2 test\n";
        temp << "test number 4\n";
        temp.close();
        fin.open("input.txt");
    }

    ofstream fout("output.txt");
    string line;
    while (getline(fin, line)) {
        if (is_valid(line)) {
            process_string(line, s1, s2);
            fout << line << "\n";
        }
    }
    fin.close();
    fout.close();
    cout << "Обробку завершено. Результати записано у output.txt\n";
}
