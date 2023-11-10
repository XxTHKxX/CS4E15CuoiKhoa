#include <iostream>
#include <string>
using namespace std;

class Vemaybay {
private:
    string tenchuyen, ngaybay;
    float giave;

public:
    Vemaybay() {}
    ~Vemaybay() {}

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
        cin.ignore();
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << ", Ngay bay: " << ngaybay << ", Gia ve: " << giave << endl;
    }

    float getgiave() {
        return giave;
    }
};

class Nguoi {
protected:
    string hoten, gioitinh;
    int tuoi;

public:
    Nguoi() {}
    ~Nguoi() {}

    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << ", Gioi tinh: " << gioitinh << ", Tuoi: " << tuoi << endl;
    }
};


class Hanhkhach : public Nguoi {
private:
    Vemaybay *ve;
    int soluong;

public:
    Hanhkhach() {}
    ~Hanhkhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        cin.ignore();

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++) {
            cout << "Nhap ve thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        for (int i = 0; i < soluong; i++) {
            ve[i].Xuat();
        }
        cout << "Tong tien: " << tongtien() << endl;
    }

    float tongtien() {
        float tong = 0;
        for (int i = 0; i < soluong; i++) {
            tong += ve[i].getgiave();
        }
        return tong;
    }
};


void sapxep(Hanhkhach* ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tongtien() < ds[j].tongtien()) {
                Hanhkhach temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}


int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore();

    Hanhkhach* ds = new Hanhkhach[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
        ds[i].Nhap();
    }

    cout << "\nDanh sach hanh khach va tong tien:" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    sapxep(ds, n);

    cout << "\nDanh sach hanh khach sau khi sap xep:" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    delete[] ds;
    return 0;
}
