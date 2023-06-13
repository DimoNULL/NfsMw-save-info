#включить <iostream>

#включить <fstream>

#включить <cstring>

int main() {

 std::ifstream сохранить("сохранить", std::ios::двоичный файл);

 if (!сохранить.is_open()) {

 std::cout << "Файл не найден" << std::endl;

 возврат 1;

    }

    

 символ magic_bytes[4];

 сохранить.прочитать(magic_bytes, 4);

 int magic_int = *переинтерпретируй_каст<int*>(magic_bytes);

 if (magic_int != 0x4D433032) {

 std::cout << "Недопустимый файл сохранения NFS: MW" << std::endl;

 возврат 1;

    }

 std::cout << "Допустимый файл сохранения NFS: MW" << std::endl;

    

 std::cout << "Информация профиля:" << std::endl;

    

 сохранить.seekg(0x5A31);

 имя символа в байтах[8];

 сохранить.прочитать(name_bytes, 8);

 std::строковое pname(name_bytes, 8);

 std::cout << "Имя: " << pname << std::endl;

    

 сохранить.seekg(0x4039);

 символ money_bytes[4];

 сохранить.прочитать(money_bytes, 4);

 int pmoney = *переинтерпретируй_каст<int*>(money_bytes);

 std::cout << "Деньги: " << pmoney << std::endl;

    

 возвращает 0;

}
