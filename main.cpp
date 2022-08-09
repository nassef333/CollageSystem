#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int test, Num, counter, studentNumber;
struct Student {
	int id;
	char name[31];
	int level;
	char department[31];
	float gpa;
	char address[31];
	char email[31];
};
struct TeachingStuff {
	int id;
	char name[31];
	char specialty[31];
	char scientificPosition[31];
	char tasks[31];
	char address[31];
	char email[31];

};
struct Staff {
	int id;
	char name[31];
	char department[31];
	char position[31];
	char address[31];
	char email[31];
};


void ShearchById(fstream& in, int id) {
	if (test == 1)
	{
		Student studentRecord;
		in.seekg(0, ios::beg);
		in.read((char*)&studentRecord, sizeof(studentRecord));
		do
		{
			if (id == studentRecord.id)
			{
				cout << "Student Name  : " << studentRecord.name << endl;
				cout << "Student Id    : " << studentRecord.id << endl;
				cout << "Student Level : " << studentRecord.level << endl;
				cout << "Student Department   : " << studentRecord.department << endl;
				cout << "Student GPA   : " << studentRecord.gpa << endl;
				cout << "Student Adress   : " << studentRecord.address << endl;
				cout << "Student Email   : " << studentRecord.email << endl;
				break;
			}
			in.read((char*)&studentRecord, sizeof(studentRecord));
		} while (!in.eof());
	}
	else if (test == 2) {
		TeachingStuff facultyRecord;
		in.seekg(0, ios::beg);
		in.read((char*)&facultyRecord, sizeof(facultyRecord));
		do
		{
			if (id == facultyRecord.id)
			{
				cout << "faculty Id                  : " << facultyRecord.id << endl;
				cout << "faculty Name                : " << facultyRecord.name << endl;
				cout << "faculty Specialty           : " << facultyRecord.specialty << endl;
				cout << "faculty scientific Position : " << facultyRecord.scientificPosition << endl;
				cout << "faculty Tasks               : " << facultyRecord.tasks << endl;
				cout << "faculty Adress              : " << facultyRecord.address << endl;
				cout << "faculty Email               : " << facultyRecord.email << endl;
				break;
			}


			in.read((char*)&facultyRecord, sizeof(facultyRecord));
		} while (!in.eof());
	}
	else if (test == 3) {
		Staff staffRecord;
		in.seekg(0, ios::beg);
		in.read((char*)&staffRecord, sizeof(staffRecord));
		do
		{
			if (id == staffRecord.id)
			{
				cout << "staff Id             : " << staffRecord.id << endl;
				cout << "staff Name           : " << staffRecord.name << endl;
				cout << "staff Department     : " << staffRecord.department << endl;
				cout << "staff Position	      : " << staffRecord.position << endl;
				cout << "staff Address	      : " << staffRecord.address << endl;
				cout << "staff Email	      : " << staffRecord.email << endl;

				break;
			}

			in.read((char*)&staffRecord, sizeof(staffRecord));
		} while (!in.eof());
	}
}
void AddNew(fstream& out) {

	if (test == 1) {
		Student studentRecord;
		cin.ignore();
		cout << "\n=============================================== Student Data ==================================================\n\n";

		cout << "Enter the student Name  : ";
		cin.getline(studentRecord.name, 31);
		cout << "Enter the student Id    : ";
		cin >> studentRecord.id;

		cout << "Enter the student Level : ";
		cin >> studentRecord.level;

		cout << "Enter the student GPA   : ";
		cin >> studentRecord.gpa;
		cout << "Enter the student department : ";
		cin.ignore();
		cin.getline(studentRecord.department, 31);
		cout << "Enter the student address : ";
		cin.getline(studentRecord.address, 31);
		cout << "Enter the student email : ";
		cin.getline(studentRecord.email, 31);


		out.write((char*)&studentRecord, sizeof(studentRecord));
	}
	else if (test == 2) {
		TeachingStuff facultyRecord;
		cout << "\n=============================================== Teaching Staff Data ==================================================\n\n";
		cout << "Enter the Id                  : ";
		cin >> facultyRecord.id;
		cout << "Enter the Name                : ";
		cin.ignore();
		cin.getline(facultyRecord.name, 31);
		cout << "Enter the Specialty           : ";
		cin.getline(facultyRecord.specialty, 31);
		cout << "Enter the Scientific position : ";
		cin.getline(facultyRecord.scientificPosition, 31);
		cout << "Enter the Tasks               : ";
		cin.getline(facultyRecord.tasks, 31);
		cout << "Enter the Address             : ";
		cin.getline(facultyRecord.address, 31);
		cout << "Enter the Email               : ";
		cin.getline(facultyRecord.email, 31);

		out.write((char*)&facultyRecord, sizeof(facultyRecord));



	}
	else if (test == 3) {
		Staff staffRecord;
		cin.ignore();
		cout << "\n=============================================== Staff Data ==================================================\n\n";

		cout << "Enter the staff Id                  : ";
		cin >> staffRecord.id;
		cout << "Enter the staff Name                : ";
		cin.ignore();
		cin.getline(staffRecord.name, 31);
		cout << "Enter the staff department          : ";
		cin.getline(staffRecord.department, 31);
		cout << "Enter the staff Scientific position : ";
		cin.getline(staffRecord.position, 31);
		cout << "Enter the staff Address : ";
		cin.getline(staffRecord.address, 31);
		cout << "Enter the staff Email : ";
		cin.getline(staffRecord.email, 31);
		out.write((char*)&staffRecord, sizeof(staffRecord));
	}
}
void ShowAll(fstream& in) {
	if (test == 1)
	{
		studentNumber = 0;
		Student studentRecord;
		in.seekg(0, ios::beg);
		in.read((char*)&studentRecord, sizeof(studentRecord));
		do
		{
			if (studentRecord.id == 0) {
				goto n;
			}
			else {
				studentNumber++;
				cout << "\n========================Student Number ( " << studentNumber << " )========================\n";
				cout << "\n\nStudent Name                : " << studentRecord.name << endl;
				cout << "Student Id                  : " << studentRecord.id << endl;
				cout << "Student Level               : " << studentRecord.level << endl;
				cout << "Student Department          : " << studentRecord.department << endl;
				cout << "Student GPA                 : " << studentRecord.gpa << endl;
				cout << "Student Adress              : " << studentRecord.address << endl;
				cout << "Student Email               : " << studentRecord.email << endl;
			}
		n:
			in.read((char*)&studentRecord, sizeof(studentRecord));
		} while (!in.eof());
	}
	else if (test == 2) {
		studentNumber = 0;
		TeachingStuff facultyRecord;
		in.seekg(0, ios::beg);
		in.read((char*)&facultyRecord, sizeof(facultyRecord));
		do
		{
			if (facultyRecord.id == 0) {
				goto b;
			}
			else {
				studentNumber++;
				cout << "\n========================Teaching Stuff Number ( " << studentNumber << " )========================\n";
				cout << "\n\nId                  : " << facultyRecord.id << endl;
				cout << "Name                : " << facultyRecord.name << endl;
				cout << "Specialty           : " << facultyRecord.specialty << endl;
				cout << "scientific Position : " << facultyRecord.scientificPosition << endl;
				cout << "Tasks               : " << facultyRecord.tasks << endl;
				cout << "Address             : " << facultyRecord.address << endl;
				cout << "Email               : " << facultyRecord.email << endl;
			}
		b:
			in.read((char*)&facultyRecord, sizeof(facultyRecord));
		} while (!in.eof());
	}
	else if (test == 3) {
		studentNumber = 0;
		Staff staffRecord;
		in.seekg(0, ios::beg);
		in.read((char*)&staffRecord, sizeof(staffRecord));
		do
		{
			if (staffRecord.id == 0) {
				goto m;
			}
			else {
				studentNumber++;
				cout << "\n========================Staff Number ( " << studentNumber << " )========================\n";
				cout << "staff Id              : " << staffRecord.id << endl;
				cout << "staff Name            : " << staffRecord.name << endl;
				cout << "staff Department      : " << staffRecord.department << endl;
				cout << "staff Position	      : " << staffRecord.position << endl;
				cout << "staff Address	      : " << staffRecord.address << endl;
				cout << "staff Email 	      : " << staffRecord.email << endl;
			}
		m:
			in.read((char*)&staffRecord, sizeof(staffRecord));
		} while (!in.eof());
	}
}
void Update(fstream& io, int n) {
	if (test == 1) {
		io.seekg(0, ios::beg);

		Student studentRecord;
		cout << "\n========================================= Old Data at record " << n + 1 << " =========================================\n";

		io.seekg(n * sizeof(studentRecord), ios::beg);
		io.read((char*)&studentRecord, sizeof(studentRecord));

		cout << "\nStudent Name  : " << studentRecord.name << endl;
		cout << "Student Id    : " << studentRecord.id << endl;
		cout << "Student Level : " << studentRecord.level << endl;
		cout << "Student Department   : " << studentRecord.department << endl;
		cout << "Student GPA   : " << studentRecord.gpa << endl;
		cout << "Student Adress   : " << studentRecord.address << endl;
		cout << "Student Email   : " << studentRecord.email << endl;


		cout << "\n========================================= Enter The New Data =========================================\n";
		cout << "\nEnter the student Id    : ";
		cin >> studentRecord.id;
		cout << "Enter the student Name  : ";
		cin.ignore();
		cin.getline(studentRecord.name, 31);
		cout << "Enter the student Level : ";
		cin >> studentRecord.level;
		cout << "Enter the student Departmeent : ";
		cin.ignore();
		cin.getline(studentRecord.department, 4);
		cout << "Enter the student GPA   : ";
		cin >> studentRecord.gpa;
		cout << "Enter the student address : ";
		cin.ignore();
		cin.getline(studentRecord.address, 31);
		cout << "Enter the student email : ";
		cin.ignore();
		cin.getline(studentRecord.email, 31);
		cin.ignore();

		io.seekp(n * sizeof(studentRecord), ios::beg);
		io.write((char*)&studentRecord, sizeof(studentRecord));
	}
	else if (test == 2) {
		io.seekg(0, ios::beg);
		TeachingStuff facultyRecord;
		cout << "\n========================================= Old Data at record " << n + 1 << " =========================================\n";
		io.seekg(n * sizeof(facultyRecord), ios::beg);
		io.read((char*)&facultyRecord, sizeof(facultyRecord));

		cout << "\nId	                 : " << facultyRecord.id << endl;
		cout << "Name                : " << facultyRecord.name << endl;
		cout << "Specialty           : " << facultyRecord.specialty << endl;
		cout << "scientific Position : " << facultyRecord.scientificPosition << endl;
		cout << "Tasks               : " << facultyRecord.tasks << endl;
		cout << "Adress              : " << facultyRecord.address << endl;
		cout << "Email               : " << facultyRecord.email << endl;



		cout << "\n========================================= Enter The New Data =========================================\n";

		cout << "\nNew Id    : ";
		cin >> facultyRecord.id;
		cout << "New Name  : ";
		cin.ignore();
		cin.getline(facultyRecord.name, 31);
		cout << "New Specialty : ";
		cin >> facultyRecord.specialty;
		cout << "New scientificPosition : ";
		cin.ignore();
		cin.getline(facultyRecord.scientificPosition, 31);
		cout << "New Tasks   : ";
		cin >> facultyRecord.tasks;
		cout << "New address : ";
		cin.ignore();
		cin.getline(facultyRecord.address, 31);
		cout << "New email : ";
		cin.getline(facultyRecord.email, 31);

		cin.ignore();

		io.seekp(n * sizeof(facultyRecord), ios::beg);
		io.write((char*)&facultyRecord, sizeof(facultyRecord));
	}
	else if (test == 3) {
		io.seekg(0, ios::beg);
		Staff staffRecord;
		cout << "\n========================================= Old Data at record " << n + 1 << " =========================================\n";

		io.seekg(n * sizeof(staffRecord), ios::beg);
		io.read((char*)&staffRecord, sizeof(staffRecord));

		cout << "\nstaff Id             : " << staffRecord.id << endl;
		cout << "staff Name           : " << staffRecord.name << endl;
		cout << "staff Department     : " << staffRecord.department << endl;
		cout << "staff Position	      : " << staffRecord.position << endl;
		cout << "staff Address	      : " << staffRecord.address << endl;
		cout << "staff Email	      : " << staffRecord.email << endl;

		cout << "\n========================================= Enter The New Data =========================================\n";

		cin.ignore();

		cout << "\nEnter the staff Id    : ";
		cin >> staffRecord.id;
		cout << "Enter the Faculty Name  : ";
		cin.ignore();
		cin.getline(staffRecord.name, 31);
		cout << "Enter the Faculty Department : ";
		cin >> staffRecord.department;
		cout << "Enter the Faculty Position : ";
		cin.ignore();
		cin.getline(staffRecord.position, 31);
		cout << "Enter the Faculty Address   : ";
		cin >> staffRecord.address;
		cout << "Enter the Faculty address : ";
		cin.ignore();
		cin.getline(staffRecord.address, 31);
		cout << "Enter the Faculty email : ";
		cin.getline(staffRecord.email, 31);



		cin.ignore();

		io.seekp(n * sizeof(staffRecord), ios::beg);
		io.write((char*)&staffRecord, sizeof(staffRecord));
	}
}
void remove(fstream& io, int n) {
	if (test == 1) {
		io.seekg(0, ios::beg);

		Student studentRecord;
		io.seekg(n * sizeof(studentRecord), ios::beg);
		io.read((char*)&studentRecord, sizeof(studentRecord));//////////////////////////////////////////////


		studentRecord.id = 0;
		studentRecord.name[0] = 0;
		studentRecord.level = 0;
		studentRecord.department[0] = 0;
		studentRecord.gpa = 0;
		studentRecord.address[0] = 0;
		studentRecord.email[0] = 0;

		io.seekp(n * sizeof(studentRecord), ios::beg);
		io.write((char*)&studentRecord, sizeof(studentRecord));
	}
	else if (test == 2) {
		io.seekg(0, ios::beg);
		TeachingStuff facultyRecord;
		io.seekg(n * sizeof(facultyRecord), ios::beg);
		io.read((char*)&facultyRecord, sizeof(facultyRecord));


		facultyRecord.id = 0;
		facultyRecord.name[0] = 0;
		facultyRecord.specialty[0] = 0;
		facultyRecord.scientificPosition[0] = 0;
		facultyRecord.tasks[0] = 0;
		facultyRecord.address[0] = 0;
		facultyRecord.email[0] = 0;


		io.seekp(n * sizeof(facultyRecord), ios::beg);
		io.write((char*)&facultyRecord, sizeof(facultyRecord));
	}
	else if (test == 3) {
		io.seekg(0, ios::beg);
		Staff staffRecord;
		io.seekg(n * sizeof(staffRecord), ios::beg);
		io.read((char*)&staffRecord, sizeof(staffRecord));


		staffRecord.id = 0;
		staffRecord.name[0] = 0;
		staffRecord.department[0] = 0;
		staffRecord.position[0] = 0;
		staffRecord.address[0] = 0;
		staffRecord.email[0] = 0;


		cin.ignore();

		io.seekp(n * sizeof(staffRecord), ios::beg);
		io.write((char*)&staffRecord, sizeof(staffRecord));
	}
}
void UpdateForDelete(fstream& io, int Num) {
	if (test == 1) {
		io.seekg(0, ios::beg);

		Student studentRecord;
		io.seekg(Num * sizeof(studentRecord), ios::beg);
		io.read((char*)&studentRecord, sizeof(studentRecord));



		cout << "\n=============================================== Student Data ==================================================\n\n";

		cout << "Enter the student Id    : ";
		cin >> studentRecord.id;
		cout << "Enter the student Name  : ";
		cin.ignore();
		cin.getline(studentRecord.name, 31);
		cout << "Enter the student Level : ";
		cin >> studentRecord.level;
		cout << "Enter the student Departmeent : ";
		cin.ignore();
		cin.getline(studentRecord.department, 4);
		cout << "Enter the student GPA   : ";
		cin >> studentRecord.gpa;
		cout << "Enter the student address : ";
		cin.ignore();
		cin.getline(studentRecord.address, 31);
		cout << "Enter the student email : ";
		cin.getline(studentRecord.email, 31);

		io.seekp(Num * sizeof(studentRecord), ios::beg);
		io.write((char*)&studentRecord, sizeof(studentRecord));
	}
	else if (test == 2) {
		io.seekg(0, ios::beg);
		TeachingStuff facultyRecord;
		io.seekg(Num * sizeof(facultyRecord), ios::beg);
		io.read((char*)&facultyRecord, sizeof(facultyRecord));




		cout << "\n=============================================== Teaching Staff Data ==================================================\n\n";


		cout << "Enter the Id    : ";
		cin >> facultyRecord.id;
		cout << "Enter the Name  : ";
		cin.ignore();
		cin.getline(facultyRecord.name, 31);
		cout << "Enter the Specialty : ";
		cin >> facultyRecord.specialty;
		cout << "Enter the scientificPosition : ";
		cin.ignore();
		cin.getline(facultyRecord.scientificPosition, 31);
		cout << "Enter the Tasks   : ";
		cin >> facultyRecord.tasks;
		cout << "Enter the address : ";
		cin.ignore();
		cin.getline(facultyRecord.address, 31);
		cout << "Enter the email : ";
		cin.getline(facultyRecord.email, 31);





		io.seekp(Num * sizeof(facultyRecord), ios::beg);
		io.write((char*)&facultyRecord, sizeof(facultyRecord));
	}
	else if (test == 3) {
		io.seekg(0, ios::beg);
		Staff staffRecord;
		io.seekg(Num * sizeof(staffRecord), ios::beg);
		io.read((char*)&staffRecord, sizeof(staffRecord));



		cout << "\n=============================================== Staff Data ==================================================\n\n";

		cout << "Enter the staff Id    : ";
		cin >> staffRecord.id;
		cout << "Enter the Faculty Name  : ";
		cin.ignore();
		cin.getline(staffRecord.name, 31);
		cout << "Enter the Faculty Department : ";
		cin >> staffRecord.department;
		cout << "Enter the Faculty Position : ";
		cin.ignore();
		cin.getline(staffRecord.position, 31);
		cout << "Enter the Faculty Address   : ";
		cin >> staffRecord.address;
		cout << "Enter the Faculty address : ";
		cin.ignore();
		cin.getline(staffRecord.address, 31);
		cout << "Enter the Faculty email : ";
		cin.getline(staffRecord.email, 31);

		io.seekp(Num * sizeof(staffRecord), ios::beg);
		io.write((char*)&staffRecord, sizeof(staffRecord));
	}
}
bool ShearchForUpdate(fstream& in) {
	Num = 0;
	counter = 0;
	if (test == 1)
	{

		//id = 0;
		Student studentRecord;
		in.seekg(0, ios::beg);
		while (!in.fail())
		{
			if (in.eof())
				break;
			if (!in.fail()) {

				in.read((char*)&studentRecord, sizeof(studentRecord));
				//cout << studentRecord.id << endl;
				Num++;
				//cout << Num<<endl;
				if (studentRecord.id == 0)
				{
					counter++;
					//cout << "\ntrue\n";
					break;
				}
				else
				{
					//cout << "\nfalse\n";
					continue;
				}
				//cout << "\nend of loop\n";
			}
			//in.read((char*)&studentRecord, sizeof(studentRecord));
		}
		if (counter > 0)
			return true;
		else
			return false;
	}
	else if (test == 2) {


		//id = 0;
		TeachingStuff facultyRecord;
		in.seekg(0, ios::beg);
		while (!in.fail())
		{
			if (in.eof())
				break;
			if (!in.fail()) {

				in.read((char*)&facultyRecord, sizeof(facultyRecord));
				//cout << studentRecord.id << endl;
				Num++;
				//cout << Num<<endl;
				if (facultyRecord.id == 0)
				{
					counter++;
					//cout << "\ntrue\n";
					break;
				}
				else
				{
					//cout << "\nfalse\n";
					continue;
				}
				//cout << "\nend of loop\n";
			}
			//in.read((char*)&studentRecord, sizeof(studentRecord));
		}
		if (counter > 0)
			return true;
		else

			return false;
	}

	else if (test == 3) {


		//id = 0;
		Staff staffRecord;
		in.seekg(0, ios::beg);
		while (!in.fail())
		{
			if (in.eof())
				break;
			if (!in.fail()) {

				in.read((char*)&staffRecord, sizeof(staffRecord));
				//cout << studentRecord.id << endl;
				Num++;
				//cout << Num<<endl;
				if (staffRecord.id == 0)
				{
					counter++;
					//cout << "\ntrue\n";
					break;
				}
				else
				{
					//cout << "\nfalse\n";
					continue;
				}
				//cout << "\nend of loop\n";
			}
			//in.read((char*)&studentRecord, sizeof(studentRecord));
		}
		if (counter > 0)
			return true;
		else

			return false;
	}
}

int main() {
	system("color B");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t                               ---------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t   	                         |     	 File Organization Project Faculty Data Base	     |" << endl;
	cout << "\t\t\t\t\t                               ---------------------------------------------------------------------" << endl;
	cout << "\n" << endl;
	int tf;
	int t;
	do
	{
		cout << "\t\t\t\t\t\t\t\t     *************************************************************************\n" << endl;
		cout << "\t\t\t\t\t\t\t\t            |  1  | Student     |  2  | Teaching Staff     |  3  | Staff\n" << endl;
		cout << "\t\t\t\t\t\t\t\t     *************************************************************************\n" << endl;
		cin >> test;
		fstream fStudent("student.txt", ios::in | ios::out | ios::app);
		fstream Student("student.txt", ios::in | ios::out);
		fstream fFaculty("Faculty.txt", ios::in | ios::out | ios::app);
		fstream Faculty("Faculty.txt", ios::in | ios::out);
		fstream fStaff("staff.txt", ios::in | ios::out | ios::app);
		fstream Staff("staff.txt", ios::in | ios::out);
		if (test == 1)
		{
		a:
			cout << "\t|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cout << "\t|       |  1  | Add new Student              |  2  | Show all Student                |  3  | Search by id               |  4  | Update Student Data      |  5  | Delete Student Data             |\n";
			cout << "\t|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cin >> tf;
			cout << endl;
			if (tf == 1)
			{
				if (ShearchForUpdate(Student)) {
					UpdateForDelete(Student, Num - 1);
				}
				else
					AddNew(fStudent);
			}
			else if (tf == 2)
			{
				ShowAll(fStudent);
			}
			else if (tf == 3)
			{
				int id;
				cout << "Id : ";
				cin >> id;
				ShearchById(fStudent, id);
			}
			else if (tf == 4)
			{
				int n;
				cout << "Student Number -> ";
				cin >> n;
				Update(Student, n - 1);
			}
			else if (tf == 5) {
				int n;
				cout << "Student Number -> ";
				cin >> n;
				remove(Student, n - 1);
			}
			else {
				system("CLS");
				cout << "choose from 1 to 5\n\n";
				goto a;
			}
			fStudent.close();

		}
		else if (test == 2) {
			cout << "\t|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cout << "\t|       |  1  | Add new              |  2  | Show all Teaching Staff                  |  3  | Search by id                 |  4  | Update Data                     |  5  | Delete Staff          |\n";
			cout << "\t|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cin >> tf;
			cout << endl;
			if (tf == 1)
			{
				if (ShearchForUpdate(Faculty)) {
					UpdateForDelete(Faculty, Num - 1);
				}
				else
					AddNew(fFaculty);
			}
			else if (tf == 2)
			{
				ShowAll(fFaculty);
			}
			else if (tf == 3)
			{
				int id;
				cout << "Id : ";
				cin >> id;
				ShearchById(fFaculty, id);
			}
			else if (tf == 4)
			{
				int n;
				cout << "Teaching staff Number -> ";
				cin >> n;
				Update(Faculty, n - 1);
			}
			else if (tf == 5) {
				int n;
				cout << "Teaching staff Number -> ";
				cin >> n;
				remove(Faculty, n - 1);
			}
			else {
				system("CLS");
				cout << "choose from 1 to 5\n\n";
				goto a;
			}
		}
		else if (test == 3) {
			cout << "\t|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cout << "\t|       |  1  | Add new stuff              |  2  | Show all stuff                |  3  | Search by id               |  4  | Update stuff Data            |  5  | Delete stuff Data               |\n";
			cout << "\t|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cin >> tf;
			cout << endl;
			if (tf == 1)
			{
				if (ShearchForUpdate(Staff)) {
					UpdateForDelete(Staff, Num - 1);
				}
				else
					AddNew(fStaff);
			}
			else if (tf == 2)
			{
				ShowAll(fStaff);
			}
			else if (tf == 3)
			{
				int id;
				cout << "Id : ";
				cin >> id;
				ShearchById(fStaff, id);
			}
			else if (tf == 4)
			{
				int n;
				cout << "Staff Number -> ";
				cin >> n;
				Update(Staff, n - 1);
			}
			else if (tf == 5) {
				int n;
				cout << "Teaching staff Number -> ";
				cin >> n;
				remove(Staff, n - 1);
			}
			else {
				system("CLS");
				cout << "choose from 1 to 5\n\n";
				goto a;
			}
		}
		cout << "\n Press any number to continue ... " << endl;
		cin >> t;
		system("cls");
	} while (t);

	return 0;
}