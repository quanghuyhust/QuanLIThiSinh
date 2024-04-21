#include <iostream>
#include <string>
#include <vector>

using namespace std;

class thiSinh 
{
protected:
	int sBD;
	string hoTen;
	string diaChi;
	int mucUT;
public:
	thiSinh(int sbd, string hoten, string diachi, int mucut) :
		sBD(sbd), hoTen(hoten), diaChi(diachi), mucUT(mucut) {}
	virtual ~thiSinh() {}
	virtual void hienthi()
	{
		cout << "SBD cua thi sinh la: " << sBD << endl;
		cout << "Ho va ten cua thi sinh la: " << hoTen << endl;
		cout << "SBD cua thi sinh la: " << diaChi << endl;
		cout << "SBD cua thi sinh la: " << mucUT << endl;
	}
	int getSBD()
	{
		return sBD;
	}
};

class TuyenSinh
{
private:
	vector<thiSinh> dsThiSinh;
public:
	void ThemTS(thiSinh ts)
	{
		dsThiSinh.push_back(ts);
	}
	void tkSBD(int sbd)
	{
		for (thiSinh ts : dsThiSinh) {
			if (ts.getSBD() == sbd) {
				cout << "Thong tin thi sinh co so bao danh " << sbd << "la: " << endl;
				ts.hienthi();
				return;
			}
			cout << "Khong co thi sinh phu hop" << endl;
		}
	}
	void hienthiTT() 
	{
		for (thiSinh ts : dsThiSinh) 
		{
				ts.hienthi();
		}
	}
};

int main()
{
	TuyenSinh* tuyensinh = new TuyenSinh();

	thiSinh* thisinh1 = new thiSinh(1,"Nguyen Van A","HN", 0);
	thiSinh* thisinh2 = new thiSinh(2, "Nguyen Quang B", "HT", 1);
	thiSinh* thisinh3 = new thiSinh(3, "Nguyen Van C", "PT", 1);
	thiSinh* thisinh4 = new thiSinh(4, "Giang Van A", "CB", 2);
	thiSinh* thisinh5 = new thiSinh(5, "Nguyen Thi L", "QN", 1);

	tuyensinh->ThemTS(*thisinh1);
	tuyensinh->ThemTS(*thisinh2);
	tuyensinh->ThemTS(*thisinh3);
	tuyensinh->ThemTS(*thisinh4);
	tuyensinh->ThemTS(*thisinh5);

	int luaChon;
	do {
		cout << "\nLua chon chuc nang:" << endl;
		cout << "1. Them moi thi sinh" << endl;
		cout << "2. Hien thi thong tin thi sinh va khoi thi" << endl;
		cout << "3. Tim kiem theo so bao danh" << endl;
		cout << "4. Thoat" << endl;
		cout << "Lua chon: ";
		cin >> luaChon;

		switch (luaChon) {
		case 1: {
			int sbd, uuTien;
			string ten, diaChi;
			cout << "Nhap so bao danh: ";
			cin >> sbd;
			cin.ignore();
			cout << "Nhap ho ten: ";
			getline(cin, ten);
			cout << "Nhap dia chi: ";
			getline(cin, diaChi);
			cout << "Nhap muc uu tien: ";
			cin >> uuTien;

			thiSinh* ts= new thiSinh(sbd, ten, diaChi, uuTien);
			tuyensinh->ThemTS(*ts);
			cout << "Them moi thanh cong!" << endl;
			break;
		}
		case 2: {
			cout << "Thong tin toan bo thi sinh: ";
			tuyensinh->hienthiTT();
			break;
		}
		case 3: {
			int sbd;
			cout << "Nhap so bao danh can tim kiem: ";
			cin >> sbd;
			tuyensinh->tkSBD(sbd);
			break;
		}
		case 4:
			cout << "Thoat chuong trinh." << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			break;
		}
	} while (luaChon != 4);
	return 0;
}