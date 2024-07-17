#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <vector>
#include<stdlib.h>
#include<windows.h>
using namespace std;
struct Sinhvien{
		string ms, ho, ten, lop;
		double diem;
		void nhap(){
			cout << "Nhap Ma: "; getline(cin, ms);
			cout << "Nhap Ho: "; getline(cin, ho);
			cout << "Nhap Ten: "; getline(cin, ten);
			cout << "Nhap Lop: "; getline(cin, lop);
			cout << "Nhap Diem: "; cin >> diem;
		}
	};
struct Node{
	Sinhvien s;
	Node* next;
	Node* prev;
};
typedef struct Node* node;

node makeNode(Sinhvien s){
	node newSV = new Node();
	newSV->s = s;
	newSV->next = NULL;
	newSV->prev = NULL;
	return newSV;
}

void them_cuoi_don(node &head, Sinhvien s, int lc){
	node newSV = makeNode(s);
	if(lc == 1){
		if(head == NULL){
			head = newSV;
			return;
		}
		node tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newSV;
	}
	else if(lc == 2){
		if(head == NULL){
			head = newSV;
			return;
		}
		node tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newSV;
		newSV->prev = tmp;
	}
	else if(lc == 3){
		if(head == NULL){
			head = newSV;
			newSV->next = head;
		}
		node tmp = head;
		while(tmp->next != head){
			tmp = tmp->next;
		}
		tmp->next = newSV;
		newSV->next = head;
	}
}
void Doc(ifstream &file, Sinhvien &sv){
	getline(file, sv.ms, ',');
	getline(file, sv.ho, ',');
	getline(file, sv.ten, ',');
	getline(file, sv.lop, ',');
	file >> sv.diem;
	file.ignore();
}
string Doc_danh_sach(ifstream &file, vector<Sinhvien> &ds, node &head, int lc){
	string res = "";
	bool check = true;
	if(lc == 1){	
		unordered_set<string> msSet;
		while(file.peek() != EOF){
			Sinhvien s;
			Doc(file, s);
			if(msSet.find(s.ms) == msSet.end()){
				ds.push_back(s);
				msSet.insert(s.ms);
			}
			else{
				res += "MA SINH VIEN " + s.ms + " DA TUNG XUAT HIEN NEN KHONG LUU SINH VIEN.\n";
				check = false;
			}
		}
	}
	else if(lc == 2){
		unordered_set<string> msSet;
		while(file.peek() != EOF){
			Sinhvien s;
			Doc(file, s);
			if(msSet.find(s.ms) == msSet.end()){
				them_cuoi_don(head,s,1);
				msSet.insert(s.ms);
			}
			else{
				check = false;
				res += "MA SINH VIEN " + s.ms + " DA TUNG XUAT HIEN NEN KHONG LUU SINH VIEN.\n";
			}
		}
	}
	else if(lc == 3){
		unordered_set<string> msSet;
		while(file.peek() != EOF){
			Sinhvien s;
			Doc(file, s);
			if(msSet.find(s.ms) == msSet.end()){
				them_cuoi_don(head,s,2);
				msSet.insert(s.ms);
			}
			else{
				check = false;
				res += "MA SINH VIEN " + s.ms + " DA TUNG XUAT HIEN NEN KHONG LUU SINH VIEN.\n";
			}
		}
	}
	else if(lc == 4){
		unordered_set<string> msSet;
		while(file.peek() != EOF){
			Sinhvien s;
			Doc(file, s);
			if(msSet.find(s.ms) == msSet.end()){
				them_cuoi_don(head,s,3);
				msSet.insert(s.ms);
			}
			else{
				check = false;
				res += "MA SINH VIEN " + s.ms + " DA TUNG XUAT HIEN NEN KHONG LUU SINH VIEN.\n";
			}
		}
	}
	if(check){
		res = "";
	}
	return res;
}
string chuyen(float value) {
    ostringstream out;
    out << fixed << setprecision(2) << value;
    
    string result = out.str();
    
    // Xóa các số 0 thừa ở phần thập phân
    if(result.find('.') != string::npos) {
        result.erase(result.find_last_not_of('0') + 1, string::npos);
        if(result.back() == '.') {
            result.pop_back();
        }
    }
    
    return result;
}
string chuan_hoa(string s){
	stringstream ss(s);
	string token;
	vector<string> v;
	string tmp = "";
	while(ss >> token){
		v.push_back(token);
	}
	for(int i = 0; i < v.size(); i++){
		tmp += toupper(v[i][0]);
		for(int j = 1; j < v[i].size(); j++){
			tmp += tolower(v[i][j]);
		}
		if(i != v.size()-1){
			tmp += " ";
		}
	}
	return tmp;
}

string daonguoc(string s){
	stack<char> st;
	string res = "";
	stringstream ss(s);
	string token;
	while(ss >> token){
		for(int i = 0; i < token.size(); i++){
			st.push(token[i]);
		}
		st.push(' ');
	}
	st.pop();
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	return res;
}

string to_lower(string &s){
	string res = "";
	for(int i = 0; i < s.size(); i++){
		res += tolower(s[i]);
	}
	return res;
}

string to_upper(string &s){
	string res = "";
	for(int i = 0; i < s.size(); i++){
		res += toupper(s[i]);
	}
	return res;
}
string  check_nhap(vector<Sinhvien> &ds, node &head, int lc){
	Sinhvien a;
	string output = "";
	a.nhap();
	string res = to_upper(a.ms);
	bool check = false;
	if(lc == 1){
		for(int i = 0; i < ds.size(); i++){
			if(ds[i].ms == res){
				check = true;
				break;
			}
		}
		if(check){	
			output += "TRUNG MA SO SINH VIEN NEN KHONG THE THEM SINH VIEN MOI.\n";
		}
		else{
			ds.push_back(a);
		}
	}
	else if(lc == 2){
		for(node i = head; i->next != NULL; i = i->next){
			string tmp = to_upper(i->s.ms);
			if(res == tmp){
				check = true;
				break;
			}
		}
		if(check){
			output += "TRUNG MA SO SINH VIEN NEN KHONG THE THEM SINH VIEN MOI.\n";
		}
		else{
			them_cuoi_don(head, a,1);
		}
	}
	else if(lc == 3){
		for(node i = head; i->next != NULL; i = i->next){
			string tmp = to_upper(i->s.ms);
			if(res == tmp){
				check = true;
				break;
			}
		}
		if(check){
			output += "TRUNG MA SO SINH VIEN NEN KHONG THE THEM SINH VIEN.\n";
		}
		else{
			them_cuoi_don(head, a,2);
		}
	}
	else if(lc == 4){
		node current = head;
		do {
		    string tmp = to_upper(current->s.ms);
		    if (tmp == res) {
		        check = true;
				break; 
		    }
		    current = current->next;
		} while (current != head);
		if(check){
			output += "TRUNG MA SO SINH VIEN NEN KHONG THE THEM SINH VIEN.\n";
		}
		else{
			them_cuoi_don(head, a, 3);
		}
	}
	return output;
}

string XUAT(vector<Sinhvien> ds, node head, int lc){
	string res = "";
	if(lc == 1){
		for(auto x : ds){
			string tmp;
			tmp = to_upper(x.ms);
			res +=  tmp + " - ";
			tmp = chuan_hoa(x.ho);
			res +=  tmp + " - ";
			tmp = chuan_hoa(x.ten);
			res +=  tmp + " - ";
			tmp = to_upper(x.lop);
			res +=  tmp + " - " + chuyen(x.diem) + "\n";
		}
	}
	else if(lc == 2 || lc == 3){
		while(head != NULL){
			string tmp;
			tmp = to_upper(head->s.ms);
			res +=  tmp + " - ";
			tmp = chuan_hoa(head->s.ho);
			res +=  tmp + " - ";
			tmp = chuan_hoa(head->s.ten);
			res +=  tmp + " - ";
			tmp = to_upper(head->s.lop);
			res +=  tmp + " - " + chuyen(head->s.diem) + "\n";
			head = head->next;
		}
	}
	else if(lc == 4){
		node temp = head;
		do{
			string tmp;
			tmp = to_upper(temp->s.ms);
			res +=  tmp + " - ";
			tmp = chuan_hoa(temp->s.ho);
			res +=  tmp + " - ";
			tmp = chuan_hoa(temp->s.ten);
			res +=  tmp + " - ";
			tmp = to_upper(temp->s.lop);
			res +=  tmp + " - " + chuyen(temp->s.diem) + "\n";
			temp = temp->next;
		}while(temp != head);
	}
	return res;
}
string tkMS(vector<Sinhvien> ds, node head, int lc){
	string ma;
	string output = "";
	bool check = false;
	cout << "Nhap ma sinh vien can tim: "; cin >> ma;
	string res = to_lower(ma);
	if(lc == 1){
		for(int i = 0; i < ds.size(); i++){
			string tmp = to_lower(ds[i].ms);
			if(res == tmp){
				output += ds[i].ms + " - " + daonguoc(ds[i].ho) + " " + daonguoc(ds[i].ten) + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";
				check = true;
				break;
			}
		}
	}
	else if(lc == 2 || lc == 3){
		for(node i = head; i->next != NULL; i = i->next){
			string tmp = to_lower(i->s.ms);
			if(res == tmp){
				output +=  i->s.ms + " - " + daonguoc(i->s.ho) + " " + daonguoc(i->s.ten) + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";	
				check = true;
				break;	
			}
		}
	}
	else if(lc == 4){
		node current = head;
		do{
		    string tmp = to_lower(current->s.ms);
		    if (res == tmp) {
		        output +=  current->s.ms + " - " + daonguoc(current->s.ho) + " " + daonguoc(current->s.ten) + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n";      
				check = true;
				break;
			}
		    current = current->next;
		}while (current != head);
	}
	if(check == false){
		output += "Khong tim thay sinh vien can tim.\n";
	}
	return output;
}

string tkHo(vector<Sinhvien> ds, node head, int lc){
	string ho;
	string output = "";
	cout << "Nhap Ho sinh vien can tim: "; getline(cin, ho);
	string res = to_lower(ho);
	bool check = false;
	if(lc == 1){
		for(int i = 0; i < ds.size(); i++){
			string tmp = to_lower(ds[i].ho);
			if(res == tmp){
				check = true;
				output += ds[i].ms + " - " + daonguoc(ds[i].ho) + " " + daonguoc(ds[i].ten) + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";	
			}
		}
	}
	else if(lc == 2 || lc == 3){
		for(node i = head; i->next != NULL; i = i->next){
			string tmp = to_lower(i->s.ho);
			if(res == tmp){
				check = true;
				output +=  i->s.ms + " - " + daonguoc(i->s.ho) + " " + daonguoc(i->s.ten) + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";	
			}
		}
	}
	else if(lc == 4){
		node current = head;
		do {
		    string tmp = to_lower(current->s.ho);
		    if (res == tmp) {
		       	output +=  current->s.ms + " - " + daonguoc(current->s.ho) + " " + daonguoc(current->s.ten) + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n";    
		        check = true;    
		    }
		    current = current->next;
		} while (current != head);
	}
	if(!check){
		output += "Khong tim thay sinh vien can tim.\n";
	}
	return output;
}

string tkTen(vector<Sinhvien> ds, node head, int lc){
	string ten;
	string output = "";
	cout << "Nhap Ten sinh vien can tim: "; cin >> ten;
	string res = to_lower(ten);
	bool check = false;
	if(lc == 1){
		for(int i = 0; i < ds.size(); i++){
			string tmp = to_lower(ds[i].ten);
			if(res == tmp){
				check = true;
				output += ds[i].ms + " - " + daonguoc(ds[i].ho) + " " + daonguoc(ds[i].ten) + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";
			}
		}
	}
	
	else if(lc == 2 || lc == 3){
		for(node i = head; i->next != NULL; i = i->next){
			string tmp = to_lower(i->s.ten);
			if(res == tmp){
				check = true;
				output +=  i->s.ms + " - " + daonguoc(i->s.ho) + " " + daonguoc(i->s.ten) + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";	
			}
		}
	}
	else if(lc == 4){
		node current = head;
		do {
		    string tmp = to_lower(current->s.ten);
		    if (res == tmp) {
		        output +=  current->s.ms + " - " + daonguoc(current->s.ho) + " " + daonguoc(current->s.ten) + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n";     
		        check = true;
		    }
		    current = current->next;
		} while (current != head);
	}
	if(!check){
		output += "Khong tim thay sinh vien can tim.\n";
	}
	return output;
}

string tkLop(vector<Sinhvien> ds, node head, int lc){
	string lop;
	string output = "";
	cout << "Nhap Lop sinh vien can tim: "; cin >> lop;
	string res = to_lower(lop);
	bool check = false;
	if(lc == 1){
		for(int i = 0; i < ds.size(); i++){
			string tmp = to_lower(ds[i].lop);
			if(res == tmp){
				check = true;
				output += ds[i].ms + " - " + daonguoc(ds[i].ho) + " " + daonguoc(ds[i].ten) + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";
			}
		}
	}
	else if(lc == 2 || lc == 3){
		for(node i = head; i->next != NULL; i = i->next){
			string tmp = to_lower(i->s.lop);
			if(res == tmp){
				check = true;
				output +=  i->s.ms + " - " + daonguoc(i->s.ho) + " " + daonguoc(i->s.ten) + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";	
			}
		}
	}
	else if(lc == 4){
		node current = head;
		do {
		    string tmp = to_lower(current->s.lop);
		    if (res == tmp) {
		        output +=  current->s.ms + " - " + daonguoc(current->s.ho) + " " + daonguoc(current->s.ten) + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n";     
		       	check = true;  
		    }
		    current = current->next;
		} while (current != head);
	}
	if(!check){
		output += "Khong tim thay sinh vien can tim.\n";
	}
	return output;
}

string tkDiem(vector<Sinhvien> ds, node head, int lc ){
	double diem;
	string output = "";
	cout << "Nhap Diem sinh vien can tim: "; cin >> diem;
	bool check = false;
	if(lc == 1){
		for(int i = 0; i < ds.size(); i++){
			if(diem == ds[i].diem){
				check = true;
				output += ds[i].ms + " - " + daonguoc(ds[i].ho) + " " + daonguoc(ds[i].ten) + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";	
			}
		}
	}
	else if(lc == 2 || lc == 3){
		for(node i = head; i->next != NULL; i = i->next){
			if(diem == i->s.diem){
				check = true;
				output +=  i->s.ms + " - " + daonguoc(i->s.ho) + " " + daonguoc(i->s.ten) + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";	
			}
		}
	}
	else if(lc == 4){
		node current = head;
		do {
		    if (diem  == current->s.diem) {
		        output +=  current->s.ms + " - " + daonguoc(current->s.ho) + " " + daonguoc(current->s.ten) + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n";   
		        check = true;   
		    }
		    current = current->next;
		} while (current != head);
	}
	if(!check){
		output +=  "Khong tim thay sinh vien can tim.\n";
	}
	return output;
}

string xoa_sinh_vien(vector<Sinhvien> &ds, node &head, int lc){
	string ma;
	cout << "Nhap Ma sinh vien can xoa: "; cin >> ma;
	cin.ignore();
	string res;
	string output = "";
	bool check = false;
	if(lc == 1){
		res = to_lower(ma);
		for(int i = 0; i < ds.size(); i++){
			string tmp = to_lower(ds[i].ms);
			if(res == tmp){
				check = true;
				ds.erase(ds.begin() + i);
				break;
			}
		}
	}
	else if(lc == 2){
		res = to_upper(ma);
		node temp = NULL;
		node tmp = head;
		Sinhvien a;
		a.ms = res;
		if(tmp != NULL && tmp->s.ms == a.ms){
			head = tmp->next;
			delete tmp;
			check = true;
		}
		else{
			while(tmp->next != NULL && tmp->s.ms != a.ms){
				temp = tmp;
				tmp = tmp->next;
			}
			if(tmp != NULL){
				check = true;
				temp->next = tmp->next;
				delete temp;
			}
		}
	}
	else if(lc == 3){
		res = to_upper(ma);
		node temp = NULL;
		node tmp = head;
		Sinhvien a;
		a.ms = res;
		if(tmp != NULL && tmp->s.ms == a.ms){
			head = tmp->next;
			delete tmp;
			check = true;
		}
		else{
			while(tmp->next != NULL && tmp->s.ms != a.ms){
				temp = tmp;
				tmp = tmp->next;
			}
			if(tmp != NULL){
				check = true;
				temp->next = tmp->next;
				if(tmp->next != NULL){
					tmp->next->prev = temp;
				}
				delete temp;
			}
		}
	}
	else if(lc == 4){
		res = to_upper(ma); 
		node temp = nullptr;
		node current = head;
		
		if (current != NULL) {
		    do {
		    	string me = to_upper(current->s.ms);
		        if (me == res) {
		            if (temp == nullptr) { // Xóa nút đầu tiên
		                head = current->next;
		                if (head != nullptr){
		                    head->prev = nullptr;// Nếu danh sách không rỗng, gán nút trước đầu thành nullptr
						}  
						delete current;        	
		                check = true;
		            } else {
		                temp->next = current->next;
		                if (current->next != nullptr)
		                    current->next->prev = temp; // Cập nhật con trỏ prev của nút kế tiếp
		                delete current;
		                check = true;
		            }
		            break;
		        }
		        temp = current;
		        current = current->next;
		    } while (current != head); // Duyệt cho đến khi quay lại nút đầu tiên
		}
	}
	if(!check){
		output = "Khong tim thay Ma sinh vien can xoa.\n";
	}
	return output;
}


string diem_cao(vector<Sinhvien> ds, node head, int lc){
	string output = "";
	if(lc == 1){
		double max_point = -1e18;
		for(int i = 0; i < ds.size(); i++){
			if(max_point < ds[i].diem){
				max_point = ds[i].diem;
			}
		}
		for(int i = 0; i < ds.size(); i++){
			if(ds[i].diem == max_point){
				output += ds[i].ms + " - " + ds[i].ho + " " + ds[i].ten + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";
			}
		}
	}
	else if(lc == 2 || lc == 3){
		double max_point = -1e18;
		for(node i = head; i->next != NULL; i = i->next){
			if(max_point < i->s.diem){
				max_point = i->s.diem;
			}
		}
		for(node i = head; i->next != NULL; i = i->next){
			if(i->s.diem == max_point){
				output += i->s.ms + " - " + i->s.ho + " - " + i->s.ten + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";
			}
		}
	}
	else if(lc == 4){
		node current = head;
		double max_point = -1e18;
		do{
	        if(current->s.diem > max_point){
	            max_point = current->s.diem;
	        }
	        current = current->next;
    	} while (current != head);

    	current = head;
		do {
		    if (current->s.diem == max_point) {
		        output += current->s.ms + " - " + current->s.ho + " - " + current->s.ten + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n" ;
		    }
		    current = current->next;
		} while (current != head);
	}
	return output;
}


string diem_thap(vector<Sinhvien> ds, node head, int lc){
	string output = "";
	if(lc == 1){
		double min_point = 1e18;
		for(int i = 0; i < ds.size(); i++){
			if(ds[i].diem != -1 && min_point > ds[i].diem){
				min_point = ds[i].diem;
			}
		}
		for(int i = 0; i < ds.size(); i++){
			if(ds[i].diem == min_point){
				output += ds[i].ms + " - " + ds[i].ho + " " + ds[i].ten + " - " + ds[i].lop + " - " + chuyen(ds[i].diem) + "\n";
			}
		}
	}
	else if(lc == 2 || lc == 3){
		double min_point = 1e18;
		for(node i = head; i->next != NULL; i = i->next){
			if(i->s.diem != -1 && min_point > i->s.diem ){
				min_point = i->s.diem;
			}
		}
		for(node i = head; i->next != NULL; i = i->next){
			if(i->s.diem == min_point){
				output += i->s.ms + " - " + i->s.ho + " - " + i->s.ten + " - " + i->s.lop + " - " + chuyen(i->s.diem) + "\n";
			}
		}
	}
	else if(lc == 4){
		node current = head;
		double min_point = 1e18;
		do{
	        if(current->s.diem < min_point){
	            min_point = current->s.diem;
	        }
	        current = current->next;
    	} while (current != head);

    	current = head;
		do {
		    if (current->s.diem == min_point) {
		        output += current->s.ms + " - " + current->s.ho + " - " + current->s.ten + " - " + current->s.lop + " - " + chuyen(current->s.diem) + "\n" ;
		    }
		    current = current->next;
		} while (current != head);
	}
	return output;
}


int count(node head, int lc){
	int res;
	if(lc == 1){
		int cnt = 0;
		while(head != NULL){
			if(head->s.diem != -1){		
				++cnt;
			}
			head = head->next;
		}
		res = cnt;
	}
	else if(lc == 2){
		int cnt = 0;
		while(head != NULL){	
			++cnt;
			head = head->next;
		}
		res = cnt;
	}
	else if(lc == 3){
		int cnt = 0;
		node tmp = head;
		do{
			tmp = tmp->next;
			++cnt;
		}while(tmp != head);
		res = cnt;
	}
	return res;
}
double trung_binh(vector<Sinhvien> ds, node head, int lc){
	double res;
	if(lc == 1){
		double tb = 0;
		int cnt = 0;
		for(int i = 0; i < ds.size(); i++){
			if(ds[i].diem != -1){
				tb += ds[i].diem;
				++cnt;
			}
		}	
		res = tb/cnt;
	}
	else if(lc == 2 || lc == 3){
		double tb = 0;
		int cnt = 0;
		for(node i = head; i->next != NULL; i = i->next){
			if(i->s.diem != -1){	
				tb += i->s.diem;
				++cnt;
			}
		}
		res = tb/count(head, 1);
	}
	else if(lc == 4){
		double tb = 0;
		int cnt = 0;
		node tmp = head;
		if(head != NULL){
			do{
				if(tmp->s.diem != -1){
					tb += tmp->s.diem;
					++cnt;
				}
				tmp = tmp->next;
			}while(tmp != head);
		}
		res = tb/cnt;
	}
	return res;
}
// bubble sort
void bubble_sort(vector<Sinhvien> &ds, node &head, int lc2, int lc){
	if(lc2 == 1){
		int n = ds.size();
		if(lc == 1){
			for(int i = 1; i < n; i++){
				for(int j = n-1; j >= i; j--){
					if(ds[j-1].ms > ds[j].ms){
						swap(ds[j-1], ds[j]);
					}
				}
			}
		}
		else if(lc == 2){
			for(int i = 1; i < n; i++){
				for(int j = n-1; j >= i; j--){
					if(ds[j-1].ten > ds[j].ten){
						swap(ds[j-1], ds[j]);
					}
				}
			}
		}
		else if(lc == 3){
			for(int i = 1; i < n; i++){
				for(int j = n-1; j >= i; j--){
					if(ds[j-1].diem > ds[j].diem){
						swap(ds[j-1], ds[j]);
					}
				}
			}
		}
	}
	else if(lc2 == 2 || lc2 == 3){
		if(lc == 1){
			if (head == nullptr || head->next == nullptr) {
        		return; // Danh sách rỗng hoặc chỉ có một nút thì đã sắp xếp rồi
	    	}
	    	bool sorted = false;
	    	while(!sorted){
	    		sorted = true;
	    		node tmp = head;
	    		node Next = tmp->next;
	    		while(Next != NULL){
	    			if(tmp->s.ms > Next->s.ms){
	    				swap(tmp->s, Next->s);
	    				sorted = false;
					}
					tmp = Next;
					Next = Next->next;
				}
			}
		}
		else if(lc == 2){
			if (head == nullptr || head->next == nullptr) {
        		return; // Danh sách rỗng hoặc chỉ có một nút thì đã sắp xếp rồi
	    	}
	    	bool sorted = false;
	    	while(!sorted){
	    		sorted = true;
	    		node tmp = head;
	    		node Next = tmp->next;
	    		while(Next != NULL){
	    			if(tmp->s.ten > Next->s.ten){
	    				swap(tmp->s, Next->s);
	    				sorted = false;
					}
					tmp = Next;
					Next = Next->next;
				}
			}
		}
		else if(lc == 3){
			if (head == nullptr || head->next == nullptr) {
        		return; // Danh sách rỗng hoặc chỉ có một nút thì đã sắp xếp rồi
	    	}
	    	bool sorted = false;
	    	while(!sorted){
	    		sorted = true;
	    		node tmp = head;
	    		node Next = tmp->next;
	    		while(Next != NULL){
	    			if(tmp->s.diem > Next->s.diem){
	    				swap(tmp->s, Next->s);
	    				sorted = false;
					}
					tmp = Next;
					Next = Next->next;
				}
			}
		}
	}
	else if(lc2 == 4){
		if(lc == 1){
			if (head == nullptr || head->next == head) {
		        return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
		    }
		    node end = nullptr;
		    bool swapped;
		
		    do {
		        swapped = false;
		        node current = head;
		
		        while (current->next != end) {
		            if (current->s.ms > current->next->s.ms) {
		                swap(current->s, current->next->s);
		                swapped = true;
		            }
		            current = current->next;
		            if (current == head) {
		                break; // Đã duyệt hết vòng, thoát khỏi vòng lặp
		            }
		        }
		        end = current;
		    } while (swapped);
		}
		else if(lc == 2){
			if (head == nullptr || head->next == head) {
		        return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
		    }
		
		    node end = nullptr;
		    bool swapped;
		
		    do {
		        swapped = false;
		        node current = head;
		
		        while (current->next != end) {
		            if (current->s.ten > current->next->s.ten) {
		                swap(current->s, current->next->s);
		                swapped = true;
		            }
		            current = current->next;
		            if (current == head) {
		                break; // Đã duyệt hết vòng, thoát khỏi vòng lặp
		            }
		        }
		        end = current;
		    } while (swapped);
		}
		else if(lc == 3){
			if (head == nullptr || head->next == head) {
		        return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
		    }
		
		    node end = nullptr;
		    bool swapped;
		
		    do {
		        swapped = false;
		        node current = head;
		
		        while (current->next != end) {
		            if (current->s.diem > current->next->s.diem) {
		                swap(current->s, current->next->s);
		                swapped = true;
		            }
		            current = current->next;
		            if (current == head) {
		                break; // Đã duyệt hết vòng, thoát khỏi vòng lặp
		            }
		        }
		        end = current;
		    } while (swapped);
		}
	}
}

//insertion_sort
void insertion_sort(vector<Sinhvien> &ds,node &head, int lc2, int lc){
	if(lc2 == 1){
		if(lc == 1){
			int i, j;
		    for(i = 1; i < ds.size(); i++){
		        Sinhvien key = ds[i];
		        j = i - 1;
		        while (j >= 0 && ds[j].ms > key.ms){
		            ds[j + 1] = ds[j];
		            j = j - 1;
		        }
		        ds[j + 1] = key;
			}
		}
		else if(lc == 2){
			int i, j;
		    for(i = 1; i < ds.size(); i++){
		        Sinhvien key = ds[i];
		        j = i - 1;
		        while (j >= 0 && ds[j].ten > key.ten){
		            ds[j + 1] = ds[j];
		            j = j - 1;
		        }
		        ds[j + 1] = key;
			}
		}
		else if(lc == 3){
			int i, j;
		    for(i = 1; i < ds.size(); i++){
		        Sinhvien key = ds[i];
		        j = i - 1;
		        while (j >= 0 && ds[j].diem > key.diem){
		            ds[j + 1] = ds[j];
		            j = j - 1;
		        }
		        ds[j + 1] = key;
			}
		}
	}
	else if(lc2 == 2 || lc2 == 3){
		if(lc == 1){
			if(head == NULL || head->next == NULL){
	       		return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
   			}
		    node sort_list = NULL; // Danh sách đã sắp xếp
		    node res = head; // Con trỏ duyệt qua danh sách chưa sắp xếp
		    while(res != NULL){
		        node nextNode = res->next; // Lưu lại con trỏ tới phần tử kế tiếp
		        // Nếu danh sách đã sắp xếp rỗng hoặc phần tử hiện tại có ms nhỏ hơn phần tử đầu tiên trong danh sách đã sắp xếp
		        if(sort_list == NULL || res->s.ms < sort_list->s.ms){
		            res->next = sort_list; // Chèn phần tử hiện tại vào đầu danh sách đã sắp xếp
		            sort_list = res;
		        } else {
		            node temp = sort_list;
		            // Tìm vị trí để chèn phần tử hiện tại vào danh sách đã sắp xếp
		            while(temp->next != NULL && temp->next->s.ms < res->s.ms){
		                temp = temp->next;
		            }
		            res->next = temp->next; // Chèn phần tử hiện tại vào vị trí tìm được
		            temp->next = res;
		        }
		        res = nextNode; // Chuyển sang phần tử kế tiếp trong danh sách chưa sắp xếp
		    }
		    head = sort_list; // Cập nhật head của danh sách thành danh sách đã sắp xếp	
		}
		else if(lc == 2){
			if(head == NULL || head->next == NULL){
	       		return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
   			}
		    node sort_list = NULL; // Danh sách đã sắp xếp
		    node res = head; // Con trỏ duyệt qua danh sách chưa sắp xếp
		    while(res != NULL){	
		        node nextNode = res->next; // Nếu danh sách đã sắp xếp rỗng hoặc phần tử hiện tại có ms nhỏ hơn phần tử đầu tiên trong danh sách đã sắp xếp
		        if(sort_list == NULL || res->s.ten < sort_list->s.ten){
		            res->next = sort_list; // Chèn phần tử hiện tại vào đầu danh sách đã sắp xếp
		            sort_list = res;
		        } else {
		            node temp = sort_list;
		            // Tìm vị trí để chèn phần tử hiện tại vào danh sách đã sắp xếp
		            while(temp->next != NULL && temp->next->s.ten < res->s.ten){
		                temp = temp->next;
		            }
		            res->next = temp->next; // Chèn phần tử hiện tại vào vị trí tìm được
		            temp->next = res;
		        }
		        res = nextNode; // Chuyển sang phần tử kế tiếp trong danh sách chưa sắp xếp
		    }
		    head = sort_list; // Cập nhật head của danh sách thành danh sách đã sắp xếp	
		}
		else if(lc == 3){
			if(head == NULL || head->next == NULL){
	       		return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
   			}
		    node sort_list = NULL; // Danh sách đã sắp xếp
		    node res = head; // Con trỏ duyệt qua danh sách chưa sắp xếp
		    while(res != NULL){
		        node nextNode = res->next; // Lưu lại con trỏ tới phần tử kế tiếp
		        // Nếu danh sách đã sắp xếp rỗng hoặc phần tử hiện tại có ms nhỏ hơn phần tử đầu tiên trong danh sách đã sắp xếp
		        if(sort_list == NULL || res->s.diem < sort_list->s.diem){
		            res->next = sort_list; // Chèn phần tử hiện tại vào đầu danh sách đã sắp xếp
		            sort_list = res;
		        } else {
		            node temp = sort_list;
		            // Tìm vị trí để chèn phần tử hiện tại vào danh sách đã sắp xếp
		            while(temp->next != NULL && temp->next->s.diem < res->s.diem){
		                temp = temp->next;
		            }
		            res->next = temp->next; // Chèn phần tử hiện tại vào vị trí tìm được
		            temp->next = res;
		        }
		        res = nextNode; // Chuyển sang phần tử kế tiếp trong danh sách chưa sắp xếp
		    }
		    head = sort_list; // Cập nhật head của danh sách thành danh sách đã sắp xếp	
		}
	}
	else if(lc2 == 4){
		if(lc == 1){
		    if (head == nullptr || head->next == head) {
		        return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
		    }
		
		    node sort_list = nullptr; // Danh sách đã sắp xếp
		    node res = head; // Con trỏ duyệt qua danh sách chưa sắp xếp
		    do {
		        node nextNode = res->next; // Lưu lại con trỏ tới phần tử kế tiếp
		        // Nếu danh sách đã sắp xếp rỗng hoặc phần tử hiện tại có mã số nhỏ hơn phần tử đầu tiên trong danh sách đã sắp xếp
		        if (sort_list == nullptr || res->s.ms< sort_list->s.ms) {
		            res->next = sort_list; // Chèn phần tử hiện tại vào đầu danh sách đã sắp xếp
		            sort_list = res;
		        } else {
		            node temp = sort_list;
		            // Tìm vị trí để chèn phần tử hiện tại vào danh sách đã sắp xếp
		            while (temp->next != nullptr && temp->next != sort_list && temp->next->s.ms < res->s.ms) {
		                temp = temp->next;
		            }
		            res->next = temp->next; // Chèn phần tử hiện tại vào vị trí tìm được
		            temp->next = res;
		        }
		        res = nextNode; // Chuyển sang phần tử kế tiếp trong danh sách chưa sắp xếp
		    } while (res != head);
		    node last = sort_list;
		    while (last->next != nullptr && last->next != sort_list) {
		        last = last->next;
		    }
		
		    // Kết nối phần tử cuối với head ban đầu
		    last->next = sort_list;
		    head = sort_list; // Cập nhật head của danh sách thành danh sách đã sắp xếp
		}
		else if(lc == 2){
			if (head == nullptr || head->next == head) {
		        return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
		    }
		
		    node sort_list = nullptr; // Danh sách đã sắp xếp
		    node res = head; // Con trỏ duyệt qua danh sách chưa sắp xếp
		    do {
		        node nextNode = res->next; // Lưu lại con trỏ tới phần tử kế tiếp
		        // Nếu danh sách đã sắp xếp rỗng hoặc phần tử hiện tại có mã số nhỏ hơn phần tử đầu tiên trong danh sách đã sắp xếp
		        if (sort_list == nullptr || res->s.ten < sort_list->s.ten) {
		            res->next = sort_list; // Chèn phần tử hiện tại vào đầu danh sách đã sắp xếp
		            sort_list = res;
		        } else {
		            node temp = sort_list;
		            // Tìm vị trí để chèn phần tử hiện tại vào danh sách đã sắp xếp
		            while (temp->next != nullptr && temp->next != sort_list && temp->next->s.ten < res->s.ten) {
		                temp = temp->next;
		            }
		            res->next = temp->next; // Chèn phần tử hiện tại vào vị trí tìm được
		            temp->next = res;
		        }
		        res = nextNode; // Chuyển sang phần tử kế tiếp trong danh sách chưa sắp xếp
		    } while (res != head);
		    node last = sort_list;
		    while (last->next != nullptr && last->next != sort_list) {
		        last = last->next;
		    }
		
		    // Kết nối phần tử cuối với head ban đầu
		    last->next = sort_list;
		    head = sort_list; // Cập nhật head của danh sách thành danh sách đã sắp xếp
		}
		else if(lc == 3){
			if (head == nullptr || head->next == head) {
		        return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử
		    }
		
		    node sort_list = nullptr; // Danh sách đã sắp xếp
		    node res = head; // Con trỏ duyệt qua danh sách chưa sắp xếp
		    do {
		        node nextNode = res->next; // Lưu lại con trỏ tới phần tử kế tiếp
		        // Nếu danh sách đã sắp xếp rỗng hoặc phần tử hiện tại có mã số nhỏ hơn phần tử đầu tiên trong danh sách đã sắp xếp
		        if (sort_list == nullptr || res->s.diem < sort_list->s.diem) {
		            res->next = sort_list; // Chèn phần tử hiện tại vào đầu danh sách đã sắp xếp
		            sort_list = res;
		        } else {
		            node temp = sort_list;
		            // Tìm vị trí để chèn phần tử hiện tại vào danh sách đã sắp xếp
		            while (temp->next != nullptr && temp->next != sort_list && temp->next->s.diem < res->s.diem) {
		                temp = temp->next;
		            }
		            res->next = temp->next; // Chèn phần tử hiện tại vào vị trí tìm được
		            temp->next = res;
		        }
		        res = nextNode; // Chuyển sang phần tử kế tiếp trong danh sách chưa sắp xếp
		    } while (res != head);
			node last = sort_list;
		    while (last->next != nullptr && last->next != sort_list) {
		        last = last->next;
		    }
		
		    // Kết nối phần tử cuối với head ban đầu
		    last->next = sort_list;
		    head = sort_list; // Cập nhật head của danh sách thành danh sách đã sắp xếp
		}
	}
}

//selection_sort	
void selection_sort(vector<Sinhvien> &ds, node &head, int lc2, int lc){
	if(lc2 == 1){
		if(lc == 1){
			int n = ds.size();
			for(int i = 0; i < n; i++){
				int min_idx = i;
				for(int j = i + 1; j < n; j++){
					if(ds[j].ms < ds[min_idx].ms){
						min_idx = j;
					}
				}
				swap(ds[min_idx], ds[i]);
			}
		}
		else if(lc == 2){
			int n = ds.size();
			for(int i = 0; i < n; i++){
				int min_idx = i;
				for(int j = i + 1; j < n; j++){
					if(ds[j].ten < ds[min_idx].ten){
						min_idx = j;
					}
				}
				swap(ds[min_idx], ds[i]);
			}
		}
		else if(lc == 3){
			int n = ds.size();
			for(int i = 0; i < n; i++){
				int min_idx = i;
				for(int j = i + 1; j < n; j++){
					if(ds[j].diem < ds[min_idx].diem){
						min_idx = j;
					}
				}
				swap(ds[min_idx], ds[i]);
			}
		}
	}
	else if(lc2 == 2 || lc2 == 3){
		if(lc == 1){
			for(node i = head; i->next != NULL; i = i-> next){
				node min_indx = i;
				for(node j = i->next; j != NULL; j = j->next){
					if(j->s.ms < min_indx->s.ms){
						min_indx = j;
					}
				}
				swap(min_indx->s, i->s);
			}
		}
		else if(lc == 2){
			for(node i = head; i->next != NULL; i = i-> next){
				node min_indx = i;
				for(node j = i->next; j != NULL; j = j->next){
					if(j->s.ten < min_indx->s.ten){
						min_indx = j;
					}
				}
				swap(min_indx->s, i->s);
			}
		}
		else if(lc == 3){
			for(node i = head; i->next != NULL; i = i-> next){
				node min_indx = i;
				for(node j = i->next; j != NULL; j = j->next){
					if(j->s.diem < min_indx->s.diem){
						min_indx = j;
					}
				}
				swap(min_indx->s, i->s);
			}
		}
	}
	else if(lc2 == 4){
		if (lc == 1){
			if (head == nullptr || head->next == head) {
	       		return; // Danh sách rỗng hoặc chỉ có một phần tử
		    }
		    node current = head;
		    node last_node = head;
		    do{
		    	last_node = last_node->next;
			}while(last_node != head);
		    do {
		        node minNode = current;
		        node temp = current->next;
		        do {
		            if (temp->s.ms < minNode->s.ms) {
		                minNode = temp;
		            }
		            temp = temp->next;
		        } while (temp != head && temp != current->next);
		        swap(current->s, minNode->s);
		        current = current->next;
		    } while (current != last_node && current->next != last_node);
		}
		else if(lc == 2){
			if (head == nullptr || head->next == head) {
		        return; // Danh sách rỗng hoặc chỉ có một phần tử
		    }
		    node current = head;
		    node last_node = head;
		    do{
		    	last_node = last_node->next;
			}while(last_node != head);
		    do {
		        node minNode = current;
		        node temp = current->next;
		        do {
		            if (temp->s.ten < minNode->s.ten) {
		                minNode = temp;
		            }
		            temp = temp->next;
		        } while (temp != head && temp != current->next);
		        
		        swap(current->s, minNode->s);
		        current = current->next;
		    } while (current != last_node && current->next != last_node);
		}
		else if(lc == 3){
			if (head == nullptr || head->next == head) {
		        return; // Danh sách rỗng hoặc chỉ có một phần tử
		    }
		    node current = head;
		    node last_node = head;
		    do{
		    	last_node = last_node->next;
			}while(last_node != head);
		    do {
		        node minNode = current;
		        node temp = current->next;
		        do {
		            if (temp->s.diem < minNode->s.diem) {
		                minNode = temp;
		            }
		            temp = temp->next;
		        } while (temp != head && temp != current->next);
		        
		        swap(current->s, minNode->s);
		        current = current->next;
		    } while (current != last_node && current->next != last_node);
		}
	}
}

//quick_sort
//start merge_sort
int partition(vector<Sinhvien> &ds,int low, int high,int lc){
		int res;
		if(lc == 1){
			string pivot = ds[(low + high)/2].ms;
			int i = low;
			int j = high;
			while(i <= j){
				while(ds[i].ms  < pivot) i++;
				while(ds[j].ms > pivot) j--;
				if(i <= j){
					swap(ds[i], ds[j]);
					i++;
					j--;
				}
			}
			res = i;
		}
		else if(lc == 2){
			string pivot = ds[(low + high)/2].ten;
			int i = low;
			int j = high;
			while(i <= j){
				while(ds[i].ten < pivot) i++;
				while(ds[j].ten > pivot) j--;
				if(i <= j){
					swap(ds[i], ds[j]);
					i++;
					j--;
				}
			}
			res = i;	
		}
		else if(lc == 3){
			float pivot = ds[(low + high)/2].diem;
			int i = low;
			int j = high;
			while(i <= j){
				while(ds[i].diem  < pivot) i++;
				while(ds[j].diem > pivot) j--;
				if(i <= j){
					swap(ds[i], ds[j]);
					i++;
					j--;
				}
			}
			res = i;
		}
		return res;
}

void merge(vector<Sinhvien>& ds, int l, int m, int r, int lc) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Sinhvien> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = ds[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = ds[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    if(lc == 1){
	    while (i < n1 && j < n2) {
	        if (L[i].ms <= R[j].ms) {
	            ds[k] = L[i];
	            i++;
	        } else {
	            ds[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	
	    while (i < n1) {
	        ds[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2) {
	        ds[k] = R[j];
	        j++;
	        k++;
	    }
	}
	else if(lc == 2){
		 while (i < n1 && j < n2) {
	        if (L[i].ten <= R[j].ten) {
	            ds[k] = L[i];
	            i++;
	        } else {
	        	ds[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	
	    while (i < n1) {
	        ds[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2) {
	        ds[k] = R[j];
	        j++;
	        k++;
	    }	
	}
	else if(lc == 3){
		 while (i < n1 && j < n2) {
	        if (L[i].diem <= R[j].diem) {
	            ds[k] = L[i];
	            i++;
	        } else {
	            ds[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	
	    while (i < n1) {
	        ds[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2) {
	        ds[k] = R[j];
	        j++;
	        k++;
	    }
	}
}

void mergeSort(vector<Sinhvien>& ds, int l, int r, int lc) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    if(lc == 1){
	    mergeSort(ds, l, m,1);
	    mergeSort(ds, m + 1, r,1);
	    merge(ds, l, m, r,1);
	}
	else if(lc == 2){
		mergeSort(ds, l, m,2);
	    mergeSort(ds, m + 1, r,2);
	    merge(ds, l, m, r,2);
	}
	else if(lc == 3){
		mergeSort(ds, l, m,3);
	    mergeSort(ds, m + 1, r,3);
	    merge(ds, l, m, r,3);
	}
}

void partition4(node &head, node left, node right, int lc){
		if(lc == 1){
			node merge_list = NULL; // Danh sách hợp nhất
		    node res = NULL; // Con trỏ đến cuối danh sách hợp nhất
		
		    // Trong khi cả hai mảng con vẫn chưa hết
		    while (left != NULL && right != NULL) {
		        // So sánh mã số sinh viên của hai phần tử
		        if (left->s.ms <= right->s.ms) {
		            if (merge_list == NULL) {
		                merge_list = left;
		                res = left;
		            } else {
		                res->next = left;
		                res = left;
		            }
		            left = left->next;
		        } else {
		            if (merge_list == NULL) {
		                merge_list = right;
		                res = right;
		            } else {
		                res->next = right;
		                res = right;
		            }
		            right = right->next;
		        }
		    }
		
		    // Nếu một trong hai mảng con đã hết, chỉ cần nối danh sách hợp nhất với mảng còn lại
		    if (left != NULL) {
		        res->next = left;
		    }
		    if (right != NULL) {
		        res->next = right;
		    }
		
		    // Cập nhật head của danh sách
		    head = merge_list;
		    res->next = right;
		}
		else if(lc == 2){
			node merge_list = NULL; // Danh sách hợp nhất
		    node res = NULL; // Con trỏ đến cuối danh sách hợp nhất
		
		    // Trong khi cả hai mảng con vẫn chưa hết
		    while (left != NULL && right != NULL) {
		        // So sánh mã số sinh viên của hai phần tử
		        if (left->s.ten <= right->s.ten) {
		            if (merge_list == NULL) {
		                merge_list = left;
		                res = left;
		            } else {
		                res->next = left;
		                res = left;
		            }
		            left = left->next;
		        } else {
		            if (merge_list == NULL) {
		                merge_list = right;
		                res = right;
		            } else {
		                res->next = right;
		                res = right;
		            }
		            right = right->next;
		        }
		    }
		
		    // Nếu một trong hai mảng con đã hết, chỉ cần nối danh sách hợp nhất với mảng còn lại
		    if (left != NULL) {
		        res->next = left;
		    }
		    if (right != NULL) {
		        res->next = right;
		    }
		
		    // Cập nhật head của danh sách
		    head = merge_list;
		    res->next = right;
		}
		else if(lc == 3){
			node merge_list = NULL; // Danh sách hợp nhất
		    node res = NULL; // Con trỏ đến cuối danh sách hợp nhất
		
		    // Trong khi cả hai mảng con vẫn chưa hết
		    while (left != NULL && right != NULL) {
		        // So sánh mã số sinh viên của hai phần tử
		        if (left->s.diem <= right->s.diem) {
		            if (merge_list == NULL) {
		                merge_list = left;
		                res = left;
		            } else {
		                res->next = left;
		                res = left;
		            }
		            left = left->next;
		        } else {
		            if (merge_list == NULL) {
		                merge_list = right;
		                res = right;
		            } else {
		                res->next = right;
		                res = right;
		            }
		            right = right->next;
		        }
		    }
		
		    // Nếu một trong hai mảng con đã hết, chỉ cần nối danh sách hợp nhất với mảng còn lại
		    if (left != NULL) {
		        res->next = left;
		    }
		    if (right != NULL) {
		        res->next = right;
		    }
		
		    // Cập nhật head của danh sách
		    head = merge_list;
		    res->next = right;
		}
		
}
void partition2(node &head, node left, node right, int lc){
		if(lc == 1){
			node merge_list = NULL; // Danh sách hợp nhất
		    node res = NULL; // Con trỏ đến cuối danh sách hợp nhất
		
		    // Trong khi cả hai mảng con vẫn chưa hết
		    while (left != NULL && right != NULL) {
		        // So sánh mã số sinh viên của hai phần tử
		        if (left->s.ms <= right->s.ms) {
		            if (merge_list == NULL) {
		                merge_list = left;
		                res = left;
		            } else {
		                res->next = left;
		                res = left;
		            }
		            left = left->next;
		        } else {
		            if (merge_list == NULL) {
		                merge_list = right;
		                res = right;
		            } else {
		                res->next = right;
		                res = right;
		            }
		            right = right->next;
		        }
		    }
		
		    // Nếu một trong hai mảng con đã hết, chỉ cần nối danh sách hợp nhất với mảng còn lại
		    if (left != NULL) {
		        res->next = left;
		    }
		    if (right != NULL) {
		        res->next = right;
		    }
		
		    // Cập nhật head của danh sách
		    head = merge_list;
		    
		}
		else if(lc == 2){
			node merge_list = NULL; // Danh sách hợp nhất
		    node res = NULL; // Con trỏ đến cuối danh sách hợp nhất
		
		    // Trong khi cả hai mảng con vẫn chưa hết
		    while (left != NULL && right != NULL) {
		        // So sánh mã số sinh viên của hai phần tử
		        if (left->s.ten <= right->s.ten) {
		            if (merge_list == NULL) {
		                merge_list = left;
		                res = left;
		            } else {
		                res->next = left;
		                res = left;
		            }
		            left = left->next;
		        } else {
		            if (merge_list == NULL) {
		                merge_list = right;
		                res = right;
		            } else {
		                res->next = right;
		                res = right;
		            }
		            right = right->next;
		        }
		    }
		
		    // Nếu một trong hai mảng con đã hết, chỉ cần nối danh sách hợp nhất với mảng còn lại
		    if (left != NULL) {
		        res->next = left;
		    }
		    if (right != NULL) {
		        res->next = right;
		    }
		
		    // Cập nhật head của danh sách
		    head = merge_list;
		}
		else if(lc == 3){
			node merge_list = NULL; // Danh sách hợp nhất
		    node res = NULL; // Con trỏ đến cuối danh sách hợp nhất
		
		    // Trong khi cả hai mảng con vẫn chưa hết
		    while (left != NULL && right != NULL) {
		        // So sánh mã số sinh viên của hai phần tử
		        if (left->s.diem <= right->s.diem) {
		            if (merge_list == NULL) {
		                merge_list = left;
		                res = left;
		            } else {
		                res->next = left;
		                res = left;
		            }
		            left = left->next;
		        } else {
		            if (merge_list == NULL) {
		                merge_list = right;
		                res = right;
		            } else {
		                res->next = right;
		                res = right;
		            }
		            right = right->next;
		        }
		    }
		
		    // Nếu một trong hai mảng con đã hết, chỉ cần nối danh sách hợp nhất với mảng còn lại
		    if (left != NULL) {
		        res->next = left;
		    }
		    if (right != NULL) {
		        res->next = right;
		    }
		
		    // Cập nhật head của danh sách
		    head = merge_list;
		}
}
void merge1(node head, node &left, node &right){
	
	if (head == NULL || head->next == NULL) {
        left = head;
        right = NULL;
    } else {
        node slow = head; // Con trỏ chạy chậm
        node fast = head->next; // Con trỏ chạy nhanh

        // Fast chạy hai bước, slow chạy một bước, để fast đến cuối danh sách thì slow đến giữa
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        left = head; // left là phần đầu của danh sách
        right = slow->next; // right là phần sau của danh sách

        // Tách danh sách thành hai
        slow->next = NULL;
    }
}
void merge2(node head, node &left, node &right){
	
	if (head == NULL || head->next == NULL) {
        left = head;
        right = NULL;
    } else {
        node slow = head; // Con trỏ chạy chậm
        node fast = head->next; // Con trỏ chạy nhanh

        // Fast chạy hai bước, slow chạy một bước, để fast đến cuối danh sách thì slow đến giữa
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        left = head; // left là phần đầu của danh sách
        right = slow->next; // right là phần sau của danh sách

        // Tách danh sách thành hai
        slow->next = NULL;
        right = head;
    }
}
void mergeSort1(node &head, int lc){
	if (head == NULL || head->next == NULL) {
        return; // Danh sách rỗng hoặc chỉ có một phần tử, không cần sắp xếp
    }

    // Chia danh sách thành hai mảng con
    node left, right;
    merge1(head, left, right);

    // Đệ quy sắp xếp hai mảng con
    mergeSort1(left,lc);
    mergeSort1(right, lc);

    // Hợp nhất hai mảng con đã sắp xếp
    partition2(head, left, right, lc);
}
void mergeSort2(node &head, int lc){
	if (head == NULL || head->next == NULL) {
        return; // Danh sách rỗng hoặc chỉ có một phần tử, không cần sắp xếp
    }

    // Chia danh sách thành hai mảng con
    node left, right;
    merge1(head, left, right);

    // Đệ quy sắp xếp hai mảng con
    mergeSort1(left,lc);
    mergeSort1(right, lc);

    // Hợp nhất hai mảng con đã sắp xếp
    partition4(head, left, right, lc);
    node last = head;
    while(last->next != NULL){
    	last = last->next;
	}
	last->next = head;
}
// end merge_sort

void quick_sort(vector<Sinhvien> &ds, int low, int high, int lc){
	if(lc == 1){
		if(low < high){
			int pi = partition(ds,low, high, 1);
			quick_sort(ds,low, pi-1, 1);
			quick_sort(ds,pi, high, 1);
		}
	}
	else if(lc == 2){
		if(low < high){
			int pi = partition(ds,low, high, 2);
			quick_sort(ds,low, pi-1, 2);
			quick_sort(ds,pi, high, 2);
		}
	}
	else if(lc == 3){
		if(low < high){
			int pi = partition(ds,low, high, 3);
			quick_sort(ds,low, pi-1, 3);
			quick_sort(ds,pi, high, 3);
		}
	}
}

void quick_sort_by_option(vector<Sinhvien> &ds, int lc){
	if(lc == 1){
		quick_sort(ds, 0, ds.size() - 1, 1);
	}
	else if(lc == 2){
		quick_sort(ds, 0, ds.size() - 1, 2);
	}
	else if(lc == 3){
		quick_sort(ds, 0, ds.size() - 1, 3);
	}
}

node layend(node head){
		node tmp = head;
		while(tmp != NULL && tmp->next != NULL){
			tmp = tmp->next;
		}
		return tmp;
}
node partition2(node head, node end, node &newhead, node &newend, int lc){
	node res;
	if(lc == 1){	
		node pivot = end;
		node pro = NULL;
		node tmp = head;
		node tail = pivot;
		while(tmp != pivot){
			if(tmp->s.ms < pivot->s.ms){
				if(newhead == NULL) newhead = tmp;
				pro = tmp;
				tmp = tmp->next;
			}
			else{
				if(pro) pro->next = tmp->next;
				node temp = tmp->next;
				tmp->next = NULL;
				tail->next = tmp;
				tail = tmp;
				tmp = temp; 
			}
		}
		if(newhead == NULL) newhead = pivot;
		newend = tail;
		res = pivot;
	}
	else if(lc == 2){
		node pivot = end;
		node pro = NULL;
		node tmp = head;
		node tail = pivot;
		while(tmp != pivot){
			if(tmp->s.ten < pivot->s.ten){
				if(newhead == NULL) newhead = tmp;
				pro = tmp;
				tmp = tmp->next;
			}
			else{
				if(pro != NULL) pro->next = tmp->next;
				node temp = tmp->next;
				tmp->next = NULL;
				tail->next = tmp;
				tail = tmp;
				tmp = temp; 
			}
		}
		if(newhead == NULL) newhead = pivot;
		newend = tail;
		res = pivot;
	}
	else if(lc == 3){
		node pivot = end;
		node pro = NULL;
		node tmp = head;
		node tail = pivot;
		while(tmp != pivot){
			if(tmp->s.diem < pivot->s.diem){
				if(newhead == NULL) newhead = tmp;
				pro = tmp;
				tmp = tmp->next;
			}
			else{
				if(pro != NULL) pro->next = tmp->next;
				node temp = tmp->next;
				tmp->next = NULL;
				tail->next = tmp;
				tail = tmp;
				tmp = temp; 
			}
		}
		if(newhead == NULL) newhead = pivot;
		newend = tail;
		res = pivot;
	}
	return res;
}

node quicksortRec(node head, node end, int lc){	
		if(!head || head == end) return head;
		node newhead = NULL;
		node newend = NULL;
		node pivot = partition2(head, end, newhead,newend, lc);
		if(newhead != pivot){
			node tmp = newhead;
			while(tmp->next != pivot){
				tmp = tmp->next;
			}
			tmp->next = NULL;
			newhead = quicksortRec(newhead, tmp,lc);
			tmp = layend(newhead);
			tmp->next = pivot;
		}
		pivot->next = quicksortRec(pivot->next, newend, lc);
		return newhead;
}
void quickSort(node &head, int lc){
	head = quicksortRec(head, layend(head), lc);
}

// end quick sort
void chuyendoi(vector<Sinhvien> &ds, node head, int lc){
	if(lc == 1){
		int n = count(head,2);
		ds.resize(n);
		node tmp = head;
		int indx = 0;
		while(tmp != NULL){
			ds[indx] = tmp->s;
			tmp = tmp->next;
			indx++;
		}
	}
	else if(lc == 2){
		int n = count(head, 3);
		ds.resize(n);
		node tmp = head;
		int indx = 0;
		bool check = true;
		do {
		    ds[indx] = tmp->s;
		    tmp = tmp->next;
		    indx++;
		
		    // Kiểm tra xem đã quay lại nút đầu tiên hay chưa
		    if (tmp == head && !check) {
		        break; // Đã duyệt qua một vòng đầy đủ
		    }
		    check = false; // Sau lần lặp đầu tiên, không phải là lần lặp đầu tiên nữa
		} while (tmp != head);			
	}
	
}

void heapify(vector<Sinhvien>& ds, int n, int i, int lc) {
	if(lc == 1){
	    int largest = i;
	    int l = 2 * i + 1;
	    int r = 2 * i + 2;
	    if (l < n && ds[l].ms > ds[largest].ms)
	        largest = l;
	
	    if (r < n && ds[r].ms > ds[largest].ms)
	        largest = r;
	
	    if (largest != i) {
	        swap(ds[i], ds[largest]);
	        heapify(ds, n, largest, lc);
	    }
	}
	else if(lc == 2){
		int largest = i;
    	int l = 2 * i + 1;
    	int r = 2 * i + 2;
    	if (l < n && ds[l].ten > ds[largest].ten)
        	largest = l;
	
   		if (r < n && ds[r].ten > ds[largest].ten)
        	largest = r;

    	if (largest != i) {
      		swap(ds[i], ds[largest]);
        	heapify(ds, n, largest,lc);
    	}
	}
	else if(lc == 3){
		int largest = i;
    	int l = 2 * i + 1;
    	int r = 2 * i + 2;
    	if (l < n && ds[l].diem > ds[largest].diem)
        	largest = l;
	
   		if (r < n && ds[r].diem > ds[largest].diem)
        	largest = r;

    	if (largest != i) {
      		swap(ds[i], ds[largest]);
        	heapify(ds, n, largest,lc);
    	}
	}
}

void heapSort(vector<Sinhvien>& ds, int lc){
    int n = ds.size();
	if(lc == 1){	
	    for (int i = n / 2 - 1; i >= 0; i--)
	        heapify(ds, n, i,lc);
	
	    for (int i = n - 1; i > 0; i--) {
	        swap(ds[0], ds[i]);
	        heapify(ds, i, 0,lc);
	    }
	}
	else if(lc == 2){
		 for (int i = n / 2 - 1; i >= 0; i--)
	        heapify(ds, n, i,lc);
	
	    for (int i = n - 1; i > 0; i--) {
	        swap(ds[0], ds[i]);
	        heapify(ds, i, 0,lc);
	    }
	}
	else if(lc == 3){
		 for (int i = n / 2 - 1; i >= 0; i--)
	        heapify(ds, n, i,lc);
	
	    for (int i = n - 1; i > 0; i--){
	        swap(ds[0], ds[i]); 
	        heapify(ds, i, 0,lc);
	    }
	}
}

void deleteList(node head,int lc){
	if(lc == 1){
		while(head != NULL){
			node tmp= head;
			head = head->next;
			delete tmp;
		}
	}
	else if(lc == 2){
		 if (head == NULL) return; // Nếu danh sách rỗng, thoát ra

    	node current = head;
    	node nextNode;

   		 // Lặp qua từng node trong danh sách và xóa nó
    	do {
        	nextNode = current->next;
       		delete current;
        	current = nextNode;
    	} while (current != head);

    	head = NULL; // Đặt head thành NULL sau khi xóa tất cả các node
	}
}

void menu1(){
	cout << " ----------------------------------------------------------------" << endl;
	cout << "|                               MENU                             |" << endl;
	cout << "|----------------------------------------------------------------|" << endl;
	cout << "|    Phim lua chon   |                 Chuc Nang                 |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         1          |   Tim kiem sinh vien theo ma sinh vien    |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         2          |   Tim kiem sinh vien theo ho sinh vien    |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         3          |  Tim kiem sinh vien theo ten sinh vien    |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         4          |  Tim kiem sinh vien theo lop sinh vien    |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         5          |  Tim kiem sinh vien theo diem sinh vien   |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         6          |               Them sinh vien              |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         7          |       Xoa sinh vien theo Ma sinh vien     |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         8          |             Liet ke theo yeu cau          |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         9          |             Sap xep sinh vien.            |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|        10          |              Duyet danh sach              |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         0          |               Thoat yeu cau               |" << endl;
	cout << " ---------------------------------------------------------------- " << endl;
}

void menu_lua_chon(){	
	cout << " ---------------------------------------------------------------- " << endl;
	cout << "|                            MENU                                |" << endl;
	cout << "|----------------------------------------------------------------|" << endl;
	cout << "|    Phim lua chon   |                Chuc Nang                  |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         1          |       Sap xep tang dan bang HEAP_SORT     |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         2          |     Sap xep tang dan bang MERGE_SORT      |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         3          |     Sap xep tang dan bang BUBBLE_SORT     |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         4          |    Sap xep tang dan bang INSERTION_SORT   |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         5          |     Sap xep tang dan bang QUICK_SORT      |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         6          |    Sap xep tang dan bang SELECTION_SORT   |" << endl;
	cout << "|--------------------|-------------------------------------------|" << endl;
	cout << "|         0          |            Thoat yeu cau                  |" << endl;
	cout << " ---------------------------------------------------------------- " << endl;
}

void menu_sort(){
	cout << " ---------------------------------------------------------" << endl;
	cout << "|                           MENU                          |" << endl;
	cout << "|---------------------------------------------------------|" << endl;
	cout << "|    Phim lua chon   |            Chuc nang               |" << endl;
	cout << "|--------------------|------------------------------------|" << endl;
	cout << "|          1         |      Sap xep theo Ma sinh vien     |" << endl;
	cout << "|--------------------|------------------------------------|" << endl;
	cout << "|          2         |     Sap xep theo Ten sinh vien     |" << endl;
	cout << "|--------------------|------------------------------------|" << endl;
	cout << "|          3         |     Sap xep theo Diem sinh vien    |" << endl;
	cout << "|--------------------|------------------------------------|" << endl;
	cout << "|          0         |          Thoat yeu cau             |" << endl;
	cout << " --------------------------------------------------------- " << endl; 
}

void menu_liet_ke(){
	cout << " ------------------------------------------------------------" << endl;
	cout << "|                            MENU                            |" << endl;
	cout << "|------------------------------------------------------------|" << endl;
	cout << "|   Phim lua chon   |            Chuc nang                   |" << endl;
	cout << "|-------------------|----------------------------------------|" << endl;
	cout << "|          1        |   Liet ke sinh vien co diem thap nhat  |" << endl;
	cout << "|-------------------|----------------------------------------|" << endl;
	cout << "|          2        |   Liet ke sinh vien co diem thap nhat  |" << endl;
	cout << "|-------------------|----------------------------------------|" << endl;
	cout << "|          3        |         Diem trung binh cua lop        |" << endl;
	cout << "|-------------------|----------------------------------------|" << endl;
	cout << "|          0        |           Thoat yeu cau                |" << endl;
	cout << " ------------------------------------------------------------ " << endl;
}

int main()
{
    while(1){
    	system("cls");
    	cout << " --------------------------------------------------------- " << endl;
		cout << "|                           MENU                          |" << endl;
		cout << "|---------------------------------------------------------|" << endl;
		cout << "|   Phim lua chon  |             Chuc nang                |" << endl;
		cout << "|------------------|--------------------------------------|" << endl;
		cout << "|         1        |       Luu danh sach bang mang        |" << endl;
	    cout << "|------------------|--------------------------------------|" << endl;
	    cout << "|         2        |    Luu danh sach bang lien ket don   |" << endl;
	    cout << "|------------------|--------------------------------------|" << endl;
	    cout << "|         3        |    Luu danh sach bang lien ket kep   |" << endl;
	    cout << "|------------------|--------------------------------------|" << endl;
	    cout << "|         4        |   Luu danh sach bang lien ket vong   |" << endl;
	    cout << "|------------------|--------------------------------------|" << endl;
		cout << "|         0        |         Thoat Chuong trinh           |" << endl;
	    cout << " --------------------------------------------------------- " << endl;
    	int lc1;
    	cout << "Nhap lua chon (nhap so): ";
    	cin >> lc1;
    	cin.ignore();
    	vector<Sinhvien> ds;
    	node head = NULL;
    	string output = "";
    	if(lc1 == 1){
    		system("cls");
		    ifstream fin("input.csv");
    		if(fin.fail()){
	    		output = "Loi khong mo duoc file";
	    		break;
			}	
			output = Doc_danh_sach(fin, ds, head, lc1);
    		while(1){
    			system("cls");
    			cout << "\033[1;31m" << output;
				cout << "\033[0m";
    			menu1();
		    	int lc2;
		    	cout << "Nhap lua chon cua ban (nhap so): ";
		    	cin >> lc2;
				cin.ignore();
				if(lc2 == 1){
					system("cls");
					output = tkMS(ds,head,lc1);
				}
				else if(lc2 == 2){
					system("cls");
					output = tkHo(ds, head, lc1);
				}
				else if(lc2 == 3){
					system("cls");
					output = tkTen(ds, head, lc1);
				}
				else if(lc2 == 4){
					system("cls");
					output = tkLop(ds, head, lc1);
				}
				else if(lc2 == 5){
					system("cls");
					output = tkDiem(ds, head, lc1);
				}
				else if(lc2 == 6){
					system("cls");
					output = check_nhap(ds,head,lc1);
				}
				else if(lc2 == 7){
					system("cls");
					output = xoa_sinh_vien(ds,head, lc1);
				}
				else if(lc2 == 8){
					output = "";
					while(1){
						system("cls");
						cout << "\033[1;31m" << output;
						cout << "\033[0m";
						menu_liet_ke();
						int lc3;
						cout << "Nhap lua chon cua ban(nhap so): "; cin >> lc3;
						if(lc3 == 1){
							system("cls");
							output = diem_thap(ds, head, lc1);
						}
						else if(lc3 == 2){
							system("cls");
							output = diem_cao(ds, head, lc1);
						}
						else if(lc3 == 3){
							system("cls");
							output =  "Diem Trung binh cua lop la: " + to_string(trung_binh(ds, head,lc1)) + "\n";
						}
						else if(lc3 == 0){
							system("cls");
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 9){
					while(1){
						system("cls");
						menu_lua_chon();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon: "; cin >> lc4;
								int n = ds.size();
								if(lc4 == 0){
									output = "";
									break;
								}
								if(lc4 == 1 || lc4 == 2 || lc4 == 3){
									system("cls");	
									heapSort(ds,lc4);
									output = XUAT(ds, head, lc1);
								}
							}
						}
						else if(lc3 == 2){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								int n = ds.size();
								if(lc4 == 0){
									output = "";
									break;
								}
								if(lc4 == 1 || lc4 == 2 || lc4 == 3){	
									mergeSort(ds,0, n - 1, lc4);
									output = XUAT(ds, head, lc1);
								}
							}
						}
						else if(lc3 == 3){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									break;
								}
								if(lc4 == 1|| lc4 == 2 || lc4 == 3){	
									bubble_sort(ds,head, lc1, lc4);
									output = XUAT(ds, head, lc1);
								}
							}
						}
						else if(lc3 == 4){
							while(1){	
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								if(lc4 == 1 || lc4 == 2 || lc4 == 3){	
									insertion_sort(ds,head,lc1, lc4);
									output = XUAT(ds, head, lc1);
								}
							}
						}
						else if(lc3 == 5){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								
									quick_sort_by_option(ds,lc4);
									output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 6){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								selection_sort(ds,head,lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 0){
							break;
						}
					}
				}
				else if(lc2 == 10){
					output = XUAT(ds, head, lc1);
				}
				else if(lc2 == 0){
					ds.clear();
					fin.close();
					break;
				}
			}
		}
		else if(lc1 == 2){
			system("cls");
		 	ifstream fin("input.csv");	
			if(fin.fail()){
		    	cout << "Loi khong mo duoc file" << endl;
		    	break;	
			}
			output = Doc_danh_sach(fin, ds, head, lc1);
    		while(1){
    			system("cls");
				cout << "\033[1;31m" << output;
				cout << "\033[0m";
    			menu1();
		    	int lc2;
		    	cout << "Nhap lua chon cua ban (nhap so): ";
		    	cin >> lc2;
				cin.ignore();
				if(lc2 == 1){
					system("cls");
					output = tkMS(ds,head,lc1);
				}
				else if(lc2 == 2){
					system("cls");
					output = tkHo(ds, head, lc1);
				}
				else if(lc2 == 3){
					system("cls");
					output = tkTen(ds, head, lc1);
				}
				else if(lc2 == 4){
					system("cls");
					output = tkLop(ds, head, lc1);
				}
				else if(lc2 == 5){
					system("cls");
					output = tkDiem(ds, head, lc1);
				}
				else if(lc2 == 6){
					system("cls");
					output = check_nhap(ds,head,lc1);
				}
				else if(lc2 == 7){
					system("cls");
					output = xoa_sinh_vien(ds, head, lc1);
				}
				else if(lc2 == 8){
					while(1){
						system("cls");
						cout << "\033[1;31m" << output;
						cout << "\033[0m";
						menu_liet_ke();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							system("cls");
							output = diem_thap(ds, head, lc1);
						}
						else if(lc3 == 2){
							system("cls");
							output = diem_cao(ds, head, lc1);
						}
						else if(lc3 == 3){
							system("cls");
							output =  "Diem Trung binh cua lop la: " +  chuyen(trung_binh(ds, head, lc1)) + "\n";
						}
						else if(lc3 == 0){
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 9){
					while(1){
						system("cls");
						menu_lua_chon();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon(Nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								chuyendoi(ds, head,1);
								heapSort(ds, lc4);
								output = XUAT(ds, head, 1);
							}
						}
						else if(lc3 == 2){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								int n = ds.size();
								if(lc4 == 0){
									output = "";
									break;
								}
								mergeSort1(head, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 3){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								bubble_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 4){
							while(1){	
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								insertion_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 5){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								quickSort(head, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 6){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								selection_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 0){
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 10){
					system("cls");
					output = XUAT(ds,head,lc1);
				}
				
				else if(lc2 == 0){
					fin.close();
					deleteList(head,1);
					break;
				}
			}
		}
		else if(lc1 == 3){
			system("cls");
		    	ifstream fin("input.csv");
		    		if(fin.fail()){
		    			output = "Loi khong mo duoc file.\n";
		    			break;
					}
					output = Doc_danh_sach(fin, ds, head, lc1);
    		while(1){
    			system("cls");
				cout << "\033[1;31m" << output;
				cout << "\033[0m";
    			menu1();
		    	int lc2;
		    	cout << "Nhap lua chon cua ban (nhap so):";
		    	cin >> lc2;
				cin.ignore();
				if(lc2 == 1){
					system("cls");
					output = tkMS(ds,head,lc1);
				}
				else if(lc2 == 2){
					system("cls");
					output = tkHo(ds, head, lc1);
				}
				else if(lc2 == 3){
					system("cls");
					output = tkTen(ds, head, lc1);
				}
				else if(lc2 == 4){
					system("cls");
					output = tkLop(ds, head, lc1);
				}
				else if(lc2 == 5){
					system("cls");
					output = tkDiem(ds, head, lc1);
				}
				else if(lc2 == 6){
					system("cls");
					output = check_nhap(ds,head,lc1);
				}
				else if(lc2 == 7){
					system("cls");
					output = xoa_sinh_vien(ds, head, lc1);
				}
				else if(lc2 == 8){
					output = "";
					while(1){
						system("cls");
						cout << "\033[1;31m" << output;
						cout << "\033[0m";
						menu_liet_ke();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							system("cls");
							output = diem_thap(ds, head, lc1);
						}
						else if(lc3 == 2){
							output = diem_cao(ds, head, lc1);
						}
						else if(lc3 == 3){
							output =  "Diem Trung binh cua lop la: " +  chuyen(trung_binh(ds, head, lc1)) + "\n";
						}
						else if(lc3 == 0){
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 9){
					while(1){
						system("cls");
						menu_lua_chon();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								chuyendoi(ds, head,1);
								heapSort(ds, lc4);
								output = XUAT(ds, head, 1);
							}
						}
						else if(lc3 == 2){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								int n = ds.size();
								if(lc4 == 0){
									output = "";
									break;
								}
								mergeSort1(head, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 3){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								bubble_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 4){
							while(1){	
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								insertion_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 5){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								quickSort(head, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 6){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								selection_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 0){
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 10){
					system("cls");
					output = XUAT(ds,head,lc1);
				}
				
				else if(lc2 == 0){
					fin.close();
					deleteList(head,1);
					break;
				}
			}
		}
		else if(lc1 == 4){
			system("cls");
			ifstream fin("input.csv");
		    if(fin.fail()){
		    	output =  "Loi khong mo duoc file.\n";
		   		break;
			}
			output = Doc_danh_sach(fin, ds, head, lc1);
    		while(1){
    			system("cls");
				cout << "\033[1;31m" << output;
				cout << "\033[0m";
    			menu1();
		    	int lc2;
		    	cout << "Nhap lua chon cua ban (nhap so):";
		    	cin >> lc2;
				cin.ignore();
				if(lc2 == 1){
					system("cls");
					output = tkMS(ds,head,lc1);
				}
				else if(lc2 == 2){
					system("cls");
					output = tkHo(ds, head, lc1);
				}
				else if(lc2 == 3){
					system("cls");
					output = tkTen(ds, head, lc1);
				}
				else if(lc2 == 4){
					system("cls");
					output = tkLop(ds, head, lc1);
				}
				else if(lc2 == 5){
					system("cls");
					output = tkDiem(ds, head, lc1);
				}
				else if(lc2 == 6){
					system("cls");
					output = check_nhap(ds,head,lc1);
				}
				else if(lc2 == 7){
					system("cls");
					output = xoa_sinh_vien(ds, head, lc1);
				}
				else if(lc2 == 8){
					output = "";
					while(1){
						system("cls");
						cout << "\033[1;31m" << output;
						cout << "\033[0m";
						menu_liet_ke();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							system("cls");
							output = diem_thap(ds, head, lc1);
						}
						else if(lc3 == 2){
							system("cls");
							output = diem_cao(ds, head, lc1);
						}
						else if(lc3 == 3){
							system("cls");
							output =  "Diem Trung binh cua lop la: " +  chuyen(trung_binh(ds, head, lc1)) + "\n";
						}
						else if(lc3 == 0){
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 9){
					output = "";
					while(1){
						ds.clear();
						system("cls");
						menu_lua_chon();
						int lc3;
						cout << "Nhap lua chon cua ban (nhap so): "; cin >> lc3;
						if(lc3 == 1){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								chuyendoi(ds, head,2);
								heapSort(ds, lc4);
								output = XUAT(ds, head, 1);
							}
						}
						else if(lc3 == 2){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon (nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								chuyendoi(ds,head, 2);
								int n = ds.size();
								mergeSort(ds,0, n - 1, lc4);
								output = XUAT(ds, head, 1);
								
							}
						}
						else if(lc3 == 3){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon(Nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								bubble_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 4){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";	
								menu_sort();
								int lc4;
								cout << "Nhap lua chon(Nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								insertion_sort(ds,head, lc1, lc4);
								output = XUAT(ds,head,lc1);
							}
						}
						else if(lc3 == 5){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon(Nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								chuyendoi(ds, head, 2);
								quick_sort_by_option(ds,lc4);
								output = XUAT(ds,head,1);
							}
						}
						else if(lc3 == 6){
							while(1){
								system("cls");
								cout << "\033[1;31m" << output;
								cout << "\033[0m";
								menu_sort();
								int lc4;
								cout << "Nhap lua chon(Nhap so): "; cin >> lc4;
								if(lc4 == 0){
									output = "";
									break;
								}
								selection_sort(ds,head, lc1, lc4);
								output = XUAT(ds, head, lc1);
							}
						}
						else if(lc3 == 0){
							output = "";
							break;
						}
					}
				}
				else if(lc2 == 10){
					system("cls");
					output = XUAT(ds,head,lc1);
				}
				else if(lc2 == 0){
					fin.close();
					deleteList(head,2);
					break;	
				}
			}	
		}
		else if(lc1 == 0){
			break;
		}
	}
}