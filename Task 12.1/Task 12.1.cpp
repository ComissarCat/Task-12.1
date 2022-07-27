﻿#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <algorithm>

using namespace std;
using namespace experimental::filesystem;

void task_1(string file_name_1, string file_name_2);
void task_2(string file_name);
void task_3(string file_name);
void task_4();
void create_file(string file_name);

int main()
{
    setlocale(LC_ALL, "Russian");

    string file_name_1 = "text_file_1.txt";
    string file_name_2 = "text_file_2.txt";
    path file = file_name_1;    
    if (not exists(file)) create_file(file_name_1);
    task_1(file_name_1, file_name_2);
    task_2(file_name_1);
    task_3(file_name_1);

    return 0;
}

void create_file(string file_name)
{
    ofstream file;
    file.open(file_name);
    file << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n";
    file << "Nisi quis eleifend quam adipiscing vitae proin sagittis nisl.Porttitor massa id neque aliquam vestibulum morbi blandit cursus.\n";
    file << "Tortor id aliquet lectus proin nibh nisl condimentum id venenatis. Convallis tellus id interdum velit laoreet id donec ultrices tincidunt.\n";
    file << "Gravida neque convallis a cras semper auctor neque vitae tempus. Fames ac turpis egestas sed tempus urna et pharetra pharetra.\n";
    file << "Phasellus egestas tellus rutrum tellus pellentesque eu. Sit amet risus nullam eget felis eget.\n";
    file << "Pellentesque eu tincidunt tortor aliquam nulla facilisi cras. Ullamcorper malesuada proin libero nunc.In egestas erat imperdiet sed.\n";
    file << "Donec et odio pellentesque diam volutpat commodo sed egestas. Vitae congue mauris rhoncus aenean vel.\n";
    file << "A iaculis at erat pellentesque adipiscing commodo elit at imperdiet. Ac feugiat sed lectus vestibulum mattis ullamcorper velit.\n";
    file << "Phasellus faucibus scelerisque eleifend donec pretium vulputate sapien nec.";
    file.close();
}

void task_1(string file_name_1, string file_name_2)
{
    ifstream file_1;
    ofstream file_2;
    string bufer;
    int number_of_strings = 0;
    file_1.open(file_name_1);
    file_2.open(file_name_2);
    while (not file_1.eof())
    {
        getline(file_1, bufer);
        number_of_strings++;
    }
    file_1.seekg(0);
    for (int i = 0; i < number_of_strings - 1; i++)
    {
        getline(file_1, bufer);
        file_2 << bufer << endl;
    }
    file_1.close();
    file_2.close();
}

void task_2(string file_name)
{
    ifstream file;
    string bufer;
    int length = 0;
    file.open(file_name);
    while (not file.eof())
    {
        getline(file, bufer);
        (bufer.length() > length) ? length = bufer.length() : length;
    }
    cout << "Длина самой длинной строки равна " << length << " символов\n\n";
    file.close();
}

void task_3(string file_name)
{
    ifstream file;
    string bufer, target_word;
    int number_of_words_if_file = 0;
    file.open(file_name);
    cout << "Введите искомое слово: ";
    getline(cin, target_word);
    transform(target_word.begin(), target_word.end(), target_word.begin(), ::tolower);
    while (not file.eof())
    {
        getline(file, bufer);
        transform(bufer.begin(), bufer.end(), bufer.begin(), ::tolower);
        while (bufer.find(target_word) != bufer.npos)
        {
            ++number_of_words_if_file;
            bufer.erase(bufer.find(target_word), target_word.length());
        }
    }
    cout << target_word << " встречается в файле " << number_of_words_if_file << " раз.\n\n";
    file.close();
}