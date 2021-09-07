#include <bits/stdc++.h>

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

using namespace std;

array<string,30> ten = {"Hiđro", "Heli", "Liti", "Beri", "Bo", "Cacbon", "Nitơ", "Oxi", "Flo", "Neon", "Natri", "Magie", "Nhôm", "Silic", "Photpho", "Lưu huỳnh", "Clo", "Agon", "Kali", "Canxi", "Crom", "Mangan", "Sắt", "Đồng", "Kẽm", "Brom", "Bạc", "Bari", "Thuỷ ngân", "Chì"};
array<string,30> nt = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Cr", "Mn", "Fe", "Cu", "Zn", "Br", "Ag", "Ba", "Hg", "Pb"};
array<string,30> ntk = {"1", "4", "7", "9", "11", "12", "14", "16", "19", "20", "23", "24", "27", "28", "31", "32", "35.5", "39.9", "39", "40", "52", "55", "56", "64", "65", "80", "108", "137", "201", "207"};
array<string,30> ht = {"1", "0", "1", "2", "3", "2,4", "2,3,4", "2", "1", "0", "1", "2", "3", "4", "3,5", "2,4,6", "1", "0", "1", "2", "2,3", "2,4,7", "2,3", "1,2", "2", "1", "1", "2", "1,2", "2,4"};
array<string,30> proton = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "24", "25", "26", "29", "30", "35", "47", "56", "80", "82"};
ofstream fo;

int getkey(map<int, bool> &m) {
    srand(time(NULL));
    int key = rand() % 30;
    while (m[key]==1)
        key = rand() % 30;
    return key;
}

void lower(string &s) {
    for_each(s.begin(), s.end(), [](char &c) {
        c = tolower(c);
    });
}

void writeLog(int i, int k, int wrong, int repeat) {
    cout << "\nDẠNG " << i << ":\n";
    cout << "Số câu đúng       : " << k << "/30\n";
    cout << "Số câu sai        : " << wrong << "\n";
    cout << "Số câu làm lại    : " << repeat << "\n";
    fo << "DẠNG " << i << ":\n";
    fo << "Số câu đúng       : " << k << "/30\n";
    fo << "Số câu sai        : " << wrong << "\n";
    fo << "Số câu làm lại    : " << repeat << "\n";
}

void intro() {
    cout << "\nSố lượng câu hỏi mỗi lần kiểm tra là 30, nếu trả lời sai câu hỏi sẽ được hỏi lại cho đến khi trả lời đúng!" << endl;
    cout << "Nhớ bấm Enter sau khi nhập câu trả lời để kiểm tra đáp án!" << endl;
    cout << "Nếu muốn thoát dạng đang làm nhập câu trả lời là x và bấm Enter.\n" << endl;
}

void Dang0() {
    intro();
    int i = 0, key, wrong = 0, repeat = 0;
    map<int, bool> m, check_wrong;
    string inp;
    array<string, 30> nt2 = nt;
    while (i < 30) {
        key = getkey(m);
        cout << "Kí hiệu hoá học của " << ten[key] << " là: ";
        cin >> inp;
        if (inp == "x") break;
        lower(inp);
        lower(nt2[key]);
        if (inp == nt2[key]) {
            cout << "Chính xác!" << endl;
            m[key] = 1;
            ++i;
        } else {
            cout << "Sai!" << endl;
            if (check_wrong[key] == false) {
                check_wrong[key] = true;
                ++wrong;
            }
            ++repeat;
        }
    }
    writeLog(0, i, wrong, repeat);
}

void Dang1() {
    intro();
    int i = 0, key, wrong = 0, repeat = 0;
    map<int, bool> m, check_wrong;
    string inp;
    while (i < 30) {
        key = getkey(m);
        cout << "Nguyên tử khối của " << nt[key] << " là: ";
        cin >> inp;
        if (inp == "x") break;
        if (inp == ntk[key]) {
            cout << "Chính xác!" << endl;
            m[key] = 1;
            ++i;
        } else {
            cout << "Sai!" << endl;
            if (check_wrong[key] == false) {
                check_wrong[key] = true;
                ++wrong;
            }
            ++repeat;
        }
    }
    writeLog(1, i, wrong, repeat);
}

void Dang2() {
    intro();
    int i = 0, key, wrong = 0, repeat = 0;
    map<int, bool> m, check_wrong;
    string inp;
    while (i < 30) {
        key = getkey(m);
        cout << "Kí hiệu nguyên tử có NTK " << ntk[key] << " là: ";
        cin >> inp;
        if (inp == "x") break;
        lower(inp);
        lower(nt[key]);
        //cout << inp << " , " << nt[key] << "\n";
        if (inp == nt[key]) {
            cout << "Chính xác!" << endl;
            m[key] = 1;
            ++i;
        } else {
            cout << "Sai!" << endl;
            if (check_wrong[key] == false) {
                check_wrong[key] = true;
                ++wrong;
            }
            ++repeat;
        }
    }
    writeLog(2, i, wrong, repeat);
}

void Dang3() {
    intro();
    cout << "Nhập hoá trị ở dạng số (VD: 2)\nNếu có nhiều hoá trị thì nhập theo thứ tự từ nhỏ đến lớn, cách nhau bởi dấu phẩy (VD: 2,3,4)\nNếu là nguyên tố khí hiếm thì nhập 0\n" << endl;
    int i = 0, key, wrong = 0, repeat = 0;
    map<int, bool> m, check_wrong;
    string inp;
    while (i < 3) {
        key = getkey(m);
        cout << "Hoá trị của " << nt[key] << " là: ";
        cin >> inp;
        if (inp == "x") break;
        if (inp == ht[key]) {
            cout << "Chính xác!" << endl;
            m[key] = 1;
            ++i;
        } else {
            cout << "Sai!" << endl;
            if (check_wrong[key] == false) {
                check_wrong[key] = true;
                ++wrong;
            }
            ++repeat;
        }
    }
    writeLog(3, i, wrong, repeat);
}

void Dang4() {
    intro();
    cout << "Nhập hoá trị ở dạng số (VD: 2)\nNếu có nhiều hoá trị thì nhập theo thứ tự từ nhỏ đến lớn, cách nhau bởi dấu phẩy (VD: 2,3,4)\nNếu là nguyên tố khí hiếm thì nhập 0\n" << endl;
    int i = 0, key, wrong = 0, repeat = 0;
    map<int, bool> m, check_wrong;
    string inp;
    while (i < 30) {
        key = getkey(m);
        cout << "Hoá trị của nguyên tử có NTK " << ntk[key] << " là: ";
        cin >> inp;
        if (inp == "x") break;
        if (inp == ht[key]) {
            cout << "Chính xác!" << endl;
            m[key] = 1;
            ++i;
        } else {
            cout << "Sai!" << endl;
            if (check_wrong[key] == false) {
                check_wrong[key] = true;
                ++wrong;
            }
            ++repeat;
        }
    }
    writeLog(4, i, wrong, repeat);
}

void Dang5() {
    intro();
    int i = 0, key, wrong = 0, repeat = 0;
    map<int, bool> m, check_wrong;
    string inp;
    while (i < 30) {
        key = getkey(m);
        cout << "Số proton của nguyên tố " << ten[key] << " là: ";
        cin >> inp;
        if (inp == "x") break;
        if (inp == proton[key]) {
            cout << "Chính xác!" << endl;
            m[key] = 1;
            ++i;
        } else {
            cout << "Sai!" << endl;
            if (check_wrong[key] == false) {
                check_wrong[key] = true;
                ++wrong;
            }
            ++repeat;
        }
    }
    writeLog(5, i, wrong, repeat);
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    try {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;                   // Width of each character in the font
        cfi.dwFontSize.Y = 21;                  // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        system("color F0");
        system("title Nguyen To Hoa Hoc - https://github.com/nguyenson-gdtd/NTHH");
    } catch (exception) {}
    #endif // _WIN32

    //Mở file log
    fo.open("log.txt", ios::app);
    //Ghi thời gian bắt đầu vào log
    auto bd = chrono::system_clock::now();
    time_t start_time = chrono::system_clock::to_time_t(bd);
    fo << "============================================\n";
    fo << "Thời gian bắt đầu : " << ctime(&start_time);
    while (true) {
        cout << "Dữ liệu sử dụng được lấy từ Bảng 1 Trang 42 SGK Hoá học 8 NXB Giáo dục Việt Nam!" << endl;
        cout << "Kết quả sau mỗi lần chạy chương trình sẽ được ghi vào file log.txt cùng thư mục." << endl;
        cout << "0.Cho tên nguyên tố   - hỏi kí hiệu hoá học" << endl;
        cout << "1.Cho kí hiệu hoá học - hỏi nguyên tử khối" << endl;
        cout << "2.Cho nguyên tử khối  - hỏi kí hiệu hoá học" << endl;
        cout << "3.Cho kí hiệu hoá học - hỏi hoá trị" << endl;
        cout << "4.Cho nguyên tử khối  - hỏi hoá trị" << endl;
        cout << "5.Cho tên nguyên tố   - hỏi số proton" << endl;
        cout << "Chọn một trong 6 dạng bằng cách nhập một trong 6 số 0,1,2,3,4,5 và nhấn Enter: ";
        string i;
        cin >> i;
        if (i >= "0" && i <= "5") {
            //Vào chương trình
            switch (stoi(i)) {
            case 0: {
                Dang0();
                break;
            }
            case 1: {
                Dang1();
                break;
            }
            case 2: {
                Dang2();
                break;
            }
            case 3: {
                Dang3();
                break;
            }
            case 4: {
                Dang4();
                break;
            }
            case 5: {
                Dang5();
                break;
            }
            }
            cout << "\nBạn có muốn làm tiếp dạng khác? Nhập y/n(có/không): ";
            string check;
            cin >> check;
            lower(check);
            if (check == "n" || check == "no" || check == "không" || check == "khong" || check == "ko" || check == "k") {
                //Ghi thời gian kết thúc vào log
                auto kt = chrono::system_clock::now();
                time_t end_time = chrono::system_clock::to_time_t(kt);
                fo << "Thời gian kết thúc: " << ctime(&end_time);
                chrono::duration<double> elapsed_seconds = kt - bd;
                fo << "Tổng thời gian làm: " << elapsed_seconds.count() / 60 << " phút";
                fo << "\n============================================\n";
                fo.close();
                break;
            } else {
                try {
                    system("cls");
                } catch (exception) {
                    system("clear");
                }
            }
        } else {
            try {
                system("cls");
            } catch (exception) {
                system("clear");
            }
        }
    }
    return 0;
}
